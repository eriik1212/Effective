#include "Enemy_White.h"

#include "Application.h"
#include "ModuleCollisions.h"

Enemy_White::Enemy_White(int x, int y) : Enemy(x, y)
{

	//Walking right and down right anim
	rightAnimW.PushBack({ 0,0,98,88});
	rightAnimW.PushBack({ 98,0,98,88 });
	rightAnimW.PushBack({ 196,0,98,88 });
	rightAnimW.PushBack({ 294,0,98,88 });
	rightAnimW.PushBack({ 392,0,98,88 });
	rightAnimW.PushBack({ 490,0,98,88 });
	rightAnimW.PushBack({ 588,0,98,88 });
	rightAnimW.PushBack({ 686,0,98,88 });
	rightAnimW.loop = true;
	rightAnimW.speed = 0.15f;

	//Walking left and down left anim
	leftAnimW.PushBack({ 784,1145,98,88});
	leftAnimW.PushBack({ 784-98,1145,98,88 });
	leftAnimW.PushBack({ 784-98*2,1145,98,88 });
	leftAnimW.PushBack({ 784-98*3,1145,98,88 });
	leftAnimW.PushBack({ 784-98*4,1145,98,88 });
	leftAnimW.PushBack({ 784-98*5,1145,98,88 });
	leftAnimW.PushBack({ 784-98*6,1145,98,88 });
	leftAnimW.PushBack({ 784-98*7,1145,98,88 });
	leftAnimW.loop = true;
	leftAnimW.speed = 0.15f;

	//Walking up left anim 
	upAnimLW.PushBack({ 880, 1233, 98, 88 });
	upAnimLW.PushBack({ 880 + 98,1233,98,88 });
	upAnimLW.PushBack({ 880 + 98 * 2,1233,98,88 });
	upAnimLW.PushBack({ 880 + 98 * 3,1233,98,88 });
	upAnimLW.PushBack({ 880 + 98 * 4,1233,98,88 });
	upAnimLW.PushBack({ 880 + 98 * 5,1233,98,88 });
	upAnimLW.PushBack({ 880 + 98 * 6,1233,98,88 });
	upAnimLW.PushBack({ 880 + 98 * 7,1233,98,88 });
	upAnimLW.loop = true;
	upAnimLW.speed = 0.15f;

	//Walking up right anim 
	upAnimRW.PushBack({0,89,98,88});
	upAnimRW.PushBack({98,89,98,88});
	upAnimRW.PushBack({98*2,89,98,88 });
	upAnimRW.PushBack({98*3,89,98,88 });
	upAnimRW.PushBack({98*4,89,98,88 });
	upAnimRW.PushBack({98*5,89,98,88 });
	upAnimRW.PushBack({98*6,89,98,88 });
	upAnimRW.PushBack({98*7,89,98,88 });
	upAnimRW.loop = true;
	upAnimRW.speed = 0.15f;

	
	path.PushBack({ -1.0f, 0.0f }, 150, &leftAnimW);
	path.PushBack({ 1.0f,0.0f }, 150, &rightAnimW);

	
	collider = App->collisions->AddCollider({ 0, 0, 38, 16 }, Collider::Type::ENEMY, (Module*)App->enemies);
}

void Enemy_White::Update()
{

	path.Update();
	position = spawnPos + path.GetRelativePosition();
	currentAnim = path.GetCurrentAnimation();
	

	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Enemy::Update();
}
