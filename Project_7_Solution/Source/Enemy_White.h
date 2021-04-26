#ifndef __ENEMY_WHITE_H__
#define __ENEMY_WHITE_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_White : public Enemy
{
public:
	// Constructor (x y coordinates in the world)
	// Creates animation and movement data and the collider
	Enemy_White(int x, int y);

	// The enemy is going to follow the different steps in the path
	// Position will be updated depending on the speed defined at each step
	void Update() override;

private:
	// The path that will define the position in the world
	Path path;

	iPoint positionEnemy;

	// Enemy animations
	//temporary animations 
	Animation idleAnimRW,
		idleAnimLW,
		leftAnimW,
		rightAnimW,
		upAnimRW,
		upAnimLW,
		downAnimRW,
		downAnimLW;

	//There are more animations, but for the prtotype we are not including it.
};

#endif // __ENEMY_MECH_H__