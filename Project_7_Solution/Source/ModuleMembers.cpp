#include "ModuleMembers.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"

ModuleMembers::ModuleMembers(bool startEnabled) : Module(startEnabled)
{
	
}

ModuleMembers::~ModuleMembers()
{

}

// Load assets
bool ModuleMembers::Start()
{
	// Members Texture
	introMembers = App->textures->Load("Assets/Introduction/intro_members.png");

	App->audio->PlayMusic("Assets/Audio/02_character_selection.ogg", 1.0f);
	return true;
}

update_status ModuleMembers::Update()
{

	// ScanCodes
	if (App->input->keys[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN)
	{
		App->fade->FadeToBlack(this, (Module*)App->sceneIntro, 60);
	}

	else if (App->input->keys[SDL_SCANCODE_ESCAPE] == KEY_STATE::KEY_DOWN)
	{
		return update_status::UPDATE_STOP;
	}

	return update_status::UPDATE_CONTINUE;
}

// Update: draw background
update_status ModuleMembers::PostUpdate()
{
	App->render->Blit(introMembers, 0, 0, NULL);

	return update_status::UPDATE_CONTINUE;
}
