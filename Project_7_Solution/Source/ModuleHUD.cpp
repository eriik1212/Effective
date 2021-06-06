#include "ModuleHUD.h"

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
#include "ModuleFonts.h"
#include "ModuleSceneCharacter.h"
#include "ModuleSceneCinematic.h"

#include <stdio.h>


ModuleHUD::ModuleHUD(bool enabled) : Module(enabled)
{
	konami.x = 117;
	konami.y = 220;
	konami.w = 78;
	konami.h = 19;

	konami1989.x = 107;
	konami1989.y = 314;
	konami1989.w = 104;
	konami1989.h = 8;

	bigTurtle.x = 16;
	bigTurtle.y = 824;
	bigTurtle.w = 64;
	bigTurtle.h = 128;

	// HUD Player1
	HUDP1.PushBack({ 5, 0, 72, 32 });

	HUDP1InsertCoins.PushBack({ 5, 107, 72, 32 });

	// HUD Player2,3,4
	HUDP234.PushBack({ 77, 107, 213, 32 });

	//SmallTurtleAnim
	smallTurtle.PushBack({ 5, 37, 72, 33 });
	smallTurtle.PushBack({ 5, 73, 72, 33 });
	smallTurtle.speed = 0.05f;
	smallTurtle.loop = true;

	//Press Start Animation
	pressStart.PushBack({ 6, 144, 70, 11 });
	pressStart.PushBack({ 6, 155, 70, 11 });
	pressStart.speed = 0.05f;
	pressStart.loop = true;

	// Life's Animation
	lifeP1.PushBack({ 6, 233, 31, 11 });
	lifeP1.PushBack({ 40, 233, 31, 11 });
	lifeP1.PushBack({ 74, 233, 31, 11 });
	lifeP1.PushBack({ 108, 233, 31, 11 });
	lifeP1.PushBack({ 143, 233, 31, 11 });
	lifeP1.PushBack({ 177, 233, 31, 11 });
	lifeP1.PushBack({ 211, 233, 31, 11 });
	lifeP1.PushBack({ 246, 233, 31, 11 });
	lifeP1.PushBack({ 280, 233, 31, 11 });
	lifeP1.PushBack({ 314, 233, 31, 11 });
	lifeP1.PushBack({ 360, 233, 31, 11 });
	lifeP1.loop = false;

	// INSERT COIN Anim for P1, P2, P3, P4
	//P1
	insertCoinP1.PushBack({ 315, 187, 71, 13 });
	insertCoinP1.PushBack({ 6, 167, 71, 13 });
	insertCoinP1.PushBack({ 83, 167, 71, 13 });
	insertCoinP1.PushBack({ 160, 167, 71, 13 });
	insertCoinP1.PushBack({ 238, 167, 71, 13 });
	insertCoinP1.PushBack({ 315, 167, 71, 13 });
	insertCoinP1.PushBack({ 6, 187, 71, 13 });
	insertCoinP1.PushBack({ 83, 187, 71, 13 });
	insertCoinP1.PushBack({ 160, 187, 71, 13 });
	insertCoinP1.PushBack({ 238, 187, 71, 13 });
	insertCoinP1.speed = 0.15f;
	insertCoinP1.loop = true;

	// P2
	insertCoinP2.PushBack({ 6, 167, 71, 13 });
	insertCoinP2.PushBack({ 83, 167, 71, 13 });
	insertCoinP2.PushBack({ 160, 167, 71, 13 });
	insertCoinP2.PushBack({ 238, 167, 71, 13 });
	insertCoinP2.PushBack({ 315, 167, 71, 13 });
	insertCoinP2.PushBack({ 6, 187, 71, 13 });
	insertCoinP2.PushBack({ 83, 187, 71, 13 });
	insertCoinP2.PushBack({ 160, 187, 71, 13 });
	insertCoinP2.PushBack({ 238, 187, 71, 13 });
	insertCoinP2.PushBack({ 315, 187, 71, 13 });
	insertCoinP2.speed = 0.15f;
	insertCoinP2.loop = true;

	// P3
	insertCoinP3.PushBack({ 83, 167, 71, 13 });
	insertCoinP3.PushBack({ 160, 167, 71, 13 });
	insertCoinP3.PushBack({ 238, 167, 71, 13 });
	insertCoinP3.PushBack({ 315, 167, 71, 13 });
	insertCoinP3.PushBack({ 6, 187, 71, 13 });
	insertCoinP3.PushBack({ 83, 187, 71, 13 });
	insertCoinP3.PushBack({ 160, 187, 71, 13 });
	insertCoinP3.PushBack({ 238, 187, 71, 13 });
	insertCoinP3.PushBack({ 315, 187, 71, 13 });
	insertCoinP3.PushBack({ 6, 167, 71, 13 });
	insertCoinP3.speed = 0.15f;
	insertCoinP3.loop = true;

	// P4
	insertCoinP4.PushBack({ 160, 167, 71, 13 });
	insertCoinP4.PushBack({ 238, 167, 71, 13 });
	insertCoinP4.PushBack({ 315, 167, 71, 13 });
	insertCoinP4.PushBack({ 6, 187, 71, 13 });
	insertCoinP4.PushBack({ 83, 187, 71, 13 });
	insertCoinP4.PushBack({ 160, 187, 71, 13 });
	insertCoinP4.PushBack({ 238, 187, 71, 13 });
	insertCoinP4.PushBack({ 315, 187, 71, 13 });
	insertCoinP4.PushBack({ 6, 167, 71, 13 });
	insertCoinP4.PushBack({ 83, 167, 71, 13 });
	insertCoinP4.speed = 0.15f;
	insertCoinP4.loop = true;
}

