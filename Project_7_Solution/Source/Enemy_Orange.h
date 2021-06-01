#ifndef __ENEMY_ORANGE_H__
#define __ENEMY_ORANGE_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_Orange : public Enemy
{
public:
	// Constructor (x y coordinates in the world)
	// Creates animation and movement data and the collider
	Enemy_Orange(int x, int y);

	float coolDown = 8.0f;
	float coolTime = 0.0f;
	float velociti = 1.0f;

	// The enemy is going to follow the different steps in the path
	// Position will be updated depending on the speed defined at each step
	void Update() override;

private:
	// The path that will define the position in the world
	Path path;

	iPoint positionEnemy;

	// Enemy animations
	Animation leftAnimO,
		rightAnimO,
		upAnimRO,
		upAnimLO,
		kickLO,
		kickRO,
		punchLO,
		punchRO,
		jumpLO,
		jumpRO,
		hitLO,
		hitRO,
		dieFacefwLO,
		dieFacefwRO,
		dieBackwLO,
		dieBackwRO,
		throwShurikenRO,
		throwShurikenLO,
		leftOW,
		rightOW,
		upOLW,
		upORW,
		meleeOWR,
		meleeOWL,
		shootOL,
		shootOR,
		hitOWR,
		hitOWL;




};

#endif // __ENEMY_ORANGE_H__
