#ifndef __ENEMY_MECH_H__
#define __ENEMY_MECH_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_Purple : public Enemy
{
public:
	// Constructor (x y coordinates in the world)
	// Creates animation and movement data and the collider
	Enemy_Purple(int x, int y);

	float coolDown = 30;
	float coolTime = 0;

	// The enemy is going to follow the different steps in the path
	// Position will be updated depending on the speed defined at each step
	void Update() override;

private:
	// The path that will define the position in the world
	Path path;

	iPoint positionEnemy;

	// Enemy animations
	Animation leftAnimP,
		rightAnimP,
		upAnimRP,
		upAnimLP;
};

#endif // __ENEMY_MECH_H__