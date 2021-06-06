#include "Enemy_Boss.h"

#include "Application.h"
#include "ModuleCollisions.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"

Enemy_Boss::Enemy_Boss(int x, int y) : Enemy(x, y)
{

<<<<<<< HEAD
	
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

	
	
	
	
=======
	// IDLE RIGHT
	idleAnimRB.PushBack({ 0, 0, 67, 106 });
	idleAnimRB.PushBack({ 67, 0, 67, 106 });
	idleAnimRB.PushBack({ 67 * 2, 0, 67, 106 });
	idleAnimRB.PushBack({ 67 * 3, 0, 67, 106 });
	idleAnimRB.PushBack({ 67 * 4, 0, 67, 106 });
	idleAnimRB.PushBack({ 67 * 5, 0, 67, 106 });
	idleAnimRB.loop = true;
	idleAnimRB.speed = 0.25f;

	// IDLE LEFT
	idleAnimLB.PushBack({ 957, 1836, 67, 106 });
	idleAnimLB.PushBack({ 957 - 67 * 1, 1836, 67, 106 });
	idleAnimLB.PushBack({ 957 - 67 * 2, 1836, 67, 106 });
	idleAnimLB.PushBack({ 957 - 67 * 3, 1836, 67, 106 });
	idleAnimLB.PushBack({ 957 - 67 * 4, 1836, 67, 106 });
	idleAnimLB.PushBack({ 957 - 67 * 5, 1836, 67, 106 });
	idleAnimLB.loop = true;
	idleAnimLB.speed = 0.25f;

	// RIGHT
	rightAnimB.PushBack({ 0, 106, 67, 106 });
	rightAnimB.PushBack({ 67, 106, 67, 106 });
	rightAnimB.PushBack({ 67 * 2, 106, 67, 106 });
	rightAnimB.PushBack({ 67 * 3, 106, 67, 106 });
	rightAnimB.PushBack({ 67 * 4, 106, 67, 106 });
	rightAnimB.PushBack({ 67 * 5, 106, 67, 106 });
	rightAnimB.loop = true;
	rightAnimB.speed = 0.25f;

	// LEFT
	leftAnimB.PushBack({ 957, 1942, 67, 106 });
	leftAnimB.PushBack({ 957 - 67, 1942, 67, 106 });
	leftAnimB.PushBack({ 957 - 67 * 2, 1942, 67, 106 });
	leftAnimB.PushBack({ 957 - 67 * 3, 1942, 67, 106 });
	leftAnimB.PushBack({ 957 - 67 * 4, 1942, 67, 106 });
	leftAnimB.PushBack({ 957 - 67 * 5, 1942, 67, 106 });
	leftAnimB.loop = true;
	leftAnimB.speed = 0.25f;

	// KICK RIGHT
	kickRB.PushBack({ 469, 0, 67, 106 });
	kickRB.PushBack({ 469 + 67, 0, 74, 106 });
	kickRB.loop = true;
	kickRB.speed = 0.25f;

	// KICK RIGHT GUN
	kickGunRB.PushBack({ 670, 0, 71, 106 });
	kickGunRB.PushBack({ 744, 0, 82, 106 });
	kickGunRB.loop = true;
	kickGunRB.speed = 0.25f;

	// KICK LEFT
	kickLB.PushBack({ 487, 1836, 67, 106 });
	kickLB.PushBack({ 413, 1836, 74, 106 });
	kickLB.loop = true;
	kickLB.speed = 0.25f;

	// KICK LEFT GUN
	kickGunLB.PushBack({ 282, 1836, 71, 106 });
	kickGunLB.PushBack({ 197, 1836, 82, 106 });
	kickGunLB.loop = true;
	kickGunLB.speed = 0.25f;

	// EMBESTIDA LEFT
	embestidaLB.PushBack({ 957, 2048, 67, 106 });
	embestidaLB.PushBack({ 957 - 67, 2048, 67, 106 });
	embestidaLB.PushBack({ 957 - 67 * 2, 2048, 67, 106 });
	embestidaLB.PushBack({ 957 - 67 * 3, 2048, 67, 106 });
	embestidaLB.loop = true;
	embestidaLB.speed = 0.25f;

	// EMBESTIDA RIGHT
	embestidaRB.PushBack({ 0, 212, 67, 106 });
	embestidaRB.PushBack({ 67, 212, 67, 106 });
	embestidaRB.PushBack({ 67 * 2, 212, 67, 106 });
	embestidaRB.PushBack({ 67 * 3, 212, 67, 106 });
	embestidaRB.loop = true;
	embestidaRB.speed = 0.25f;


	// HITTED LOW LEFT
	hittedLowLB.PushBack({ 957, 2154, 67, 106 });
	hittedLowLB.PushBack({ 957, 2154, 67, 106 });
	hittedLowLB.loop = true;
	hittedLowLB.speed = 0.25f;

	// HITTED LOW RIGHT
	hittedLowRB.PushBack({ 0, 318, 67, 106 });
	hittedLowRB.PushBack({ 0, 318, 67, 106 });
	hittedLowRB.loop = true;
	hittedLowRB.speed = 0.25f;

	// DIE RIGHT
	dieRB.PushBack({ 0, 318, 67, 106 });
	dieRB.PushBack({ 67*2, 318, 67, 106 });
	dieRB.PushBack({ 402, 318, 67, 106 });
	dieRB.loop = false;
	dieRB.speed = 0.25f;

	// DIE LEFT
	dieLB.PushBack({ 957, 2154, 67, 106 });
	dieLB.PushBack({ 823, 2154, 67, 106 });
	dieLB.PushBack({ 555, 2154, 67, 106 });
	dieLB.loop = false;
	dieLB.speed = 0.25f;

>>>>>>> 940ac04f51c1bd4fbf227ca701eb4b2c1f7541ca

	collider = App->collisions->AddCollider({ 0, 0, 38, 16 }, Collider::Type::ENEMY, (Module*)App->enemies);
	HIT = App->collisions->AddCollider({ 200, 122, 18, 16 }, Collider::Type::ENEMY_HIT, (Module*)App->enemies);

}

