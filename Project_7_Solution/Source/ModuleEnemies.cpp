#include "ModuleEnemies.h"

#include "Application.h"

#include "ModuleRender.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"

#include "ModulePlayer.h"

#include "Enemy.h"
#include "Enemy_Purple.h"
#include "Enemy_Orange.h"
#include "Enemy_White.h"
#include "Enemy_Boss.h"
#include "Enemy_Ball.h"
#include "ModuleCollisions.h"

#define SPAWN_MARGIN 50


ModuleEnemies::ModuleEnemies(bool enabled) : Module(enabled)
{
	for(uint i = 0; i < MAX_ENEMIES; ++i)
		enemies[i] = nullptr;
}

ModuleEnemies::~ModuleEnemies()
{

}

bool ModuleEnemies::Start()
{

	white = App->textures->Load("Assets/Enemies/white_enemy.png");
	purple = App->textures->Load("Assets/Enemies/purple_enemy.png");
	orange = App->textures->Load("Assets(Enemies/orange_enemy.png");
	boss = App->textures->Load("Assets/Enemies/white_enemy.png");
	ball = App->textures->Load("Assets/Enemies/tile_map_set_stage_1.png.png");

	enemyDamageFX = App->audio->LoadFx("Assets/FX/punch_2.wav");
	enemyDestroyedFx = App->audio->LoadFx("Assets/FX/enemy_die.wav");

	return true;
}

update_status ModuleEnemies::Update()
{
	HandleEnemiesSpawn();

	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if(enemies[i] != nullptr)
			enemies[i]->Update();
	}

	HandleEnemiesDespawn();

	return update_status::UPDATE_CONTINUE;
}

update_status ModuleEnemies::PostUpdate()
{
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] != nullptr)
			enemies[i]->Draw();
	}


	App->render->Blit(App->player->fireTexture, 0, 162, &(App->player->frontFire.GetCurrentFrame()), 1); // FrontFire animation
	App->render->Blit(App->player->fireTexture, 256, 162, &(App->player->frontFire.GetCurrentFrame()), 1); // FrontFire animation
	App->render->Blit(App->player->fireTexture, 512, 162, &(App->player->frontFire.GetCurrentFrame()), 1); // FrontFire animation
	App->render->Blit(App->player->fireTexture, 768, 162, &(App->player->frontFire.GetCurrentFrame()), 1); // FrontFire animation
	App->render->Blit(App->player->fireTexture, 1024, 162, &(App->player->frontFire.GetCurrentFrame()), 1); // FrontFire animation
	App->render->Blit(App->player->fireTexture, 1280, 162, &(App->player->frontFire.GetCurrentFrame()), 1); // FrontFire animation

	return update_status::UPDATE_CONTINUE;
}

// Called before quitting
bool ModuleEnemies::CleanUp()
{
	LOG("Freeing all enemies");

	for(uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if(enemies[i] != nullptr)
		{
			delete enemies[i];
			enemies[i] = nullptr;
		}
	}

	return true;
}

bool ModuleEnemies::AddEnemy(ENEMY_TYPE type, int x, int y)
{
	bool ret = false;

	for(uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if(spawnQueue[i].type == ENEMY_TYPE::NO_TYPE)
		{
			spawnQueue[i].type = type;
			spawnQueue[i].x = x;
			spawnQueue[i].y = y;
			ret = true;
			break;
		}
	}

	return ret;
}

void ModuleEnemies::HandleEnemiesSpawn()
{
	// Iterate all the enemies queue
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (spawnQueue[i].type != ENEMY_TYPE::NO_TYPE)
		{
			// Spawn a new enemy if the screen has reached a spawn position
			if (spawnQueue[i].x * SCREEN_SIZE < App->render->camera.x + (App->render->camera.w * SCREEN_SIZE) + SPAWN_MARGIN)
			{
				LOG("Spawning enemy at %d", spawnQueue[i].x * SCREEN_SIZE);

				SpawnEnemy(spawnQueue[i]);
				spawnQueue[i].type = ENEMY_TYPE::NO_TYPE; // Removing the newly spawned enemy from the queue
			}
		}
	}
}

