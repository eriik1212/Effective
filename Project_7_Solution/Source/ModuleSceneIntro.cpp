#include "ModuleSceneIntro.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"

ModuleSceneIntro::ModuleSceneIntro(bool enabled) : Module(enabled)
{
	spawnPos = iPoint(100,0);

	cloud1.PushBack({ 20, 539, 207, 29 });

	//PATH
	path.PushBack({ -1.2f, 0.0f }, 45, &cloud1);
}

ModuleSceneIntro::~ModuleSceneIntro() {}

// Load assets
bool ModuleSceneIntro::Start()
{
	// Members Texture
	introMembers = App->textures->Load("Assets/Introduction/intro_members.png");
	members = true;
	membersCounter = 0;

	introBackground = App->textures->Load("Assets/Introduction/introduction.png");	

	App->audio->PlayMusic("Assets/Audio/02_character_selection.ogg", 1.0f);
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
<<<<<<< Updated upstream
			App->audio->PlayMusic("Assets/Audio/01_opening_demo.ogg", 1.0f);
=======

			App->audio->PlayMusic("Assets/Audio/01 Opening Demo.ogg", 1.0f);

			path.Update();
			position = spawnPos + path.GetRelativePosition();
			currentAnim = path.GetCurrentAnimation();

>>>>>>> Stashed changes
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
		App->render->Blit(introBackground, -550, -89, NULL, NULL, true);
	}	
	return update_status::UPDATE_CONTINUE;
}

bool ModuleSceneIntro::CleanUp()
{
	bool ret;
	App->textures->CleanUp();
	return true;
}
