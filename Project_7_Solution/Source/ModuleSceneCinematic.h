#ifndef __MODULE_SCENECINEMATIC_H__
#define __MODULE_SCENECINEMATIC_H__

#include "Module.h"
#include "Animation.h"
#include "ModuleInput.h"
#include "ModulePlayer.h"
#include "ModuleEnemies.h"
#include "Path.h"

struct SDL_Texture;

class ModuleSceneCinematic : public Module
{
public:
	//Constructor
	ModuleSceneCinematic(bool enabled);

	//Destructor
	~ModuleSceneCinematic();

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
	SDL_Rect backGround,
		frontBuildings,
		leo,
		raphael,
		donatello,
		michelangelo,
		fireComment,
		drawColorScreen;

	SDL_Texture* cinematicBackground;
	SDL_Texture* charactersTexture;
	SDL_Texture* raphaelTexture;
	SDL_Texture* leoTexture;
	SDL_Texture* donatelloTexture;
	SDL_Texture* michelangeloTexture;

	// The path that will define the position in the world
	Path pathLeo,
		pathMichelangelo,
		pathDonatello,
		pathRaphael;

	// A ptr to the current animation
	Animation* splinterCurrentAnim = nullptr;

	Animation* leoCurrentAnim = nullptr;

	Animation* raphaelCurrentAnim = nullptr;

	Animation* donatelloCurrentAnim = nullptr;

	Animation* michelangeloCurrentAnim = nullptr;

	Animation* fireCurrentAnim = nullptr;

	Animation splinterAnim,
		donatelloAnim,
		leoAnim,
		michelangeloAnim,
		raphaelAnim,
		
		fireAnim;

	// The current position in the world
	iPoint positionDonatello,
		positionLeo,
		positionMichelangelo,
		positionRaphael;

	// Original spawn position. Stored for movement calculations
	iPoint spawnPosLeo,
		spawnPosMichelangelo,
		spawnPosDonatello,
		spawnPosRaphael;

	// Sound effects indices
	uint Scream1 = 0;

	// Counter for camera movement, audio and intro events
	int counter;
};

#endif //__MODULE_SCENEINTRO_H__