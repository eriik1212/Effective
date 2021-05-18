#include "ModuleSceneIntro.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleFadeToBlack.h"

ModuleSceneIntro::ModuleSceneIntro(bool enabled) : Module(enabled)
{
	cloud1.PushBack({ 20, 539, 207, 29 });
	cloud1.loop = true;
	cloud1.speed = 0.15f;

	//PATH
	path.PushBack({ -0.5f, 0.0f }, 45, &cloud1);
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

			App->audio->PlayMusic("Assets/Audio/01_opening_demo.ogg", 1.0f);

		}
	}
	else {
		path.Update();
		positionCloud1 = iPoint((int)100, (int)65) + path.GetRelativePosition();
		currentAnim = path.GetCurrentAnimation();
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

		if (currentAnim != nullptr)
		App->render->Blit(introBackground, positionCloud1.x, positionCloud1.y, &(currentAnim->GetCurrentFrame()));

	}	
	return update_status::UPDATE_CONTINUE;
}

bool ModuleSceneIntro::CleanUp()
{
	bool ret;
	App->textures->CleanUp();
	return true;
}