ModuleHUD::~ModuleHUD()
{

}

// Load assets
bool ModuleHUD::Start()
{
	bool ret = true;

	HUDTexture = App->textures->Load("Assets/UI & HUD/HUD.png");
	introTexture = App->textures->Load("Assets/Introduction/introduction.png");
	lifeIncrease = App->audio->LoadFx("Assets/FX/01_cowabunga.wav");

	// ----------------------------------------------------------------- FONTS
	char lookupTableNumb[] = { "0123456789 " };
	scoreFont = App->fonts->Load("Assets/Fonts/fonts.png", lookupTableNumb, 1);
	lifeFont = App->fonts->Load("Assets/UI & HUD/num_lifes_font.png", lookupTableNumb, 1);

	return ret;
}

update_status ModuleHUD::Update()
{
	insertCoinP1.Update();
	insertCoinP2.Update();
	insertCoinP3.Update();
	insertCoinP4.Update();

	smallTurtle.Update();
	pressStart.Update();

	// ------------------------------- Life's Increment
	if (App->input->keys[SDL_SCANCODE_LSHIFT] == KEY_STATE::KEY_DOWN)
	{
		if (lifes < 998)
		{
			lifes += 2;
			App->audio->PlayFx(lifeIncrease);
		}

	}

	return update_status::UPDATE_CONTINUE;
}

// Update: draw background
update_status ModuleHUD::PostUpdate()
{
	// Draw UI (score) --------------------------------------
	sprintf_s(scoreTextP1, 10, "%3d", scoreP1); //P1
	sprintf_s(scoreTextP234, 10, "%3d", scoreP234); //P234

	// Draw UI (NumLifes) --------------------------------------
	sprintf_s(lifeText, 10, "%3d", lifes);


	App->render->Blit(HUDTexture, 80, 0, &(HUDP234.GetCurrentFrame()), 0); // HUD Square Player2,3,4

	App->render->Blit(HUDTexture, 80, 16, &(insertCoinP2.GetCurrentFrame()), 0); // INSERT COIN Player2
	App->render->Blit(HUDTexture, 151, 16, &(insertCoinP3.GetCurrentFrame()), 0); // INSERT COIN Player3
	App->render->Blit(HUDTexture, 222, 16, &(insertCoinP4.GetCurrentFrame()), 0); // INSERT COIN Player4


	App->fonts->BlitText(45, 8, scoreFont, scoreTextP1); // P1
	App->fonts->BlitText(116, 8, scoreFont, scoreTextP234); // P2
	App->fonts->BlitText(187, 8, scoreFont, scoreTextP234); // P3
	App->fonts->BlitText(258, 8, scoreFont, scoreTextP234); // P4

	

	// -------------------------------------------------------------------------------------------- HUD
	if (lifes > 0 && App->sceneCharacter->Enabled())
	{
		App->render->Blit(HUDTexture, 8, 0, &(smallTurtle.GetCurrentFrame()), 0); // HUD Square Player1
		App->fonts->BlitText(17, 16, lifeFont, lifeText);

		App->render->Blit(HUDTexture, 9, 34, &(pressStart.GetCurrentFrame()), 0); // HUD Square Player1

		App->render->Blit(introTexture, 12, 56, &bigTurtle, 0); // Big Blue Turtle

		App->render->Blit(introTexture, ((SCREEN_WIDTH/2) - (konami.w/2) - 4), (SCREEN_HEIGHT - konami1989.h - konami.h - 4), &konami, 0); // KONAMI

		App->render->Blit(introTexture, (SCREEN_WIDTH / 2) - (konami1989.w / 2), (SCREEN_HEIGHT - konami1989.h), &konami1989, 0); // KONAMI1989
	}
	else if (lifes == 0 && App->sceneCharacter->Enabled())
	{
		App->render->Blit(HUDTexture, 8, 0, &(HUDP1InsertCoins.GetCurrentFrame()), 0); // HUD Square Player1
		App->render->Blit(HUDTexture, 9, 16, &(insertCoinP1.GetCurrentFrame()), 0); // HUD Square Player1

		App->render->Blit(introTexture, ((SCREEN_WIDTH / 2) - (konami.w / 2) - 4), (SCREEN_HEIGHT - konami1989.h - konami.h - 4), &konami, 0); // KONAMI

		App->render->Blit(introTexture, (SCREEN_WIDTH / 2) - (konami1989.w / 2), (SCREEN_HEIGHT - konami1989.h), &konami1989, 0); // KONAMI1989
	}
	else if (App->scene->Enabled() || App->level2->Enabled() || App->sceneCinematic->Enabled())
	{
		App->render->Blit(HUDTexture, 8, 0, &(HUDP1.GetCurrentFrame()), 0); // HUD Square Player1
		App->render->Blit(HUDTexture, 41, 16, &(lifeP1.GetCurrentFrame()), 0); // Full Life Indicator
		App->fonts->BlitText(17, 16, lifeFont, lifeText);
	}



	return update_status::UPDATE_CONTINUE;
}

void  ModuleHUD::Reset()
{
	lifes = 0;
	scoreP1 = 0;
	lifeP1.Reset();
}

bool ModuleHUD::CleanUp()
{
	bool ret;

	App->fonts->UnLoad(scoreFont);
	App->fonts->UnLoad(lifeFont);

	return true;
}
