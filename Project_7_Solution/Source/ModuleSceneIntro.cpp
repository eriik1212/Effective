#include "ModuleSceneIntro.h"

#include "SDL/include/SDL.h"
#pragma comment( lib, "SDL/libx86/SDL2.lib")
#pragma comment( lib, "SDL/libx86/SDL2main.lib")
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleFadeToBlack.h"

ModuleSceneIntro::ModuleSceneIntro(bool enabled) : Module(enabled)
{

	drawColorScreen.x = 0;
	drawColorScreen.y = 0;
	drawColorScreen.w = SCREEN_WIDTH * SCREEN_SIZE;
	drawColorScreen.h = SCREEN_HEIGHT * SCREEN_SIZE;

	backGround.x = 550;
	backGround.y = 89;
	backGround.w = 320;
	backGround.h = 385;

	frontBuildings.x = 919;
	frontBuildings.y = 89;
	frontBuildings.w = 304;
	frontBuildings.h = 515;

	buildingLights.x = 1263;
	buildingLights.y = 114;
	buildingLights.w = 304;
	buildingLights.h = 64;

	secondFloor.x = 1604;
	secondFloor.y = 646;
	secondFloor.w = 304;
	secondFloor.h = 47;

	floor.x = 1604;
	floor.y = 114;
	floor.w = 304;
	floor.h = 503;

	sewer.x = 21;
	sewer.y = 459;
	sewer.w = 60;
	sewer.h = 28;

	text.x = 19;
	text.y = 220;
	text.w = 272;
	text.h = 108;

	//Characters ANIMATION
	leoAnim1.PushBack({ 0, 4200, 94, 84 });
	leoAnim2.PushBack({ (94 * 1), 4200, 94, 84 });
	leoAnim3.PushBack({ (94 * 2), 4200, 94, 84 });
	leoAnim4.PushBack({ (94 * 3), 4200, 94, 84 });
	leoAnim5.PushBack({ (94 * 4), 4200, 94, 84 });
	leoAnim6.PushBack({ (94 * 5), 4200, 94, 84 });

	leoImage.PushBack({ 14, 658, 124, 110 });

	raphaelAnim1.PushBack({ 0, 3360, 94, 84 });
	raphaelAnim2.PushBack({ (94 * 1), 3360, 94, 84 });
	raphaelAnim3.PushBack({ (94 * 2), 3360, 94, 84 });
	raphaelAnim4.PushBack({ (94 * 3), 3360, 94, 84 });
	raphaelAnim5.PushBack({ (94 * 4), 3360, 94, 84 });
	raphaelAnim6.PushBack({ (94 * 5), 3360, 94, 84 });

	raphaelImage.PushBack({ 500, 658, 124, 110 });

	michelangeloAnim1.PushBack({ 0, 3117, 84, 67 });
	michelangeloAnim2.PushBack({ (84 * 1), 3117, 84, 67 });
	michelangeloAnim3.PushBack({ (84 * 2), 3117, 84, 67 });
	michelangeloAnim4.PushBack({ (84 * 3), 3117, 84, 67 });
	michelangeloAnim5.PushBack({ (84 * 4), 3117, 84, 67 });
	michelangeloAnim6.PushBack({ (84 * 5), 3117, 84, 67 });

	michelangeloImage.PushBack({ 340, 658, 124, 110 });

	donatelloAnim1.PushBack({ 0, 3574, 97, 81 });
	donatelloAnim2.PushBack({ (97 * 1), 3574, 97, 81 });
	donatelloAnim3.PushBack({ (97 * 2), 3574, 97, 81 });
	donatelloAnim4.PushBack({ (97 * 3), 3574, 97, 81 });
	donatelloAnim5.PushBack({ (97 * 4), 3574, 97, 81 });
	donatelloAnim6.PushBack({ (97 * 5), 3574, 97, 81 });

	donatelloImage.PushBack({ 174, 658, 124, 110 });


	cloud1.PushBack({ 20, 539, 207, 29 });
	cloud1.loop = true;
	cloud1.speed = 0.15f;

	cloud2.PushBack({ 119, 461, 88, 26 });
	cloud2.loop = true;
	cloud2.speed = 0.15f;

	littleLightAnim.PushBack({ 252, 579, 64, 21 });
	littleLightAnim.PushBack({ 252, 600, 64, 21 });
	littleLightAnim.loop = true;
	littleLightAnim.speed = 1.0f;

	bigLightUpAnim.PushBack({ 573, 1733, 64, 242 });
	bigLightUpAnim.PushBack({ 492, 1733, 64, 242 });
	bigLightUpAnim.PushBack({ 413, 1733, 64, 242 });
	bigLightUpAnim.PushBack({ 336, 1733, 64, 242 });
	bigLightUpAnim.PushBack({ 255, 1733, 64, 242 });
	bigLightUpAnim.PushBack({ 181, 1733, 64, 242 });
	bigLightUpAnim.PushBack({ 100, 1733, 64, 242 });
	bigLightUpAnim.PushBack({ 19, 1733, 64, 242 });
	bigLightUpAnim.loop = false;
	bigLightUpAnim.speed = 1.0f;

	bigLightAnim.PushBack({ 19, 1733, 64, 242 });
	bigLightAnim.PushBack({ 252, 600, 64, 21 });
	bigLightAnim.loop = true;
	bigLightAnim.speed = 1.0f;

	//TitleScreen
	TMNRectAnim.PushBack({ 19, 89, 206, 24 });
	TurtlesRectAnim.PushBack({ 19, 129, 256, 71 });

	//PATH TMNRect
	pathTMNRect.PushBack({ 0.0f, 5.0f }, 30, & TMNRectAnim);
	pathTMNRect.PushBack({ 0.0f, 3.0f }, 5, & TMNRectAnim);
	pathTMNRect.PushBack({ 0.0f, 0.0f }, 2, & TMNRectAnim);
	pathTMNRect.PushBack({ 0.0f, -3.0f }, 5, & TMNRectAnim);
	pathTMNRect.PushBack({ 0.0f, -5.0f }, 20, & TMNRectAnim);
	pathTMNRect.PushBack({ 0.0f, 0.0f }, 1000, & TMNRectAnim);

	//PATH TurtlesRect
	pathTurtlesRect.PushBack({ -9.7f, 0.0f }, 28, & TurtlesRectAnim);
	pathTurtlesRect.PushBack({ 0.0f, 0.0f }, 1000, & TurtlesRectAnim);

	//PATH Cloud1
	pathCloud1.PushBack({ -0.3f, 0.0f }, 300, &cloud1);

	//PATH Cloud2
	pathCloud2.PushBack({ 0.3f, 0.0f }, 300, &cloud2);

	//PATH Donatello
	pathDonatello.PushBack({ 0.0f, -1.8f }, 14, & donatelloAnim1);
	pathDonatello.PushBack({ -1.5f, -1.8f }, 14, & donatelloAnim2);
	pathDonatello.PushBack({ -1.5f, -1.8f }, 14, & donatelloAnim3);
	pathDonatello.PushBack({ -1.5f, -1.8f }, 14, & donatelloAnim4);
	pathDonatello.PushBack({ -1.5f, -1.8f }, 14, & donatelloAnim5);
	pathDonatello.PushBack({ -1.5f, -1.8f }, 14, & donatelloAnim6);

	pathDonatelloImage.PushBack({ -3.55f, 2.625f }, 42, &donatelloImage);
	pathDonatelloImage.PushBack({ 0.0f, 0.0f }, 1000, & donatelloImage);

	//PATH Leo
	pathLeo.PushBack({ 0.0f, -1.8f }, 14, &leoAnim1);
	pathLeo.PushBack({ -0.5f, -1.8f }, 14, &leoAnim2);
	pathLeo.PushBack({ -0.5f, -1.8f }, 14, &leoAnim3);
	pathLeo.PushBack({ -0.5f, -1.8f }, 14, &leoAnim4);
	pathLeo.PushBack({ -0.5f, -1.8f }, 14, &leoAnim5);
	pathLeo.PushBack({ -0.5f, -1.8f }, 14, &leoAnim6);

	pathLeoImage.PushBack({ 3.55f, 2.625f }, 42, &leoImage);
	pathLeoImage.PushBack({ 0.0f, 0.0f }, 1000, & leoImage);

	//PATH Mikel
	pathMichelangelo.PushBack({ 0.0f, -1.8f }, 14, & michelangeloAnim1);
	pathMichelangelo.PushBack({ 0.5f, -1.8f }, 14, & michelangeloAnim2);
	pathMichelangelo.PushBack({ 0.5f, -1.8f }, 14, & michelangeloAnim3);
	pathMichelangelo.PushBack({ 0.5f, -1.8f }, 14, & michelangeloAnim4);
	pathMichelangelo.PushBack({ 0.5f, -1.8f }, 14, & michelangeloAnim5);
	pathMichelangelo.PushBack({ 0.5f, -1.8f }, 14, & michelangeloAnim6);

	pathMichelangeloImage.PushBack({ 3.55f, -2.625f }, 42, &michelangeloImage);
	pathMichelangeloImage.PushBack({ 0.0f, 0.0f }, 1000, & michelangeloImage);

	//PATH Rafa
	pathRaphael.PushBack({ 0.0f, -1.8f }, 14, & raphaelAnim1);
	pathRaphael.PushBack({ 1.5f, -1.8f }, 14, & raphaelAnim2);
	pathRaphael.PushBack({ 1.5f, -1.8f }, 14, & raphaelAnim3);
	pathRaphael.PushBack({ 1.5f, -1.8f }, 14, & raphaelAnim4);
	pathRaphael.PushBack({ 1.5f, -1.8f }, 14, & raphaelAnim5);
	pathRaphael.PushBack({ 1.5f, -1.8f }, 14, & raphaelAnim6);

	pathRaphaelImage.PushBack({ -3.55f, -2.625f }, 42, & raphaelImage);
	pathRaphaelImage.PushBack({ 0.0f, 0.0f }, 1000, & raphaelImage);
}

