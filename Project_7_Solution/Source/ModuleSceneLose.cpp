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
	gameOverTexture = App->textures->Load("Assets/UI & HUD/game_over.png");
	App->audio->PlayMusic("Assets/Audio/06 shredder final", 1.0f);
	return true;
}

update_status ModuleSceneLose::Update()
{
	App->audio->PlayMusic("Assets/Audio/08 GameOver.ogg");
	if (App->input->keys[SDL_SCANCODE_R] == KEY_STATE::KEY_DOWN)
	{
		this->Disable();
		App->sceneIntro->Enable();
	}

	if (App->input->keys[SDL_SCANCODE_ESCAPE] == KEY_STATE::KEY_DOWN)
	{
		return update_status::UPDATE_STOP;
	}

	return update_status::UPDATE_CONTINUE;
}

// Update: draw background
update_status ModuleSceneLose::PostUpdate()
{
	App->render->Blit(gameOverTexture, SCREEN_WIDTH / 2 - 50, SCREEN_HEIGHT / 2 - 50, NULL, 0, true); // GameOver Texture
	return update_status::UPDATE_CONTINUE;
}

bool ModuleSceneLose::CleanUp()
{
	bool ret;
	return true;
}
