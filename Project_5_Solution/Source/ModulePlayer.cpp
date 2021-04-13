#include "ModulePlayer.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleParticles.h"

#include "SDL/include/SDL_scancode.h"


ModulePlayer::ModulePlayer()
{
	srand(time(NULL));

	position.x = 100;
	position.y = 200;

	// idle animation
	idleAnim.PushBack({ 21, 24, 53, 60 });
	idleAnim.PushBack({ 115, 24, 53, 60 });
	idleAnim.PushBack({ 303, 24, 53, 60 });
	idleAnim.PushBack({ 115, 24, 53, 60 });
	idleAnim.PushBack({ 21, 24, 53, 60 });
	idleAnim.PushBack({ 491, 24, 53, 60 });
	idleAnim.PushBack({ 21, 24, 53, 60 });
	idleAnim.PushBack({ 115, 24, 53, 60 });
	idleAnim.PushBack({ 209, 24, 53, 60 });
	idleAnim.PushBack({ 115, 24, 53, 60 });
	idleAnim.PushBack({ 303, 24, 53, 60 });
	idleAnim.PushBack({ 115, 24, 53, 60 });
	idleAnim.PushBack({ 21, 24, 53, 60 });
	idleAnim.loop = false;
	idleAnim.speed = 0.02f;

	// move right
	rightAnim.PushBack({ 30, 964, 47, 62 });
	rightAnim.PushBack({ 124, 964, 47, 62 });
	rightAnim.PushBack({ 223, 964, 47, 62 });
	rightAnim.PushBack({ 317, 964, 47, 62 });
	rightAnim.PushBack({ 412, 964, 47, 62 });
	rightAnim.PushBack({ 503, 964, 47, 62 });
	rightAnim.PushBack({ 598, 964, 47, 62 });
	rightAnim.PushBack({ 691, 964, 47, 62 });
	rightAnim.loop = true;
	rightAnim.speed = 0.25f;

	// move left
	leftAnim.PushBack({ 1235, 2642, 47, 62 });
	leftAnim.PushBack({ 1141, 2642, 47, 62 });
	leftAnim.PushBack({ 1042, 2642, 47, 62 });
	leftAnim.PushBack({ 948, 2642, 47, 62 });
	leftAnim.PushBack({ 853, 2642, 47, 62 });
	leftAnim.PushBack({ 762, 2642, 47, 62 });
	leftAnim.PushBack({ 667, 2642, 47, 62 });
	leftAnim.PushBack({ 574, 2642, 47, 62 });
	leftAnim.loop = true;
	leftAnim.speed = 0.25f;

	// move upwards
	upAnim.PushBack({ 32, 1051, 47, 62 });
	upAnim.PushBack({ 128, 1051, 47, 62 });
	upAnim.PushBack({ 224, 1051, 47, 62 });
	upAnim.PushBack({ 318, 1051, 47, 62 });
	upAnim.PushBack({ 408, 1051, 47, 62 });
	upAnim.PushBack({ 500, 1051, 47, 62 });
	upAnim.PushBack({ 590, 1051, 48, 62 });
	upAnim.PushBack({ 683, 1051, 51, 62 });
	upAnim.loop = true;
	upAnim.speed = 0.25f;

	// Move down
	downAnim.PushBack({ 30, 964, 47, 62 });
	downAnim.PushBack({ 124, 964, 47, 62 });
	downAnim.PushBack({ 223, 964, 47, 62 });
	downAnim.PushBack({ 317, 964, 47, 62 });
	downAnim.PushBack({ 412, 964, 47, 62 });
	downAnim.PushBack({ 503, 964, 47, 62 });
	downAnim.PushBack({ 598, 964, 47, 62 });
	downAnim.PushBack({ 691, 964, 47, 62 });
	downAnim.loop = true;
	downAnim.speed = 0.25f;

	// Hit Air Animation 1
	hitAirAnim1.PushBack({ 19, 179, 62, 84 });
	hitAirAnim1.PushBack({ 110, 179, 62, 84 });
	hitAirAnim1.PushBack({ 215, 179, 62, 84 });
	hitAirAnim1.PushBack({ 299, 179, 62, 84 });
	hitAirAnim1.PushBack({ 394, 179, 62, 84 });
	hitAirAnim1.PushBack({ 493, 179, 62, 84 });
	hitAirAnim1.loop = false;
	hitAirAnim1.speed = 0.4f;

	// Hit Air Animation 2
	hitAirAnim2.PushBack({ 18, 356, 62, 84 });
	hitAirAnim2.PushBack({ 114, 356, 62, 84 });
	hitAirAnim2.PushBack({ 192, 356, 87, 84 });
	hitAirAnim2.PushBack({ 288, 356, 87, 84 });
	hitAirAnim2.PushBack({ 402, 356, 62, 84 });
	hitAirAnim2.PushBack({ 479, 356, 87, 84 });
	hitAirAnim2.loop = false;
	hitAirAnim2.speed = 0.4f;
}

