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
	// RIGHT
	idleAnimR.PushBack({ 21, 24, 53, 60 });
	idleAnimR.PushBack({ 115, 24, 53, 60 });
	idleAnimR.PushBack({ 303, 24, 53, 60 });
	idleAnimR.PushBack({ 115, 24, 53, 60 });
	idleAnimR.PushBack({ 21, 24, 53, 60 });
	idleAnimR.PushBack({ 491, 24, 53, 60 });
	idleAnimR.PushBack({ 21, 24, 53, 60 });
	idleAnimR.PushBack({ 115, 24, 53, 60 });
	idleAnimR.PushBack({ 209, 24, 53, 60 });
	idleAnimR.PushBack({ 115, 24, 53, 60 });
	idleAnimR.PushBack({ 303, 24, 53, 60 });
	idleAnimR.PushBack({ 115, 24, 53, 60 });
	idleAnimR.PushBack({ 21, 24, 53, 60 });
	idleAnimR.loop = false;
	idleAnimR.speed = 0.02f;

	// LEFT
	idleAnimL.PushBack({ 1238, 1702, 53, 60 });
	idleAnimL.PushBack({ 1144, 1702, 53, 60 });
	idleAnimL.PushBack({ 956, 1702, 53, 60 });
	idleAnimL.PushBack({ 1144, 1702, 53, 60 });
	idleAnimL.PushBack({ 1238, 1702, 53, 60 });
	idleAnimL.PushBack({ 768, 1702, 53, 60 });
	idleAnimL.PushBack({ 1238, 1702, 53, 60 });
	idleAnimL.PushBack({ 1144, 1702, 53, 60 });
	idleAnimL.PushBack({ 1050, 1702, 53, 60 });
	idleAnimL.PushBack({ 1144, 1702, 53, 60 });
	idleAnimL.PushBack({ 956, 1702, 53, 60 });
	idleAnimL.PushBack({ 1144, 1702, 53, 60 });
	idleAnimL.PushBack({ 1238, 1702, 53, 60 });
	idleAnimL.loop = false;
	idleAnimL.speed = 0.02f;

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
	// RIGHT
	upAnimR.PushBack({ 32, 1051, 47, 62 });
	upAnimR.PushBack({ 128, 1051, 47, 62 });
	upAnimR.PushBack({ 224, 1051, 47, 62 });
	upAnimR.PushBack({ 318, 1051, 47, 62 });
	upAnimR.PushBack({ 408, 1051, 47, 62 });
	upAnimR.PushBack({ 500, 1051, 47, 62 });
	upAnimR.PushBack({ 590, 1051, 48, 62 });
	upAnimR.PushBack({ 683, 1051, 51, 62 });
	upAnimR.loop = true;
	upAnimR.speed = 0.25f;

	//LEFT
	upAnimL.PushBack({ 1233, 2729, 47, 62 });
	upAnimL.PushBack({ 1137, 2729, 47, 62 });
	upAnimL.PushBack({ 1041, 2729, 47, 62 });
	upAnimL.PushBack({ 947, 2729, 47, 62 });
	upAnimL.PushBack({ 857, 2729, 47, 62 });
	upAnimL.PushBack({ 765, 2729, 47, 62 });
	upAnimL.PushBack({ 674, 2729, 48, 62 });
	upAnimL.PushBack({ 578, 2729, 51, 62 });
	upAnimL.loop = true;
	upAnimL.speed = 0.25f;

	// Move down
	// RIGHT
	downAnimR.PushBack({ 30, 964, 47, 62 });
	downAnimR.PushBack({ 124, 964, 47, 62 });
	downAnimR.PushBack({ 223, 964, 47, 62 });
	downAnimR.PushBack({ 317, 964, 47, 62 });
	downAnimR.PushBack({ 412, 964, 47, 62 });
	downAnimR.PushBack({ 503, 964, 47, 62 });
	downAnimR.PushBack({ 598, 964, 47, 62 });
	downAnimR.PushBack({ 691, 964, 47, 62 });
	downAnimR.loop = true;
	downAnimR.speed = 0.25f;

	// LEFT
	downAnimL.PushBack({ 1235, 2642, 47, 62 });
	downAnimL.PushBack({ 1141, 2642, 47, 62 });
	downAnimL.PushBack({ 1042, 2642, 47, 62 });
	downAnimL.PushBack({ 948, 2642, 47, 62 });
	downAnimL.PushBack({ 853, 2642, 47, 62 });
	downAnimL.PushBack({ 762, 2642, 47, 62 });
	downAnimL.PushBack({ 667, 2642, 47, 62 });
	downAnimL.PushBack({ 574, 2642, 47, 62 });
	downAnimL.loop = true;
	downAnimL.speed = 0.25f;

	// Hit Air Animation 1
	hitAirAnim1R.PushBack({ 19, 179, 62, 84 });
	hitAirAnim1R.PushBack({ 110, 179, 62, 84 });
	hitAirAnim1R.PushBack({ 215, 179, 62, 84 });
	hitAirAnim1R.PushBack({ 299, 179, 62, 84 });
	hitAirAnim1R.PushBack({ 394, 179, 62, 84 });
	hitAirAnim1R.PushBack({ 493, 179, 62, 84 });
	hitAirAnim1R.loop = false;
	hitAirAnim1R.speed = 0.4f;

	// Hit Air Animation 2
	hitAirAnim2R.PushBack({ 18, 356, 62, 84 });
	hitAirAnim2R.PushBack({ 114, 356, 62, 84 });
	hitAirAnim2R.PushBack({ 192, 356, 87, 84 });
	hitAirAnim2R.PushBack({ 288, 356, 87, 84 });
	hitAirAnim2R.PushBack({ 402, 356, 62, 84 });
	hitAirAnim2R.PushBack({ 479, 356, 87, 84 });
	hitAirAnim2R.loop = false;
	hitAirAnim2R.speed = 0.4f;
}

