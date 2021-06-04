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
#include "ModuleFonts.h"
#include <stdio.h>

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

	backGround3.x = 1542;
	backGround3.y = 1169;
	backGround3.w = 320;
	backGround3.h = 224;

	finalDoor.x = 1798;
	finalDoor.y = 1169;
	finalDoor.w = 64;
	finalDoor.h = 224;

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
	fireAnim.speed = 0.15f;

	secondFireAnim.PushBack({ 16, 1490, 158, 224 });
	secondFireAnim.PushBack({ 213, 1490, 158, 224 });
	secondFireAnim.PushBack({ 410, 1490, 158, 224 });
	secondFireAnim.PushBack({ 605, 1490, 158, 224 });
	secondFireAnim.PushBack({ 793, 1490, 158, 224 });
	secondFireAnim.PushBack({ 980, 1490, 158, 224 });
	secondFireAnim.PushBack({ 1161, 1490, 158, 224 });
	secondFireAnim.loop = true;
	secondFireAnim.speed = 0.15f;

	//Characters Jump Anim
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

	//Characters Fall Anim
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
	pathLeo2.PushBack({ 0.0f, 3.0f }, 20, & leoFallAnim3);
	pathLeo2.PushBack({ 0.0f, 3.0f }, 20, & leoFallAnim4);

	//PATH FALL Mikel
	pathMichelangelo2.PushBack({ 0.0f, 2.0f }, 20, & michelangeloFallAnim1);
	pathMichelangelo2.PushBack({ -0.3f, 2.0f }, 20, & michelangeloFallAnim2);
	pathMichelangelo2.PushBack({ -0.3f, 3.0f }, 20, & michelangeloFallAnim3);
	pathMichelangelo2.PushBack({ -0.3f, 3.0f }, 20, & michelangeloFallAnim4);

	//PATH FALL Dona
	pathDonatello2.PushBack({ 0.0f, 2.0f }, 20, & donatelloFallAnim1);
	pathDonatello2.PushBack({ -0.5f, 2.0f }, 20, & donatelloFallAnim2);
	pathDonatello2.PushBack({ -0.5f, 3.0f }, 20, & donatelloFallAnim3);
	pathDonatello2.PushBack({ -0.5f, 3.0f }, 20, & donatelloFallAnim4);

	//PATH FALL Rafa
	pathRaphael2.PushBack({ 0.0f, 2.0f }, 20, & raphaelFallAnim1);
	pathRaphael2.PushBack({ 0.5f, 2.0f }, 20, & raphaelFallAnim2);
	pathRaphael2.PushBack({ 0.5f, 3.0f }, 20, & raphaelFallAnim3);
	pathRaphael2.PushBack({ 0.5f, 3.0f }, 20, & raphaelFallAnim4);

	//Characters Final Anim
	leoFinalAnim1.PushBack({ 837, 588, 94, 84 });
	leoFinalAnim2.PushBack({ 0, 924, 94, 84 });
	leoFinalAnim3.PushBack({ 0, 924, 94, 84 });
	leoFinalAnim3.PushBack({ 94, 924, 94, 84 });
	leoFinalAnim3.PushBack({ 188, 924, 94, 84 });
	leoFinalAnim3.PushBack({ 282, 924, 94, 84 });
	leoFinalAnim3.PushBack({ 376, 924, 94, 84 });
	leoFinalAnim3.PushBack({ 470, 924, 94, 84 });
	leoFinalAnim3.PushBack({ 564, 924, 94, 84 });
	leoFinalAnim3.PushBack({ 658, 924, 94, 84 });
	leoFinalAnim3.loop = true;
	leoFinalAnim3.speed = 0.25f;

	michelangeloFinalAnim1.PushBack({ 731, 545, 94, 84 });
	michelangeloFinalAnim2.PushBack({ 898, 1383, 94, 94});
	michelangeloFinalAnim2.PushBack({ 992, 1383, 94, 94 });
	michelangeloFinalAnim2.PushBack({ 1086, 1383, 94, 94 });
	michelangeloFinalAnim2.speed = 0.03f;
	michelangeloFinalAnim3.PushBack({ 0, 890, 80, 84 });
	michelangeloFinalAnim3.PushBack({ 10 + (80 * 1), 890, 80, 84 });
	michelangeloFinalAnim3.PushBack({ 10 + (80 * 2), 890, 80, 84 });
	michelangeloFinalAnim3.PushBack({ 10 + (80 * 3), 890, 80, 84 });
	michelangeloFinalAnim3.PushBack({ 10 + (80 * 4), 890, 80, 84 });
	michelangeloFinalAnim3.PushBack({ 10 + (80 * 5), 890, 80, 84 });
	michelangeloFinalAnim3.PushBack({ 10 + (80 * 6), 890, 80, 84 });
	michelangeloFinalAnim3.loop = true;
	michelangeloFinalAnim3.speed = 0.25f;

	donatelloFinalAnim1.PushBack({ 932, 648, 94, 84 });
	donatelloFinalAnim2.PushBack({ 0, 1012, 103, 84 });
	donatelloFinalAnim3.PushBack({ 0, 1012, 103, 84 });
	donatelloFinalAnim3.PushBack({ 0 + (103 * 1), 1012, 103, 84 });
	donatelloFinalAnim3.PushBack({ 0 + (103 * 2), 1012, 103, 84 });
	donatelloFinalAnim3.PushBack({ 0 + (103 * 3), 1012, 103, 84 });
	donatelloFinalAnim3.PushBack({ 0 + (103 * 4), 1012, 103, 84 });
	donatelloFinalAnim3.PushBack({ 0 + (103 * 5), 1012, 103, 84 });
	donatelloFinalAnim3.PushBack({ 0 + (103 * 6), 1012, 103, 84 });
	donatelloFinalAnim3.loop = true;
	donatelloFinalAnim3.speed = 0.25f;

	raphaelFinalAnim1.PushBack({ 940, 588, 94, 84 });
	raphaelFinalAnim2.PushBack({ 0, 924, 94, 84 });
	raphaelFinalAnim3.PushBack({ 0, 924, 94, 84 });
	raphaelFinalAnim3.PushBack({ 0 + (94 * 1), 924, 94, 84 });
	raphaelFinalAnim3.PushBack({ 0 + (94 * 2), 924, 94, 84 });
	raphaelFinalAnim3.PushBack({ 0 + (94 * 3), 924, 94, 84 });
	raphaelFinalAnim3.PushBack({ 0 + (94 * 4), 924, 94, 84 });
	raphaelFinalAnim3.PushBack({ 0 + (94 * 5), 924, 94, 84 });
	raphaelFinalAnim3.PushBack({ 0 + (94 * 6), 924, 94, 84 });
	raphaelFinalAnim3.loop = true;
	raphaelFinalAnim3.speed = 0.25f;

	//FINAL PATH Leo
	pathLeo3.PushBack({ 2.0f, 6.0f }, 30, & leoFinalAnim1);
	pathLeo3.PushBack({ 0.0f, 0.0f }, 30, & leoFinalAnim2);
	pathLeo3.PushBack({ 2.0f, 0.0f }, 400, & leoFinalAnim3);

	//FINAL PATH Mikel
	pathMichelangelo3.PushBack({ 2.0f, 6.0f }, 30, & michelangeloFinalAnim1);
	pathMichelangelo3.PushBack({ 0.0f, 0.0f }, 105, & michelangeloFinalAnim2);
	pathMichelangelo3.PushBack({ 2.0f, 0.0f }, 400, & michelangeloFinalAnim3);

	//FINAL PATH Dona
	pathDonatello3.PushBack({ 2.0f, 6.0f }, 30, & donatelloFinalAnim1);
	pathDonatello3.PushBack({ 0.0f, 0.0f }, 30, & donatelloFinalAnim2);
	pathDonatello3.PushBack({ 2.0f, 0.0f }, 400, & donatelloFinalAnim3);

	//FINAL PATH Rafa
	pathRaphael3.PushBack({ 2.0f, 6.0f }, 30, & raphaelFinalAnim1);
	pathRaphael3.PushBack({ 0.0f, 0.0f }, 30, & raphaelFinalAnim2);
	pathRaphael3.PushBack({ 2.0f, 0.0f }, 400, & raphaelFinalAnim3);
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
	pathDonatello2.Reset();
	pathRaphael2.Reset();
	pathMichelangelo2.Reset();

	pathLeo3.Reset();
	pathDonatello3.Reset();
	pathRaphael3.Reset();
	pathMichelangelo3.Reset();

	michelangeloFinalAnim2.Reset();

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

	pathDonatello2.ResetRelativePosition();
	spawnPosDonatello2 = iPoint((int)((SCREEN_WIDTH / 2 - 50)), (int)(-30));

	pathRaphael2.ResetRelativePosition();
	spawnPosRaphael2 = iPoint((int)((SCREEN_WIDTH / 2 - 50)), (int)(-30));

	pathMichelangelo2.ResetRelativePosition();
	spawnPosMichelangelo2 = iPoint((int)((SCREEN_WIDTH / 2 - 50)), (int)(-30));

	//Final Paths
	pathLeo3.ResetRelativePosition();
	spawnPosLeo3 = iPoint((int)(50), (int)(-100));

	pathDonatello3.ResetRelativePosition();
	spawnPosDonatello3 = iPoint((int)(50), (int)(-100));

	pathRaphael3.ResetRelativePosition();
	spawnPosRaphael3 = iPoint((int)(50), (int)(-100));

	pathMichelangelo3.ResetRelativePosition();
	spawnPosMichelangelo3 = iPoint((int)(50), (int)(-100));

	cinematicBackground = App->textures->Load("Assets/Introduction/introduction.png");
	charactersTexture = App->textures->Load("Assets/Characters/Introduction.png");
	raphaelTexture = App->textures->Load("Assets/Characters/Raphael.png");
	donatelloTexture = App->textures->Load("Assets/Characters/Donatello.png");
	leoTexture = App->textures->Load("Assets/Characters/Leonardo.png");
	michelangeloTexture = App->textures->Load("Assets/Characters/Michelangelo.png");

	// ----------------------------------------------------------------- AUDIO
	Fire = App->audio->LoadFx("Assets/FX/02_aprilsfire.wav");
	HangOn = App->audio->LoadFx("Assets/FX/03_hang_on_april.wav"); 

	//------------------------------------------------------------------ TEXT
	char lookupTable[] = { "! @abcdefghijklmnop rstuvwxyz." };
	tmntFont = App->fonts->Load("Assets/Fonts/tmnt_font.png", lookupTable, 2);

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

	//Walk Update
	leoFinalAnim3.Update();
	donatelloFinalAnim3.Update();
	raphaelFinalAnim3.Update();
	michelangeloFinalAnim3.Update();

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


	//Fall Pos
	positionLeo2 = spawnPosLeo2 + pathLeo2.GetRelativePosition();
	if (counter > 270)
	{
		leoCurrentAnim = pathLeo2.GetCurrentAnimation();
		pathLeo2.Update();
	}

	positionMichelangelo2 = spawnPosMichelangelo2 + pathMichelangelo2.GetRelativePosition();
	if (counter > 300)
	{
		michelangeloCurrentAnim = pathMichelangelo2.GetCurrentAnimation();
		pathMichelangelo2.Update();
	}

	positionDonatello2 = spawnPosDonatello2 + pathDonatello2.GetRelativePosition();
	if (counter > 330)
	{
		donatelloCurrentAnim = pathDonatello2.GetCurrentAnimation();
		pathDonatello2.Update();
	}

	positionRaphael2 = spawnPosRaphael2 + pathRaphael2.GetRelativePosition();
	if (counter > 360)
	{
		raphaelCurrentAnim = pathRaphael2.GetCurrentAnimation();
		pathRaphael2.Update();
	}

	if (counter > 450)
	{
		fireCurrentAnim = &secondFireAnim;
		secondFireAnim.Update();
	}

	//Final Pos
	positionLeo3 = spawnPosLeo3 + pathLeo3.GetRelativePosition();
	if (counter > 460)
	{
		leoCurrentAnim = pathLeo3.GetCurrentAnimation();
		pathLeo3.Update();
	}

	positionMichelangelo3 = spawnPosMichelangelo3 + pathMichelangelo3.GetRelativePosition();
	if (counter > 490)
	{
		michelangeloCurrentAnim = pathMichelangelo3.GetCurrentAnimation();
		pathMichelangelo3.Update();
	}
	if (counter > 530)
	{
		michelangeloFinalAnim2.Update();
	}

	positionDonatello3 = spawnPosDonatello3 + pathDonatello3.GetRelativePosition();
	if (counter > 520)
	{
		donatelloCurrentAnim = pathDonatello3.GetCurrentAnimation();
		pathDonatello3.Update();
	}

	positionRaphael3 = spawnPosRaphael3 + pathRaphael3.GetRelativePosition();
	if (counter > 550)
	{
		raphaelCurrentAnim = pathRaphael3.GetCurrentAnimation();
		pathRaphael3.Update();
	}

	// ScanCodes
	if ((App->input->keys[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN) || counter > 900)
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
	//---------------------------------------------------------------------------------------------------------------BLACK SCREEN
	if (counter < 10)
	{
		SDL_SetRenderDrawColor(App->render->renderer, 0, 0, 0, 255);
		SDL_RenderFillRect(App->render->renderer, &drawColorScreen);
	}

	//----------------------------------------------------------------------------------------------------------------------FIRST BACKGROUND
	//BackGround
	App->render->Blit(cinematicBackground, ((SCREEN_WIDTH/2) - (backGround.w/2)), 0, &backGround, NULL); 

	//Fire
	if (fireCurrentAnim != nullptr)
	App->render->Blit(cinematicBackground, ((SCREEN_WIDTH / 2) - (backGround.w / 2)) + 187, 0, &(fireCurrentAnim->GetCurrentFrame()), NULL); 

	//---------------------------------------------------------------------------Characters
	
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

	//---------------------------------------------------------------------------------------------------------------BLACK SCREEN
	if (counter > 240 && counter < 260)
	{
		SDL_SetRenderDrawColor(App->render->renderer, 0, 0, 0, 255);
		SDL_RenderFillRect(App->render->renderer, &drawColorScreen);
	}

	//---------------------------------------------------------------------------------------------------------------SECOND BACKGROUND
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

	if (counter > 300)
	{
		//Michelangelo
		if (michelangeloCurrentAnim != nullptr)
			App->render->Blit(charactersTexture, positionMichelangelo2.x, positionMichelangelo2.y, &(michelangeloCurrentAnim->GetCurrentFrame()), NULL);
	}

	if (counter > 330)
	{
		//Donatello
		if (donatelloCurrentAnim != nullptr)
			App->render->Blit(charactersTexture, positionDonatello2.x, positionDonatello2.y, &(donatelloCurrentAnim->GetCurrentFrame()), NULL);
	}

	if (counter > 360)
	{
		//Raphael
		if (raphaelCurrentAnim != nullptr)
			App->render->Blit(charactersTexture, positionRaphael2.x, positionRaphael2.y, &(raphaelCurrentAnim->GetCurrentFrame()), NULL);
	}
	
	//---------------------------------------------------------------------------------------------------------------BLACK SCREEN
	if (counter > 440 && counter < 460)
	{
		SDL_SetRenderDrawColor(App->render->renderer, 0, 0, 0, 255);
		SDL_RenderFillRect(App->render->renderer, &drawColorScreen);
	}

	//---------------------------------------------------------------------------------------------------------------THIRD BACKGROUND
	if (counter > 450)
	{
		//SecondBackground
		App->render->Blit(cinematicBackground, -2, 0, &backGround3, NULL); //SecondBackGround

		//Fire
		if (fireCurrentAnim != nullptr)
			App->render->Blit(cinematicBackground, 0, 0, &(fireCurrentAnim->GetCurrentFrame()), NULL);
	}

	if (counter > 550)
	{
		//Rafa
		if (raphaelCurrentAnim != nullptr)
			App->render->Blit(raphaelTexture, positionRaphael3.x, positionRaphael3.y, &(raphaelCurrentAnim->GetCurrentFrame()), NULL);
	}

	if (counter > 520)
	{
		//Donatello
		if (donatelloCurrentAnim != nullptr)
			App->render->Blit(donatelloTexture, positionDonatello3.x, positionDonatello3.y, &(donatelloCurrentAnim->GetCurrentFrame()), NULL);
	}

	if (counter > 490)
	{
		//Mikel
		if (michelangeloCurrentAnim != nullptr)
			App->render->Blit(michelangeloTexture, positionMichelangelo3.x, positionMichelangelo3.y, &(michelangeloCurrentAnim->GetCurrentFrame()), NULL);
	}

	if (counter > 460)
	{
		//Leo
		if (leoCurrentAnim != nullptr)
			App->render->Blit(leoTexture, positionLeo3.x, positionLeo3.y, &(leoCurrentAnim->GetCurrentFrame()), NULL);
	}

	if (counter > 450)
	{
		//Final Door
		App->render->Blit(cinematicBackground, 254, 0, &finalDoor, NULL); //SecondBackGround
	}

	//---------------------------------------------------------------------------------------------------------------BLACK SCREEN
	if (counter > 700)
	{
		SDL_SetRenderDrawColor(App->render->renderer, 0, 0, 0, 255);
		SDL_RenderFillRect(App->render->renderer, &drawColorScreen);

		// Blit the text
		if (counter > 705)
		{
			App->fonts->BlitText(SCREEN_WIDTH/2, 0, tmntFont, "s");
		}
		if (counter > 710)
		{
			App->fonts->BlitText(0, 0, tmntFont, "e");
		}
		if (counter > 715)
		{
			App->fonts->BlitText(0, 0, tmntFont, "n");
		}
		if (counter > 720)
		{
			App->fonts->BlitText(0, 0, tmntFont, "e");
		}
		if (counter > 725)
		{
			App->fonts->BlitText(0, 0, tmntFont, " ");
		}
		if (counter > 730)
		{
			App->fonts->BlitText(0, 0, tmntFont, "1");
		}
		if (counter > 735)
		{
			App->fonts->BlitText(0, 0, tmntFont, "f");
		}
		if (counter > 740)
		{
			App->fonts->BlitText(0, 0, tmntFont, "i");
		}
		if (counter > 745)
		{
			App->fonts->BlitText(0, 0, tmntFont, "r");
		}
		if (counter > 750)
		{
			App->fonts->BlitText(0, 0, tmntFont, "e");
		}
		if (counter > 755)
		{
			App->fonts->BlitText(0, 0, tmntFont, "!");
		}
		if (counter > 760)
		{
			App->fonts->BlitText(0, 0, tmntFont, " ");
		}
		if (counter > 765)
		{
			App->fonts->BlitText(0, 0, tmntFont, "w");
		}
		if (counter > 770)
		{
			App->fonts->BlitText(0, 0, tmntFont, "e");
		}
		if (counter > 775)
		{
			App->fonts->BlitText(0, 0, tmntFont, " ");
		}
		if (counter > 780)
		{
			App->fonts->BlitText(0, 0, tmntFont, "g");
		}
		if (counter > 785)
		{
			App->fonts->BlitText(0, 0, tmntFont, "o");
		}
		if (counter > 790)
		{
			App->fonts->BlitText(0, 0, tmntFont, "t");
		}
		if (counter > 795)
		{
			App->fonts->BlitText(0, 0, tmntFont, "t");
		}
		if (counter > 800)
		{
			App->fonts->BlitText(0, 0, tmntFont, "a");
		}
		if (counter > 805)
		{
			App->fonts->BlitText(0, 0, tmntFont, " ");
		}
		if (counter > 810)
		{
			App->fonts->BlitText(0, 0, tmntFont, "g");
		}
		if (counter > 815)
		{
			App->fonts->BlitText(0, 0, tmntFont, "e");
		}
		if (counter > 820)
		{
			App->fonts->BlitText(0, 0, tmntFont, "t");
		}
		if (counter > 825)
		{
			App->fonts->BlitText(0, 0, tmntFont, " ");
		}
		if (counter > 830)
		{
			App->fonts->BlitText(0, 0, tmntFont, "a");
		}
		if (counter > 835)
		{
			App->fonts->BlitText(0, 0, tmntFont, "p");
		}
		if (counter > 840)
		{
			App->fonts->BlitText(0, 0, tmntFont, "r");
		}
		if (counter > 845)
		{
			App->fonts->BlitText(0, 0, tmntFont, "i");
		}
		if (counter > 850)
		{
			App->fonts->BlitText(0, 0, tmntFont, "l");
		}
		if (counter > 855)
		{
			App->fonts->BlitText(0, 0, tmntFont, " ");
		}
		if (counter > 860)
		{
			App->fonts->BlitText(0, 0, tmntFont, "o");
		}
		if (counter > 865)
		{
			App->fonts->BlitText(0, 0, tmntFont, "u");
		}
		if (counter > 890)
		{
			App->fonts->BlitText(0, 0, tmntFont, "t");
		}
		if (counter > 895)
		{
			App->fonts->BlitText(0, 0, tmntFont, "!");
		}
		if (counter > 900)
		{
			App->fonts->BlitText(0, 0, tmntFont, "!");
		}
		
	}


	return update_status::UPDATE_CONTINUE;
}

bool ModuleSceneCinematic::CleanUp()
{
	bool ret;
	App->textures->CleanUp();
	return true;
}