#include "ModuleSceneCinematic.h"

#include "SDL/include/SDL.h"
#pragma comment( lib, "SDL/libx86/SDL2.lib")
#pragma comment( lib, "SDL/libx86/SDL2main.lib")
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleFadeToBlack.h"
#include "ModuleSceneCharacter.h"

ModuleSceneCinematic::ModuleSceneCinematic(bool enabled) : Module(enabled)
{

	drawColorScreen.x = 0;
	drawColorScreen.y = 0;
	drawColorScreen.w = SCREEN_WIDTH * SCREEN_SIZE;
	drawColorScreen.h = SCREEN_HEIGHT * SCREEN_SIZE;

	backGround.x = 950;
	backGround.y = 1170;
	backGround.w = 256;
	backGround.h = 224;

	backGround2.x = 654;
	backGround2.y = 1170;
	backGround2.w = 256;
	backGround2.h = 224;

	frontBuilding.x = 1542;
	frontBuilding.y = 1410;
	frontBuilding.w = 256;
	frontBuilding.h = 224;

	splinterAnim.PushBack({ 64, 1298, 37, 62 });
	splinterAnim.PushBack({ 106, 1298, 37, 62 });
	splinterAnim.loop = false;
	splinterAnim.speed = 0.05f;

	leo.x = 331;
	leo.y = 54;
	leo.w = 30;
	leo.h = 50;

	donatello.x = 134;
	donatello.y = 54;
	donatello.w = 29;
	donatello.h = 50;

	raphael.x = 38;
	raphael.y = 54;
	raphael.w = 29;
	raphael.h = 50;

	michelangelo.x = 234;
	michelangelo.y = 53;
	michelangelo.w = 28;
	michelangelo.h = 51;

	fireComment.x = 396;
	fireComment.y = 1196;
	fireComment.w = 64;
	fireComment.h = 32;

	hangOnComment.x = 483;
	hangOnComment.y = 1196;
	hangOnComment.w = 64;
	hangOnComment.h = 32;

	fireAnim.PushBack({ 1430, 1169, 69, 153 });
	fireAnim.PushBack({ 1335, 1169, 69, 153 });
	fireAnim.PushBack({ 1242, 1170, 69, 153 });
	fireAnim.loop = true;
	fireAnim.speed = 0.1f;

	leoJumpAnim.PushBack({ 30, 148, 46, 60 });

	michelangeloJumpAnim.PushBack({ 127, 148, 46, 60 });

	donatelloJumpAnim.PushBack({ 220, 148, 46, 60 });

	raphaelJumpAnim.PushBack({ 321, 148, 46, 60 });

	//PATH JUMP Leo
	pathLeo.PushBack({ 0.7f, -4.0f }, 20, &leoJumpAnim);
	pathLeo.PushBack({ 0.7f, -2.0f }, 15, &leoJumpAnim);
	pathLeo.PushBack({ 0.7f, 0.0f }, 15, &leoJumpAnim);
	pathLeo.PushBack({ 0.7f, 2.0f }, 15, &leoJumpAnim);
	pathLeo.PushBack({ 0.7f, 4.0f }, 80, &leoJumpAnim);

	//PATH JUMP Dona
	pathDonatello.PushBack({ 0.7f, -4.0f }, 20, &donatelloJumpAnim);
	pathDonatello.PushBack({ 0.7f, -2.0f }, 15, &donatelloJumpAnim);
	pathDonatello.PushBack({ 0.7f, 0.0f }, 15, &donatelloJumpAnim);
	pathDonatello.PushBack({ 0.7f, 2.0f }, 15, &donatelloJumpAnim);
	pathDonatello.PushBack({ 0.7f, 4.0f }, 80, &donatelloJumpAnim);

	//PATH JUMP Rafa
	pathRaphael.PushBack({ 0.7f, -4.0f }, 20, &raphaelJumpAnim);
	pathRaphael.PushBack({ 0.7f, -2.0f }, 15, &raphaelJumpAnim);
	pathRaphael.PushBack({ 0.7f, 0.0f }, 15, &raphaelJumpAnim);
	pathRaphael.PushBack({ 0.7f, 2.0f }, 15, &raphaelJumpAnim);
	pathRaphael.PushBack({ 0.7f, 4.0f }, 80, &raphaelJumpAnim);

	//PATH JUMP Mikel
	pathMichelangelo.PushBack({ 0.7f, -4.0f }, 20, &michelangeloJumpAnim);
	pathMichelangelo.PushBack({ 0.7f, -2.0f }, 15, &michelangeloJumpAnim);
	pathMichelangelo.PushBack({ 0.7f, 0.0f }, 15, &michelangeloJumpAnim);
	pathMichelangelo.PushBack({ 0.7f, 2.0f }, 15, &michelangeloJumpAnim);
	pathMichelangelo.PushBack({ 0.7f, 4.0f }, 80, &michelangeloJumpAnim);

	leoFallAnim1.PushBack({ 0, 312 + (104 * 3), 95, 104 });
	leoFallAnim2.PushBack({ 0, 312 + (104 * 2), 95, 104 });
	leoFallAnim3.PushBack({ 0, 312 + (104 * 1), 95, 104 });
	leoFallAnim4.PushBack({ 0, 312, 95, 104 });

	michelangeloFallAnim1.PushBack({ 95, 312 + (104 * 3), 101, 104 });
	michelangeloFallAnim2.PushBack({ 95, 312 + (104 * 2), 101, 104 });
	michelangeloFallAnim3.PushBack({ 95, 312 + (104 * 1), 101, 104 });
	michelangeloFallAnim4.PushBack({ 95, 312, 101, 104 });

	donatelloFallAnim1.PushBack({ 196, 312 + (104 * 3), 101, 104 });
	donatelloFallAnim2.PushBack({ 196, 312 + (104 * 2), 101, 104 });
	donatelloFallAnim3.PushBack({ 196, 312 + (104 * 1), 101, 104 });
	donatelloFallAnim4.PushBack({ 196, 312, 101, 104 });

	raphaelFallAnim1.PushBack({ 297, 312 + (104 * 3), 101, 104 });
	raphaelFallAnim2.PushBack({ 297, 312 + (104 * 2), 101, 104 });
	raphaelFallAnim3.PushBack({ 297, 312 + (104 * 1), 101, 104 });
	raphaelFallAnim4.PushBack({ 297, 312, 101, 104 });

	//PATH FALL Leo
	pathLeo2.PushBack({ 0.0f, 2.0f }, 20, & leoFallAnim1);
	pathLeo2.PushBack({ 0.0f, 2.0f }, 20, & leoFallAnim2);
	pathLeo2.PushBack({ 0.0f, 2.0f }, 20, & leoFallAnim3);
	pathLeo2.PushBack({ 0.0f, 2.0f }, 20, & leoFallAnim4);


}

