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

	frontBuildings.x = 919;
	frontBuildings.y = 89;
	frontBuildings.w = 304;
	frontBuildings.h = 515;

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
}

ModuleSceneCinematic::~ModuleSceneCinematic() {}

// Load assets
bool ModuleSceneCinematic::Start()
{

	counter = 0;

	App->audio->StopMusic();

	App->render->camera.x = 0;
	App->render->camera.y = 0;

	//Spawn ALL Paths

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
	splinterAnim.Update();

	fireCurrentAnim = &fireAnim;
	fireAnim.Update();

	//----------------------------------------------------------------------------------------Initialize Positions


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
	//Splinter
	if (splinterCurrentAnim != nullptr)
		App->render->Blit(cinematicBackground, 56, SCREEN_HEIGHT - 70, &(splinterCurrentAnim->GetCurrentFrame()), NULL);

	//Leo
	App->render->Blit(charactersTexture, SCREEN_WIDTH - 122, SCREEN_HEIGHT - leo.h - 3, &leo, NULL);

	//Mikel
	App->render->Blit(charactersTexture, SCREEN_WIDTH - 120 - leo.w, SCREEN_HEIGHT - michelangelo.h - 13, &michelangelo, NULL);

	//Donatello
	App->render->Blit(charactersTexture, SCREEN_WIDTH - 122 - leo.w - michelangelo.w, SCREEN_HEIGHT - donatello.h - 13, &donatello, NULL);

	//Rafa
	App->render->Blit(charactersTexture, SCREEN_WIDTH - 118 - leo.w - michelangelo.w - donatello.w, SCREEN_HEIGHT - raphael.h - 32, &raphael, NULL);


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

	if (counter > 100 && counter < 160)
	{
		App->render->Blit(cinematicBackground, ((SCREEN_WIDTH / 2) - (backGround.w / 2)) + 28, 120, &hangOnComment, NULL); //FireComment
	}

	if (counter == 20)
	{
		App->audio->PlayFx(HangOn);
	}
	


	return update_status::UPDATE_CONTINUE;
}

bool ModuleSceneCinematic::CleanUp()
{
	bool ret;
	App->textures->CleanUp();
	return true;
}