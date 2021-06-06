#include "Enemy_Purple.h"

#include "Application.h"
#include "ModuleCollisions.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"

Enemy_Purple::Enemy_Purple(int x, int y) : Enemy(x, y)
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

	//LEFT
	leftAnimP.PushBack({1032,1890,86,90});
	leftAnimP.PushBack({ 1032-86,1890,86,90 });
	leftAnimP.PushBack({ 1032 - 86 * 2,1890,86,90 });
	leftAnimP.PushBack({ 1032 - 86 * 3,1890,86,90 });
	leftAnimP.PushBack({ 1032 - 86 * 4,1890,86,90 });
	leftAnimP.PushBack({ 1032 - 86 * 5,1890,86,90 });
	leftAnimP.PushBack({ 1032 - 86 * 6,1890,86,90 });
	leftAnimP.PushBack({ 1032 - 86 * 7,1890,86,90 });
	leftAnimP.loop = true;
	leftAnimP.speed = 0.15f;

	//UP LEFT
	upAnimLP.PushBack({ 1032,1980,86,90 });
	upAnimLP.PushBack({ 1032 - 86,1980,86,90 });
	upAnimLP.PushBack({ 1032 - 86 * 2,1980,86,90 });
	upAnimLP.PushBack({ 1032 - 86 * 3,1980,86,90 });
	upAnimLP.PushBack({ 1032 - 86 * 4,1980,86,90 });
	upAnimLP.PushBack({ 1032 - 86 * 5,1980,86,90 });
	upAnimLP.PushBack({ 1032 - 86 * 6,1980,86,90 });
	upAnimLP.PushBack({ 1032 - 86 * 7,1980,86,90 });
	upAnimLP.loop = true;
	upAnimLP.speed = 0.15f;

	//UP RIGHT
	upAnimRP.PushBack({ 0, 540, 86, 90 });
	upAnimRP.PushBack({ 86, 540, 86, 90 });
	upAnimRP.PushBack({ 86 * 2, 540, 86, 90 });
	upAnimRP.PushBack({ 86 * 3, 540, 86, 90 });
	upAnimRP.PushBack({ 86 * 4, 540, 86, 90 });
	upAnimRP.PushBack({ 86 * 5, 540, 86, 90 });
	upAnimRP.PushBack({ 86 * 6, 540, 86, 90 });
	upAnimRP.PushBack({ 86 * 7, 540, 86, 90 });
	upAnimRP.loop = true;
	upAnimRP.speed = 0.15f;


	//RIGHT KICK
	kickRP.PushBack({ 0, 90, 86, 90 });
	kickRP.PushBack({ 86, 90, 86, 90 });
	kickRP.PushBack({ 86 * 2, 90, 86, 90 });
	kickRP.PushBack({ 86 * 3, 90, 86, 90 });
	kickRP.loop = false; //it can be true
	kickRP.speed = 0.15f;

	//LEFT KICK
	kickLP.PushBack({ 1032,1530,86,90 });
	kickLP.PushBack({ 1032 - 86,1530,86,90 });
	kickLP.PushBack({ 1032 - 86 * 2,1530,86,90 });
	kickLP.PushBack({ 1032 - 86 * 3,1530,86,90 });
	kickLP.loop = false; //it can be true
	kickLP.speed = 0.15f;

	//LEFT PUNCH
	punchLP.PushBack({ 1032, 2790, 86, 90 });
	punchLP.PushBack({ 1032 - 86, 2790, 86, 90 });
	punchLP.PushBack({ 1032 - 86 * 2, 2790, 86, 90 });
	punchLP.PushBack({ 1032 - 86 * 3, 2790, 86, 90 });
	punchLP.PushBack({ 1032 - 86 * 4, 2790, 86, 90 });
	punchLP.PushBack({ 1032 - 86 * 5, 2790, 86, 90 });
	punchLP.PushBack({ 1032 - 86 * 6, 2790, 86, 90 });
	punchLP.PushBack({ 1032 - 86 * 7, 2790, 86, 90 });
	punchLP.PushBack({ 1032 - 86 * 8, 2790, 86, 90 });
	punchLP.PushBack({ 1032 - 86 * 9, 2790, 86, 90 });
	punchLP.loop = true; //it can be true
	punchLP.speed = 0.15f;

	//RIGHT PUNCH
	punchRP.PushBack({ 0, 1350, 86, 90 });
	punchRP.PushBack({ 86, 1350, 86, 90 });
	punchRP.PushBack({ 86 * 2, 1350, 86, 90 });
	punchRP.PushBack({ 86 * 3, 1350, 86, 90 });
	punchRP.PushBack({ 86 * 4, 1350, 86, 90 });
	punchRP.PushBack({ 86 * 5, 1350, 86, 90 });
	punchRP.PushBack({ 86 * 6, 1350, 86, 90 });
	punchRP.PushBack({ 86 * 7, 1350, 86, 90 });
	punchRP.PushBack({ 86 * 8, 1350, 86, 90 });
	punchRP.PushBack({ 86 * 9, 1350, 86, 90 });
	punchRP.loop = true; //it can be true
	punchRP.speed = 0.15f;

	//RIGHT JUMP
	jumpRP.PushBack({ 0, 900, 86, 90 });
	jumpRP.PushBack({ 86, 900, 86, 90 });
	jumpRP.PushBack({ 86 * 2, 900, 86, 90 });
	jumpRP.PushBack({ 86 * 3, 900, 86, 90 });
	jumpRP.PushBack({ 86 * 4, 900, 86, 90 });
	jumpRP.PushBack({ 86 * 5, 900, 86, 90 });
	jumpRP.PushBack({ 86 * 6, 900, 86, 90 });
	jumpRP.loop = false; //it can be true
	jumpRP.speed = 0.15f;

	//LEFT JUMP
	jumpLP.PushBack({ 1032,2340,86,90 });
	jumpLP.PushBack({ 1032 - 86,2340,86,90 });
	jumpLP.PushBack({ 1032 - 86 * 2,2340,86,90 });
	jumpLP.PushBack({ 1032 - 86 * 3,2340,86,90 });
	jumpLP.PushBack({ 1032 - 86 * 4,2340,86,90 });
	jumpLP.PushBack({ 1032 - 86 * 5,2340,86,90 });
	jumpLP.PushBack({ 1032 - 86 * 6,2340,86,90 });
	jumpLP.loop = true; //it can be true
	jumpLP.speed = 0.15f;

	//FROM LEFT HIT
	hitLP.PushBack({ 1032,1440,86,90 });
	hitLP.PushBack({ 1032-86,1440,86,90 });
	hitLP.PushBack({ 1032-86 * 2,1440,86,90 });
	hitLP.PushBack({ 1032-87 * 3,1440,86,90 });
	hitLP.loop = false;
	hitLP.speed = 0.15f;

	//FROM RIGHT HIT
	hitRP.PushBack({ 0,0,86,90 });
	hitRP.PushBack({ 86,0,86,90 });
	hitRP.PushBack({ 86 * 2,0,86,90 });
	hitRP.PushBack({ 86 * 3,0,86,90 });
	hitRP.loop = false;
	hitRP.speed = 0.15f;

	//DIE FACE FORWARD TO LEFT
	dieFacefwLP.PushBack({ 0,270,86,90});
	dieFacefwLP.PushBack({ 86,270,86,90});
	dieFacefwLP.PushBack({ 86 * 2,270,86,90});
	dieFacefwLP.PushBack({ 86 * 3,270,86,90 });
	dieFacefwLP.PushBack({ 86 * 4,270,86,90 });
	dieFacefwLP.PushBack({ 86 * 5,270,86,90 });
	dieFacefwLP.PushBack({ 86 * 6,270,86,90 });
	dieFacefwLP.loop = false;
	dieFacefwLP.speed = 0.15f;

	//DIE FACE FORWARD TO RIGHT
	dieFacefwRP.PushBack({ 1032,1710,86,90 });
	dieFacefwRP.PushBack({ 1032 - 86,1710,86,90 });
	dieFacefwRP.PushBack({ 1032 - 86 * 2,1710,86,90 });
	dieFacefwRP.PushBack({ 1032 - 86 * 3,1710,86,90 });
	dieFacefwRP.PushBack({ 1032 - 86 * 4,1710,86,90 });
	dieFacefwRP.PushBack({ 1032 - 86 * 5,1710,86,90 });
	dieFacefwRP.PushBack({ 1032 - 86 * 6,1710,86,90 });
	dieFacefwRP.loop = false;
	dieFacefwRP.speed = 0.15f;


	

	collider = App->collisions->AddCollider({0, 0, 38, 16}, Collider::Type::ENEMY, (Module*)App->enemies);
	HIT = App->collisions->AddCollider({ 200, 122, 18, 16 }, Collider::Type::ENEMY_HIT, (Module*)App->enemies);
	
}

void Enemy_Purple::Update()
{
	//-----------------------------------------------------------------------AI
	//-----------------------------------------------------x

	

	if (tocado == true && direcction == 1 && currentAnim != &dieFacefwRP && nohit <0.0f)
	{
		position.x -= 40;
		currentAnim = &dieFacefwRP;
		dieFacefwRP.Reset();
		
		nohit = 10.0f;
	}
	else if (tocado == true && direcction == 0 && currentAnim != &dieFacefwLP && nohit < 0.0f)
	{
		currentAnim = &dieFacefwLP;
		dieFacefwLP.Reset();

		position.x += 40;
		nohit = 10.0f;
	}
	else
	{
		tocado = false;
		nohit -= 0.1f;
	}
	if ( time <= 0 && tocado != true && nohit < 0.0f) {

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
		if (position.y  < App->player->position.y - 16)
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

			if (direcction==0 && currentAnim != &kickLP)
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
			coolTime += 0.1f;
			time -= 0.1f;
		}
			
	}

	
	
	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Enemy::Update();
}
