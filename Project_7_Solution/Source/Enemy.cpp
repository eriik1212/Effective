#include "Enemy.h"

#include "Application.h"
#include "ModuleCollisions.h"
#include "ModuleParticles.h"
#include "ModuleAudio.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "Particle.h"


Enemy::Enemy(int x, int y) : position(x, y)
{
	spawnPos = position;
}

Enemy::~Enemy()
{
	if (collider != nullptr)
		collider->pendingToDelete = true;
	if (HIT != nullptr)
		HIT->pendingToDelete = true;
	if (SEE != nullptr)
	    SEE->pendingToDelete = true;
}

const Collider* Enemy::GetCollider() const
{
	return collider;
}

void Enemy::Update()
{
	if (currentAnim != nullptr)
		currentAnim->Update();
	//----------------------------------------------------left collider

	if (collider != nullptr && direcction ==0) 
		collider->SetPos(position.x+28, position.y+75);

	if (HIT != nullptr && direcction == 0)
		HIT->SetPos(position.x + 10, position.y + 75);

	//----------------------------------------------------right collider

	if (collider != nullptr && direcction ==1 )
		collider->SetPos(position.x + 20, position.y + 75);


	if (HIT != nullptr && direcction==1)
		HIT->SetPos(position.x + 58, position.y + 75);
	

}

void Enemy::Draw()
{
	if (currentAnim != nullptr)
		App->render->Blit(texture, position.x, position.y, &(currentAnim->GetCurrentFrame()));
}

void Enemy::OnCollision(Collider* collider)
{
	if (App->collisions->matrix[Collider::Type::ENEMY][Collider::Type::PLAYER_SHOT]) {
		tocado = true;
	}
	else tocado = false;

	if (App->collisions->matrix[Collider::Type::ENEMY][Collider::Type::PLAYER]) {
		retirar = true;
	}
	else retirar = false;
	
	App->particles->AddParticle(App->particles->explosion, position.x, position.y);
	App->audio->PlayFx(damageFX);
}