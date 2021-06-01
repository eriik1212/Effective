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


ModuleScene::ModuleScene(bool enabled) : Module(enabled)
{
	background.x = 0;
	background.y = 0;
	background.w = 1373;
	background.h = 224;


	fireDoor.PushBack({ 476, 233, 33, 79 });
	fireDoor.PushBack({ 511, 233, 33, 79 });
	fireDoor.PushBack({ 546, 233, 33, 79 });
	fireDoor.PushBack({ 581, 233, 33, 79 });
	fireDoor.PushBack({ 616, 233, 33, 79 });
	fireDoor.PushBack({ 651, 233, 33, 79 });
	fireDoor.PushBack({ 686, 233, 33, 79 });
	fireDoor.speed = 0.25f;

	fireElev.PushBack({ 400, 326, 44, 77 });
	fireElev.PushBack({ 446, 326, 44, 77 });
	fireElev.PushBack({ 492, 326, 44, 77 });
	fireElev.PushBack({ 538, 326, 44, 77 });
	fireElev.PushBack({ 584, 326, 44, 77 });
	fireElev.PushBack({ 630, 326, 44, 77 });
	fireElev.PushBack({ 676, 326, 44, 77 });
	fireElev.speed = 0.25f;

	doorBreak.PushBack({ 262, 233, 33, 79 });
	doorBreak.PushBack({ 301, 233, 33, 79 });
	doorBreak.PushBack({ 341, 233, 48, 79 });
	doorBreak.PushBack({ 394, 233, 57, 79 });
	doorBreak.PushBack({ 452, 233, 16, 79 });
	doorBreak.loop = false;
	doorBreak.speed = 0.2f;

	doorBreak2.PushBack({ 262, 233, 33, 79 });
	doorBreak2.PushBack({ 301, 233, 33, 79 });
	doorBreak2.PushBack({ 341, 233, 48, 79 });
	doorBreak2.PushBack({ 394, 233, 57, 79 });
	doorBreak2.PushBack({ 452, 233, 16, 79 });
	doorBreak2.loop = false;
	doorBreak2.speed = 0.2f;

	doorBreak3.PushBack({ 262, 233, 33, 79 });
	doorBreak3.PushBack({ 301, 233, 33, 79 });
	doorBreak3.PushBack({ 341, 233, 48, 79 });
	doorBreak3.PushBack({ 394, 233, 57, 79 });
	doorBreak3.PushBack({ 452, 233, 16, 79 });
	doorBreak3.loop = false;
	doorBreak3.speed = 0.2f;


	openElev.PushBack({ 262, 326, 44, 77 });
	openElev.PushBack({ 308, 326, 44, 77 });
	openElev.PushBack({ 354, 326, 44, 77 });
	openElev.PushBack({ 452, 233, 16, 79 });
	openElev.loop = false;
	openElev.speed = 0.1f;

	openElev2.PushBack({ 262, 326, 44, 77 });
	openElev2.PushBack({ 308, 326, 44, 77 });
	openElev2.PushBack({ 354, 326, 44, 77 });
	openElev2.PushBack({ 452, 233, 16, 79 });
	openElev2.loop = false;
	openElev2.speed = 0.1f;
}

ModuleScene::~ModuleScene()
{

}

// Load assets
bool ModuleScene::Start()
{
	LOG("Loading background assets");

	bool ret = true;

	countDown = 0;

	App->player->Enable();
	App->HUD->Enable();
	App->enemies->Enable();

	doorBreak.Reset();
	doorBreak2.Reset();
	doorBreak3.Reset();

	openElev.Reset();
	openElev2.Reset();

	App->player->position.x = 5;
	App->player->position.y = 112;

	App->render->camera.x = 0;
	App->render->camera.y = 0;
	App->render->playerLimitR = App->render->camera.w - 135;
	App->render->playerLimitL = App->render->camera.x - 13;

	stageTexture = App->textures->Load("Assets/Tilesets/tile_map_stage_1.png");

	App->audio->PlayMusic("Assets/Audio/03_fire_scene_1_stage_1.ogg", 1.0f);
	DoorBrake = App->audio->LoadFx("Assets/FX/broken_door.wav");
	ElevatorDoor = App->audio->LoadFx("Assets/FX/auto_doors.wav");

	// Final wall colliders
	/*App->collisions->AddCollider({ 1000, 200, 20, 10 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 1000, 145, 20, 10 }, Collider::Type::WALL);*/

	// Enemies --- CURRENT MAX. ENEMIES == 4 --- 
	//¡¡IMPORTANT: TO ADD AN ENEMY CHANGE moduleEnemies.h -> #define MAX_ENEMIES 2!!
	if (App->scene->Enabled() && App->level2->Disabled())
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
		App->enemies->AddEnemy(ENEMY_TYPE::PURPLE_ENEMY, 400, 52);
		App->enemies->AddEnemy(ENEMY_TYPE::WHITE_ENEMY, 1150, 110);
		App->enemies->AddEnemy(ENEMY_TYPE::BALL_ENEMY, 495, -75);
		
	}

	return ret;
}