void Enemy_Boss::Update()
{

<<<<<<< HEAD
	//-----------------------------------------------------------------------AI
	if (retirar == true)
		//	currentAnim = &dieFacefwRP;

	//---------------------------------------------------------------------HIT ENEMY
	if (tocado == true && direcction == 1 && currentAnim != &dieFacefwRP && nohit < 0.0f)
	{
		position.x -= 40;
			//currentAnim = &dieFacefwRP;
			//dieFacefwRP.Reset();
		App->collisions->matrix[Collider::Type::PLAYER][Collider::Type::ENEMY_HIT] = false;
		nohit = 10.0f;
	}

	else if (tocado == true && direcction == 0 && currentAnim != &dieFacefwLP && nohit < 0.0f)
	{
			//currentAnim = &dieFacefwLP;
			//dieFacefwLP.Reset();
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
				//currentAnim = &rightAnimP;

		}
		if (position.x - 15 > App->player->position.x)
		{
			position.x -= velociti;
			direcction = 0;
				//currentAnim = &leftAnimP;


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
				//currentAnim = &upAnimLP;
			}



			else if (position.x - 20 < App->player->position.x)
			{
				direcction = 1;
				//currentAnim = &upAnimRP;
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
						//currentAnim = &kickLP;
					App->collisions->matrix[Collider::Type::PLAYER][Collider::Type::ENEMY_HIT] = true;
					coolTime = 0.0f;
					//	kickLP.Reset();
					time = 2.0f;
				
				}

				else if (direcction == 1 && currentAnim != &kickRP)
				{
						//currentAnim = &kickRP;
					App->collisions->matrix[Collider::Type::PLAYER][Collider::Type::ENEMY_HIT] = true;
					coolTime = 0.0f;
					//	kickRP.Reset();
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


	
=======
>>>>>>> 940ac04f51c1bd4fbf227ca701eb4b2c1f7541ca
	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Enemy::Update();
}
