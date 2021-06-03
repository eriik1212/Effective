#include "Enemy_Orange.h"

#include "Application.h"
#include "ModuleCollisions.h"
#include "ModuleParticles.h"


Enemy_Orange::Enemy_Orange(int x, int y) : Enemy(x, y)
{
	// RIGHT 
	rightAnimO.PushBack({ 0, 830, 88, 69 });
	rightAnimO.PushBack({ 88, 830, 88, 69 });
	rightAnimO.PushBack({ 88 * 2, 830, 88, 69 });
	rightAnimO.PushBack({ 88 * 3, 830, 88, 69 });
	rightAnimO.PushBack({ 88 * 4, 830, 88, 69 });
	rightAnimO.PushBack({ 88 * 5, 830, 88, 69 });
	rightAnimO.PushBack({ 88 * 6, 830,88, 69 });
	rightAnimO.PushBack({ 88 * 7, 830, 88, 69 });
	rightAnimO.loop = true;
	rightAnimO.speed = 0.15f;

	//LEFT 
	leftAnimO.PushBack({ 1055,2140,88, 69 });
	leftAnimO.PushBack({ 1055 - 88,2140,88, 69 });
	leftAnimO.PushBack({ 1055 - 88 * 2,2140,88, 69 });
	leftAnimO.PushBack({ 1055 - 88 * 3,2140,88, 69 });
	leftAnimO.PushBack({ 1055 - 88 * 4,2140,88, 69 });
	leftAnimO.PushBack({ 1055 - 88 * 5,2140,88, 69 });
	leftAnimO.PushBack({ 1055 - 88 * 6,2140,88, 69 });
	leftAnimO.PushBack({ 1055 - 88 * 7,2140,88, 69 });
	leftAnimO.loop = true;
	leftAnimO.speed = 0.15f;

	//UP LEFT
	upAnimLO.PushBack({ 1055,2209,88, 69 });
	upAnimLO.PushBack({ 1055 - 88,2209,88, 69 });
	upAnimLO.PushBack({ 1055 - 88 * 2,2209,88, 69 });
	upAnimLO.PushBack({ 1055 - 88 * 3,2209,88, 69 });
	upAnimLO.PushBack({ 1055 - 88 * 4,2209,88, 69 });
	upAnimLO.PushBack({ 1055 - 88 * 5,2209,88, 69 });
	upAnimLO.PushBack({ 1055 - 88 * 6,2209,88, 69 });
	upAnimLO.PushBack({ 1055 - 88 * 7,2209,88, 69 });
	upAnimLO.loop = true;
	upAnimLO.speed = 0.15f;

	//UP RIGHT
	upAnimRO.PushBack({ 0, 897, 88, 69 });
	upAnimRO.PushBack({ 88, 897, 88, 69 });
	upAnimRO.PushBack({ 88 * 2, 897, 88, 69 });
	upAnimRO.PushBack({ 88 * 3, 897,88, 69 });
	upAnimRO.PushBack({ 88 * 4, 897, 88, 69 });
	upAnimRO.PushBack({ 88 * 5, 897, 88, 69 });
	upAnimRO.PushBack({ 88 * 6, 897, 88, 69 });
	upAnimRO.PushBack({ 88 * 7, 897, 88, 69 });
	upAnimRO.loop = true;
	upAnimRO.speed = 0.15f;


	//RIGHT KICK
	kickRO.PushBack({ 0, 552, 88, 69 });
	kickRO.PushBack({ 88, 552, 88, 69 });
	kickRO.PushBack({ 88 * 2, 552, 88, 69 });
	kickRO.PushBack({ 88 * 3, 552, 88, 69 });
	kickRO.loop = true; //it can be true
	kickRO.speed = 0.15f;

	//LEFT KICK
	kickLO.PushBack({ 1055,1863,88, 69 });
	kickLO.PushBack({ 1055 - 88,1863,88, 69 });
	kickLO.PushBack({ 1055 - 88 * 2,1863,88, 69 });
	kickLO.PushBack({ 1055 - 88 * 3,1863,88, 69 });
	kickLO.loop = false; //it can be true
	kickLO.speed = 0.15f;

	//LEFT PUNCH
	punchLO.PushBack({ 1055, 2346, 88, 69 });
	punchLO.PushBack({ 1055 - 88, 2346, 88, 69 });
	punchLO.PushBack({ 1055 - 88 * 2, 2346, 88, 69 });
	punchLO.PushBack({ 1055 - 88 * 3, 2346, 88, 69 });
	punchLO.loop = true; //it can be true
	punchLO.speed = 0.15f;

	//RIGHT PUNCH 
	punchRO.PushBack({ 0, 1035, 88, 69 });
	punchRO.PushBack({ 88, 1035, 88, 69 });
	punchRO.PushBack({ 88 * 2, 1035, 88, 69 });
	punchRO.PushBack({ 88 * 3, 1035, 88, 69 });
	punchRO.loop = true; //it can be true
	punchRO.speed = 0.15f;

	//RIGHT JUMP
	jumpRO.PushBack({ 0, 759, 88, 69 });
	jumpRO.PushBack({ 88, 759, 88, 69 });
	jumpRO.PushBack({ 88 * 2, 759, 88, 69 });
	jumpRO.PushBack({ 88 * 3, 759, 88, 69 });
	jumpRO.PushBack({ 88 * 4, 759, 88, 69 });
	jumpRO.loop = false; //it can be true
	jumpRO.speed = 0.15f;

	//LEFT JUMP
	jumpLO.PushBack({ 1055,2070,88, 69 });
	jumpLO.PushBack({ 1055 - 88,2070,88, 69 });
	jumpLO.PushBack({ 1055 - 88 * 2,2070,88, 69 });
	jumpLO.PushBack({ 1055 - 88 * 3,2070,88, 69 });
	jumpLO.PushBack({ 1055 - 88 * 4,2070,88, 69 });
	jumpLO.loop = true; //it can be true
	jumpLO.speed = 0.15f;

	//FROM LEFT HIT
	hitLO.PushBack({ 1055,1794,88, 69 });
	hitLO.PushBack({ 1055 - 88,1794,88, 69 });
	hitLO.PushBack({ 1055 - 88 * 2,1794,88, 69 });
	hitLO.PushBack({ 1055 - 88 * 3,1794,88, 69 });
	hitLO.loop = false;
	hitLO.speed = 0.15f;

	//FROM RIGHT HIT
	hitRO.PushBack({ 0,552,88, 69 });
	hitRO.PushBack({ 88,552,88, 69 });
	hitRO.PushBack({ 88 * 2,552,88, 69 });
	hitRO.PushBack({ 88 * 3,0,552, 69 });
	hitRO.loop = false;
	hitRO.speed = 0.15f;

	//DIE FACE FORWARD TO RIGHT
	dieFacefwLO.PushBack({ 0,690,88, 69 });
	dieFacefwLO.PushBack({ 88,690,88, 69 });
	dieFacefwLO.PushBack({ 88 * 2,690,88, 69 });
	dieFacefwLO.PushBack({ 88 * 3,690,88, 69 });
	dieFacefwLO.PushBack({ 88 * 4,690,88, 69 });
	dieFacefwLO.PushBack({ 88 * 5,690,88, 69 });
	dieFacefwLO.PushBack({ 88 * 6,690,88, 69 });
	dieFacefwLO.loop = false;
	dieFacefwLO.speed = 0.15f;

	//DIE FACE FORWARD TO LEFT
	dieFacefwRO.PushBack({ 1055,2001,88, 69 });
	dieFacefwRO.PushBack({ 1055 - 88,2001,88, 69 });
	dieFacefwRO.PushBack({ 1055 - 88 * 2,2001,88, 69 });
	dieFacefwRO.PushBack({ 1055 - 88 * 3,2001,88, 69 }); 
	dieFacefwRO.PushBack({ 1055 - 88 * 4,2001,88, 69 });
	dieFacefwRO.PushBack({ 1055 - 88 * 5,2001,88, 69 });
	dieFacefwRO.PushBack({ 1055 - 88 * 6,2001,88, 69 });
	dieFacefwRO.loop = false;
	dieFacefwRO.speed = 0.15f;

	//THROW SHURIKEN TO RIGHT
	throwShurikenRO.PushBack({ 0,966,88,69 });
	throwShurikenRO.PushBack({ 88,966,88,69 });
	throwShurikenRO.PushBack({ 88*2,966,88,69 });
	throwShurikenRO.PushBack({ 88*3,966,88,69 });
	throwShurikenRO.PushBack({ 88*4,966,88,69 });
	throwShurikenRO.PushBack({ 88*5,966,88,69 });
	throwShurikenRO.loop = false;
	throwShurikenRO.speed = 0.15f;

	//THROW SHURIKEN TO LEFT
	throwShurikenLO.PushBack({ 1055,2277,88,69 });
	throwShurikenLO.PushBack({ 1055 - 88,2277,88,69 });
	throwShurikenLO.PushBack({ 1055 - 88 * 2,2277,88,69 });
	throwShurikenLO.PushBack({ 1055 - 88 * 3,2277,88,69 });
	throwShurikenLO.PushBack({ 1055 - 88 * 4,2277,88,69 });
	throwShurikenLO.PushBack({ 1055 - 88 * 5,2277,88,69 });
	throwShurikenLO.loop = false;
	throwShurikenLO.speed = 0.15f;


	//DIE BACKWARDS TO LEFT
	dieBackwLO.PushBack({0,621,88,69});
	dieBackwLO.PushBack({ 88,621,88,69 });
	dieBackwLO.PushBack({ 88*2,621,88,69 });
	dieBackwLO.loop = false;
	dieBackwLO.speed = 0.15f;


	//DIE BACKDARDS TO RIGHT
	dieBackwRO.PushBack({ 1055 - 0,1863,88,69 });
	dieBackwRO.PushBack({ 1055 - 88,621,1863,69 });
	dieBackwRO.PushBack({ 1055 - 88 * 2,621,1863,69 });
	dieBackwRO.loop = false;
	dieBackwRO.speed = 0.15f;


//---------------------------------------------------HERE STARTS WEAPON ANIMATION

	//WALKING RIGHT
	rightOW.PushBack({ 0,207,88,69 });
	rightOW.PushBack({ 88,207,88,69 });
	rightOW.PushBack({ 88 * 2,207,88,69 });
	rightOW.PushBack({ 88 * 3,207,88,69 });
	rightOW.PushBack({ 88 * 4,207,88,69 });
	rightOW.PushBack({ 88 * 5,207,88,69 });
	rightOW.PushBack({ 88 * 6,207,88,69 });
	rightOW.loop = true;
	rightOW.speed = 0.15f;

	//WALKING UP RIGHT
	upORW.PushBack({ 0,276,88,69 });
	upORW.PushBack({ 88,276,88,69 });
	upORW.PushBack({ 88 * 2,276,88,69 });
	upORW.PushBack({ 88 * 3,276,88,69 });
	upORW.PushBack({ 88 * 4,276,88,69 });
	upORW.PushBack({ 88 * 5,276,88,69 });
	upORW.PushBack({ 88 * 6,276,88,69 });
	upORW.PushBack({ 88 * 7,276,88,69 });
	upORW.loop = true;
	upORW.speed = 0.15f;

	//WALKING LEFT
	leftOW.PushBack({ 1055,1518,88,69 });
	leftOW.PushBack({ 1055 - 88,1518,88,69 });
	leftOW.PushBack({ 1055 - 88 * 2,1518,88,69 });
	leftOW.PushBack({ 1055 - 88 * 3,1518,88,69 });
	leftOW.PushBack({ 1055 - 88 * 4,1518,88,69 });
	leftOW.PushBack({ 1055 - 88 * 5,1518,88,69 });
	leftOW.PushBack({ 1055 - 88 * 6,1518,88,69 });
	leftOW.loop = true;
	leftOW.speed = 0.15f;
	
	//WALKING UP LEFT
	upOLW.PushBack({ 1055,1587,88,69 });
	upOLW.PushBack({ 1055 - 88,1587,88,69 });
	upOLW.PushBack({ 1055 - 88 * 2,1587,88,69 });
	upOLW.PushBack({ 1055 - 88 * 3,1587,88,69 });
	upOLW.PushBack({ 1055 - 88 * 4,1587,88,69 });
	upOLW.PushBack({ 1055 - 88 * 5,1587,88,69 });
	upOLW.PushBack({ 1055 - 88 * 6,1587,88,69 });
	upOLW.PushBack({ 1055 - 88 * 7,1587,88,69 });
	upOLW.loop = true;
	upOLW.speed = 0.15f;

	//MELEE TO RIGHT
	meleeOWR.PushBack({ 0,69,88,69 });
	meleeOWR.PushBack({ 88,69,88,69 });
	meleeOWR.PushBack({ 88 * 2,69,88,69 });
	meleeOWR.PushBack({ 88 * 3,69,88,69 });
	meleeOWR.PushBack({ 88 * 4,69,88,69 });
	meleeOWR.loop = false;
	meleeOWR.speed = 0.15f;

	//MELEE TO LEFT
	meleeOWL.PushBack({ 1055,1380,88,69 });
	meleeOWL.PushBack({ 1055 - 88,1380,88,69 });
	meleeOWL.PushBack({ 1055 - 88 * 2,1380,88,69 });
	meleeOWL.PushBack({ 1055 - 88 * 3,1380,88,69 });
	meleeOWL.PushBack({ 1055 - 88 * 4,1380,88,69 });
	meleeOWL.loop = false;
	meleeOWL.speed = 0.15f;

	//SHOOT TO RIGHT 
	shootOR.PushBack({ 0,138,88,69 });
	shootOR.PushBack({ 88,138,88,69 });
	shootOR.PushBack({ 88 * 2,138,88,69 });
	shootOR.PushBack({ 88 * 3,138,88,69 });
	shootOR.PushBack({ 88 * 4,138,88,69 });
	shootOR.PushBack({ 88 * 5,138,88,69 });
	shootOR.PushBack({ 88 * 6,138,88,69 });
	shootOR.loop = false;
	shootOR.speed = 0.15f;

	//SHOOT TO LEFT
	shootOL.PushBack({ 1055,1449,88,69 });
	shootOL.PushBack({ 1055 - 88,1449,88,69 });
	shootOL.PushBack({ 1055 - 88 * 2,1449,88,69 });
	shootOL.PushBack({ 1055 - 88 * 3,1449,88,69 });
	shootOL.PushBack({ 1055 - 88 * 4,1449,88,69 });
	shootOL.PushBack({ 1055 - 88 * 5,1449,88,69 });
	shootOL.loop = false;
	shootOL.speed = 0.15f;

	//HIT FROM RIGHT
	hitOWR.PushBack({ 0,0,88,69 });
	hitOWR.PushBack({ 88,0,88,69 });
	hitOWR.PushBack({ 88 * 2,0,88,69 });
	hitOWR.PushBack({ 88 * 3,0,88,69 });
	hitOWR.loop = false;
	hitOWR.speed = 0.15f;

	//HIT FROM LEFT
	hitOWL.PushBack({ 1055,1311,88,69 });
	hitOWL.PushBack({ 1055 -88,1311,88,69 });
	hitOWL.PushBack({ 1055 -88 * 2,1311,88,69 });
	hitOWL.PushBack({ 1055 -88 * 3,1311,88,69 });
	hitOWL.loop = false;
	hitOWL.speed = 0.15f;



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