#include "Enemy_Ball.h"

#include "Application.h"
#include "ModuleCollisions.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"


Enemy_Ball::Enemy_Ball(int x, int y) : Enemy(x, y)
{

	// Ball animation
	animBall.PushBack({ 113, 232, 37, 34 });
	animBall.PushBack({ 150, 232, 37, 34 });
	animBall.loop = false;
	animBall.speed = 0.15f;
	
	




	//PATH
	path.PushBack({ -1.0f, 0.0f }, 20, &animBall);
	path.PushBack({ 0.0f, 0.0f }, 40, &animBall);
	path.PushBack({ -1.0f, 0.0f }, 130, &animBall);
	path.PushBack({ 1.0f,0.0f }, 150, &animBall);
	path.PushBack({ 0.0f, 0.0f }, 40, &animBall);
	


	HIT = App->collisions->AddCollider({ 200, 122, 18, 16 }, Collider::Type::ENEMY_HIT, (Module*)App->enemies);

}

void Enemy_Ball::Update()
{
	
	if (App->collisions->GodMode == true) {

		App->collisions->matrix[Collider::Type::PLAYER][Collider::Type::ENEMY_HIT] = false;

		if (coolTime >= coolDown) {
			
			
				App->collisions->matrix[Collider::Type::PLAYER][Collider::Type::ENEMY_HIT] = true;
				coolTime = 0.0f;

		}
		else
			coolTime += 0.1f;

	}
	
	
	
	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Enemy::Update();
}