update_status ModuleScene::Update()
{
	//Handle Camera Limits
	if (App->render->camera.x > CAMERA_LIMIT_LVL1) App->render->camera.x = CAMERA_LIMIT_LVL1;

	// Position Players Limits
	if (App->player->position.x < App->render->playerLimitL) App->player->position.x = App->render->playerLimitL;
	if (App->player->position.x > 1250) App->player->position.x = 1250;
	if (App->player->position.y < 56) App->player->position.y = 56;
	if (App->player->position.y > 136) App->player->position.y = 136;

	// ------------------------------------------- World Animations Updates
	fireDoor.Update();
	fireElev.Update();


	// Camera
	if (App->render->camera.x > 780)
	{
		doorBreak.Update();
	}

	//Second if for the FX
	if (App->render->camera.x == 781)
	{
		App->audio->PlayFx(DoorBrake);
	}

	if (App->render->camera.x > 1650)
	{
		doorBreak2.Update();
	}

	if (App->render->camera.x == 1651)
	{
		App->audio->PlayFx(DoorBrake);
	}

	if (App->render->camera.x >2025)
	{
		doorBreak3.Update();
	}

	if (App->render->camera.x >= 2026 && App->render->camera.x <= 2029)
	{
		App->audio->PlayFx(DoorBrake);
	}

	if (App->render->camera.x > 2500)
	{
		openElev.Update();
		openElev2.Update();
	}

	if (App->render->camera.x >= 2501 && App->render->camera.x <= 2504)
	{
		App->audio->PlayFx(ElevatorDoor);
	}

	if (App->enemies->enemies[0] == nullptr && App->render->camera.x == CAMERA_LIMIT_LVL1)
	{
		countDown++;

		if (countDown > 80)
		{
			this->Disable();
			CleanUp();
			App->player->Disable();
			App->player->CleanUp();

			App->enemies->Disable();
			App->enemies->CleanUp();

			App->HUD->Disable();

			App->level2->Enable();
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
	else if (App->input->keys[SDL_SCANCODE_F6] == KEY_STATE::KEY_DOWN)
	{
		this->Disable();
		CleanUp();
		App->player->Disable();
		App->player->CleanUp();

		App->enemies->Disable();
		App->enemies->CleanUp();

		App->HUD->Disable();

		App->level2->Enable();
	}

	return update_status::UPDATE_CONTINUE;
}

// Update: draw background
update_status ModuleScene::PostUpdate()
{
	// Draw everything --------------------------------------
	App->render->Blit(stageTexture, 0, 0, &background, 1); // Background

	App->render->Blit(stageTexture, 412, 49, &(fireDoor.GetCurrentFrame()), 1); // FireDoor1
	App->render->Blit(stageTexture, 701, 49, &(fireDoor.GetCurrentFrame()), 1); // FireDoor2
	App->render->Blit(stageTexture, 829, 49, &(fireDoor.GetCurrentFrame()), 1); // FireDoor3


	App->render->Blit(stageTexture, 412, 49, &(doorBreak.GetCurrentFrame()), 1); // DoorBreak1
	App->render->Blit(stageTexture, 701, 49, &(doorBreak2.GetCurrentFrame()), 1); // DoorBreak2
	App->render->Blit(stageTexture, 829, 49, &(doorBreak3.GetCurrentFrame()), 1); // DoorBreak3


	App->render->Blit(stageTexture, 950, 50, &(fireElev.GetCurrentFrame()), 1); // FireElevator1
	App->render->Blit(stageTexture, 1079, 50, &(fireElev.GetCurrentFrame()), 1); // FireElevator2

	App->render->Blit(stageTexture, 950, 50, &(openElev.GetCurrentFrame()), 1); // OpenElevator1
	App->render->Blit(stageTexture, 1079, 50, &(openElev2.GetCurrentFrame()), 1); // OpenElevator2


	return update_status::UPDATE_CONTINUE;
}

bool ModuleScene::CleanUp()
{
	bool ret;
	App->textures->CleanUp();
	//App->audio->CleanUp();
	return true;
}
