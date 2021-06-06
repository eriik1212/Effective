#include "Enemy_Boss.h"

#include "Application.h"
#include "ModuleCollisions.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"

Enemy_Boss::Enemy_Boss(int x, int y) : Enemy(x, y)
{

	
	// RIGHT
	rightAnimP.PushBack({ 0, 453, 86, 90 });
	rightAnimP.PushBack({ 86, 453, 86, 90 });
	rightAnimP.PushBack({ 86 * 2, 453, 86, 90 });
	rightAnimP.PushBack({ 86 * 3, 453, 86, 90 });
	rightAnimP.PushBack({ 86 * 4, 453, 86, 90 });
	rightAnimP.PushBack({ 86 * 5, 453, 86, 90 });
	rightAnimP.PushBack({ 86 * 6, 453, 86, 90 });
	rightAnimP.PushBack({ 86 * 7, 453, 86, 90 });
	rightAnimP.loop = true;
	rightAnimP.speed = 0.15f;

	
	//PATH

	
	
	
	

	collider = App->collisions->AddCollider({ 0, 0, 38, 16 }, Collider::Type::ENEMY, (Module*)App->enemies);
	HIT = App->collisions->AddCollider({ 200, 122, 18, 16 }, Collider::Type::ENEMY_HIT, (Module*)App->enemies);

}

void Enemy_Boss::Update()
{

	//-----------------------------------------------------------------------AI
	if (retirar == true)
		currentAnim = &dieFacefwRP;

	//---------------------------------------------------------------------HIT ENEMY
	if (tocado == true && direcction == 1 && currentAnim != &dieFacefwRP && nohit < 0.0f)
	{
		position.x -= 40;
		currentAnim = &dieFacefwRP;
		dieFacefwRP.Reset();
		App->collisions->matrix[Collider::Type::PLAYER][Collider::Type::ENEMY_HIT] = false;
		nohit = 10.0f;
	}

	else if (tocado == true && direcction == 0 && currentAnim != &dieFacefwLP && nohit < 0.0f)
	{
		currentAnim = &dieFacefwLP;
		dieFacefwLP.Reset();
		App->collisions->matrix[Collider::Type::PLAYER][Collider::Type::ENEMY_HIT] = false;
		position.x += 40;
		nohit = 10.0f;
	}

	else
	{
		tocado = false;
		nohit -= 0.1f;
	}

	//--------------------------------------------------------------- ENEMY MOVE
	//-----------------------------------------------------x
	if (time <= 0 && tocado != true && nohit < 0.0f)
	{

		if (position.x + 15 == App->player->position.x)
		{
			App->player->position.x - 100;
			position.x -= velociti;

		}
		if (position.x - 15 == App->player->position.x)
		{
			App->player->position.x + 100;
			position.x += velociti;

		}

		if (position.x + 15 < App->player->position.x)
		{
			position.x += velociti;
			direcction = 1;
			currentAnim = &rightAnimP;

		}
		if (position.x - 15 > App->player->position.x)
		{
			position.x -= velociti;
			direcction = 0;
			currentAnim = &leftAnimP;


		}

		//-----------------------------------------------------y
		if (position.y < App->player->position.y - 16)
		{

			position.y += velociti;
			if (position.x + 10 > App->player->position.x)
			{
				direcction = 0;

			}

			else if (position.x - 10 < App->player->position.x)
			{
				direcction = 1;

			}

		}
		if (position.y > App->player->position.y)
		{
			position.y -= velociti;
			if (position.x + 20 > App->player->position.x)
			{
				direcction = 0;
				currentAnim = &upAnimLP;
			}



			else if (position.x - 20 < App->player->position.x)
			{
				direcction = 1;
				currentAnim = &upAnimRP;
			}


		}
	}



	//------------------------------------------------------------LEFT direcction
	if (currentAnim == &jumpLP)direcction = 0;
	if (currentAnim == &leftAnimP)direcction = 0;
	if (currentAnim == &punchLP)direcction = 0;
	if (currentAnim == &kickLP)direcction = 0;
	if (currentAnim == &upAnimLP)direcction = 0;
	//------------------------------------------------------------LEFT ANIM direction
	if (currentAnim == &upAnimRP)direcction = 1;
	if (currentAnim == &kickRP)direcction = 1;


	if (App->collisions->GodMode == true) {


		App->collisions->matrix[Collider::Type::PLAYER][Collider::Type::ENEMY_HIT] = false;

		if (coolTime >= coolDown && time <= 0.0f && position.x >= App->player->position.x + 38 && position.x + 38 <= App->player->position.x && App->collisions->matrix[Collider::Type::PLAYER][Collider::Type::ENEMY_HIT] == false && tocado != true && nohit < 0.0f ||
			coolTime >= coolDown && time <= 0.0f && position.x >= App->player->position.x - 38 && position.x - 38 <= App->player->position.x && App->collisions->matrix[Collider::Type::PLAYER][Collider::Type::ENEMY_HIT] == false && tocado != true && nohit < 0.0f) {
			
			
				if (direcction == 0 && currentAnim != &kickLP)
				{
					currentAnim = &kickLP;
					App->collisions->matrix[Collider::Type::PLAYER][Collider::Type::ENEMY_HIT] = true;
					coolTime = 0.0f;
					kickLP.Reset();
					time = 2.0f;
				
				}

				else if (direcction == 1 && currentAnim != &kickRP)
				{
					currentAnim = &kickRP;
					App->collisions->matrix[Collider::Type::PLAYER][Collider::Type::ENEMY_HIT] = true;
					coolTime = 0.0f;
					kickRP.Reset();
					time = 2.0f;
				
				}
				else
					App->collisions->matrix[Collider::Type::PLAYER][Collider::Type::ENEMY_HIT] = false;

			

		


		}
		else {
		
			
			velociti = 1.0f;
			coolTime += 0.1f;
		
			time -= 0.1f;
			
		}

	}


	
	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Enemy::Update();
}
