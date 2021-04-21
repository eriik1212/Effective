#include "ModuleSceneWin.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"

ModuleSceneWin::ModuleSceneWin(bool enabled) : Module(enabled)
{
	
}

ModuleSceneWin::~ModuleSceneWin() {}

// Load assets
bool ModuleSceneWin::Start()
{
	introBackground = App->textures->Load("");
	App->audio->PlayMusic("", 1.0f);
	return true;
}

update_status ModuleSceneWin::Update()
{
	if (App->input->keys[SDL_SCANCODE_1] == KEY_STATE::KEY_DOWN)
	{
		this->Disable();
		App->scene->Enable();
		App->player->Enable();
		App->enemies->Enable();
	}

	return update_status::UPDATE_CONTINUE;
}

// Update: draw background
update_status ModuleSceneWin::PostUpdate()
{
	App->render->Blit(introBackground, 0, 0, NULL);
	return update_status::UPDATE_CONTINUE;
}

bool ModuleSceneWin::CleanUp()
{
	bool ret;
	return true;
}
