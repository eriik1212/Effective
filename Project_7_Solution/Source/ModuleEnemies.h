#ifndef __MODULE_ENEMIES_H__
#define __MODULE_ENEMIES_H__

#include "Module.h"

#define MAX_ENEMIES 21
#define MAX_LIFE 5     //enemy lifes

enum class ENEMY_TYPE
{
	NO_TYPE,
	PURPLE_ENEMY,
	WHITE_ENEMY,
	ORANGE_ENEMY,
	BOSS_ENEMY,
	BALL_ENEMY,
};

struct EnemySpawnpoint
{
	ENEMY_TYPE type = ENEMY_TYPE::NO_TYPE;
	int x, y;
};

class Enemy;
struct SDL_Texture;

class ModuleEnemies : public Module
{
public:
	// Constructor
	ModuleEnemies(bool enabled);

	// Destructor
	~ModuleEnemies();

	// Called when the module is activated
	// Loads the necessary textures for the enemies
	bool Start() override;

	// Called at the middle of the application loop
	// Handles all enemies logic and spawning/despawning
	update_status Update() override;

	// Called at the end of the application loop
	// Iterates all the enemies and draws them
	update_status PostUpdate() override;

	// Called on application exit
	// Destroys all active enemies left in the array
	bool CleanUp() override;

	// Called when an enemi collider hits another collider
	// The enemy is destroyed and an explosion particle is fired
	void OnCollision(Collider* c1, Collider* c2) override;

	// Add an enemy into the queue to be spawned later
	bool AddEnemy(ENEMY_TYPE type, int x, int y);

	// Iterates the queue and checks for camera position
	void HandleEnemiesSpawn();

	// Destroys any enemies that have moved outside the camera limits
	void HandleEnemiesDespawn();

	// All spawned enemies in the scene
	Enemy* enemies[MAX_ENEMIES] = { nullptr };
	
private:
	// Spawns a new enemy using the data from the queue
	void SpawnEnemy(const EnemySpawnpoint& info);

private:
	// A queue with all spawn points information
	EnemySpawnpoint spawnQueue[MAX_ENEMIES];

	// The enemies sprite sheet
	SDL_Texture* white = nullptr;
	SDL_Texture* purple = nullptr;
	SDL_Texture* orange = nullptr;
	SDL_Texture* boss = nullptr;
	SDL_Texture* ball = nullptr;
	// The audio fx for destroying an enemy
	int enemyDestroyedFx = 0;
	int enemyDamageFX = 0;


	
};

#endif // __MODULE_ENEMIES_H__