#include "ModuleSceneLose.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"

ModuleSceneLose::ModuleSceneLose(bool enabled) : Module(enabled)
{
	
}

ModuleSceneLose::~ModuleSceneLose() {}

// Load assets
bool ModuleSceneLose::Start()
{
	introBackground = App->textures->Load("");
	App->audio->PlayMusic("", 1.0f);
	return true;
}

update_status ModuleSceneLose::Update()
{
	if (App->input->keys[SDL_SCANCODE_R] == KEY_STATE::KEY_DOWN)
	{
		this->Disable();
		App->scene->Enable();
		App->player->Enable();
		App->enemies->Enable();
	}

	return update_status::UPDATE_CONTINUE;
}

// Update: draw background
update_status ModuleSceneLose::PostUpdate()
{
	App->render->Blit(introBackground, 0, 0, NULL, NULL, true);
	return update_status::UPDATE_CONTINUE;
}

bool ModuleSceneLose::CleanUp()
{
	bool ret;
	return true;
}