ModuleSceneIntro::~ModuleSceneIntro() {}

// Load assets
bool ModuleSceneIntro::Start()
{

	counter = 0;

	App->render->camera.x = 0;
	App->render->camera.y = 0;

	pathLeo.Reset();
	pathDonatello.Reset();
	pathRaphael.Reset();
	pathMichelangelo.Reset();
	pathLeoImage.Reset();
	pathDonatelloImage.Reset();
	pathRaphaelImage.Reset();
	pathMichelangeloImage.Reset();
	pathTMNRect.Reset();
	pathTurtlesRect.Reset();

	//Spawn ALL Paths
	pathCloud1.ResetRelativePosition();
	spawnPosCloud1 = iPoint((int)100, (int)65);

	pathCloud2.ResetRelativePosition();
	spawnPosCloud2 = iPoint((int)10, (int)28);

	pathLeo.ResetRelativePosition();
	spawnPosLeo = iPoint((int)110, (int)915 + (64 * 12) + 410);

	pathRaphael.ResetRelativePosition();
	spawnPosRaphael = iPoint((int)110, (int)915 + (64 * 12) + 412);

	pathMichelangelo.ResetRelativePosition();
	spawnPosMichelangelo = iPoint((int)110, (int)915 + (64 * 12) + 426);

	pathDonatello.ResetRelativePosition();
	spawnPosDonatello = iPoint((int)110, (int)915 + (64 * 12) + 416);

	pathDonatelloImage.ResetRelativePosition();
	spawnPosDonatelloImage = iPoint((int)(SCREEN_WIDTH), (int)-110);

	pathLeoImage.ResetRelativePosition();
	spawnPosLeoImage = iPoint((int)(-124), (int)-110);

	pathMichelangeloImage.ResetRelativePosition();
	spawnPosMichelangeloImage = iPoint((int)(-124), (int)(SCREEN_HEIGHT));

	pathRaphaelImage.ResetRelativePosition();
	spawnPosRaphaelImage = iPoint((int)(SCREEN_WIDTH), (int)(SCREEN_HEIGHT));

	pathTMNRect.ResetRelativePosition();
	spawnPosTMNRect = iPoint((int)(53), (int)(-24));

	pathTurtlesRect.ResetRelativePosition();
	spawnPosTurtlesRect = iPoint((int)(SCREEN_WIDTH), (int)(45));

	bigLightUpAnim.Reset();

	introBackground = App->textures->Load("Assets/Introduction/introduction.png");
	raphaelTexture = App->textures->Load("Assets/Characters/Raphael.png");
	donatelloTexture = App->textures->Load("Assets/Characters/Donatello.png");
	leoTexture = App->textures->Load("Assets/Characters/Leonardo.png");
	michelangeloTexture = App->textures->Load("Assets/Characters/Michelangelo.png");

	App->audio->StopMusic();

	return true;
}