ModuleSceneCinematic::~ModuleSceneCinematic() {}

// Load assets
bool ModuleSceneCinematic::Start()
{

	counter = 0;

	App->audio->StopMusic();

	App->render->camera.x = 0;
	App->render->camera.y = 0;

	pathLeo.Reset();
	pathDonatello.Reset();
	pathRaphael.Reset();
	pathMichelangelo.Reset();

	pathLeo2.Reset();

	//Spawn ALL Paths
	//Jump Paths
	pathLeo.ResetRelativePosition();
	spawnPosLeo = iPoint((int)(SCREEN_WIDTH - 122), (int)(SCREEN_HEIGHT - leo.h - 3));

	pathDonatello.ResetRelativePosition();
	spawnPosDonatello = iPoint((int)(SCREEN_WIDTH - 122 - leo.w - michelangelo.w), (int)(SCREEN_HEIGHT - donatello.h - 13));

	pathRaphael.ResetRelativePosition();
	spawnPosRaphael = iPoint((int)(SCREEN_WIDTH - 118 - leo.w - michelangelo.w - donatello.w), (int)(SCREEN_HEIGHT - raphael.h - 32));

	pathMichelangelo.ResetRelativePosition();
	spawnPosMichelangelo = iPoint((int)(SCREEN_WIDTH - 120 - leo.w), (int)(SCREEN_HEIGHT - michelangelo.h - 13));

	//Fall Paths
	pathLeo2.ResetRelativePosition();
	spawnPosLeo2 = iPoint((int)((SCREEN_WIDTH / 2 - 40)), (int)(-10));

	cinematicBackground = App->textures->Load("Assets/Introduction/introduction.png");
	charactersTexture = App->textures->Load("Assets/Characters/Introduction.png");
	raphaelTexture = App->textures->Load("Assets/Characters/Raphael.png");
	donatelloTexture = App->textures->Load("Assets/Characters/Donatello.png");
	leoTexture = App->textures->Load("Assets/Characters/Leonardo.png");
	michelangeloTexture = App->textures->Load("Assets/Characters/Michelangelo.png");

	// ----------------------------------------------------------------- AUDIO
	Fire = App->audio->LoadFx("Assets/FX/02_aprilsfire.wav");
	HangOn = App->audio->LoadFx("Assets/FX/03_hang_on_april.wav"); 

	return true;
}

