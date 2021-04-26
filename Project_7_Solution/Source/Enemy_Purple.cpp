#include "Enemy_Purple.h"

#include "Application.h"
#include "ModuleCollisions.h"

Enemy_Purple::Enemy_Purple(int x, int y) : Enemy(x, y)
{

	// RIGHT
	leftAnimP.PushBack({ 2, 0, 94, 84 });
	leftAnimP.PushBack({ 94, 0, 94, 84 });
	leftAnimP.PushBack({ 282, 0, 94, 84 });
	leftAnimP.PushBack({ 94, 0, 94, 84 });
	leftAnimP.PushBack({ 2, 0, 94, 84 });
	leftAnimP.PushBack({ 470, 0, 94, 84 });
	leftAnimP.PushBack({ 2, 0, 94, 84 });
	leftAnimP.PushBack({ 94, 0, 94, 84 });
	leftAnimP.PushBack({ 188, 0, 94, 84 });
	leftAnimP.PushBack({ 94, 0, 94, 84 });
	leftAnimP.PushBack({ 282, 0, 94, 84 });
	leftAnimP.PushBack({ 94, 0, 94, 84 });
	leftAnimP.PushBack({ 2, 0, 94, 84 });
	leftAnimP.loop = false;
	leftAnimP.speed = 0.02f;

	/*back.PushBack({170, 108, 31, 29});
	back.PushBack({170, 141, 31, 29});
	back.PushBack({137, 108, 31, 29});
	back.speed = 0.1f;*/
	//back.pingpong = true;

	//path.PushBack({-1.2f, 0.0f}, 150, &idleAnimR);
	//path.PushBack({1.2f, 0.0f}, 150, &idleAnimR);
	

	collider = App->collisions->AddCollider({0, 0, 38, 16}, Collider::Type::ENEMY, (Module*)App->enemies);
	HIT = App->collisions->AddCollider({ 200, 122, 40, 16 }, Collider::Type::ENEMY_SHOT, (Module*)App->enemies);
	//SEE = App->collisions->AddCollider({ 150, 122, 70, 16 }, Collider::Type::SEE, (Module*)App->enemies);
}

void Enemy_Purple::Update()
{

	App->collisions->matrix[Collider::Type::PLAYER][Collider::Type::ENEMY_SHOT] = false;

	if (coolTime >= coolDown) 
	{
		App->collisions->matrix[Collider::Type::PLAYER][Collider::Type::ENEMY_SHOT] = true;
		coolTime = 0;	
		
	}
	else 
	{
		coolTime += 0.1;

	}

	path.Update();
	position = spawnPos + path.GetRelativePosition();
	currentAnim = &leftAnimP;
	
	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Enemy::Update();
}
