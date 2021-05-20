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
	SDL_Rect frontBuildings,
		buildingLights,
		floor;

	SDL_Texture* introBackground;

	// The path that will define the position in the world
	Path pathCloud1,
		pathCloud2;

	// A ptr to the current animation
	Animation* currentAnimCloud1 = nullptr;

	Animation* currentAnimCloud2 = nullptr;

	Animation cloud1,
		cloud2;

	// The current position in the world
	iPoint positionCloud1,
		positionCloud2;

	// Original spawn position. Stored for movement calculations
	iPoint spawnPosCloud1,
		spawnPosCloud2;

	// Counter for camera movement and audio
	int counter;
};

#endif //__MODULE_SCENEINTRO_H__