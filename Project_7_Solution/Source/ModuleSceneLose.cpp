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
	countDown = 0;

	gameOverTexture = App->textures->Load("Assets/UI & HUD/game_over.png");
	App->audio->PlayMusic("Assets/Audio/08_game_over", 1.0f);
	return true;
}

update_status ModuleSceneLose::Update()
{
	countDown++;

	if (countDown > 250)
	{
		this->Disable();
		CleanUp();
		App->scene->Disable();
		App->scene->CleanUp();
		App->sceneIntro->Enable();
	}

	else if (App->input->keys[SDL_SCANCODE_R] == KEY_STATE::KEY_DOWN)
	{
		this->Disable();
		CleanUp();
		App->scene->Disable();
		App->scene->CleanUp();
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
