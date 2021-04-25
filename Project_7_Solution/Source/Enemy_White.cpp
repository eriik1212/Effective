#include "Enemy_White.h"

#include "Application.h"
#include "ModuleCollisions.h"

Enemy_White::Enemy_White(int x, int y) : Enemy(x, y)
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

	
	collider = App->collisions->AddCollider({ 0, 0, 38, 16 }, Collider::Type::ENEMY, (Module*)App->enemies);
}

void Enemy_White::Update()
{
	path.Update();
	position = spawnPos + path.GetRelativePosition();
	currentAnim = &idleAnimR;

	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Enemy::Update();
}