ModulePlayer::~ModulePlayer()
{

}

bool ModulePlayer::Start()
{
	LOG("Loading player textures");

	bool ret = true;

	texture = App->textures->Load("Assets/Characters/Leonardo.png"); // arcade version
	currentAnimation = &idleAnimR;

	return ret;
}

update_status ModulePlayer::Update()
{
	// Position Players Limits
	if (position.x < 25) position.x = 25;
	if (position.x > 1250 && position.y < 165) position.x = 1250;
	if (position.x > 1255 && position.y < 166) position.x = 1255;
	if (position.x > 1260 && position.y < 167) position.x = 1260;
	if (position.x > 1265 && position.y < 168) position.x = 1265;
	if (position.x > 1280) position.x = 1280;
	if (position.y < 142) position.y = 142;
	if (position.y > 224) position.y = 224;

	// Hits
	if (App->input->keys[SDL_SCANCODE_X] == KEY_STATE::KEY_DOWN)
	{
		int x = (rand() % 2);
		if (x == 0) {
			if (currentAnimation != &hitAirAnim1R)
			{
			hitAirAnim1R.Reset();
			currentAnimation = &hitAirAnim1R;
			}
		}

		else if (x == 1) {
			if (currentAnimation != &hitAirAnim2R)
			{
				hitAirAnim2R.Reset();
				currentAnimation = &hitAirAnim2R;
			}
		}
	}

	// Moving the player

		// ALL MOVEMENT KEYS PRESSED
	if (App->input->keys[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT
		&& App->input->keys[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT
		&& App->input->keys[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT
		&& App->input->keys[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT)
	{
		if (currentAnimation != &idleAnimR)
		{
			idleAnimR.Reset();
			currentAnimation = &idleAnimR;
		}
		else currentAnimation = &idleAnimR;
	}

	else if ( App->input->keys[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT
		&& App->input->keys[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT
		&& App->input->keys[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT)
	{
		if (currentAnimation != &idleAnimR)
		{
			idleAnimR.Reset();
			currentAnimation = &idleAnimR;
		}
		else currentAnimation = &idleAnimR;
	}

	else if (App->input->keys[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT
		&& App->input->keys[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT
		&& App->input->keys[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT)
	{
		if (currentAnimation != &idleAnimR)
		{
			idleAnimR.Reset();
			currentAnimation = &idleAnimR;
		}
		else currentAnimation = &idleAnimR;
	}

	// UP & RIGHT MOVEMENT
	else if (App->input->keys[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT && App->input->keys[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT) 
	{
		position.x += speed;
		position.y -= speed;
		if (currentAnimation != &upAnimR)
		{
			upAnimR.Reset();
			currentAnimation = &upAnimR;
		}
	}

	// DOWN & RIGHT MOVEMENT
	else if (App->input->keys[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT && App->input->keys[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT)
	{
		position.x += speed;
		position.y += speed;
		if (currentAnimation != &downAnimR)
		{
			downAnimR.Reset();
			currentAnimation = &downAnimR;
		}
	}

	// LEFT & UP MOVEMENT
	else if (App->input->keys[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT && App->input->keys[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT)
	{
		position.x -= speed;
		position.y -= speed;
		if (currentAnimation != &upAnimL)
		{
			upAnimL.Reset();
			currentAnimation = &upAnimL;
		}
	}

	// LEFT & DOWN
	else if (App->input->keys[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT && App->input->keys[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT)
	{
		position.x -= speed;
		position.y += speed;
		if (currentAnimation != &downAnimL)
		{
			downAnimL.Reset();
			currentAnimation = &downAnimL;
		}
	}

	// LEFT & RIGHT PRESSED
	else if (App->input->keys[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT && App->input->keys[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT)
	{
		if (currentAnimation != &idleAnimR)
		{
			idleAnimR.Reset();
			currentAnimation = &idleAnimR;
		}
	}

	// UP & DOWN PRESSED
	else if (App->input->keys[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT && App->input->keys[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT)
	{
		if (currentAnimation != &idleAnimR)
		{
			idleAnimR.Reset();
			currentAnimation = &idleAnimR;
		}
	}

	// UP
	else if (App->input->keys[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT)
	{
		position.y -= speed;
		if (currentAnimation != &upAnimR)
		{
			upAnimR.Reset();
			currentAnimation = &upAnimR;
		}
	}

	// LEFT
	else if (App->input->keys[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT)
	{
		position.x -= speed;
		if (currentAnimation != &leftAnim)
		{
			leftAnim.Reset();
			currentAnimation = &leftAnim;
		}
	}

	// RIGHT
	else if (App->input->keys[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT)
	{
		position.x += speed;
		if (currentAnimation != &rightAnim)
		{
			rightAnim.Reset();
			currentAnimation = &rightAnim;
		}
	}

	// DOWN
	else if (App->input->keys[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT)
	{
		position.y += speed;
		if (currentAnimation != &downAnimR)
		{
			downAnimR.Reset();
			currentAnimation = &downAnimR;
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
		if (currentAnimation != &idleAnimR)
		{
			idleAnimR.Reset();
			currentAnimation = &idleAnimR;
		}

	}

	else if (App->input->keys[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_IDLE
		&& App->input->keys[SDL_SCANCODE_UP] == KEY_STATE::KEY_IDLE
		&& App->input->keys[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_IDLE
		&& App->input->keys[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_IDLE
		&& App->input->keys[SDL_SCANCODE_X] == KEY_STATE::KEY_IDLE)
	{
		if (currentAnimation != &idleAnimL)
		{
			idleAnimL.Reset();
			currentAnimation = &idleAnimL;
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