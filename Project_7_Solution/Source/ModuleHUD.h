#ifndef __MODULE_HUD_H__
#define __MODULE_HUD_H__

#include "Module.h"
#include "Animation.h"
#include "ModuleInput.h"

struct SDL_Texture;

class ModuleHUD : public Module
{
public:
	//Constructor
	ModuleHUD(bool enabled);

	//Destructor
	~ModuleHUD();

	// Called when the module is activated
	// Loads the necessary textures for the map background
	bool Start() override;

	void Reset();

	// Called at the middle of the application loop
	// Updates the scene's background animations
	update_status Update() override;

	// Called at the end of the application loop.
	// Performs the render call of all the parts of the scene's background
	update_status PostUpdate() override;

	bool CleanUp();

public:
	SDL_Rect background;

	SDL_Texture* HUDTexture = nullptr;

	// HUD & Foreground Animations
	Animation 
		HUDP1,
		HUDP234,
		insertCoinP2,
		insertCoinP3,
		insertCoinP4,
		lifeP1;

	// Font score index
	uint scoreP1 = 000;
	uint scoreP234 = 000;
	uint lifes = 000;
	int scoreFont = -1;
	int lifeFont = -1;
	char scoreTextP1[10] = { "\0" };
	char scoreTextP234[10] = { "\0" };
	char lifeText[10] = { "\0" };

	// Sound effects indices
	uint lifeIncrease = 0;

};


#endif //__MODULE_HUD_H__