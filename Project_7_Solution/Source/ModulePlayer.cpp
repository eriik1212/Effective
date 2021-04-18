#include "ModulePlayer.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleParticles.h"
#include "ModuleAudio.h"
#include "ModuleCollisions.h"

#include "SDL/include/SDL_scancode.h"


ModulePlayer::ModulePlayer()
{
	srand(time(NULL));

	position.x = 100;
	position.y = 112;

	// ---------------------------------------------------------------------idle animation
	// RIGHT
	idleAnimR.PushBack({ 2, 0, 94, 84 });
	idleAnimR.PushBack({ 94, 0, 94, 84 });
	idleAnimR.PushBack({ 282, 0, 94, 84 });
	idleAnimR.PushBack({ 94, 0, 94, 84 });
	idleAnimR.PushBack({ 2, 0, 94, 84 });
	idleAnimR.PushBack({ 470, 0, 94, 84 });
	idleAnimR.PushBack({ 2, 0, 94, 84 });
	idleAnimR.PushBack({ 94, 0, 94, 84 });
	idleAnimR.PushBack({ 188, 0, 94, 84 });
	idleAnimR.PushBack({ 94, 0, 94, 84 });
	idleAnimR.PushBack({ 282, 0, 94, 84 });
	idleAnimR.PushBack({ 94, 0, 94, 84 });
	idleAnimR.PushBack({ 2, 0, 94, 84 });
	idleAnimR.loop = false;
	idleAnimR.speed = 0.02f;

	// LEFT
	idleAnimL.PushBack({ 1690, 1680, 94, 84 });
	idleAnimL.PushBack({ 1598, 1680, 94, 84 });
	idleAnimL.PushBack({ 1410, 1680, 94, 84 });
	idleAnimL.PushBack({ 1598, 1680, 94, 84 });
	idleAnimL.PushBack({ 1690, 1680, 94, 84 });
	idleAnimL.PushBack({ 1222, 1680, 94, 84 });
	idleAnimL.PushBack({ 1690, 1680, 94, 84 });
	idleAnimL.PushBack({ 1598, 1680, 94, 84 });
	idleAnimL.PushBack({ 1504, 1680, 94, 84 });
	idleAnimL.PushBack({ 1598, 1680, 94, 84 });
	idleAnimL.PushBack({ 1410, 1680, 94, 84 });
	idleAnimL.PushBack({ 1598, 1680, 94, 84 });
	idleAnimL.PushBack({ 1690, 1680, 94, 84 });
	idleAnimL.loop = false;
	idleAnimL.speed = 0.02f;
	//-----------------------------------------------------------------------------MOVE
	// move right
	rightAnim.PushBack({ 0, 924, 94, 84 });
	rightAnim.PushBack({ 94, 924, 94, 84 });
	rightAnim.PushBack({ 188, 924, 94, 84 });
	rightAnim.PushBack({ 282, 924, 94, 84 });
	rightAnim.PushBack({ 376, 924, 94, 84 });
	rightAnim.PushBack({ 470, 924, 94, 84 });
	rightAnim.PushBack({ 564, 924, 94, 84 });
	rightAnim.PushBack({ 658, 924, 94, 84 });
	rightAnim.loop = true;
	rightAnim.speed = 0.25f;

	// move left
	leftAnim.PushBack({ 1692, 2604, 94, 84 });
	leftAnim.PushBack({ 1598, 2604, 94, 84 });
	leftAnim.PushBack({ 1504, 2604, 94, 84 });
	leftAnim.PushBack({ 1410, 2604, 94, 84 });
	leftAnim.PushBack({ 1316, 2604, 94, 84 });
	leftAnim.PushBack({ 1222, 2604, 94, 84 });
	leftAnim.PushBack({ 1128, 2604, 94, 84 });
	leftAnim.PushBack({ 1034, 2604, 94, 84 });
	leftAnim.loop = true;
	leftAnim.speed = 0.25f;

	// move upwards
	// RIGHT
	upAnimR.PushBack({ 0, 1008, 94, 84 });
	upAnimR.PushBack({ 94, 1008, 94, 84 });
	upAnimR.PushBack({ 188, 1008, 94, 84 });
	upAnimR.PushBack({ 282, 1008, 94, 84 });
	upAnimR.PushBack({ 376, 1008, 94, 84 });
	upAnimR.PushBack({ 470, 1008, 94, 84 });
	upAnimR.PushBack({ 564, 1008, 94, 84 });
	upAnimR.PushBack({ 658, 1008, 94, 84 });
	upAnimR.loop = true;
	upAnimR.speed = 0.25f;

	//LEFT
	upAnimL.PushBack({ 1692, 2688, 94, 84 });
	upAnimL.PushBack({ 1598, 2688, 94, 84 });
	upAnimL.PushBack({ 1504, 2688, 94, 84 });
	upAnimL.PushBack({ 1410, 2688, 94, 84 });
	upAnimL.PushBack({ 1316, 2688, 94, 84 });
	upAnimL.PushBack({ 1222, 2688, 94, 84 });
	upAnimL.PushBack({ 1128, 2688, 94, 84 });
	upAnimL.PushBack({ 1034, 2688, 94, 84 });
	upAnimL.loop = true;
	upAnimL.speed = 0.25f;

	// Move down
	// RIGHT
	downAnimR.PushBack({ 0, 924, 94, 84 });
	downAnimR.PushBack({ 94, 924, 94, 84 });
	downAnimR.PushBack({ 188, 924, 94, 84 });
	downAnimR.PushBack({ 282, 924, 94, 84 });
	downAnimR.PushBack({ 376, 924, 94, 84 });
	downAnimR.PushBack({ 470, 924, 94, 84 });
	downAnimR.PushBack({ 564, 924, 94, 84 });
	downAnimR.PushBack({ 658, 924, 94, 84 });
	downAnimR.loop = true;
	downAnimR.speed = 0.25f;

	// LEFT
	downAnimL.PushBack({ 1692, 2604, 94, 84 });
	downAnimL.PushBack({ 1598, 2604, 94, 84 });
	downAnimL.PushBack({ 1504, 2604, 94, 84 });
	downAnimL.PushBack({ 1410, 2604, 94, 84 });
	downAnimL.PushBack({ 1316, 2604, 94, 84 });
	downAnimL.PushBack({ 1222, 2604, 94, 84 });
	downAnimL.PushBack({ 1128, 2604, 94, 84 });
	downAnimL.PushBack({ 1034, 2604, 94, 84 });
	downAnimL.loop = true;
	downAnimL.speed = 0.25f;

	//---------------------------------------------------------------------------- JUMP
	// Right
	InitjumpAnimR.PushBack({ 0, 588, 94, 84 });
	jumpAnimR.PushBack({ 94, 588, 94, 84 });
	jumpAnimR.PushBack({ 188, 588, 94, 84 });
	jumpAnimR.PushBack({ 282, 588, 94, 84 });
	jumpAnimR.PushBack({ 376, 588, 94, 84 });
	jumpAnimR.PushBack({ 470, 588, 94, 84 });
	jumpAnimR.PushBack({ 564, 588, 94, 84 });
	jumpAnimR.PushBack({ 658, 588, 94, 84 });
	jumpAnimR.PushBack({ 752, 588, 94, 84 });
	jumpAnimR.PushBack({ 846, 588, 94, 84 });


	jumpAnimR.loop = false;
	jumpAnimR.speed = 0.25f;

	// Left
	InitjumpAnimL.PushBack({ 1692, 2268, 94, 84 });
	jumpAnimL.PushBack({ 1598, 2268, 94, 84 });
	jumpAnimL.PushBack({ 1504, 2268, 94, 84 });
	jumpAnimL.PushBack({ 1410, 2268, 94, 84 });
	jumpAnimL.PushBack({ 1316, 2268, 94, 84 });
	jumpAnimL.PushBack({ 1222, 2268, 94, 84 });
	jumpAnimL.PushBack({ 1128, 2268, 94, 84 });
	jumpAnimL.PushBack({ 1034, 2268, 94, 84 });
	jumpAnimL.PushBack({ 940, 2268, 94, 84 });
	jumpAnimL.PushBack({ 846, 2268, 94, 84 });
	jumpAnimL.loop = false;
	jumpAnimL.speed = 0.25f;

	// Hit Air Animation 1
	hitAirAnim1R.PushBack({ 8, 336, 94, 84 });
	hitAirAnim1R.PushBack({ 94, 336, 94, 84 });
	hitAirAnim1R.PushBack({ 180, 336, 102, 84 });
	hitAirAnim1R.PushBack({ 282, 336, 102, 84 });
	hitAirAnim1R.PushBack({ 387, 336, 94, 84 });
	hitAirAnim1R.PushBack({ 485, 336, 94, 84 });
	hitAirAnim1R.loop = false;
	hitAirAnim1R.speed = 0.3f;

	// Hit Air Animation 2
	hitAirAnim2R.PushBack({ 0, 168, 94, 84 });
	hitAirAnim2R.PushBack({ 98, 168, 94, 84 });
	hitAirAnim2R.PushBack({ 192, 168, 94, 84 });
	hitAirAnim2R.PushBack({ 276, 168, 94, 84 });
	hitAirAnim2R.PushBack({ 370, 168, 94, 84 });
	hitAirAnim2R.PushBack({ 476, 168, 94, 84 });
	hitAirAnim2R.loop = false;
	hitAirAnim2R.speed = 0.3f;

	//------------------------------------------------------------------------------------- Hit Collide
	// 1R
	hitKickAnimR.PushBack({ 4, 84, 94, 84 });
	hitKickAnimR.PushBack({ 98, 84, 94, 84 });
	hitKickAnimR.PushBack({ 192, 84, 108, 84 });
	hitKickAnimR.PushBack({ 300, 84, 94, 84 });
	
	hitKickAnimR.loop = false;
	hitKickAnimR.speed = 0.2f;

	// 1L
	hitKickAnimL.PushBack({ 4, 84, 94, 84 });
	hitKickAnimL.PushBack({ 98, 84, 94, 84 });
	hitKickAnimL.PushBack({ 192, 84, 108, 84 });
	hitKickAnimL.PushBack({ 300, 84, 94, 84 });
	
	hitKickAnimL.loop = false;
	hitKickAnimL.speed = 0.2f;

	// 2R
	
}

