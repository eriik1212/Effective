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

#include <stdio.h>


ModuleHUD::ModuleHUD(bool enabled) : Module(enabled)
{
	// HUD Player1
	HUDP1.PushBack({ 5, 0, 72, 32 });

	// HUD Player2,3,4
	HUDP234.PushBack({ 77, 107, 213, 32 });

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

	// INSERT COIN Anim for P2, P3, P4
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
	lifeIncrease = App->audio->LoadFx("Assets/FX/01_cowabunga.wav");

	// ----------------------------------------------------------------- FONTS
	char lookupTable[] = { "0123456789 " };
	scoreFont = App->fonts->Load("Assets/UI & HUD/fonts.png", lookupTable, 1);
	lifeFont = App->fonts->Load("Assets/UI & HUD/num_lifes_font.png", lookupTable, 1);

	return ret;
}

update_status ModuleHUD::Update()
{
	insertCoinP2.Update();
	insertCoinP3.Update();
	insertCoinP4.Update();

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
	// -------------------------------------------------------------------------------------------- HUD

	App->render->Blit(HUDTexture, 8, 0, &(HUDP1.GetCurrentFrame()), 0); // HUD Square Player1
	App->render->Blit(HUDTexture, 80, 0, &(HUDP234.GetCurrentFrame()), 0); // HUD Square Player2,3,4

	App->render->Blit(HUDTexture, 80, 16, &(insertCoinP2.GetCurrentFrame()), 0); // INSERT COIN Player2
	App->render->Blit(HUDTexture, 151, 16, &(insertCoinP3.GetCurrentFrame()), 0); // INSERT COIN Player3
	App->render->Blit(HUDTexture, 222, 16, &(insertCoinP4.GetCurrentFrame()), 0); // INSERT COIN Player4

	App->render->Blit(HUDTexture, 41, 16, &(lifeP1.GetCurrentFrame()), 0); // Full Life Indicator

	// Draw UI (score) --------------------------------------
	sprintf_s(scoreTextP1, 10, "%3d", scoreP1); //P1
	sprintf_s(scoreTextP234, 10, "%3d", scoreP234); //P234

	App->fonts->BlitText(45, 8, scoreFont, scoreTextP1); // P1
	App->fonts->BlitText(116, 8, scoreFont, scoreTextP234); // P2
	App->fonts->BlitText(187, 8, scoreFont, scoreTextP234); // P3
	App->fonts->BlitText(258, 8, scoreFont, scoreTextP234); // P4


	// Draw UI (NumLifes) --------------------------------------
	sprintf_s(lifeText, 10, "%3d", lifes);

	App->fonts->BlitText(17, 16, lifeFont, lifeText);

	return update_status::UPDATE_CONTINUE;
}

void  ModuleHUD::Reset()
{
	lifes = 0;
	scoreP1 = 0;
}

bool ModuleHUD::CleanUp()
{
	bool ret;
	App->textures->CleanUp();
	//App->audio->CleanUp();
	return true;
}
