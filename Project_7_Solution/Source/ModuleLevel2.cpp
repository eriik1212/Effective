#include "ModuleScene.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleCollisions.h"

#include "ModulePlayer.h"
#include "ModuleEnemies.h"

#include "ModuleLevel2.h"
#include "ModuleSceneIntro.h"
#include "ModuleSceneWin.h"
#include "ModuleSceneLose.h"
#include "ModuleHUD.h"


ModuleLevel2::ModuleLevel2(bool enabled) : Module(enabled)
{
	background.x = 864;
	background.y = 229;
	background.w = 448;
	background.h = 224;

	aprilAnim.PushBack({ 163, 286, 29, 63 });
	aprilAnim.PushBack({ 200, 286, 29, 63 });
	aprilAnim.loop = true;
	aprilAnim.speed = 0.02f;

	shrederStandAnim.PushBack({ 560, 194, 63, 76 });

	shrederWalkAnim.PushBack({ 623, 194, 63, 76 });
	shrederWalkAnim.PushBack({ 686, 194, 63, 76 });
	shrederWalkAnim.PushBack({ 756, 194, 63, 76 });
	shrederWalkAnim.PushBack({ 821, 194, 63, 76 });
	shrederWalkAnim.PushBack({ 889, 194, 63, 76 });
	shrederWalkAnim.PushBack({ 959, 194, 63, 76 });

	shrederWalkAnim.loop = true;
	shrederWalkAnim.speed = 0.15f;

	shrederGrabAnim.PushBack({ 560, 284, 63, 76 });
	shrederGrabAnim.PushBack({ 634, 284, 63, 76 });

	shrederGrabAnim.loop = true;
	shrederGrabAnim.speed = 0.07f;

	shrederJumpAnim.PushBack({ 720, 284, 73, 76 });

	//PATH Shreder
	pathShreder.PushBack({ 0.0f, 0.0f }, 20, &shrederStandAnim);
	pathShreder.PushBack({ -2.0f, 0.0f }, 68, &shrederWalkAnim);
	pathShreder.PushBack({ 0.0f, 0.0f }, 20, &shrederGrabAnim);
	pathShreder.PushBack({ 2.0f, -0.7f }, 50, &shrederJumpAnim);
	pathShreder.PushBack({ 2.0f, -0.5f }, 10, &shrederJumpAnim);
	pathShreder.PushBack({ 2.0f, 0.0f }, 10, &shrederJumpAnim);
	pathShreder.PushBack({ 2.0f, 0.7f }, 10, &shrederJumpAnim);
	pathShreder.PushBack({ 2.0f, 1.0f }, 50, &shrederJumpAnim);

}

ModuleLevel2::~ModuleLevel2()
{

}

// Load assets
bool ModuleLevel2::Start()
{
	LOG("Loading background assets");

	bool ret = true;

	countDown = 0;

	App->player->Enable();
	App->HUD->Enable();
	App->enemies->Enable();

	App->player->position.x = 5;
	App->player->position.y = 112;

	App->render->camera.x = 1;
	App->render->playerLimitR = App->render->camera.w - 135;
	App->render->playerLimitL = App->render->camera.x - 13;

	pathShreder.Reset();

	//Spawn Schreder Path
	pathShreder.ResetRelativePosition();
	spawnPosShreder = iPoint((int)170, (int)72);

	stage2Texture = App->textures->Load("Assets/Tilesets/tile_map_stage_1.png");
	aprilTexture = App->textures->Load("Assets/Tilesets/fire.png");
	shrederTexture = App->textures->Load("Assets/Enemies/boss.png");

	App->audio->PlayMusic("Assets/Audio/04_aprils_room_scene_1_stage_2.ogg", 1.0f);

	// Enemies --- CURRENT MAX. ENEMIES == 2 --- 
	//¡¡IMPORTANT: TO ADD AN ENEMY CHANGE moduleEnemies.h -> #define MAX_ENEMIES 2!!

	if (App->level2->Enabled() && App->scene->Disabled())
	{
		// Iterate existing enemies
		for (uint i = 0; i < MAX_ENEMIES; ++i)
		{
			if (App->enemies->enemies[i] != nullptr)
			{
				// Delete the enemy when it has reached the end of the screen
				delete App->enemies->enemies[i];
				App->enemies->enemies[i] = nullptr;
			}
		}
		App->enemies->AddEnemy(ENEMY_TYPE::WHITE_ENEMY, 250, 90);
	}

	return ret;
}