ModulePlayer::~ModulePlayer()
{

}

bool ModulePlayer::Start()
{
	LOG("Loading player textures");

	bool ret = true;

	texture = App->textures->Load("Assets/Characters/Leonardo.png");
	currentAnimation = &idleAnimR;

	/*laserFx = App->audio->LoadFx("Assets/laser.wav");
	explosionFx = App->audio->LoadFx("Assets/explosion.wav");*/

	collider = App->collisions->AddCollider({ position.x, position.y, 32, 16 }, Collider::Type::PLAYER, this);

	return ret;
}

update_status ModulePlayer::Update()
{
	// Position Players Limits
	if (position.x < App->render->playerLimitL) position.x = App->render->playerLimitL;
	if (position.x > 1250) position.x = 1250;
	if (position.y < 56) position.y = 56;
	if (position.y > 136) position.y = 136;

	// Camera Movement
	if (position.x > (App->render->playerLimitR))
	{
		if (App->render->camera.x < CAMERA_LIMIT)
		{
			App->render->camera.x += App->render->cameraSpeed;
			App->render->playerLimitR += speed;
			App->render->playerLimitL += speed;
		}
	}

	// ------------------------------------------------------Hits RIGHT
	if (App->input->keys[SDL_SCANCODE_X] == KEY_STATE::KEY_DOWN && lastPosition == 0)
	{
		int x = (rand() % 2);

		switch (x)
		{
		case 0:
			if (currentAnimation != &hitAirAnim1R
				&& currentAnimation != &hitAirAnim2R)
			{
				hitAirAnim1R.Reset();
				currentAnimation = &hitAirAnim1R;
			}
			break;
		case 1:
			if (currentAnimation != &hitAirAnim2R
				&& currentAnimation != &hitAirAnim1R)
			{
				hitAirAnim2R.Reset();
				currentAnimation = &hitAirAnim2R;
			}
			break;
		default:
			break;
		}
	}

	// ------------------------------------------------------Hits LEFT
	if (App->input->keys[SDL_SCANCODE_X] == KEY_STATE::KEY_DOWN && lastPosition == 1)
	{
		int x = (rand() % 2);

		switch (x)
		{
		case 0:
			if (currentAnimation != &hitAirAnim1L 
				&& currentAnimation != &hitAirAnim2L)
			{
				hitAirAnim1L.Reset();
				currentAnimation = &hitAirAnim1L;
			}
			break;
		case 1:
			if (currentAnimation != &hitAirAnim2L
				&& currentAnimation != &hitAirAnim1L)
			{
				hitAirAnim2L.Reset();
				currentAnimation = &hitAirAnim2L;
			}
			break;
		default:
			break;
		}
	}




	// TEST HITS

	//--------------------------------------------------------------KICK RIGHT
	else if (App->input->keys[SDL_SCANCODE_C] == KEY_STATE::KEY_DOWN && lastPosition==0 )
	{
		if (currentAnimation != &hitKickAnimR)
		{
		
			currentAnimation = &hitKickAnimR;
			hitKickAnimR.Reset();
		
		}
		
	}
	else if (App->input->keys[SDL_SCANCODE_C] == KEY_STATE::KEY_UP && lastPosition == 0 )
	{
		
		currentAnimation = &idleAnimR;
		idleAnimR.Reset();
	}

	//--------------------------------------------------------------KICK LEFT
	else if (App->input->keys[SDL_SCANCODE_C] == KEY_STATE::KEY_DOWN && lastPosition == 1)
	{
		if (currentAnimation != &hitKickAnimR)
		{

			currentAnimation = &hitKickAnimR;
			hitKickAnimR.Reset();

		}

	}
	else if (App->input->keys[SDL_SCANCODE_C] == KEY_STATE::KEY_UP && lastPosition == 1)
	{

		currentAnimation = &idleAnimL;
		idleAnimL.Reset();

	}
	// Moving the player

	// ALL MOVEMENT KEYS PRESSED
	else if (App->input->keys[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT
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

	// THREE KEYS PRESSED
	else if (App->input->keys[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT
		&& App->input->keys[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT
		&& App->input->keys[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT)
	{
		position.y -= speed;
		if (currentAnimation != &upAnimR)
		{
			upAnimR.Reset();
			currentAnimation = &upAnimR;
		}
	}

	else if (App->input->keys[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT
		&& App->input->keys[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT
		&& App->input->keys[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT)
	{
		position.y += speed;
		if (currentAnimation != &downAnimR)
		{
			downAnimR.Reset();
			currentAnimation = &downAnimR;
		}
	}

	else if (App->input->keys[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT
		&& App->input->keys[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT
		&& App->input->keys[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT)
	{
		position.x -= speed;
		if (currentAnimation != &leftAnim)
		{
			leftAnim.Reset();
			currentAnimation = &leftAnim;
		}
	}

	else if (App->input->keys[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT
		&& App->input->keys[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT
		&& App->input->keys[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT)
	{
		position.x += speed;
		if (currentAnimation != &rightAnim)
		{
			rightAnim.Reset();
			currentAnimation = &rightAnim;
		}
	}

	// ---------------------------------------------JUMP RIGHT
	else if (App->input->keys[SDL_SCANCODE_Z] == KEY_STATE::KEY_REPEAT && lastPosition == 0)
	{
	position.y -= 2;
	if (currentAnimation != &InitjumpAnimR)
	{
		InitjumpAnimR.Reset();
		currentAnimation = &InitjumpAnimR;

	}
	}

	else if (App->input->keys[SDL_SCANCODE_Z] == KEY_STATE::KEY_UP && lastPosition == 0)
	{
	
	if (currentAnimation != &jumpAnimR)
	{
		jumpAnimR.Reset();
		currentAnimation = &jumpAnimR;
		
	}
	}

	// ---------------------------------------------JUMP LEFT
	else if (App->input->keys[SDL_SCANCODE_Z] == KEY_STATE::KEY_REPEAT && lastPosition == 1)
	{
	position.y -= 2;
	if (currentAnimation != &InitjumpAnimL)
	{
		InitjumpAnimL.Reset();
		currentAnimation = &InitjumpAnimL;

	}
	}

	else if (App->input->keys[SDL_SCANCODE_Z] == KEY_STATE::KEY_UP && lastPosition == 1)
	{

	if (currentAnimation != &jumpAnimR)
	{
		jumpAnimR.Reset();
		currentAnimation = &jumpAnimR;

	}
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
	lastPosition = 1;
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
	lastPosition = 0;

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


	// If no movement detected, set the current animation back to idle
	if (App->input->keys[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_IDLE
		&& App->input->keys[SDL_SCANCODE_UP] == KEY_STATE::KEY_IDLE
		&& App->input->keys[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_IDLE
		&& App->input->keys[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_IDLE
		&& App->input->keys[SDL_SCANCODE_X] == KEY_STATE::KEY_IDLE
		&& App->input->keys[SDL_SCANCODE_Z] == KEY_STATE::KEY_IDLE)
	{
		if (currentAnimation != &idleAnimR
			&& currentAnimation != &hitKickAnimR
			&& currentAnimation != &jumpAnimR)
		{
			switch (lastPosition) {

			case 1:
				idleAnimL.Reset();
				currentAnimation = &idleAnimL;
				break;

			case 0:
				idleAnimR.Reset();
				currentAnimation = &idleAnimR;
				break;
			}
			
		}
	}


	// Spawn explosion particles when pressing B
	/*if (App->input->keys[SDL_SCANCODE_B] == KEY_STATE::KEY_DOWN)
	{
		App->particles->AddParticle(App->particles->explosion, position.x, position.y + 25);
		App->particles->AddParticle(App->particles->explosion, position.x - 25, position.y, 30);
		App->particles->AddParticle(App->particles->explosion, position.x, position.y - 25, 60);
		App->particles->AddParticle(App->particles->explosion, position.x + 25, position.y, 90);
	}*/

	collider->SetPos(position.x, position.y);

	currentAnimation->Update();

	if (destroyed)
	{
		destroyedCountdown--;
		if (destroyedCountdown <= 0)
			return update_status::UPDATE_STOP;
	}

	return update_status::UPDATE_CONTINUE;
}

update_status ModulePlayer::PostUpdate()
{
	if (!destroyed)
	{
		SDL_Rect rect = currentAnimation->GetCurrentFrame();
		App->render->Blit(texture, position.x, position.y, &rect);
	}

	return update_status::UPDATE_CONTINUE;
}

void ModulePlayer::OnCollision(Collider* c1, Collider* c2)
{
	if (c1 == collider && destroyed == false)
	{
		App->particles->AddParticle(App->particles->explosion, position.x, position.y, Collider::Type::NONE, 9);
		App->particles->AddParticle(App->particles->explosion, position.x + 8, position.y + 11, Collider::Type::NONE, 14);
		App->particles->AddParticle(App->particles->explosion, position.x - 7, position.y + 12, Collider::Type::NONE, 40);
		App->particles->AddParticle(App->particles->explosion, position.x + 5, position.y - 5, Collider::Type::NONE, 28);
		App->particles->AddParticle(App->particles->explosion, position.x - 4, position.y - 4, Collider::Type::NONE, 21);

		App->audio->PlayFx(explosionFx);

		destroyed = true;
	}
}