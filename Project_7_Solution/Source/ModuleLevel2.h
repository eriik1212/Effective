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

	SDL_Rect background,
		drill,
		sayYourPrayersText;

	// The scene sprite sheet loaded into an SDL_Texture
	SDL_Texture* stage2Texture = nullptr;

	SDL_Texture* textTexture = nullptr;

	SDL_Texture* drillTexture = nullptr;

	SDL_Texture* aprilTexture = nullptr;

	SDL_Texture* shrederTexture = nullptr;

	// The pointer to the current player animation
	// It will be switched depending on the player's movement direction
	Animation* aprilCurrentAnimation = nullptr;

	Animation* shrederCurrentAnimation = nullptr;

	Animation* drillCurrentAnimation = nullptr;

	Animation aprilAnim,
		shrederStandAnim,
		shrederWalkAnim,
		shrederGrabAnim,
		shrederJumpAnim,
		
		drillAnim;

	// The path that will define the position in the world
	Path pathShreder;

	// The current position in the world
	iPoint positionShreder;

	// Original spawn position. Stored for movement calculations
	iPoint spawnPosShreder;

	int countDown = 0;
	int countDown2 = 0;

	// Sound effects indices
	uint drillSound = 0;
	uint door = 0;

	uint glassBreak = 0;
	uint sayYourPrayers = 0;

	uint rinoDamage = 0;
	uint rinoDead = 0;
};


#endif //__MODULE_LEVEL_2_H__