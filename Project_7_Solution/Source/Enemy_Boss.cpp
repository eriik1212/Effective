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
	path.PushBack({0.0f, 0.0f }, 45, &jumpLP);
	

	collider = App->collisions->AddCollider({ 0, 0, 38, 16 }, Collider::Type::ENEMY, (Module*)App->enemies);
	HIT = App->collisions->AddCollider({ 200, 122, 18, 16 }, Collider::Type::ENEMY_HIT, (Module*)App->enemies);

}

void Enemy_Boss::Update()
{

	
	path.Update();
	position = spawnPos + path.GetRelativePosition();
	currentAnim = path.GetCurrentAnimation();

	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Enemy::Update();
}
