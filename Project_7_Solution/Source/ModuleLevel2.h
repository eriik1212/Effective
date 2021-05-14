#ifndef __MODULE_LEVEL_2_H__
#define __MODULE_LEVEL_2_H__

#include "Module.h"
#include "Animation.h"
#include "ModuleInput.h"

struct SDL_Texture;

class ModuleLevel2 : public Module
{
public:
	//Constructor
	ModuleLevel2(bool enabled);

	//Destructor
	~ModuleLevel2();

	// Called when the module is activated
	// Loads the necessary textures for the map background
	bool Start() override;

	// Called at the middle of the application loop
	// Updates the scene's background animations
	update_status Update() override;

	// Called at the end of the application loop.
	// Performs the render call of all the parts of the scene's background
	update_status PostUpdate() override;

	bool CleanUp();

public:

	SDL_Rect background;

	// The scene sprite sheet loaded into an SDL_Texture
	SDL_Texture* stageTexture = nullptr;

	//Animation drill;

	//Initialazing scene audio index
	//uint drill = 0;

	int countDown = 0;
};


#endif //__MODULE_LEVEL_2_H__