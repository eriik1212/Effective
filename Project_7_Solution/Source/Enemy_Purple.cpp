#include "Enemy_Purple.h"

#include "Application.h"
#include "ModuleCollisions.h"
#include "ModuleParticles.h"

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

	

	path.PushBack({-1.2f, 0.0f}, 150, &rightAnimP);
	path.PushBack({1.2f, 0.0f}, 150, &rightAnimP);
	

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
		App->particles->AddParticle(App->particles->suriken, position.x + 20, position.y+74, Collider::Type::ENEMY_SHOT);
	
	}
	else 
	{
		coolTime += 0.1;

	}

	path.Update();
	position = spawnPos + path.GetRelativePosition();
	currentAnim = path.GetCurrentAnimation();
	
	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Enemy::Update();
}
