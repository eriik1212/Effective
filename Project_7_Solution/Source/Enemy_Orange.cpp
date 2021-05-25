#include "Enemy_Orange.h"

#include "Application.h"
#include "ModuleCollisions.h"
#include "ModuleParticles.h"


Enemy_Orange::Enemy_Orange(int x, int y) : Enemy(x, y)
{
	// RIGHT pixels pendents
	rightAnimO.PushBack({ 0, 453, 86, 90 });
	rightAnimO.PushBack({ 86, 453, 86, 90 });
	rightAnimO.PushBack({ 86 * 2, 453, 86, 90 });
	rightAnimO.PushBack({ 86 * 3, 453, 86, 90 });
	rightAnimO.PushBack({ 86 * 4, 453, 86, 90 });
	rightAnimO.PushBack({ 86 * 5, 453, 86, 90 });
	rightAnimO.PushBack({ 86 * 6, 453, 86, 90 });
	rightAnimO.PushBack({ 86 * 7, 453, 86, 90 });
	rightAnimO.loop = true;
	rightAnimO.speed = 0.15f;

	//LEFT pixels pendents
	leftAnimO.PushBack({ 1032,1890,86,90 });
	leftAnimO.PushBack({ 1032 - 86,1890,86,90 });
	leftAnimO.PushBack({ 1032 - 86 * 2,1890,86,90 });
	leftAnimO.PushBack({ 1032 - 86 * 3,1890,86,90 });
	leftAnimO.PushBack({ 1032 - 86 * 4,1890,86,90 });
	leftAnimO.PushBack({ 1032 - 86 * 5,1890,86,90 });
	leftAnimO.PushBack({ 1032 - 86 * 6,1890,86,90 });
	leftAnimO.PushBack({ 1032 - 86 * 7,1890,86,90 });
	leftAnimO.loop = true;
	leftAnimO.speed = 0.15f;

	//UP LEFT pixels pendents
	upAnimLO.PushBack({ 1032,1980,86,90 });
	upAnimLO.PushBack({ 1032 - 86,1980,86,90 });
	upAnimLO.PushBack({ 1032 - 86 * 2,1980,86,90 });
	upAnimLO.PushBack({ 1032 - 86 * 3,1980,86,90 });
	upAnimLO.PushBack({ 1032 - 86 * 4,1980,86,90 });
	upAnimLO.PushBack({ 1032 - 86 * 5,1980,86,90 });
	upAnimLO.PushBack({ 1032 - 86 * 6,1980,86,90 });
	upAnimLO.PushBack({ 1032 - 86 * 7,1980,86,90 });
	upAnimLO.loop = true;
	upAnimLO.speed = 0.15f;

	//UP RIGHT pixels pendents
	upAnimRO.PushBack({ 0, 540, 86, 90 });
	upAnimRO.PushBack({ 86, 540, 86, 90 });
	upAnimRO.PushBack({ 86 * 2, 540, 86, 90 });
	upAnimRO.PushBack({ 86 * 3, 540, 86, 90 });
	upAnimRO.PushBack({ 86 * 4, 540, 86, 90 });
	upAnimRO.PushBack({ 86 * 5, 540, 86, 90 });
	upAnimRO.PushBack({ 86 * 6, 540, 86, 90 });
	upAnimRO.PushBack({ 86 * 7, 540, 86, 90 });
	upAnimRO.loop = true;
	upAnimRO.speed = 0.15f;


	//RIGHT KICK pixels pendents
	kickRO.PushBack({ 0, 90, 86, 90 });
	kickRO.PushBack({ 86, 90, 86, 90 });
	kickRO.PushBack({ 86 * 2, 90, 86, 90 });
	kickRO.PushBack({ 86 * 3, 90, 86, 90 });
	kickRO.loop = true; //it can be true
	kickRO.speed = 0.15f;

	//LEFT KICK pixels pendents
	kickLO.PushBack({ 1032,1530,86,90 });
	kickLO.PushBack({ 1032 - 86,1530,86,90 });
	kickLO.PushBack({ 1032 - 86 * 2,1530,86,90 });
	kickLO.PushBack({ 1032 - 86 * 3,1530,86,90 });
	kickLO.loop = false; //it can be true
	kickLO.speed = 0.15f;

	//LEFT PUNCH pixels pendents
	punchLO.PushBack({ 1032, 2790, 86, 90 });
	punchLO.PushBack({ 1032 - 86, 2790, 86, 90 });
	punchLO.PushBack({ 1032 - 86 * 2, 2790, 86, 90 });
	punchLO.PushBack({ 1032 - 86 * 3, 2790, 86, 90 });
	punchLO.PushBack({ 1032 - 86 * 4, 2790, 86, 90 });
	punchLO.PushBack({ 1032 - 86 * 5, 2790, 86, 90 });
	punchLO.PushBack({ 1032 - 86 * 6, 2790, 86, 90 });
	punchLO.PushBack({ 1032 - 86 * 7, 2790, 86, 90 });
	punchLO.PushBack({ 1032 - 86 * 8, 2790, 86, 90 });
	punchLO.PushBack({ 1032 - 86 * 9, 2790, 86, 90 });
	punchLO.loop = true; //it can be true
	punchLO.speed = 0.15f;

	//RIGHT PUNCH pixels pendents
	punchRO.PushBack({ 0, 1350, 86, 90 });
	punchRO.PushBack({ 86, 1350, 86, 90 });
	punchRO.PushBack({ 86 * 2, 1350, 86, 90 });
	punchRO.PushBack({ 86 * 3, 1350, 86, 90 });
	punchRO.PushBack({ 86 * 4, 1350, 86, 90 });
	punchRO.PushBack({ 86 * 5, 1350, 86, 90 });
	punchRO.PushBack({ 86 * 6, 1350, 86, 90 });
	punchRO.PushBack({ 86 * 7, 1350, 86, 90 });
	punchRO.PushBack({ 86 * 8, 1350, 86, 90 });
	punchRO.PushBack({ 86 * 9, 1350, 86, 90 });
	punchRO.loop = true; //it can be true
	punchRO.speed = 0.15f;

	//RIGHT JUMP pixels pendents
	jumpRO.PushBack({ 0, 900, 86, 90 });
	jumpRO.PushBack({ 86, 900, 86, 90 });
	jumpRO.PushBack({ 86 * 2, 900, 86, 90 });
	jumpRO.PushBack({ 86 * 3, 900, 86, 90 });
	jumpRO.PushBack({ 86 * 4, 900, 86, 90 });
	jumpRO.PushBack({ 86 * 5, 900, 86, 90 });
	jumpRO.PushBack({ 86 * 6, 900, 86, 90 });
	jumpRO.loop = false; //it can be true
	jumpRO.speed = 0.15f;

	//LEFT JUMP pixels pendents
	jumpLO.PushBack({ 1032,2340,86,90 });
	jumpLO.PushBack({ 1032 - 86,2340,86,90 });
	jumpLO.PushBack({ 1032 - 86 * 2,2340,86,90 });
	jumpLO.PushBack({ 1032 - 86 * 3,2340,86,90 });
	jumpLO.PushBack({ 1032 - 86 * 4,2340,86,90 });
	jumpLO.PushBack({ 1032 - 86 * 5,2340,86,90 });
	jumpLO.PushBack({ 1032 - 86 * 6,2340,86,90 });
	jumpLO.loop = true; //it can be true
	jumpLO.speed = 0.15f;

	//FROM LEFT HIT pixels pendents
	hitLO.PushBack({ 1032,1440,86,90 });
	hitLO.PushBack({ 1032 - 86,1440,86,90 });
	hitLO.PushBack({ 1032 - 86 * 2,1440,86,90 });
	hitLO.PushBack({ 1032 - 87 * 3,1440,86,90 });
	hitLO.loop = false;
	hitLO.speed = 0.15f;

	//FROM RIGHT HIT pixels pendents
	hitRO.PushBack({ 0,0,86,90 });
	hitRO.PushBack({ 86,0,86,90 });
	hitRO.PushBack({ 86 * 2,0,86,90 });
	hitRO.PushBack({ 86 * 3,0,86,90 });
	hitRO.loop = false;
	hitRO.speed = 0.15f;

	//DIE FACE FORWARD TO LEFT pixels pendents
	dieFacefwLO.PushBack({ 0,270,86,90 });
	dieFacefwLO.PushBack({ 86,270,86,90 });
	dieFacefwLO.PushBack({ 86 * 2,270,86,90 });
	dieFacefwLO.PushBack({ 86 * 3,270,86,90 });
	dieFacefwLO.PushBack({ 86 * 4,270,86,90 });
	dieFacefwLO.PushBack({ 86 * 5,270,86,90 });
	dieFacefwLO.PushBack({ 86 * 6,270,86,90 });
	dieFacefwLO.loop = false;
	dieFacefwLO.speed = 0.15f;

	//DIE FACE FORWARD TO RIGHT pixels pendents
	dieFacefwRO.PushBack({ 1032,1710,86,90 });
	dieFacefwRO.PushBack({ 1032 - 86,1710,86,90 });
	dieFacefwRO.PushBack({ 1032 - 86 * 2,1710,86,90 });
	dieFacefwRO.PushBack({ 1032 - 86 * 3,1710,86,90 });
	dieFacefwRO.PushBack({ 1032 - 86 * 4,1710,86,90 });
	dieFacefwRO.PushBack({ 1032 - 86 * 5,1710,86,90 });
	dieFacefwRO.PushBack({ 1032 - 86 * 6,1710,86,90 });
	dieFacefwRO.loop = false;
	dieFacefwRO.speed = 0.15f;

	//PATH

	collider = App->collisions->AddCollider({ 0, 0, 38, 16 }, Collider::Type::ENEMY, (Module*)App->enemies);
	HIT = App->collisions->AddCollider({ 200, 122, 18, 16 }, Collider::Type::ENEMY_HIT, (Module*)App->enemies);
}