update_status ModuleSceneCinematic::Update()
{

	counter++;

	splinterCurrentAnim = &splinterAnim;

	if (counter > 100)
	{
		splinterAnim.Update();
	}

	fireCurrentAnim = &fireAnim;
	fireAnim.Update();

	//----------------------------------------------------------------------------------------Initialize Positions
	//Jump Pos
	positionLeo = spawnPosLeo + pathLeo.GetRelativePosition();
	leoCurrentAnim = pathLeo.GetCurrentAnimation();

	positionDonatello = spawnPosDonatello + pathDonatello.GetRelativePosition();
	donatelloCurrentAnim = pathDonatello.GetCurrentAnimation();

	positionRaphael = spawnPosRaphael + pathRaphael.GetRelativePosition();
	raphaelCurrentAnim = pathRaphael.GetCurrentAnimation();

	positionMichelangelo = spawnPosMichelangelo + pathMichelangelo.GetRelativePosition();
	michelangeloCurrentAnim = pathMichelangelo.GetCurrentAnimation();

	//Fall Pos
	positionLeo2 = spawnPosLeo2 + pathLeo2.GetRelativePosition();
	if (counter > 270)
	{
		leoCurrentAnim = pathLeo2.GetCurrentAnimation();
		pathLeo2.Update();
	}


	if (counter > 80)
	{
		pathLeo.Update();
	}

	if (counter > 100)
	{
		pathMichelangelo.Update();
	}

	if (counter > 120)
	{
		pathDonatello.Update();
	}

	if (counter > 140)
	{
		pathRaphael.Update();
	}
	// ScanCodes
	if ((App->input->keys[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN) || counter > 950)
	{
		this->Disable();
		CleanUp();
		App->scene->Enable();
	}

	else if (App->input->keys[SDL_SCANCODE_ESCAPE] == KEY_STATE::KEY_DOWN)
	{
		return update_status::UPDATE_STOP;
	}

	return update_status::UPDATE_CONTINUE;
}

// Update: draw background
update_status ModuleSceneCinematic::PostUpdate()
{
	if (counter < 10)
	{
		SDL_SetRenderDrawColor(App->render->renderer, 0, 0, 0, 255);
		SDL_RenderFillRect(App->render->renderer, &drawColorScreen);
	}

	App->render->Blit(cinematicBackground, ((SCREEN_WIDTH/2) - (backGround.w/2)), 0, &backGround, NULL); //BackGround

	if (fireCurrentAnim != nullptr)
	App->render->Blit(cinematicBackground, ((SCREEN_WIDTH / 2) - (backGround.w / 2)) + 187, 0, &(fireCurrentAnim->GetCurrentFrame()), NULL); //Fire

	//---------------------------------------------------------------------------------------------------Characters
	
	if (counter < 80)
	{
		//Leo
		App->render->Blit(charactersTexture, SCREEN_WIDTH - 122, SCREEN_HEIGHT - leo.h - 3, &leo, NULL);
	}

	if (counter < 100)
	{
		//Mikel
		App->render->Blit(charactersTexture, SCREEN_WIDTH - 120 - leo.w, SCREEN_HEIGHT - michelangelo.h - 13, &michelangelo, NULL);
	}

	if (counter < 120)
	{
		//Donatello
		App->render->Blit(charactersTexture, SCREEN_WIDTH - 122 - leo.w - michelangelo.w, SCREEN_HEIGHT - donatello.h - 13, &donatello, NULL);
	}

	if (counter < 140)
	{
		//Rafa
		App->render->Blit(charactersTexture, SCREEN_WIDTH - 118 - leo.w - michelangelo.w - donatello.w, SCREEN_HEIGHT - raphael.h - 32, &raphael, NULL);
	}


	if (counter == 10)
	{
		App->audio->PlayFx(Fire);
	}

	if (counter == 80)
	{
		App->audio->PlayMusic("Assets/Audio/01_opening_demo.ogg", 0.0f, 0);
	}

	if (counter > 30 && counter < 80)
	{
		App->render->Blit(cinematicBackground, ((SCREEN_WIDTH / 2) - (backGround.w / 2)) + 123, 116, &fireComment, NULL); //FireComment
	}

	if (counter > 80)
	{
		//Leo
		if (leoCurrentAnim != nullptr)
			App->render->Blit(charactersTexture, positionLeo.x, positionLeo.y, &(leoCurrentAnim->GetCurrentFrame()), NULL);
	}

	if (counter > 100)
	{
		//Mikel
		if (michelangeloCurrentAnim != nullptr)
			App->render->Blit(charactersTexture, positionMichelangelo.x, positionMichelangelo.y, &(michelangeloCurrentAnim->GetCurrentFrame()), NULL);
	}

	if (counter > 120)
	{
		//Donatello
		if (donatelloCurrentAnim != nullptr)
			App->render->Blit(charactersTexture, positionDonatello.x, positionDonatello.y, &(donatelloCurrentAnim->GetCurrentFrame()), NULL);
	}

	if (counter > 140)
	{
		//Rafa
		if (raphaelCurrentAnim != nullptr)
			App->render->Blit(charactersTexture, positionRaphael.x, positionRaphael.y, &(raphaelCurrentAnim->GetCurrentFrame()), NULL);
	}

	if (counter > 100 && counter < 160)
	{
		App->render->Blit(cinematicBackground, ((SCREEN_WIDTH / 2) - (backGround.w / 2)) + 28, 120, &hangOnComment, NULL); //FireComment
	}

	if (counter > 160)
	{
		//Roof Go On Front
		App->render->Blit(cinematicBackground, ((SCREEN_WIDTH / 2) - (backGround.w / 2)), 0, &frontBuilding, NULL);
	}

	//Splinter
	if (splinterCurrentAnim != nullptr)
		App->render->Blit(cinematicBackground, 56, SCREEN_HEIGHT - 70, &(splinterCurrentAnim->GetCurrentFrame()), NULL);


	if (counter == 20)
	{
		App->audio->PlayFx(HangOn);
	}

	if (counter > 240 && counter < 260)
	{
		SDL_SetRenderDrawColor(App->render->renderer, 0, 0, 0, 255);
		SDL_RenderFillRect(App->render->renderer, &drawColorScreen);
	}

	if (counter > 250)
	{
		//SecondBackground
		App->render->Blit(cinematicBackground, ((SCREEN_WIDTH / 2) - (backGround2.w / 2)), 0, &backGround2, NULL); //BackGround
	}

	if (counter > 270)
	{
		//Leo
		if (leoCurrentAnim != nullptr)
			App->render->Blit(charactersTexture, positionLeo2.x, positionLeo2.y, &(leoCurrentAnim->GetCurrentFrame()), NULL);
	}
	


	return update_status::UPDATE_CONTINUE;
}

bool ModuleSceneCinematic::CleanUp()
{
	bool ret;
	App->textures->CleanUp();
	return true;
}