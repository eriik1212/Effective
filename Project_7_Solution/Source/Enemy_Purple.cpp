#include "Enemy_Purple.h"

#include "Application.h"
#include "ModuleCollisions.h"

Enemy_Purple::Enemy_Purple(int x, int y) : Enemy(x, y)
{

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

	/*back.PushBack({170, 108, 31, 29});
	back.PushBack({170, 141, 31, 29});
	back.PushBack({137, 108, 31, 29});
	back.speed = 0.1f;*/
	//back.pingpong = true;

	/*path.PushBack({-0.3f, 0.0f}, 150, &front);
	path.PushBack({1.2f, 0.0f}, 150, &back);*/
	

	collider = App->collisions->AddCollider({0, 0, 24, 24}, Collider::Type::ENEMY, (Module*)App->enemies);
}

void Enemy_Purple::Update()
{
	//path.Update();
	position = spawnPos + path.GetRelativePosition();
	currentAnim = &idleAnimR;
	
	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Enemy::Update();
}
