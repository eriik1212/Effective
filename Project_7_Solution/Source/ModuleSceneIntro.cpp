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
	introBackground = App->textures->Load("Assets/Introduction/title_screen.png");
	App->audio->PlayMusic("Assets/Audio/01 Opening Demo.ogg", 1.0f);
	return true;
}

update_status ModuleSceneIntro::Update()
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
update_status ModuleSceneIntro::PostUpdate()
{
	App->render->Blit(introBackground, 0, 0, NULL);
	return update_status::UPDATE_CONTINUE;
}

bool ModuleSceneIntro::CleanUp()
{
	bool ret;
	return true;
}
