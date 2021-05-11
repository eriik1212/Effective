#include "ModuleSceneIntro.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"

ModuleSceneIntro::ModuleSceneIntro(bool enabled) : Module(enabled)
{
	
}

ModuleSceneIntro::~ModuleSceneIntro() {}

// Load assets
bool ModuleSceneIntro::Start()
{
	// Members Texture
	introMembers = App->textures->Load("Assets/Introduction/introMembers.png");
	members = true;
	membersCounter = 0;

	introBackground = App->textures->Load("Assets/Introduction/title_screen.png");	

	App->audio->PlayMusic("Assets/Audio/02 Character selection.ogg", 1.0f);
	return true;
}

update_status ModuleSceneIntro::Update()
{
	// Counter
	if (members)
	{
		if (App->input->keys[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN)
		{
			membersCounter = 1;
		}
		else if (membersCounter > 0)
		{
			introMembers = nullptr;
			members = false;
			membersCounter = 0;
			App->audio->PlayMusic("Assets/Audio/01 Opening Demo.ogg", 1.0f);
		}
	}
	// ScanCodes
	if ((App->input->keys[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN) && (!members))
	{
		this->Disable();
		CleanUp();
		App->scene->Enable();
		App->player->Enable();
		App->enemies->Enable();
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
	if (members)
	{
		App->render->Blit(introMembers, 0, 0, NULL, NULL, true);
	}
	else
	{
		App->render->Blit(introBackground, 0, 0, NULL, NULL, true);
	}	
	return update_status::UPDATE_CONTINUE;
}

bool ModuleSceneIntro::CleanUp()
{
	bool ret;
	App->textures->CleanUp();
	return true;
}