void ModuleEnemies::HandleEnemiesDespawn()
{
	// Iterate existing enemies
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] != nullptr)
		{
			// Delete the enemy when it has reached the end of the screen
			/*if (enemies[i]->position.x * SCREEN_SIZE < (App->render->camera.x) - SPAWN_MARGIN)
			{
				LOG("DeSpawning enemy at %d", enemies[i]->position.x * SCREEN_SIZE);

				delete enemies[i];
				enemies[i] = nullptr;
			}*/
		}
	}
}

void ModuleEnemies::SpawnEnemy(const EnemySpawnpoint& info)
{
	// Find an empty slot in the enemies array
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] == nullptr)
		{
			switch (info.type)
			{
				case ENEMY_TYPE::PURPLE_ENEMY:
					enemies[i] = new Enemy_Purple(info.x, info.y);
					enemies[i]->texture = purple;
					enemies[i]->destroyedFx = enemyDestroyedFx;
					enemies[i]->damageFX = enemyDamageFX;

					for (int a = 0; a < MAX_LIFE; ++a) {
						enemies[i]->lifes[a] = 1;
					}
					break;
				case ENEMY_TYPE::WHITE_ENEMY:
					enemies[i] = new Enemy_White(info.x, info.y);
					enemies[i]->texture = white;
					enemies[i]->destroyedFx = enemyDestroyedFx;
					enemies[i]->damageFX = enemyDamageFX;
					for (int a = 0; a < MAX_LIFE; ++a) {
						enemies[i]->lifes[a] = 1;
					}
					break;
				case ENEMY_TYPE::ORANGE_ENEMY:
					enemies[i] = new Enemy_Orange(info.x, info.y);
					enemies[i]->texture = orange;
					enemies[i]->destroyedFx = enemyDestroyedFx;
					enemies[i]->damageFX = enemyDamageFX;

					for (int a = 0; a < MAX_LIFE; ++a) {
						enemies[i]->lifes[a] = 1;
					}
					break;
				case ENEMY_TYPE::BOSS_ENEMY:
					enemies[i] = new Enemy_Boss(info.x, info.y);
					enemies[i]->texture = boss;
					enemies[i]->destroyedFx = enemyDestroyedFx;
					enemies[i]->damageFX = enemyDamageFX;

					for (int a = 0; a < MAX_LIFE; ++a) {
						enemies[i]->lifes[a] = 1;
					}
					break;
				case ENEMY_TYPE::BALL_ENEMY:
					enemies[i] = new Enemy_Ball(info.x, info.y);
					enemies[i]->texture = ball;
					enemies[i]->damageFX = enemyDamageFX;
					break;
			}

			break;
		}
	}
}
void updateLifes(unsigned short* lifes, unsigned short damage)
{

	for (int i = (MAX_LIFE - 1); i >= 0; --i) {

		if (*(lifes + i) == 0) {
			++damage;
		}
		else if (*(lifes + i) == 1 && i >= (MAX_LIFE - damage)) {
			*(lifes + i) = 0;
		}
	}
}

void ModuleEnemies::OnCollision(Collider* c1, Collider* c2)
{
	for(uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if(enemies[i] != nullptr && enemies[i]->GetCollider() == c1)
		{
			enemies[i]->OnCollision(c2); //Notify the enemy of a collision

			if (App->collisions->matrix[Collider::Type::PLAYER][Collider::Type::ENEMY_HIT])
			{
				App->collisions->matrix[Collider::Type::ENEMY][Collider::Type::PLAYER_SHOT] = true;
			}
			//---------------------------------------------------------------iNTENT DE VIDES ALS ENEMICS-----------------------------------------------
			updateLifes(enemies[i]->lifes, 1);
			if (enemies[i]->lifes[0] == 0)
			{
				delete enemies[i];
				enemies[i] = nullptr;
			}
			
			
				
			

			break;
		}
	}
}