update_status ModuleSceneIntro::Update()
{

	littleLightAnim.Update();
	currentAnimLight = &littleLightAnim;

	counter++;

	if (counter == 80)
	{
		App->audio->PlayMusic("Assets/Audio/01_opening_demo.ogg", 0.0f, 0);
	}

	if (counter > 150)
	{
		App->render->camera.y += 6.0f;
	}

	//----------------------------------------------------------------------------------------Initialize Positions
	pathCloud1.Update();
	positionCloud1 = spawnPosCloud1 + pathCloud1.GetRelativePosition();
	currentAnimCloud1 = pathCloud1.GetCurrentAnimation();

	pathCloud2.Update();
	positionCloud2 = spawnPosCloud2 + pathCloud2.GetRelativePosition();
	currentAnimCloud2 = pathCloud2.GetCurrentAnimation();

	positionLeo = spawnPosLeo + pathLeo.GetRelativePosition();
	leoCurrentAnim = pathLeo.GetCurrentAnimation();

	positionRaphael = spawnPosRaphael + pathRaphael.GetRelativePosition();
	raphaelCurrentAnim = pathRaphael.GetCurrentAnimation();

	positionMichelangelo = spawnPosMichelangelo + pathMichelangelo.GetRelativePosition();
	michelangeloCurrentAnim = pathMichelangelo.GetCurrentAnimation();

	positionDonatello = spawnPosDonatello + pathDonatello.GetRelativePosition();
	donatelloCurrentAnim = pathDonatello.GetCurrentAnimation();

	positionDonatelloImage = spawnPosDonatelloImage + pathDonatelloImage.GetRelativePosition();
	donatelloImageCurrentAnim = pathDonatelloImage.GetCurrentAnimation();

	positionLeoImage = spawnPosLeoImage + pathLeoImage.GetRelativePosition();
	leoImageCurrentAnim = pathLeoImage.GetCurrentAnimation();

	positionMichelangeloImage = spawnPosMichelangeloImage + pathMichelangeloImage.GetRelativePosition();
	michelangeloImageCurrentAnim = pathMichelangeloImage.GetCurrentAnimation();

	positionRaphaelImage = spawnPosRaphaelImage + pathRaphaelImage.GetRelativePosition();
	raphaelImageCurrentAnim = pathRaphaelImage.GetCurrentAnimation();

	positionTMNRect = spawnPosTMNRect + pathTMNRect.GetRelativePosition();
	TMNRectCurrentAnim = pathTMNRect.GetCurrentAnimation();

	positionTurtlesRect = spawnPosTurtlesRect + pathTurtlesRect.GetRelativePosition();
	TurtlesRectCurrentAnim = pathTurtlesRect.GetCurrentAnimation();


	if (counter > 370)
	{
		bigLightUpAnim.Update();
		currentAnimLight = &bigLightUpAnim;
	}

	if (counter > 380)
	{
		bigLightAnim.Update();
		currentAnimLight = &bigLightAnim;
	}

	if (counter > 385)
	{
		pathLeo.Update();
		pathRaphael.Update();
		pathMichelangelo.Update();
		pathDonatello.Update();
	}

	if (counter > 470)
	{
		pathDonatelloImage.Update();
		pathMichelangeloImage.Update();
		pathLeoImage.Update();
		pathRaphaelImage.Update();
	}

	if (counter > 630)
	{
		pathTMNRect.Update();
	}

	if (counter > 720)
	{
		pathTurtlesRect.Update();
	}


	// ScanCodes
	if ((App->input->keys[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN) || counter > 800)
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
update_status ModuleSceneIntro::PostUpdate()
{
  	App->render->Blit(introBackground, 0, 0, &backGround, 2, true); //BackGround
	App->render->Blit(introBackground, 0, 400, &frontBuildings, 7, true); //Front Buildings

	//Building Lights
	App->render->Blit(introBackground, 0, 915, &buildingLights, 7, true);
	App->render->Blit(introBackground, 0, 915 + (64 * 1), &buildingLights, 7, true);
	App->render->Blit(introBackground, 0, 915 + (64 * 2), &buildingLights, 7, true);
	App->render->Blit(introBackground, 0, 915 + (64 * 3), &buildingLights, 7, true);
	App->render->Blit(introBackground, 0, 915 + (64 * 4), &buildingLights, 7, true);
	App->render->Blit(introBackground, 0, 915 + (64 * 5), &buildingLights, 7, true);
	App->render->Blit(introBackground, 0, 915 + (64 * 6), &buildingLights, 7, true);
	App->render->Blit(introBackground, 0, 915 + (64 * 7), &buildingLights, 7, true);
	App->render->Blit(introBackground, 0, 915 + (64 * 8), &buildingLights, 7, true);
	App->render->Blit(introBackground, 0, 915 + (64 * 9), &buildingLights, 7, true);
	App->render->Blit(introBackground, 0, 915 + (64 * 10), &buildingLights, 7, true);
	App->render->Blit(introBackground, 0, 915 + (64 * 11), &buildingLights, 7, true);

	//Floor
	App->render->Blit(introBackground, 0, 915 + (64 * 12), &floor, 7, true);

	// Clouds
	if (currentAnimCloud1 != nullptr)
		App->render->Blit(introBackground, positionCloud1.x, positionCloud1.y, &(currentAnimCloud1->GetCurrentFrame()), 2, true);

	if (currentAnimCloud2 != nullptr)
		App->render->Blit(introBackground, positionCloud2.x, positionCloud2.y, &(currentAnimCloud2->GetCurrentFrame()), 2, true);

	//---------------------------------------------------------------------------------------------------Characters
	//Rafa
	if (raphaelCurrentAnim != nullptr)
		App->render->Blit(raphaelTexture, positionRaphael.x, positionRaphael.y, &(raphaelCurrentAnim->GetCurrentFrame()), 7, true); 

	//Mikel
	if (michelangeloCurrentAnim != nullptr)
		App->render->Blit(michelangeloTexture, positionMichelangelo.x, positionMichelangelo.y, &(michelangeloCurrentAnim->GetCurrentFrame()), 7, true); 

	 //Donatello
	if (donatelloCurrentAnim != nullptr)
		App->render->Blit(donatelloTexture, positionDonatello.x, positionDonatello.y, &(donatelloCurrentAnim->GetCurrentFrame()), 7, true);
	
	//Leo
	if (leoCurrentAnim != nullptr)
		App->render->Blit(leoTexture, positionLeo.x, positionLeo.y, &(leoCurrentAnim->GetCurrentFrame()), 7, true);

	// SecondFloor
	App->render->Blit(introBackground, 0, 915 + (64 * 12) + 456, &secondFloor, 7, true);

	//LittleLight Sewer
	if (counter > 330 && counter < 370)
	{
		App->render->Blit(introBackground, 127, 2138, &(currentAnimLight->GetCurrentFrame()), 7, true);
	}

	if (counter > 370)
	{
		App->render->Blit(introBackground, 127, 1916, &(currentAnimLight->GetCurrentFrame()), 7, true);
	}

	//Sewer (Alcantarilla)
	if (counter < 370)
	{
		App->render->Blit(introBackground, 129, 2125, &sewer, 7, true);
	}

	if (counter > 470)
	{
		SDL_RenderFillRect(App->render->renderer, &drawColorScreen);
	}
	
	if (counter > 470)
	{
		if (donatelloCurrentAnim != nullptr)
			App->render->Blit(introBackground, positionDonatelloImage.x, positionDonatelloImage.y, &(donatelloImageCurrentAnim->GetCurrentFrame()), NULL);

		if (leoCurrentAnim != nullptr)
			App->render->Blit(introBackground, positionLeoImage.x, positionLeoImage.y, &(leoImageCurrentAnim->GetCurrentFrame()), NULL);

		if (michelangeloCurrentAnim != nullptr)
			App->render->Blit(introBackground, positionMichelangeloImage.x, positionMichelangeloImage.y, &(michelangeloImageCurrentAnim->GetCurrentFrame()), NULL);

		if (raphaelCurrentAnim != nullptr)
			App->render->Blit(introBackground, positionRaphaelImage.x, positionRaphaelImage.y, &(raphaelImageCurrentAnim->GetCurrentFrame()), NULL);
	}

	if (counter > 620)
	{
		SDL_RenderFillRect(App->render->renderer, &drawColorScreen);
	}

	if (counter > 630)
	{
		SDL_SetRenderDrawColor(App->render->renderer, 0, 123, 222, 255);
		SDL_RenderFillRect(App->render->renderer, &drawColorScreen);

		if (TMNRectCurrentAnim != nullptr)
			App->render->Blit(introBackground, positionTMNRect.x, positionTMNRect.y, &(TMNRectCurrentAnim->GetCurrentFrame()), NULL);

		if (TurtlesRectCurrentAnim != nullptr)
			App->render->Blit(introBackground, positionTurtlesRect.x, positionTurtlesRect.y, &(TurtlesRectCurrentAnim->GetCurrentFrame()), NULL);
	}

	if (counter > 750)
	{
		App->render->Blit(introBackground, 16, 116, &text, NULL); //BackGround

	}
	
	//Camera Limit
	if (App->render->camera.y >= 835) App->render->camera.y = 835;

	return update_status::UPDATE_CONTINUE;
}

bool ModuleSceneIntro::CleanUp()
{
	bool ret;
	App->textures->CleanUp();
	return true;
}
