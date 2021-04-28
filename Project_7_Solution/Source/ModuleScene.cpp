#include "ModuleScene.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleCollisions.h"

#include "ModulePlayer.h"
#include "ModuleEnemies.h"

#include "ModuleSceneIntro.h"
#include "ModuleSceneWin.h"


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

	App->render->camera.x = 0;
	App->render->playerLimitR = App->render->camera.w - 135;
	App->render->playerLimitL = App->render->camera.x + 5;

	stageTexture = App->textures->Load("Assets/Tilesets/TileMapStage1.png");
	gameOverTexture = App->textures->Load("Assets/UI & HUD/game_over.png");

	App->audio->PlayMusic("Assets/Audio/03 Fire! Scene 1 Stage 1.ogg", 1.0f);
	DoorBrake = App->audio->LoadFx("Assets/FX/BrokenDoor.wav");
	ElevatorDoor = App->audio->LoadFx("Assets/FX/AutoDoors.wav");

	// Final wall colliders
	/*App->collisions->AddCollider({ 1000, 200, 20, 10 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 1000, 145, 20, 10 }, Collider::Type::WALL);*/

	// Enemies ---
	App->enemies->AddEnemy(ENEMY_TYPE::PURPLE_ENEMY, 200, 52);
	App->enemies->AddEnemy(ENEMY_TYPE::WHITE_ENEMY, 200, 102);
	//App->enemies->AddEnemy(ENEMY_TYPE::PURPLE_ENEMY, 250, 112);
	
	return ret;
}

update_status ModuleScene::Update()
{
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

	// SCANCODES

	if (App->input->keys[SDL_SCANCODE_F4] == KEY_STATE::KEY_DOWN)
	{
		
		
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
		gameOver = true;
		App->player->HIT->pendingToDelete = true;
		App->player->collider->pendingToDelete = true;
		App->player->Disable();
		App->player->CleanUp();

		App->enemies->Disable();
		App->enemies->CleanUp();
	}

	// GameOver Counter
	if (gameOver)
	{
		App->audio->StopMusic();
		if (gOverCounter <= 200)
		{
			gOverCounter++;
		}
		else if(gOverCounter > 200)
		{
			gameOverTexture = nullptr;
			gameOver = false;
			gOverCounter = 0;
			this->Disable();
			CleanUp();
			App->sceneIntro->Enable();
		}
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
	 
	if (gameOver)
	{
		App->render->Blit(gameOverTexture, SCREEN_WIDTH / 2 - 50, SCREEN_HEIGHT / 2 - 50, NULL, 0, true); // GameOver Texture
	}


	return update_status::UPDATE_CONTINUE;
}

bool ModuleScene::CleanUp()
{
	bool ret;
	App->textures->CleanUp();
	//App->audio->CleanUp();
	return true;
}