update_status ModuleLevel2::Update()
{
	aprilCurrentAnimation = &aprilAnim;
	aprilAnim.Update();

	positionShreder = spawnPosShreder + pathShreder.GetRelativePosition();
	shrederCurrentAnimation = pathShreder.GetCurrentAnimation();

	shrederWalkAnim.Update();
	shrederGrabAnim.Update();

	//Handle Camera Limits
	if (App->render->camera.x > CAMERA_LIMIT_LVL2) App->render->camera.x = CAMERA_LIMIT_LVL2;

	// Position Players Limits
	if (App->player->position.x < 3) App->player->position.x = 3;
	if (App->player->position.x < App->render->playerLimitL) App->player->position.x = App->render->playerLimitL;
	if (App->player->position.x > 336) App->player->position.x = 336;
	if (App->player->position.y < 65) App->player->position.y = 65;
	if (App->player->position.y > 136) App->player->position.y = 136;


	if (App->enemies->enemies[0] == nullptr && App->render->camera.x == CAMERA_LIMIT_LVL2)
	{
		//----------------------------------------------------------------------------------------Initialize Positions
		pathShreder.Update();
		

		countDown++;

		if (countDown > 200)
		{
			this->Disable();
			CleanUp();
			App->player->HIT->pendingToDelete = true;
			App->player->collider->pendingToDelete = true;
			App->player->Disable();
			App->player->CleanUp();

			App->enemies->Disable();
			App->enemies->CleanUp();

			App->HUD->Disable();

			App->sceneWin->Enable();
		}
	}

	if (App->input->keys[SDL_SCANCODE_F2] == KEY_STATE::KEY_DOWN)
	{
		this->Disable();
		CleanUp();
		App->player->HIT->pendingToDelete = true;
		App->player->collider->pendingToDelete = true;
		App->player->Disable();
		App->player->CleanUp();

		App->enemies->Disable();
		App->enemies->CleanUp();

		App->HUD->Disable();

		App->sceneWin->Enable();
	}
	else if (App->input->keys[SDL_SCANCODE_F3] == KEY_STATE::KEY_DOWN)
	{
		App->player->HIT->pendingToDelete = true;
		App->player->collider->pendingToDelete = true;
		App->player->Disable();
		App->player->CleanUp();

		App->enemies->Disable();
		App->enemies->CleanUp();

		App->HUD->Disable();

		App->sceneLose->Enable();
	}
	else if (App->input->keys[SDL_SCANCODE_F5] == KEY_STATE::KEY_DOWN)
	{
		this->Disable();
		CleanUp();

		App->player->Disable();
		App->player->CleanUp();

		App->enemies->Disable();
		App->enemies->CleanUp();

		App->HUD->Disable();

		App->scene->Enable();
	}

	return update_status::UPDATE_CONTINUE;
}

// Update: draw background
update_status ModuleLevel2::PostUpdate()
{
	// Draw everything --------------------------------------
	App->render->Blit(stage2Texture, 0, 0, &background, 1); // Background
	
	if (App->enemies->enemies[0] == nullptr && App->render->camera.x == CAMERA_LIMIT_LVL2)
	{
		// Shreder
		if (shrederCurrentAnimation != nullptr)
			App->render->Blit(shrederTexture, positionShreder.x, positionShreder.y, &(shrederCurrentAnimation->GetCurrentFrame()), NULL);
	}

	return update_status::UPDATE_CONTINUE;
}

bool ModuleLevel2::CleanUp()
{
	bool ret;
	App->textures->CleanUp();
	//App->audio->CleanUp();
	return true;
}
