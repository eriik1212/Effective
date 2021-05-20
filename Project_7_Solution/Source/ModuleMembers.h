#ifndef __MODULE_MEMBERS_H__
#define __MODULE_MEMBERS_H__

#include "Module.h"
#include "Animation.h"
#include "ModuleInput.h"
#include "ModuleScene.h"
#include "ModulePlayer.h"
#include "ModuleEnemies.h"
#include "Path.h"

struct SDL_Texture;

class ModuleMembers : public Module
{
public:
	//Constructor
	ModuleMembers(bool startEnabled);

	//Destructor
	~ModuleMembers();

	// Called when the module is activated
	// Loads the necessary textures for the map background
	bool Start() override;

	// Called at the middle of the application loop
	// Updates the scene's background animations
	update_status Update() override;

	// Called at the end of the application loop.
	// Performs the render call of all the parts of the scene's background
	update_status PostUpdate() override;

public:
	// Members Texture
	SDL_Texture* introMembers;
};

#endif //__MODULE_MEMBERS_H__