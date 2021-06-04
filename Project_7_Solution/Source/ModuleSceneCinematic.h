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
		backGround2,
		backGround3,
		frontBuilding,

		leo,
		raphael,
		donatello,
		michelangelo,

		fireComment,
		hangOnComment,

		finalDoor,

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
		pathRaphael,
		
		pathLeo2,
		pathMichelangelo2,
		pathDonatello2,
		pathRaphael2,
		
		pathLeo3,
		pathMichelangelo3,
		pathDonatello3,
		pathRaphael3;

	// A ptr to the current animation
	Animation* splinterCurrentAnim = nullptr;

	Animation* leoCurrentAnim = nullptr;

	Animation* raphaelCurrentAnim = nullptr;

	Animation* donatelloCurrentAnim = nullptr;

	Animation* michelangeloCurrentAnim = nullptr;

	Animation* fireCurrentAnim = nullptr;

	Animation splinterAnim,
		donatelloJumpAnim,
		leoJumpAnim,
		michelangeloJumpAnim,
		raphaelJumpAnim,
		
		donatelloFallAnim1,
		leoFallAnim1,
		michelangeloFallAnim1,
		raphaelFallAnim1,

		donatelloFallAnim2,
		leoFallAnim2,
		michelangeloFallAnim2,
		raphaelFallAnim2,

		donatelloFallAnim3,
		leoFallAnim3,
		michelangeloFallAnim3,
		raphaelFallAnim3,

		donatelloFallAnim4,
		leoFallAnim4,
		michelangeloFallAnim4,
		raphaelFallAnim4,

		leoFinalAnim1,
		michelangeloFinalAnim1,
		donatelloFinalAnim1,
		raphaelFinalAnim1,

		leoFinalAnim2,
		michelangeloFinalAnim2,
		donatelloFinalAnim2,
		raphaelFinalAnim2,

		leoFinalAnim3,
		michelangeloFinalAnim3,
		donatelloFinalAnim3,
		raphaelFinalAnim3,
		
		fireAnim,
		secondFireAnim;

	// The current position in the world
	iPoint positionDonatello,
		positionLeo,
		positionMichelangelo,
		positionRaphael,
		
		positionDonatello2,
		positionLeo2,
		positionMichelangelo2,
		positionRaphael2,
		
		positionDonatello3,
		positionLeo3,
		positionMichelangelo3,
		positionRaphael3;

	// Original spawn position. Stored for movement calculations
	iPoint spawnPosLeo,
		spawnPosMichelangelo,
		spawnPosDonatello,
		spawnPosRaphael,
		
		spawnPosLeo2,
		spawnPosMichelangelo2,
		spawnPosDonatello2,
		spawnPosRaphael2,
		
		spawnPosLeo3,
		spawnPosMichelangelo3,
		spawnPosDonatello3,
		spawnPosRaphael3;

	// Sound effects indices
	uint Fire = 0;
	uint HangOn = 0;

	// Text
	uint text = 0;
	int tmntFont = -1;

	// Counter for camera movement, audio and intro events
	int counter;
};

#endif //__MODULE_SCENEINTRO_H__