ModulePlayer::~ModulePlayer()
{

}

bool ModulePlayer::Start()
{
	LOG("Loading player textures");

	bool ret = true;

	texture = App->textures->Load("Assets/Characters/Leonardo.png"); // arcade version
	currentAnimation = &idleAnim;

	return ret;
}

update_status ModulePlayer::Update()
{
	// Hits

	if (App->input->keys[SDL_SCANCODE_X] == KEY_STATE::KEY_DOWN)
	{
		int x = (rand() % 2);
		if (x == 0) {
			if (currentAnimation != &hitAirAnim1)
			{
			hitAirAnim1.Reset();
			currentAnimation = &hitAirAnim1;
			}
		}

		if (x == 1) {
			if (currentAnimation != &hitAirAnim2)
			{
				hitAirAnim2.Reset();
				currentAnimation = &hitAirAnim2;
			}
		}
	}

	// Moving the player

	if (App->input->keys[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT)
	{
		position.x -= speed;
		if (position.x < 50) position.x = 50;
		if (currentAnimation != &leftAnim)
		{
			leftAnim.Reset();
			currentAnimation = &leftAnim;
		}
	}

	if (App->input->keys[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT)
	{
		position.x += speed;
		if (position.x > 1300) position.x = 1300;
		if (currentAnimation != &rightAnim)
		{
			rightAnim.Reset();
			currentAnimation = &rightAnim;
		}
	}

	if (App->input->keys[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT)
	{
		position.y += speed;
		if (position.y > 224) position.y = 224;
		if (currentAnimation != &downAnim)
		{
			downAnim.Reset();
			currentAnimation = &downAnim;
		}
	}

	if (App->input->keys[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT)
	{
		position.y -= speed;
		if (position.y < 142) position.y = 142;
		if (currentAnimation != &upAnim)
		{
			upAnim.Reset();
			currentAnimation = &upAnim;
		}
	}

	// TODO 3: Shoot lasers when the player hits SPACE
	if (App->input->keys[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN)
	{
		if (currentAnimation != &hitAirAnim1)
		{
			hitAirAnim1.Reset();
			currentAnimation = &hitAirAnim1;
		}
	}

	// Spawn explosion particles when pressing B
	if (App->input->keys[SDL_SCANCODE_B] == KEY_STATE::KEY_DOWN)
	{
		App->particles->AddParticle(App->particles->explosion, position.x, position.y + 25);
		App->particles->AddParticle(App->particles->explosion, position.x - 25, position.y, 30);
		App->particles->AddParticle(App->particles->explosion, position.x, position.y - 25, 60);
		App->particles->AddParticle(App->particles->explosion, position.x + 25, position.y, 90);
	}

	// If no movement detected, set the current animation back to idle

	if (App->input->keys[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_IDLE
		&& App->input->keys[SDL_SCANCODE_UP] == KEY_STATE::KEY_IDLE
		&& App->input->keys[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_IDLE
		&& App->input->keys[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_IDLE
		&& App->input->keys[SDL_SCANCODE_X] == KEY_STATE::KEY_IDLE)
	{
		if (currentAnimation != &idleAnim && currentAnimation != &hitAirAnim1 && currentAnimation != &hitAirAnim2)
		{
			idleAnim.Reset();
			currentAnimation = &idleAnim;
		}

	}

	currentAnimation->Update();

	return update_status::UPDATE_CONTINUE;
}

update_status ModulePlayer::PostUpdate()
{
	SDL_Rect rect = currentAnimation->GetCurrentFrame();
	App->render->Blit(texture, position.x, position.y - rect.h, &rect);

	return update_status::UPDATE_CONTINUE;
}