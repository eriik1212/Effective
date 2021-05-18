#ifndef __MODULE_SCENEINTRO_H__
#define __MODULE_SCENEINTRO_H__

#include "Module.h"
#include "Animation.h"
#include "ModuleInput.h"
#include "ModuleScene.h"
#include "ModulePlayer.h"
#include "ModuleEnemies.h"
#include "Path.h"

struct SDL_Texture;

class ModuleSceneIntro : public Module
{
public:
	//Constructor
	ModuleSceneIntro(bool enabled);

	//Destructor
	~ModuleSceneIntro();

	// Called when the module is activated
	// Loads the necessary textures for the map background
	bool Start() override;

	// Called at the middle of the application loop
	// Updates the scene's background animations
	update_status Update() override;

	// Called at the end of the application loop.
	// Performs the render call of all the parts of the scene's background
	update_status PostUpdate() override;

	// CleanUp the scene
	bool CleanUp();

public:	
	SDL_Texture* introBackground;

	// The path that will define the position in the world
	Path path;

	// A ptr to the current animation
	Animation* currentAnim = nullptr;

	Animation cloud1,
		cloud2;

	// Members Texture
	SDL_Texture* introMembers;
	int membersCounter;
	bool members;

	// The current position in the world
	iPoint positionCloud1,
		positionCloud2;

	// Original spawn position. Stored for movement calculations
	iPoint spawnPos;
};

#endif //__MODULE_SCENEINTRO_H__