void Enemy_Orange::Update()
{
	//------------------------------------------------------------LEFT direcction
	if (currentAnim == &jumpLO)direcction = 0;
	if (currentAnim == &leftAnimO)direcction = 0;
	if (currentAnim == &punchLO)direcction = 0;

	//------------------------------------------------------------LEFT ANIM direction
	if (currentAnim == &upAnimRO)direcction = 1;
	if (currentAnim == &kickRO)direcction = 1;

	if (App->collisions->GodMode == true) {


		App->collisions->matrix[Collider::Type::PLAYER][Collider::Type::ENEMY_HIT] = false;


		if (coolTime >= coolDown) {

			if (currentAnim == &punchLO)
			{
				App->collisions->matrix[Collider::Type::PLAYER][Collider::Type::ENEMY_HIT] = true;
				coolTime = 0.0f;

			}
			else if (currentAnim == &kickRO)
			{
				App->collisions->matrix[Collider::Type::PLAYER][Collider::Type::ENEMY_HIT] = true;
				coolTime = 0.0f;
			}
			else
				App->collisions->matrix[Collider::Type::PLAYER][Collider::Type::ENEMY_HIT] = false;
		}
		else
			coolTime += 0.1f;

	}
	path.Update();
	position = spawnPos + path.GetRelativePosition();
	currentAnim = path.GetCurrentAnimation();

	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Enemy::Update();
}