#include "ModuleLevel2.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleCollisions.h"

#include "ModulePlayer.h"
#include "ModuleEnemies.h"

#include "ModuleSceneIntro.h"
#include "ModuleSceneWin.h"
#include "ModuleSceneLose.h"


ModuleLevel2::ModuleLevel2(bool enabled) : Module(enabled)
{
	background.x = 0;
	background.y = 0;
	background.w = 448;
	background.h = 224;
}

ModuleLevel2::~ModuleLevel2()
{

}

// Load assets
bool ModuleLevel2::Start()
{
	LOG("Loading background assets");

	bool ret = true;

	App->player->Enable();

	App->enemies->Enable();

	countDown = 0;

	App->player->position.x = 5;
	App->player->position.y = 112;

	App->render->camera.x = 0;
	App->render->playerLimitR = App->render->camera.w - 135;
	App->render->playerLimitL = App->render->camera.x + 5;

	stage2Texture = App->textures->Load("Assets/Tilesets/TileMapStage1.png");

	App->audio->PlayMusic("Assets/Audio/03 Fire! Scene 1 Stage 1.ogg", 1.0f);

	// Enemies --- CURRENT MAX. ENEMIES == 2 --- 
	//¡¡IMPORTANT: TO ADD AN ENEMY CHANGE moduleEnemies.h -> #define MAX_ENEMIES 2!!

	//App->enemies->AddEnemy(ENEMY_TYPE::PURPLE_ENEMY, 400, 52);
	//App->enemies->AddEnemy(ENEMY_TYPE::WHITE_ENEMY, 1150, 110);

	return ret;
}

update_status ModuleLevel2::Update()
{
	//Handle Camera Limits
	if (App->render->camera.x > CAMERA_LIMIT_LVL2) App->render->camera.x = CAMERA_LIMIT_LVL2;

	// Position Players Limits
	if (App->player->position.x < App->render->playerLimitL) App->player->position.x = App->render->playerLimitL;
	if (App->player->position.x > 448) App->player->position.x = 448;
	if (App->player->position.y < 56) App->player->position.y = 56;
	if (App->player->position.y > 136) App->player->position.y = 136;

	// ------------------------------------------- World Animations Updates



	if (App->enemies->enemies[0] == nullptr && App->render->camera.x == CAMERA_LIMIT_LVL2)
	{
		countDown++;

		if (countDown > 80)
		{
			this->Disable();
			CleanUp();
			App->player->HIT->pendingToDelete = true;
			App->player->collider->pendingToDelete = true;
			App->player->Disable();
			App->player->CleanUp();

			App->enemies->Disable();
			App->enemies->CleanUp();

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

		App->sceneLose->Enable();
	}

	return update_status::UPDATE_CONTINUE;
}

// Update: draw background
update_status ModuleLevel2::PostUpdate()
{
	// Draw everything --------------------------------------
	App->render->Blit(stage2Texture, 864, 229, &background, 1); // Background


	return update_status::UPDATE_CONTINUE;
}

bool ModuleLevel2::CleanUp()
{
	bool ret;
	App->textures->CleanUp();
	//App->audio->CleanUp();
	return true;
}
