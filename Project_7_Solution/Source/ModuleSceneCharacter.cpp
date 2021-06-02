#include "ModuleSceneCharacter.h"

#include "SDL/include/SDL.h"
#pragma comment( lib, "SDL/libx86/SDL2.lib")
#pragma comment( lib, "SDL/libx86/SDL2main.lib")
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleFadeToBlack.h"
#include "ModuleFonts.h"
#include "ModuleSceneIntro.h"
#include "ModulePlayer.h"
#include "ModuleHUD.h"

#include<stdio.h>

ModuleSceneCharacter::ModuleSceneCharacter(bool enabled) : Module(enabled)
{
	drawColorScreen.x = 0;
	drawColorScreen.y = 0;
	drawColorScreen.w = SCREEN_WIDTH * SCREEN_SIZE;
	drawColorScreen.h = SCREEN_HEIGHT * SCREEN_SIZE;
}

ModuleSceneCharacter::~ModuleSceneCharacter() {}

// Load assets
bool ModuleSceneCharacter::Start()
{
	App->render->camera.x = 0;
	App->render->camera.y = 0;

	App->HUD->Reset();
	App->HUD->Enable();

	characterTexture = App->textures->Load("Assets/Introduction/introduction.png");

	App->audio->PlayMusic("Assets/Audio/02_character_selection.ogg", 0.0f, -1);

	return true;
}

update_status ModuleSceneCharacter::Update()
{

	// ScanCodes
	if ((App->input->keys[SDL_SCANCODE_RETURN] == KEY_STATE::KEY_DOWN) && App->HUD->lifes > 0)
	{
		this->Disable();
		CleanUp();
		App->HUD->Disable();
		App->scene->Enable();
	}

	else if (App->input->keys[SDL_SCANCODE_ESCAPE] == KEY_STATE::KEY_DOWN)
	{
		return update_status::UPDATE_STOP;
	}

	return update_status::UPDATE_CONTINUE;
}

// Update: draw background
update_status ModuleSceneCharacter::PostUpdate()
{
	SDL_SetRenderDrawColor(App->render->renderer, 0, 0, 0, 255);
	SDL_RenderFillRect(App->render->renderer, &drawColorScreen);
	

	return update_status::UPDATE_CONTINUE;
}

bool ModuleSceneCharacter::CleanUp()
{
	bool ret;
	App->textures->CleanUp();
	return true;
}
