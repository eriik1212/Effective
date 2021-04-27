#ifndef __MODULE_SCENEWIN_H__
#define __MODULE_SCENEWIN_H__

#include "Module.h"
#include "Animation.h"
#include "ModuleInput.h"
#include "ModuleScene.h"
#include "ModuleSceneIntro.h"
#include "ModulePlayer.h"
#include "ModuleEnemies.h"

struct SDL_Texture;

class ModuleSceneWin : public Module
{
public:
	//Constructor
	ModuleSceneWin(bool enabled);

	//Destructor
	~ModuleSceneWin();

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
};

#endif //__MODULE_SCENEWIN_H__