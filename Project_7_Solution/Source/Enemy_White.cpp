#include "Enemy_White.h"

#include "Application.h"
#include "ModuleCollisions.h"

Enemy_White::Enemy_White(int x, int y) : Enemy(x, y)
{

	// RIGHT
	idleAnimRW.PushBack({ 2, 0, 94, 84 });
	idleAnimRW.PushBack({ 94, 0, 94, 84 });
	idleAnimRW.PushBack({ 282, 0, 94, 84 });
	idleAnimRW.PushBack({ 94, 0, 94, 84 });
	idleAnimRW.PushBack({ 2, 0, 94, 84 });
	idleAnimRW.PushBack({ 470, 0, 94, 84 });
	idleAnimRW.PushBack({ 2, 0, 94, 84 });
	idleAnimRW.PushBack({ 94, 0, 94, 84 });
	idleAnimRW.PushBack({ 188, 0, 94, 84 });
	idleAnimRW.PushBack({ 94, 0, 94, 84 });
	idleAnimRW.PushBack({ 282, 0, 94, 84 });
	idleAnimRW.PushBack({ 94, 0, 94, 84 });
	idleAnimRW.PushBack({ 2, 0, 94, 84 });
	idleAnimRW.loop = false;
	idleAnimRW.speed = 0.02f;

	

	
	collider = App->collisions->AddCollider({ 0, 0, 38, 16 }, Collider::Type::ENEMY, (Module*)App->enemies);
}

void Enemy_White::Update()
{
	path.Update();
	position = spawnPos + path.GetRelativePosition();
	currentAnim = &idleAnimRW;

	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Enemy::Update();
}
