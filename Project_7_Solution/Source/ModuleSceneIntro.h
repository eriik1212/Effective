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
	SDL_Rect backGround,
		frontBuildings,
		buildingLights,
		secondFloor,
		floor,
		leo,
		michelangelo,
		donatello,
		raphael,
		sewer;

	SDL_Texture* introBackground;
	SDL_Texture* raphaelTexture;
	SDL_Texture* leoTexture;
	SDL_Texture* donatelloTexture;
	SDL_Texture* michelangeloTexture;

	// The path that will define the position in the world
	Path pathCloud1,
		pathCloud2,
		pathLeo,
		pathMichelangelo,
		pathDonatello,
		pathRaphael;

	// A ptr to the current animation
	Animation* currentAnimCloud1 = nullptr;

	Animation* currentAnimCloud2 = nullptr;

	Animation* currentAnimLight = nullptr;

	Animation* leoCurrentAnim = nullptr;

	Animation* raphaelCurrentAnim = nullptr;

	Animation* donatelloCurrentAnim = nullptr;

	Animation* michelangeloCurrentAnim = nullptr;

	Animation cloud1,
		cloud2,
		littleLightAnim,
		bigLightUpAnim,
		bigLightAnim,

		leoAnim1,
		leoAnim2,
		leoAnim3,
		leoAnim4,
		leoAnim5,
		leoAnim6,

		raphaelAnim1,
		raphaelAnim2,
		raphaelAnim3,
		raphaelAnim4,
		raphaelAnim5,
		raphaelAnim6,

		donatelloAnim1,
		donatelloAnim2,
		donatelloAnim3,
		donatelloAnim4,
		donatelloAnim5,
		donatelloAnim6,

		michelangeloAnim1,
		michelangeloAnim2,
		michelangeloAnim3,
		michelangeloAnim4,
		michelangeloAnim5,
		michelangeloAnim6;

	// The current position in the world
	iPoint positionCloud1,
		positionCloud2,
		positionLeo,
		positionMichelangelo,
		positionDonatello,
		positionRaphael;

	// Original spawn position. Stored for movement calculations
	iPoint spawnPosCloud1,
		spawnPosCloud2,
		spawnPosLeo,
		spawnPosMichelangelo,
		spawnPosDonatello,
		spawnPosRaphael;

	// Counter for camera movement and audio
	int counter;
};

#endif //__MODULE_SCENEINTRO_H__