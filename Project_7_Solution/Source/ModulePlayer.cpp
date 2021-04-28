#include "ModulePlayer.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleParticles.h"
#include "ModuleAudio.h"
#include "ModuleCollisions.h"
#include "ModuleFonts.h"
#include "ModuleSceneIntro.h"
#include "ModuleSceneLose.h"

#include <stdio.h>

#include "SDL/include/SDL_scancode.h"
#include "SDL/include/SDL.h"


ModulePlayer::ModulePlayer(bool enabled) : Module(enabled)
{
	srand(time(NULL));



	// ALL ANIMATIONS DOWN HERE
	{
		// Atack Quote
		AttackQuote.PushBack({ 116, 168, 64, 32 });
		AttackQuote.PushBack({ 0, 296, 64, 32 });
		AttackQuote.speed = 0.015f;
		AttackQuote.loop = false;

		// Life's Animation
		lifeP1.PushBack({ 6, 233, 31, 11 });
		lifeP1.PushBack({ 40, 233, 31, 11 });
		lifeP1.PushBack({ 74, 233, 31, 11 });
		lifeP1.PushBack({ 108, 233, 31, 11 });
		lifeP1.PushBack({ 143, 233, 31, 11 });
		lifeP1.PushBack({ 177, 233, 31, 11 });
		lifeP1.PushBack({ 211, 233, 31, 11 });
		lifeP1.PushBack({ 246, 233, 31, 11 });
		lifeP1.PushBack({ 280, 233, 31, 11 });
		lifeP1.PushBack({ 314, 233, 31, 11 });
		lifeP1.PushBack({ 360, 233, 31, 11 });
		lifeP1.loop = false;

		// HUD Player1
		HUDP1.PushBack({ 5, 0, 72, 32 });

		// HUD Player2,3,4
		HUDP234.PushBack({ 77, 107, 213, 32 });

		// INSERT COIN Anim for P2, P3, P4
		// P2
		insertCoinP2.PushBack({ 6, 167, 71, 13 });
		insertCoinP2.PushBack({ 83, 167, 71, 13 });
		insertCoinP2.PushBack({ 160, 167, 71, 13 });
		insertCoinP2.PushBack({ 238, 167, 71, 13 });
		insertCoinP2.PushBack({ 315, 167, 71, 13 });
		insertCoinP2.PushBack({ 6, 187, 71, 13 });
		insertCoinP2.PushBack({ 83, 187, 71, 13 });
		insertCoinP2.PushBack({ 160, 187, 71, 13 });
		insertCoinP2.PushBack({ 238, 187, 71, 13 });
		insertCoinP2.PushBack({ 315, 187, 71, 13 });
		insertCoinP2.speed = 0.15f;
		insertCoinP2.loop = true;

		// P3
		insertCoinP3.PushBack({ 83, 167, 71, 13 });
		insertCoinP3.PushBack({ 160, 167, 71, 13 });
		insertCoinP3.PushBack({ 238, 167, 71, 13 });
		insertCoinP3.PushBack({ 315, 167, 71, 13 });
		insertCoinP3.PushBack({ 6, 187, 71, 13 });
		insertCoinP3.PushBack({ 83, 187, 71, 13 });
		insertCoinP3.PushBack({ 160, 187, 71, 13 });
		insertCoinP3.PushBack({ 238, 187, 71, 13 });
		insertCoinP3.PushBack({ 315, 187, 71, 13 });
		insertCoinP3.PushBack({ 6, 167, 71, 13 });
		insertCoinP3.speed = 0.15f;
		insertCoinP3.loop = true;

		// P4
		insertCoinP4.PushBack({ 160, 167, 71, 13 });
		insertCoinP4.PushBack({ 238, 167, 71, 13 });
		insertCoinP4.PushBack({ 315, 167, 71, 13 });
		insertCoinP4.PushBack({ 6, 187, 71, 13 });
		insertCoinP4.PushBack({ 83, 187, 71, 13 });
		insertCoinP4.PushBack({ 160, 187, 71, 13 });
		insertCoinP4.PushBack({ 238, 187, 71, 13 });
		insertCoinP4.PushBack({ 315, 187, 71, 13 });
		insertCoinP4.PushBack({ 6, 167, 71, 13 });
		insertCoinP4.PushBack({ 83, 167, 71, 13 });
		insertCoinP4.speed = 0.15f;
		insertCoinP4.loop = true;

		// FrontFire animation
		frontFire.PushBack({ 335, 430, 304, 62 });
		frontFire.PushBack({ 19, 497, 304, 62 });
		frontFire.PushBack({ 336, 500, 304, 62 });
		frontFire.PushBack({ 21, 564, 304, 62 });

		//frontFire.PushBack({ 18, 429, 304, 62 });
		//frontFire.PushBack({ 336, 565, 304, 62 });

		frontFire.PushBack({ 710, 536, 304, 62 });
		frontFire.PushBack({ 1030, 536, 304, 62 });
		frontFire.speed = 0.15f;


		// SmallFire In Map Animation
		smallFire.PushBack({ 20, 635, 82, 46 });
		smallFire.PushBack({ 102, 635, 82, 46 });
		smallFire.PushBack({ 184, 635, 82, 46 });
		smallFire.PushBack({ 266, 635, 82, 46 });
		smallFire.PushBack({ 348, 635, 82, 46 });
		smallFire.PushBack({ 430, 635, 82, 46 });
		smallFire.speed = 0.15f;

		// ---------------------------------------------------------------------idle animation
		// RIGHT
		idleAnimR.PushBack({ 2, 0, 94, 84 });
		idleAnimR.PushBack({ 94, 0, 94, 84 });
		idleAnimR.PushBack({ 282, 0, 94, 84 });
		idleAnimR.PushBack({ 94, 0, 94, 84 });
		idleAnimR.PushBack({ 2, 0, 94, 84 });
		idleAnimR.PushBack({ 470, 0, 94, 84 });
		idleAnimR.PushBack({ 2, 0, 94, 84 });
		idleAnimR.PushBack({ 94, 0, 94, 84 });
		idleAnimR.PushBack({ 188, 0, 94, 84 });
		idleAnimR.PushBack({ 94, 0, 94, 84 });
		idleAnimR.PushBack({ 282, 0, 94, 84 });
		idleAnimR.PushBack({ 94, 0, 94, 84 });
		idleAnimR.PushBack({ 2, 0, 94, 84 });
		idleAnimR.loop = true;
		idleAnimR.speed = 0.02f;

		// LEFT
		idleAnimL.PushBack({ 1690, 1680, 94, 84 });
		idleAnimL.PushBack({ 1598, 1680, 94, 84 });
		idleAnimL.PushBack({ 1410, 1680, 94, 84 });
		idleAnimL.PushBack({ 1598, 1680, 94, 84 });
		idleAnimL.PushBack({ 1690, 1680, 94, 84 });
		idleAnimL.PushBack({ 1222, 1680, 94, 84 });
		idleAnimL.PushBack({ 1690, 1680, 94, 84 });
		idleAnimL.PushBack({ 1598, 1680, 94, 84 });
		idleAnimL.PushBack({ 1504, 1680, 94, 84 });
		idleAnimL.PushBack({ 1598, 1680, 94, 84 });
		idleAnimL.PushBack({ 1410, 1680, 94, 84 });
		idleAnimL.PushBack({ 1598, 1680, 94, 84 });
		idleAnimL.PushBack({ 1690, 1680, 94, 84 });
		idleAnimL.loop = true;
		idleAnimL.speed = 0.02f;
		//-----------------------------------------------------------------------------MOVE
		// move right
		rightAnim.PushBack({ 0, 924, 94, 84 });
		rightAnim.PushBack({ 94, 924, 94, 84 });
		rightAnim.PushBack({ 188, 924, 94, 84 });
		rightAnim.PushBack({ 282, 924, 94, 84 });
		rightAnim.PushBack({ 376, 924, 94, 84 });
		rightAnim.PushBack({ 470, 924, 94, 84 });
		rightAnim.PushBack({ 564, 924, 94, 84 });
		rightAnim.PushBack({ 658, 924, 94, 84 });
		rightAnim.loop = true;
		rightAnim.speed = 0.25f;

		// move left
		leftAnim.PushBack({ 1692, 2604, 94, 84 });
		leftAnim.PushBack({ 1598, 2604, 94, 84 });
		leftAnim.PushBack({ 1504, 2604, 94, 84 });
		leftAnim.PushBack({ 1410, 2604, 94, 84 });
		leftAnim.PushBack({ 1316, 2604, 94, 84 });
		leftAnim.PushBack({ 1222, 2604, 94, 84 });
		leftAnim.PushBack({ 1128, 2604, 94, 84 });
		leftAnim.PushBack({ 1034, 2604, 94, 84 });
		leftAnim.loop = true;
		leftAnim.speed = 0.25f;

		// move upwards
		// RIGHT
		upAnimR.PushBack({ 0, 1008, 94, 84 });
		upAnimR.PushBack({ 94, 1008, 94, 84 });
		upAnimR.PushBack({ 188, 1008, 94, 84 });
		upAnimR.PushBack({ 282, 1008, 94, 84 });
		upAnimR.PushBack({ 376, 1008, 94, 84 });
		upAnimR.PushBack({ 470, 1008, 94, 84 });
		upAnimR.PushBack({ 564, 1008, 94, 84 });
		upAnimR.PushBack({ 658, 1008, 94, 84 });
		upAnimR.loop = true;
		upAnimR.speed = 0.25f;

		//LEFT
		upAnimL.PushBack({ 1692, 2688, 94, 84 });
		upAnimL.PushBack({ 1598, 2688, 94, 84 });
		upAnimL.PushBack({ 1504, 2688, 94, 84 });
		upAnimL.PushBack({ 1410, 2688, 94, 84 });
		upAnimL.PushBack({ 1316, 2688, 94, 84 });
		upAnimL.PushBack({ 1222, 2688, 94, 84 });
		upAnimL.PushBack({ 1128, 2688, 94, 84 });
		upAnimL.PushBack({ 1034, 2688, 94, 84 });
		upAnimL.loop = true;
		upAnimL.speed = 0.25f;

		// Move down
		// RIGHT
		downAnimR.PushBack({ 0, 924, 94, 84 });
		downAnimR.PushBack({ 94, 924, 94, 84 });
		downAnimR.PushBack({ 188, 924, 94, 84 });
		downAnimR.PushBack({ 282, 924, 94, 84 });
		downAnimR.PushBack({ 376, 924, 94, 84 });
		downAnimR.PushBack({ 470, 924, 94, 84 });
		downAnimR.PushBack({ 564, 924, 94, 84 });
		downAnimR.PushBack({ 658, 924, 94, 84 });
		downAnimR.loop = true;
		downAnimR.speed = 0.25f;

		// LEFT
		downAnimL.PushBack({ 1692, 2604, 94, 84 });
		downAnimL.PushBack({ 1598, 2604, 94, 84 });
		downAnimL.PushBack({ 1504, 2604, 94, 84 });
		downAnimL.PushBack({ 1410, 2604, 94, 84 });
		downAnimL.PushBack({ 1316, 2604, 94, 84 });
		downAnimL.PushBack({ 1222, 2604, 94, 84 });
		downAnimL.PushBack({ 1128, 2604, 94, 84 });
		downAnimL.PushBack({ 1034, 2604, 94, 84 });
		downAnimL.loop = true;
		downAnimL.speed = 0.25f;

		//---------------------------------------------------------------------------- JUMP
		//-------------------------------------------------------------Right
		InitjumpAnimR.PushBack({ 0, 588, 94, 84 });
		jumpAnimR.PushBack({ 94, 588, 94, 84 });
		jumpAnimR.PushBack({ 188, 588, 94, 84 });
		jumpAnimR.PushBack({ 282, 588, 94, 84 });
		jumpAnimR.PushBack({ 376, 588, 94, 84 });
		jumpAnimR.PushBack({ 470, 588, 94, 84 });
		jumpAnimR.PushBack({ 564, 588, 94, 84 });
		jumpAnimR.PushBack({ 658, 588, 94, 84 });
		jumpAnimR.PushBack({ 752, 588, 94, 84 });
		jumpAnimR.PushBack({ 846, 588, 94, 84 });


		jumpAnimR.loop = false;
		jumpAnimR.speed = 0.25f;

		//---------------------------------- JUMP HIT ANIM
		hitJumpHorizontalAnimR.PushBack({ 0, 672, 94, 84 });
		hitJumpHorizontalAnimR.PushBack({ 94, 672, 94, 84 });
		hitJumpHorizontalAnimR.PushBack({ 188, 672, 94, 84 });
		hitJumpHorizontalAnimR.loop = false;
		hitJumpHorizontalAnimR.speed = 0.1f;

		hitJumpSwordAnimR.PushBack({ 0, 756, 94, 84 });
		hitJumpSwordAnimR.PushBack({ 94, 756, 94, 84 });
		hitJumpSwordAnimR.PushBack({ 188, 756, 94, 84 });
		hitJumpSwordAnimR.PushBack({ 282, 756, 94, 84 });
		hitJumpSwordAnimR.PushBack({ 376, 756, 94, 84 });
		hitJumpSwordAnimR.PushBack({ 470, 756, 94, 84 });
		hitJumpSwordAnimR.PushBack({ 564, 756, 94, 84 });
		hitJumpSwordAnimR.loop = false;
		hitJumpSwordAnimR.speed = 0.2f;

		hitJumpDownAnimR.PushBack({ 0, 840, 94, 84 });
		hitJumpDownAnimR.PushBack({ 94, 840, 94, 84 });
		hitJumpDownAnimR.PushBack({ 188, 840, 94, 84 });
		hitJumpDownAnimR.loop = false;
		hitJumpDownAnimR.speed = 0.2f;

		//--------------------------------------------------------------Left
		InitjumpAnimL.PushBack({ 1692, 2268, 94, 84 });
		jumpAnimL.PushBack({ 1598, 2268, 94, 84 });
		jumpAnimL.PushBack({ 1504, 2268, 94, 84 });
		jumpAnimL.PushBack({ 1410, 2268, 94, 84 });
		jumpAnimL.PushBack({ 1316, 2268, 94, 84 });
		jumpAnimL.PushBack({ 1222, 2268, 94, 84 });
		jumpAnimL.PushBack({ 1128, 2268, 94, 84 });
		jumpAnimL.PushBack({ 1034, 2268, 94, 84 });
		jumpAnimL.PushBack({ 940, 2268, 94, 84 });
		jumpAnimL.PushBack({ 846, 2268, 94, 84 });
		jumpAnimL.loop = false;
		jumpAnimL.speed = 0.25f;

		//---------------------------------- JUMP HIT ANIM
		hitJumpHorizontalAnimL.PushBack({ 1692, 2352, 94, 84 });
		hitJumpHorizontalAnimL.PushBack({ 1598, 2352, 94, 84 });
		hitJumpHorizontalAnimL.PushBack({ 1504, 2352, 94, 84 });
		hitJumpHorizontalAnimL.loop = false;
		hitJumpHorizontalAnimL.speed = 0.1f;

		hitJumpSwordAnimL.PushBack({ 1692, 2436, 94, 84 });
		hitJumpSwordAnimL.PushBack({ 1598, 2436, 94, 84 });
		hitJumpSwordAnimL.PushBack({ 1504, 2436, 94, 84 });
		hitJumpSwordAnimL.PushBack({ 1410, 2436, 94, 84 });
		hitJumpSwordAnimL.PushBack({ 1316, 2436, 94, 84 });
		hitJumpSwordAnimL.PushBack({ 1222, 2436, 94, 84 });
		hitJumpSwordAnimL.PushBack({ 1128, 2436, 94, 84 });
		hitJumpSwordAnimL.loop = false;
		hitJumpSwordAnimL.speed = 0.2f;

		hitJumpDownAnimL.PushBack({ 1692, 2520, 94, 84 });
		hitJumpDownAnimL.PushBack({ 1598, 2520, 94, 84 });
		hitJumpDownAnimL.PushBack({ 1504, 2520, 94, 84 });
		hitJumpDownAnimL.loop = false;
		hitJumpDownAnimL.speed = 0.2f;

		// Hit Air Animation 1
		// RIGHT
		hitAirAnim1R.PushBack({ 8, 336, 94, 84 });
		hitAirAnim1R.PushBack({ 94, 336, 94, 84 });
		hitAirAnim1R.PushBack({ 180, 336, 102, 84 });
		hitAirAnim1R.PushBack({ 282, 336, 102, 84 });
		hitAirAnim1R.PushBack({ 390, 336, 94, 84 });
		hitAirAnim1R.PushBack({ 492, 336, 94, 84 });
		hitAirAnim1R.loop = false;
		hitAirAnim1R.speed = 0.3f;

		// LEFT
		hitAirAnim1L.PushBack({ 1692, 2016, 94, 84 });
		hitAirAnim1L.PushBack({ 1598, 2016, 94, 84 });
		hitAirAnim1L.PushBack({ 1504, 2016, 94, 84 });
		hitAirAnim1L.PushBack({ 1398, 2016, 94, 84 });
		hitAirAnim1L.PushBack({ 1304, 2016, 94, 84 });
		hitAirAnim1L.PushBack({ 1196, 2016, 116, 84 });
		hitAirAnim1L.loop = false;
		hitAirAnim1L.speed = 0.3f;


		// Hit Air Animation 2
		// RIGHT
		hitAirAnim2R.PushBack({ 0, 168, 94, 84 });
		hitAirAnim2R.PushBack({ 98, 168, 94, 84 });
		hitAirAnim2R.PushBack({ 192, 168, 94, 84 });
		hitAirAnim2R.PushBack({ 276, 168, 94, 84 });
		hitAirAnim2R.PushBack({ 370, 168, 94, 84 });
		hitAirAnim2R.PushBack({ 476, 168, 94, 84 });
		hitAirAnim2R.loop = false;
		hitAirAnim2R.speed = 0.3f;


		// LEFT
		hitAirAnim2L.PushBack({ 1692, 1848, 94, 84 });
		hitAirAnim2L.PushBack({ 1598, 1848, 94, 84 });
		hitAirAnim2L.PushBack({ 1504, 1848, 94, 84 });
		hitAirAnim2L.PushBack({ 1410, 1848, 94, 84 });
		hitAirAnim2L.PushBack({ 1316, 1848, 94, 84 });
		hitAirAnim2L.PushBack({ 1222, 1848, 94, 84 });
		hitAirAnim2L.loop = false;
		hitAirAnim2L.speed = 0.3f;

		//------------------------------------------------------------------------------------- Hit Collide
		// 1R
		hitKickAnimR.PushBack({ 4, 84, 94, 84 });
		hitKickAnimR.PushBack({ 94, 84, 94, 84 });
		hitKickAnimR.PushBack({ 182, 84, 108, 84 });
		hitKickAnimR.PushBack({ 300, 84, 94, 84 });

		hitKickAnimR.loop = false;
		hitKickAnimR.speed = 0.2f;

		// 1L
		hitKickAnimL.PushBack({ 1692, 1764, 94, 84 });
		hitKickAnimL.PushBack({ 1598, 1764, 94, 84 });
		hitKickAnimL.PushBack({ 1504, 1764, 108, 84 });
		hitKickAnimL.PushBack({ 1410, 1764, 94, 84 });

		hitKickAnimL.loop = false;
		hitKickAnimL.speed = 0.2f;

		// 2R
		hitThrowAnimR.PushBack({ 1692, 1932, 94, 84 });
		hitThrowAnimR.PushBack({ 1598, 1932, 94, 84 });
		hitThrowAnimR.PushBack({ 1504, 1932, 94, 84 });
		hitThrowAnimR.PushBack({ 1410, 1932, 94, 84 });
		hitThrowAnimR.PushBack({ 1316, 1932, 94, 84 });
		hitThrowAnimR.loop = false;
		hitThrowAnimR.speed = 0.15f;

		// 2L
		hitThrowAnimL.PushBack({ 0, 252, 94, 84 });
		hitThrowAnimL.PushBack({ 94, 252, 94, 84 });
		hitThrowAnimL.PushBack({ 188, 252, 94, 84 });
		hitThrowAnimL.PushBack({ 282, 252, 94, 84 });
		hitThrowAnimL.PushBack({ 376, 252, 94, 84 });
		hitThrowAnimL.loop = false;
		hitThrowAnimL.speed = 0.15f;

		// 3R
		hitUpAnimR.PushBack({ 0, 420, 94, 84 });
		hitUpAnimR.PushBack({ 94, 420, 94, 84 });
		hitUpAnimR.PushBack({ 188, 420, 94, 84 });
		hitUpAnimR.PushBack({ 282, 420, 94, 84 });
		hitUpAnimR.loop = false;
		hitUpAnimR.speed = 0.3f;

		// 3L
		hitUpAnimL.PushBack({ 1692, 2100, 94, 84 });
		hitUpAnimL.PushBack({ 1598, 2100, 94, 84 });
		hitUpAnimL.PushBack({ 1504, 2100, 94, 84 });
		hitUpAnimL.PushBack({ 1410, 2100, 94, 84 });
		hitUpAnimL.loop = false;
		hitUpAnimL.speed = 0.3f;

		// 4R
		hitDownAnimR.PushBack({ 0, 504, 94, 84 });
		hitDownAnimR.PushBack({ 94, 504, 94, 84 });
		hitDownAnimR.PushBack({ 188, 504, 94, 84 });
		hitDownAnimR.PushBack({ 282, 504, 110, 84 });
		hitDownAnimR.loop = false;
		hitDownAnimR.speed = 0.3f;

		// 4L
		hitDownAnimL.PushBack({ 1692, 2184, 94, 84 });
		hitDownAnimL.PushBack({ 1598, 2184, 94, 84 });
		hitDownAnimL.PushBack({ 1504, 2184, 94, 84 });
		hitDownAnimL.PushBack({ 1415, 2184, 94, 84 });
		hitDownAnimL.loop = false;
		hitDownAnimL.speed = 0.3f;

		// 5R
		hitPrickAnimR.PushBack({ 0, 3780, 94, 84 });
		hitPrickAnimR.PushBack({ 94, 3780, 94, 84 });
		hitPrickAnimR.PushBack({ 188, 3780, 94, 84 });
		hitPrickAnimR.PushBack({ 278, 3780, 104, 84 });
		hitPrickAnimR.PushBack({ 380, 3780, 116, 84 });
		hitPrickAnimR.loop = false;
		hitPrickAnimR.speed = 0.3f;

		// 5L
		hitPrickAnimL.PushBack({ 1692, 3360, 94, 84 });
		hitPrickAnimL.PushBack({ 1598, 3360, 94, 84 });
		hitPrickAnimL.PushBack({ 1504, 3360, 94, 84 });
		hitPrickAnimL.PushBack({ 1410, 3360, 94, 84 });
		hitPrickAnimL.PushBack({ 1316, 3360, 94, 84 });
		hitPrickAnimL.loop = false;
		hitPrickAnimL.speed = 0.3f;

		// 6R
		hitOverAnimR.PushBack({ 0, 3864, 94, 84 });
		hitOverAnimR.PushBack({ 88, 3864, 94, 84 });
		hitOverAnimR.PushBack({ 188, 3864, 94, 84 });
		hitOverAnimR.PushBack({ 278, 3864, 94, 84 });
		hitOverAnimR.PushBack({ 381, 3864, 94, 84 });
		hitOverAnimR.loop = false;
		hitOverAnimR.speed = 0.3f;

		// 6L
		hitOverAnimL.PushBack({ 1692, 3444, 94, 84 });
		hitOverAnimL.PushBack({ 1598, 3444, 94, 84 });
		hitOverAnimL.PushBack({ 1504, 3444, 94, 84 });
		hitOverAnimL.PushBack({ 1412, 3444, 94, 84 });
		hitOverAnimL.PushBack({ 1304, 3444, 110, 84 });
		hitOverAnimL.loop = false;
		hitOverAnimL.speed = 0.3f;


		// ---------------------------------------------------------------- Hitted
		// --------------------------------------------- Front
		// 1R
		hittedLowAnim1R.PushBack({ 0, 1092, 94, 84 });
		hittedLowAnim1R.PushBack({ 94, 1092, 94, 84 });
		hittedLowAnim1R.PushBack({ 188, 1092, 94, 84 });
		hittedLowAnim1R.PushBack({ 282, 1092, 94, 84 });
		hittedLowAnim1R.PushBack({ 376, 1092, 94, 84 });
		hittedLowAnim1R.loop = false;
		hittedLowAnim1R.speed = 0.2f;

		// 1L
		hittedLowAnim1L.PushBack({ 1692, 2772, 94, 84 });
		hittedLowAnim1L.PushBack({ 1598, 2772, 94, 84 });
		hittedLowAnim1L.PushBack({ 1504, 2772, 94, 84 });
		hittedLowAnim1L.PushBack({ 1410, 2772, 94, 84 });
		hittedLowAnim1L.PushBack({ 1316, 2772, 94, 84 });
		hittedLowAnim1L.loop = false;
		hittedLowAnim1L.speed = 0.2f;

		// 2R
		hittedLowAnim2R.PushBack({ 0, 1176, 94, 84 });
		hittedLowAnim2R.PushBack({ 94, 1176, 94, 84 });
		hittedLowAnim2R.PushBack({ 188, 1176, 94, 84 });
		hittedLowAnim2R.PushBack({ 282, 1176, 94, 84 });
		hittedLowAnim2R.PushBack({ 376, 1176, 94, 84 });
		hittedLowAnim2R.loop = false;
		hittedLowAnim2R.speed = 0.2f;

		// 2L
		hittedLowAnim2L.PushBack({ 1692, 2856, 94, 84 });
		hittedLowAnim2L.PushBack({ 1598, 2856, 94, 84 });
		hittedLowAnim2L.PushBack({ 1504, 2856, 94, 84 });
		hittedLowAnim2L.PushBack({ 1410, 2856, 94, 84 });
		hittedLowAnim2L.PushBack({ 1316, 2856, 94, 84 });
		hittedLowAnim2L.loop = false;
		hittedLowAnim2L.speed = 0.2f;

		// 3R
		hittedMediumAnimR.PushBack({ 0, 1260, 94, 84 });
		hittedMediumAnimR.PushBack({ 94, 1260, 94, 84 });
		hittedMediumAnimR.PushBack({ 188, 1260, 94, 84 });
		hittedMediumAnimR.PushBack({ 282, 1260, 94, 84 });
		hittedMediumAnimR.PushBack({ 376, 1260, 94, 84 });
		hittedMediumAnimR.PushBack({ 470, 1240, 94, 120 });
		hittedMediumAnimR.PushBack({ 564, 1260, 94, 84 });
		hittedMediumAnimR.PushBack({ 658, 1260, 94, 84 });
		hittedMediumAnimR.PushBack({ 752, 1260, 94, 84 });
		hittedMediumAnimR.PushBack({ 846, 1260, 94, 84 });
		hittedMediumAnimR.loop = false;
		hittedMediumAnimR.speed = 0.2f;

		// 3L
		hittedMediumAnimL.PushBack({ 1692, 2940, 94, 84 });
		hittedMediumAnimL.PushBack({ 1598, 2940, 94, 84 });
		hittedMediumAnimL.PushBack({ 1504, 2940, 94, 84 });
		hittedMediumAnimL.PushBack({ 1410, 2940, 94, 84 });
		hittedMediumAnimL.PushBack({ 1316, 2940, 94, 84 });
		hittedMediumAnimL.PushBack({ 1222, 2920, 94, 120 });
		hittedMediumAnimL.PushBack({ 1128, 2940, 94, 84 });
		hittedMediumAnimL.PushBack({ 1034, 2940, 94, 84 });
		hittedMediumAnimL.PushBack({ 940, 2940, 94, 84 });
		hittedMediumAnimL.PushBack({ 846, 2940, 94, 84 });
		hittedMediumAnimL.loop = false;
		hittedMediumAnimL.speed = 0.2f;

		// 4R
		hittedHighAnimR.PushBack({ 0, 4032, 94, 84 });
		hittedHighAnimR.PushBack({ 94, 4032, 94, 84 });
		hittedHighAnimR.PushBack({ 188, 4032, 94, 84 });
		hittedHighAnimR.PushBack({ 282, 4032, 94, 84 });
		hittedHighAnimR.PushBack({ 376, 4032, 94, 84 });
		hittedHighAnimR.PushBack({ 470, 4032, 94, 84 });
		hittedHighAnimR.PushBack({ 564, 4032, 94, 84 });
		hittedHighAnimR.PushBack({ 658, 4032, 94, 84 });
		hittedHighAnimR.PushBack({ 752, 4032, 94, 84 });
		hittedHighAnimR.PushBack({ 846, 4022, 94, 110 });
		hittedHighAnimR.PushBack({ 940, 4032, 94, 84 });
		hittedHighAnimR.loop = false;
		hittedHighAnimR.speed = 0.1f;

		// 4L
		hittedHighAnimL.PushBack({ 1692, 3612, 94, 84 });
		hittedHighAnimL.PushBack({ 1598, 3612, 94, 84 });
		hittedHighAnimL.PushBack({ 1504, 3612, 94, 84 });
		hittedHighAnimL.PushBack({ 1410, 3612, 94, 84 });
		hittedHighAnimL.PushBack({ 1316, 3612, 94, 84 });
		hittedHighAnimL.PushBack({ 1222, 3612, 94, 84 });
		hittedHighAnimL.PushBack({ 1128, 3612, 94, 84 });
		hittedHighAnimL.PushBack({ 1034, 3612, 94, 84 });
		hittedHighAnimL.PushBack({ 940, 3612, 94, 84 });
		hittedHighAnimL.PushBack({ 846, 3592, 94, 120 });
		hittedHighAnimL.PushBack({ 752, 3612, 94, 84 });
		hittedHighAnimL.loop = false;
		hittedHighAnimL.speed = 0.1f;

		// --------------------------------------------- Back
		// 5R
		hittedBackLowAnimR.PushBack({ 0, 1344, 94, 84 });
		hittedBackLowAnimR.PushBack({ 92, 1344, 94, 84 });
		hittedBackLowAnimR.PushBack({ 172, 1344, 110, 84 });
		hittedBackLowAnimR.loop = false;
		hittedBackLowAnimR.speed = 0.1f;

		// 5L
		hittedBackLowAnimL.PushBack({ 1692, 3024, 94, 84 });
		hittedBackLowAnimL.PushBack({ 1594, 3024, 94, 84 });
		hittedBackLowAnimL.PushBack({ 1525, 3024, 80, 84 });
		hittedBackLowAnimL.loop = false;
		hittedBackLowAnimL.speed = 0.1f;

		// 6R
		hittedBackMediumAnimR.PushBack({ 0, 1512, 94, 84 });
		hittedBackMediumAnimR.PushBack({ 94, 1512, 94, 84 });
		hittedBackMediumAnimR.PushBack({ 188, 1512, 94, 84 });
		hittedBackMediumAnimR.PushBack({ 282, 1512, 94, 84 });
		hittedBackMediumAnimR.PushBack({ 376, 1512, 94, 84 });
		hittedBackMediumAnimR.PushBack({ 470, 1512, 94, 84 });
		hittedBackMediumAnimR.PushBack({ 564, 1512, 90, 84 });
		hittedBackMediumAnimR.PushBack({ 654, 1512, 94, 84 });
		hittedBackMediumAnimR.PushBack({ 752, 1512, 94, 84 });
		hittedBackMediumAnimR.PushBack({ 846, 1512, 94, 84 });
		hittedBackMediumAnimR.loop = false;
		hittedBackMediumAnimR.speed = 0.1f;

		// 6L
		hittedBackMediumAnimL.PushBack({ 1692, 3192, 94, 84 });
		hittedBackMediumAnimL.PushBack({ 1598, 3192, 94, 84 });
		hittedBackMediumAnimL.PushBack({ 1504, 3192, 94, 84 });
		hittedBackMediumAnimL.PushBack({ 1410, 3192, 94, 84 });
		hittedBackMediumAnimL.PushBack({ 1316, 3192, 94, 84 });
		hittedBackMediumAnimL.PushBack({ 1222, 3192, 94, 84 });
		hittedBackMediumAnimL.PushBack({ 1132, 3192, 94, 84 });
		hittedBackMediumAnimL.PushBack({ 1034, 3192, 94, 84 });
		hittedBackMediumAnimL.PushBack({ 940, 3192, 94, 84 });
		hittedBackMediumAnimL.PushBack({ 846, 3192, 94, 84 });
		hittedBackMediumAnimL.loop = false;
		hittedBackMediumAnimL.speed = 0.1f;

		// 7R
		hittedBackHighAnimR.PushBack({ 0, 1428, 94, 84 });
		hittedBackHighAnimR.PushBack({ 188, 1428, 94, 84 });
		hittedBackHighAnimR.PushBack({ 282, 1428, 94, 84 });
		hittedBackHighAnimR.PushBack({ 376, 1428, 94, 84 });
		hittedBackHighAnimR.PushBack({ 470, 1428, 94, 84 });
		hittedBackHighAnimR.PushBack({ 564, 1428, 90, 84 });
		hittedBackHighAnimR.PushBack({ 654, 1428, 94, 84 });
		hittedBackHighAnimR.PushBack({ 752, 1428, 94, 84 });
		hittedBackHighAnimR.PushBack({ 846, 1428, 94, 84 });
		hittedBackHighAnimR.PushBack({ 940, 1428, 90, 84 });
		hittedBackHighAnimR.PushBack({ 1034, 1428, 94, 84 });
		hittedBackHighAnimR.PushBack({ 1034, 1428, 94, 84 });
		hittedBackHighAnimR.PushBack({ 1132, 1428, 94, 84 });
		hittedBackHighAnimR.PushBack({ 1222, 1428, 94, 84 });
		hittedBackHighAnimR.loop = false;
		hittedBackHighAnimR.speed = 0.15f;

		// 7L
		hittedBackHighAnimL.PushBack({ 1692, 3108, 94, 84 });
		hittedBackHighAnimL.PushBack({ 1598, 3108, 94, 84 });
		hittedBackHighAnimL.PushBack({ 1504, 3108, 94, 84 });
		hittedBackHighAnimL.PushBack({ 1410, 3108, 94, 84 });
		hittedBackHighAnimL.PushBack({ 1316, 3108, 94, 84 });
		hittedBackHighAnimL.PushBack({ 1222, 3108, 94, 84 });
		hittedBackHighAnimL.PushBack({ 1132, 3108, 94, 84 });
		hittedBackHighAnimL.PushBack({ 1034, 3108, 94, 84 });
		hittedBackHighAnimL.PushBack({ 940, 3108, 94, 84 });
		hittedBackHighAnimL.PushBack({ 846, 3108, 94, 84 });
		hittedBackHighAnimL.PushBack({ 752, 3108, 94, 84 });
		hittedBackHighAnimL.PushBack({ 658, 3108, 94, 84 });
		hittedBackHighAnimL.PushBack({ 658, 3108, 94, 84 });
		hittedBackHighAnimL.PushBack({ 564, 3108, 94, 84 });
		hittedBackHighAnimL.PushBack({ 470, 3108, 94, 84 });
		hittedBackHighAnimL.loop = false;
		hittedBackHighAnimL.speed = 0.15f;

		// 8R
		hittedGrabbedAnimR.PushBack({ 0, 1596, 94, 84 });
		hittedGrabbedAnimR.PushBack({ 94, 1596, 94, 84 });
		hittedGrabbedAnimR.PushBack({ 188, 1596, 94, 84 });
		hittedGrabbedAnimR.loop = true;
		hittedGrabbedAnimR.speed = 0.1f;

		// 9L
		hittedGrabbedAnimL.PushBack({ 1692, 3276, 94, 84 });
		hittedGrabbedAnimL.PushBack({ 1598, 3276, 94, 84 });
		hittedGrabbedAnimL.PushBack({ 1504, 3276, 94, 84 });
		hittedGrabbedAnimL.loop = true;
		hittedGrabbedAnimL.speed = 0.1f;

		// -----------------------------------------------------------Death
		// Right
		deathAnimR.PushBack({ 1222, 3833, 94, 84 });
		deathAnimR.PushBack({ 1504, 3833, 94, 84 });
		deathAnimR.PushBack({ 1504, 3833, 94, 84 });
		deathAnimR.PushBack({ 1222, 3833, 94, 84 });
		deathAnimR.PushBack({ 1316, 3833, 94, 84 });
		deathAnimR.PushBack({ 1598, 3833, 94, 84 });
		deathAnimR.PushBack({ 1598, 3833, 94, 84 });
		deathAnimR.PushBack({ 1316, 3833, 94, 84 });
		deathAnimR.PushBack({ 1410, 3833, 94, 84 });
		deathAnimR.PushBack({ 1692, 3833, 94, 84 });
		deathAnimR.PushBack({ 1692, 3833, 94, 84 });
		deathAnimR.PushBack({ 1410, 3833, 94, 84 });
		deathAnimR.loop = true;
		deathAnimR.speed = 0.6f;

		// Left
		deathAnimL.PushBack({ 1692, 3735, 94, 84 });
		deathAnimL.PushBack({ 1410, 3735, 94, 84 });
		deathAnimL.PushBack({ 1410, 3735, 94, 84 });
		deathAnimL.PushBack({ 1692, 3735, 94, 84 });
		deathAnimL.PushBack({ 1598, 3735, 94, 84 });
		deathAnimL.PushBack({ 1316, 3735, 94, 84 });
		deathAnimL.PushBack({ 1316, 3735, 94, 84 });
		deathAnimL.PushBack({ 1598, 3735, 94, 84 });
		deathAnimL.PushBack({ 1504, 3735, 94, 84 });
		deathAnimL.PushBack({ 1222, 3735, 94, 84 });
		deathAnimL.PushBack({ 1222, 3735, 94, 84 });
		deathAnimL.PushBack({ 1504, 3735, 94, 84 });
		deathAnimL.loop = true;
		deathAnimL.speed = 0.6f;

	}
}


ModulePlayer::~ModulePlayer()
{

}

bool ModulePlayer::Start()
{
	LOG("Loading player textures");

	bool ret = true;

	blockAnim = false;

	lifeP1.Reset();

	scoreP1 = 0;

	position.x = 5;
	position.y = 112;

	// ----------------------------------------------------------------- LIFE ELEMENTS
	// Load Lifes P1
	for (int i = 0; i < MAX_LIFE; ++i) {
		lifesP1[i] = 1;
	}

	// ----------------------------------------------------------------- TEXTURES
	texture = App->textures->Load("Assets/Characters/Leonardo.png");
	fireTexture = App->textures->Load("Assets/Tilesets/fire.png");
	HUDTexture = App->textures->Load("Assets/UI & HUD/HUD.png");
	AttackQuoteTexture = App->textures->Load("Assets/UI & HUD/Quotes.png");
	currentAnimation = &idleAnimR;

	// ----------------------------------------------------------------- AUDIO
	PunchMiss = App->audio->LoadFx("Assets/FX/Punch1.wav");
	PunchHit = App->audio->LoadFx("Assets/Fx/Punch2.wav");
	Scream1 = App->audio->LoadFx("Assets/FX/AtackScream.wav");
	lifeIncrease = App->audio->LoadFx("Assets/FX/01Cowabunga.wav");

	// ----------------------------------------------------------------- COLLIDERS
	HIT = App->collisions->AddCollider({ position.x , position.y  , 58, 16 }, Collider::Type::PLAYER_SHOT,this);
	collider = App->collisions->AddCollider({ position.x, position.y, 38, 16 }, Collider::Type::PLAYER, this);

	// ----------------------------------------------------------------- FONTS
	char lookupTable[] = { "0123456789 " };
	scoreFont = App->fonts->Load("Assets/UI & HUD/fonts.png", lookupTable, 1);
	lifeFont = App->fonts->Load("Assets/UI & HUD/NumLifesFont.png", lookupTable, 1);

	return ret;
}

update_status ModulePlayer::Update()
{
	App->collisions->matrix[Collider::Type::ENEMY][Collider::Type::PLAYER_SHOT] = false;
	frontFire.Update();
	smallFire.Update();
	AttackQuote.Update();
	insertCoinP2.Update();
	insertCoinP3.Update();
	insertCoinP4.Update();

	// Position Players Limits
	if (position.x < App->render->playerLimitL) position.x = App->render->playerLimitL;
	if (position.x > 1250) position.x = 1250;
	if (position.y < 56) position.y = 56;
	if (position.y > 136) position.y = 136;

	// Camera Movement
	if (position.x > (App->render->playerLimitR))
	{
		if (App->render->camera.x < CAMERA_LIMIT)
		{
			App->render->camera.x += App->render->cameraSpeed;
			App->render->playerLimitR += speed;
			App->render->playerLimitL += speed;
		}
	}

	// ------------------------------- Life's Increment
	if (App->input->keys[SDL_SCANCODE_LSHIFT] == KEY_STATE::KEY_DOWN)
	{
		lifes += 2;
		App->audio->PlayFx(lifeIncrease);
	}

	// ------------------------------------------------------Hits RIGHT
	if (App->input->keys[SDL_SCANCODE_X] == KEY_STATE::KEY_DOWN && lastPosition == 0 && blockAnim == false)
	{
		
		int x = (rand() % 2);

		switch (x)
		{
		case 0:
			if (currentAnimation != &hitAirAnim1R
				&& currentAnimation != &hitAirAnim2R)
			{

			hitAirAnim1R.Reset();
			currentAnimation = &hitAirAnim1R;

		    App->collisions->matrix[Collider::Type::ENEMY][Collider::Type::PLAYER_SHOT] = true;
			App->audio->PlayFx(PunchMiss);

			}
			break;
		case 1:
			if (currentAnimation != &hitAirAnim2R
				&& currentAnimation != &hitAirAnim1R)
			{
				hitAirAnim2R.Reset();
				currentAnimation = &hitAirAnim2R;

				App->collisions->matrix[Collider::Type::ENEMY][Collider::Type::PLAYER_SHOT] = true;
				App->audio->PlayFx(PunchMiss);

			}
			break;

		default:

			break;
		}
	}

	// ------------------------------------------------------Hits LEFT
	if (App->input->keys[SDL_SCANCODE_X] == KEY_STATE::KEY_DOWN && lastPosition == 1 && blockAnim == false)
	{
		int x = (rand() % 2);

		switch (x)
		{
		case 0:
			if (currentAnimation != &hitAirAnim1L
				&& currentAnimation != &hitAirAnim2L)
			{
				hitAirAnim1L.Reset();
				currentAnimation = &hitAirAnim1L;

				App->collisions->matrix[Collider::Type::ENEMY][Collider::Type::PLAYER_SHOT] = true;
				App->audio->PlayFx(PunchMiss);


			}
			break;
		case 1:
			if (currentAnimation != &hitAirAnim2L
				&& currentAnimation != &hitAirAnim1L)
			{
				hitAirAnim2L.Reset();
				currentAnimation = &hitAirAnim2L;

				App->collisions->matrix[Collider::Type::ENEMY][Collider::Type::PLAYER_SHOT] = true;
				App->audio->PlayFx(PunchMiss);


			}
			break;
		default:
			break;

		}
	}

	// COLLIDE HITS
/*
	//------------------------------------------------------------------------------------ COLLIDE RIGHT
	else if (App->input->keys[SDL_SCANCODE_X] == KEY_STATE::KEY_DOWN && lastPosition == 0)
	{
		int x = (rand() % 6);

		switch (x)
		{
		case 0:
			if (currentAnimation != &hitKickAnimR
				&& currentAnimation != &hitThrowAnimR
				&& currentAnimation != &hitUpAnimR
				&& currentAnimation != &hitDownAnimR
				&& currentAnimation != &hitPrickAnimR
				&& currentAnimation != &hitOverAnimR)
			{

				hitKickAnimR.Reset();
				currentAnimation = &hitKickAnimR;

				App->collisions->matrix[Collider::Type::ENEMY][Collider::Type::PLAYER_SHOT] = true;
				App->audio->PlayFx(PunchHit);

			}
			break;
		case 1:
			if (currentAnimation != &hitKickAnimR
				&& currentAnimation != &hitThrowAnimR
				&& currentAnimation != &hitUpAnimR
				&& currentAnimation != &hitDownAnimR
				&& currentAnimation != &hitPrickAnimR
				&& currentAnimation != &hitOverAnimR)
			{
				hitThrowAnimR.Reset();
				currentAnimation = &hitThrowAnimR;

				App->collisions->matrix[Collider::Type::ENEMY][Collider::Type::PLAYER_SHOT] = true;
				App->audio->PlayFx(PunchHit);

			}
			break;
		case 2:
			if (currentAnimation != &hitKickAnimR
				&& currentAnimation != &hitThrowAnimR
				&& currentAnimation != &hitUpAnimR
				&& currentAnimation != &hitDownAnimR
				&& currentAnimation != &hitPrickAnimR
				&& currentAnimation != &hitOverAnimR)
			{
				hitUpAnimR.Reset();
				currentAnimation = &hitUpAnimR;

				App->collisions->matrix[Collider::Type::ENEMY][Collider::Type::PLAYER_SHOT] = true;
				App->audio->PlayFx(PunchHit);

			}
			break;
		case 3:
			if (currentAnimation != &hitKickAnimR
				&& currentAnimation != &hitThrowAnimR
				&& currentAnimation != &hitUpAnimR
				&& currentAnimation != &hitDownAnimR
				&& currentAnimation != &hitPrickAnimR
				&& currentAnimation != &hitOverAnimR)
			{
				hitDownAnimR.Reset();
				currentAnimation = &hitDownAnimR;

				App->collisions->matrix[Collider::Type::ENEMY][Collider::Type::PLAYER_SHOT] = true;
				App->audio->PlayFx(PunchHit);

			}
			break;
		case 4:
			if (currentAnimation != &hitKickAnimR
				&& currentAnimation != &hitThrowAnimR
				&& currentAnimation != &hitUpAnimR
				&& currentAnimation != &hitDownAnimR
				&& currentAnimation != &hitPrickAnimR
				&& currentAnimation != &hitOverAnimR)
			{
				hitPrickAnimR.Reset();
				currentAnimation = &hitPrickAnimR;

				App->collisions->matrix[Collider::Type::ENEMY][Collider::Type::PLAYER_SHOT] = true;
				App->audio->PlayFx(PunchHit);

			}
			break;
		case 5:
			if (currentAnimation != &hitKickAnimR
				&& currentAnimation != &hitThrowAnimR
				&& currentAnimation != &hitUpAnimR
				&& currentAnimation != &hitDownAnimR
				&& currentAnimation != &hitPrickAnimR
				&& currentAnimation != &hitOverAnimR)
			{
				hitOverAnimR.Reset();
				currentAnimation = &hitOverAnimR;

				App->collisions->matrix[Collider::Type::ENEMY][Collider::Type::PLAYER_SHOT] = true;
				App->audio->PlayFx(PunchHit);

			}
			break;
		default:

			break;
		}
	}

	// -------------------------------------------------------------------------------------- COLLIDE LEFT
	else if (App->input->keys[SDL_SCANCODE_X] == KEY_STATE::KEY_DOWN && lastPosition == 1)
	{
		int x = (rand() % 6);

		switch (x)
		{
		case 0:
			if (currentAnimation != &hitKickAnimL
				&& currentAnimation != &hitThrowAnimL
				&& currentAnimation != &hitUpAnimL
				&& currentAnimation != &hitDownAnimL
				&& currentAnimation != &hitPrickAnimL
				&& currentAnimation != &hitOverAnimL)
			{

				hitKickAnimL.Reset();
				currentAnimation = &hitKickAnimL;

				App->collisions->matrix[Collider::Type::ENEMY][Collider::Type::PLAYER_SHOT] = true;
				App->audio->PlayFx(PunchHit);

			}
			break;
		case 1:
			if (currentAnimation != &hitKickAnimL
				&& currentAnimation != &hitThrowAnimL
				&& currentAnimation != &hitUpAnimL
				&& currentAnimation != &hitDownAnimL
				&& currentAnimation != &hitPrickAnimL
				&& currentAnimation != &hitOverAnimL)
			{
				hitThrowAnimL.Reset();
				currentAnimation = &hitThrowAnimL;

				App->collisions->matrix[Collider::Type::ENEMY][Collider::Type::PLAYER_SHOT] = true;
				App->audio->PlayFx(PunchHit);

			}
			break;
		case 2:
			if (currentAnimation != &hitKickAnimL
				&& currentAnimation != &hitThrowAnimL
				&& currentAnimation != &hitUpAnimL
				&& currentAnimation != &hitDownAnimL
				&& currentAnimation != &hitPrickAnimL
				&& currentAnimation != &hitOverAnimL)
			{
				hitUpAnimL.Reset();
				currentAnimation = &hitUpAnimL;

				App->collisions->matrix[Collider::Type::ENEMY][Collider::Type::PLAYER_SHOT] = true;
				App->audio->PlayFx(PunchHit);

			}
			break;
		case 3:
			if (currentAnimation != &hitKickAnimL
				&& currentAnimation != &hitThrowAnimL
				&& currentAnimation != &hitUpAnimL
				&& currentAnimation != &hitDownAnimL
				&& currentAnimation != &hitPrickAnimL
				&& currentAnimation != &hitOverAnimL)
			{
				hitDownAnimL.Reset();
				currentAnimation = &hitDownAnimL;

				App->collisions->matrix[Collider::Type::ENEMY][Collider::Type::PLAYER_SHOT] = true;
				App->audio->PlayFx(PunchHit);

			}
			break;
		case 4:
			if (currentAnimation != &hitKickAnimL
				&& currentAnimation != &hitThrowAnimL
				&& currentAnimation != &hitUpAnimL
				&& currentAnimation != &hitDownAnimL
				&& currentAnimation != &hitPrickAnimL
				&& currentAnimation != &hitOverAnimL)
			{
				hitPrickAnimL.Reset();
				currentAnimation = &hitPrickAnimL;

				App->collisions->matrix[Collider::Type::ENEMY][Collider::Type::PLAYER_SHOT] = true;
				App->audio->PlayFx(PunchHit);

			}
			break;
		case 5:
			if (currentAnimation != &hitKickAnimL
				&& currentAnimation != &hitThrowAnimL
				&& currentAnimation != &hitUpAnimL
				&& currentAnimation != &hitDownAnimL
				&& currentAnimation != &hitPrickAnimL
				&& currentAnimation != &hitOverAnimL)
			{
				hitOverAnimL.Reset();
				currentAnimation = &hitOverAnimL;

				App->collisions->matrix[Collider::Type::ENEMY][Collider::Type::PLAYER_SHOT] = true;
				App->audio->PlayFx(PunchHit);

			}
			break;
		default:

			break;
		}
	}*/
	// ---------------------------------------------------------------------- Moving the player

	// ALL MOVEMENT KEYS PRESSED
	else if (App->input->keys[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT
		&& App->input->keys[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT
		&& App->input->keys[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT
		&& App->input->keys[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT
		&& blockAnim == false)
	{
		if (currentAnimation != &idleAnimR)
		{
			idleAnimR.Reset();
			currentAnimation = &idleAnimR;
		}
		else currentAnimation = &idleAnimR;
	}

	// THREE KEYS PRESSED
	else if (App->input->keys[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT
		&& App->input->keys[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT
		&& App->input->keys[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT
		&& blockAnim == false)
	{
		position.y -= speed;
		if (currentAnimation != &upAnimR)
		{
			upAnimR.Reset();
			currentAnimation = &upAnimR;
		}
	}

	else if (App->input->keys[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT
		&& App->input->keys[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT
		&& App->input->keys[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT
		&& blockAnim == false)
	{
		position.y += speed;
		if (currentAnimation != &downAnimR)
		{
			downAnimR.Reset();
			currentAnimation = &downAnimR;
		}
	}

	else if (App->input->keys[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT
		&& App->input->keys[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT
		&& App->input->keys[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT
		&& blockAnim == false)
	{
		position.x -= speed;
		if (currentAnimation != &leftAnim)
		{
			leftAnim.Reset();
			currentAnimation = &leftAnim;
		}
	}

	else if (App->input->keys[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT
		&& App->input->keys[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT
		&& App->input->keys[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT
		&& blockAnim == false)
	{
		position.x += speed;
		if (currentAnimation != &rightAnim)
		{
			rightAnim.Reset();
			currentAnimation = &rightAnim;
		}
	}

	// ---------------------------------------------JUMP RIGHT
	else if (App->input->keys[SDL_SCANCODE_Z] == KEY_STATE::KEY_REPEAT && lastPosition == 0 && blockAnim == false)
	{
	position.y -= 2;
	if (currentAnimation != &InitjumpAnimR)
	{
		InitjumpAnimR.Reset();
		currentAnimation = &InitjumpAnimR;

	}
	}

	else if (App->input->keys[SDL_SCANCODE_Z] == KEY_STATE::KEY_UP && lastPosition == 0 && blockAnim == false)
	{

	if (currentAnimation != &jumpAnimR)
	{
		jumpAnimR.Reset();
		currentAnimation = &jumpAnimR;

	}
	}

	// ---------------------------------------------JUMP LEFT
	else if (App->input->keys[SDL_SCANCODE_Z] == KEY_STATE::KEY_REPEAT && lastPosition == 1 && blockAnim == false)
	{
	position.y -= 2;
	if (currentAnimation != &InitjumpAnimL)
	{
		InitjumpAnimL.Reset();
		currentAnimation = &InitjumpAnimL;

	}
	}

	else if (App->input->keys[SDL_SCANCODE_Z] == KEY_STATE::KEY_UP && lastPosition == 1 && blockAnim == false)
	{

	if (currentAnimation != &jumpAnimL)
	{
		jumpAnimL.Reset();
		currentAnimation = &jumpAnimL;

	}
	}


	// UP & RIGHT MOVEMENT
	else if (App->input->keys[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT 
	&& App->input->keys[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT
	&& blockAnim == false)
	{
		position.x += speed;
		position.y -= speed;
		if (currentAnimation != &upAnimR)
		{
			upAnimR.Reset();
			currentAnimation = &upAnimR;
		}
	}

	// DOWN & RIGHT MOVEMENT
	else if (App->input->keys[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT 
	&& App->input->keys[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT
	&& blockAnim == false)
	{


		position.x += speed;
		position.y += speed;
		if (currentAnimation != &downAnimR)
		{
			downAnimR.Reset();
			currentAnimation = &downAnimR;
		}
	}

	// LEFT & UP MOVEMENT
	else if (App->input->keys[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT 
	&& App->input->keys[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT
	&& blockAnim == false)
	{
		position.x -= speed;
		position.y -= speed;
		if (currentAnimation != &upAnimL)
		{
			upAnimL.Reset();
			currentAnimation = &upAnimL;
		}
	}

	// LEFT & DOWN
	else if (App->input->keys[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT 
	&& App->input->keys[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT
	&& blockAnim == false)
	{
		position.x -= speed;
		position.y += speed;
		if (currentAnimation != &downAnimL)
		{
			downAnimL.Reset();
			currentAnimation = &downAnimL;
		}
	}

	// LEFT & RIGHT PRESSED
	else if (App->input->keys[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT 
	&& App->input->keys[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT
	&& blockAnim == false)
	{
		if (currentAnimation != &idleAnimR)
		{
			idleAnimR.Reset();
			currentAnimation = &idleAnimR;
		}
	}

	// UP & DOWN PRESSED
	else if (App->input->keys[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT
	&& App->input->keys[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT
	&& blockAnim == false)
	{
		if (currentAnimation != &idleAnimR)
		{
			idleAnimR.Reset();
			currentAnimation = &idleAnimR;
		}
	}

	// UP
	// ---------------------------------------------------------UP LEFT
	else if (App->input->keys[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT && lastPosition == 1 && blockAnim == false)
	{
		position.y -= speed;
		if (currentAnimation != &upAnimL)
		{
			upAnimL.Reset();
			currentAnimation = &upAnimL;
		}
	}

	// ---------------------------------------------------------UP RIGHT
	else if (App->input->keys[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT && lastPosition == 0 && blockAnim == false)
	{
	position.y -= speed;
	if (currentAnimation != &upAnimR)
	{
		upAnimR.Reset();
		currentAnimation = &upAnimR;
	}
	}


	// LEFT
	else if (App->input->keys[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT && blockAnim == false)
	{
	lastPosition = 1;
		position.x -= speed;
		if (currentAnimation != &leftAnim)
		{
			leftAnim.Reset();
			currentAnimation = &leftAnim;
		}
	}

	// RIGHT
	else if (App->input->keys[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT && blockAnim == false)
	{
	lastPosition = 0;

		position.x += speed;
		if (currentAnimation != &rightAnim)
		{
			rightAnim.Reset();
			currentAnimation = &rightAnim;
		}
	}

	// DOWN
	// --------------------------------------------------------DOWN LEFT
	else if (App->input->keys[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT && lastPosition == 1 && blockAnim == false)
	{
	position.y += speed;
	if (currentAnimation != &downAnimL)
	{
		downAnimL.Reset();
		currentAnimation = &downAnimL;
	}
	}

	// --------------------------------------------------------DOWN RIGHT
	else if (App->input->keys[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT && lastPosition == 0 && blockAnim == false)
	{
		position.y += speed;
		if (currentAnimation != &downAnimR)
		{
			downAnimR.Reset();
			currentAnimation = &downAnimR;
		}
	}

	//---------------------------------------------------------GOD MODE

	

	// If no movement detected, set the current animation back to idle
	if (App->input->keys[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_IDLE
		&& App->input->keys[SDL_SCANCODE_UP] == KEY_STATE::KEY_IDLE
		&& App->input->keys[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_IDLE
		&& App->input->keys[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_IDLE
		&& App->input->keys[SDL_SCANCODE_X] == KEY_STATE::KEY_IDLE
		&& App->input->keys[SDL_SCANCODE_Z] == KEY_STATE::KEY_IDLE
		&& App->input->keys[SDL_SCANCODE_C] == KEY_STATE::KEY_IDLE
		&& blockAnim == false)
	{
		if (currentAnimation != &idleAnimR
			&& currentAnimation != &idleAnimL
			&& currentAnimation != &hitAirAnim1L
			&& currentAnimation != &hitAirAnim2L
			&& currentAnimation != &hitAirAnim2R
			&& currentAnimation != &hitAirAnim1R
			&& currentAnimation != &hitKickAnimL
			&& currentAnimation != &hitThrowAnimL
			&& currentAnimation != &hitUpAnimL
			&& currentAnimation != &hitDownAnimL
			&& currentAnimation != &hitPrickAnimL
			&& currentAnimation != &hitOverAnimL
			&& currentAnimation != &hitKickAnimR
			&& currentAnimation != &hitThrowAnimR
			&& currentAnimation != &hitUpAnimR
			&& currentAnimation != &hitDownAnimR
			&& currentAnimation != &hitPrickAnimR
			&& currentAnimation != &hitOverAnimR
			&& currentAnimation != &jumpAnimR
			&& currentAnimation != &jumpAnimL
			&& currentAnimation != &deathAnimR
			&& currentAnimation != &deathAnimL)
		{
			switch (lastPosition) {

			case 1:
				idleAnimL.Reset();
				currentAnimation = &idleAnimL;
				break;

			case 0:
				idleAnimR.Reset();
				currentAnimation = &idleAnimR;
				break;
			}

		}
	}

	// Spawn explosion particles when pressing B
	/*if (App->input->keys[SDL_SCANCODE_B] == KEY_STATE::KEY_DOWN)
	{
		App->particles->AddParticle(App->particles->explosion, position.x, position.y + 25);
		App->particles->AddParticle(App->particles->explosion, position.x - 25, position.y, 30);
		App->particles->AddParticle(App->particles->explosion, position.x, position.y - 25, 60);
		App->particles->AddParticle(App->particles->explosion, position.x + 25, position.y, 90);
	}*/

	// ----------------------------- SET POS COLLIDER
	switch (lastPosition) {

	case 1:
		collider->SetPos(position.x + 36, position.y + 68);
		HIT->SetPos(position.x +16, position.y + 68);
		break;

	case 0:
		collider->SetPos(position.x + 20, position.y + 68);
		HIT->SetPos(position.x + 20, position.y + 68);
		break;
	}

	currentAnimation->Update();

	// ESC to leave the game
	if (App->input->keys[SDL_SCANCODE_ESCAPE] == KEY_STATE::KEY_DOWN)
	{
		return update_status::UPDATE_STOP;
	}

	// R to Restart
	if (App->input->keys[SDL_SCANCODE_R] == KEY_STATE::KEY_DOWN)
	{
		HIT->pendingToDelete = true;
		collider->pendingToDelete = true;
		CleanUp();
		this->Disable();
		App->audio->StopMusic();
		App->player->Disable();
		App->enemies->Disable();
		App->scene->Disable();  
		App->sceneIntro->Enable();
	}

	if (destroyed)
	{
		destroyedCountdown--;
		if (destroyedCountdown <= 0)
		
			return update_status::UPDATE_STOP;
	}



	return update_status::UPDATE_CONTINUE;
}

update_status ModulePlayer::PostUpdate()
{
	if (!destroyed)
	{
		if (position.y < 100)
		{
			SDL_Rect rect = currentAnimation->GetCurrentFrame();
			App->render->Blit(texture, position.x, position.y, &rect);
			App->render->Blit(fireTexture, 301, 135, &(smallFire.GetCurrentFrame()), 1); // SmallFire animation
		}
		else
		{
			App->render->Blit(fireTexture, 301, 135, &(smallFire.GetCurrentFrame()), 1); // SmallFire animation
			SDL_Rect rect = currentAnimation->GetCurrentFrame();
			App->render->Blit(texture, position.x, position.y, &rect);
		}

		// After Hits Animations, go back to Idle Anim
		// HIT AIR
		// RIGHT
		if (hitAirAnim1R.loopCount > 0)
		{
			idleAnimR.Reset();
			currentAnimation = &idleAnimR;
		}
		else if (hitAirAnim2R.loopCount > 0)
		{
			idleAnimR.Reset();
			currentAnimation = &idleAnimR;
		}

		// LEFT
		else if (hitAirAnim1L.loopCount > 0)
		{
			idleAnimL.Reset();
			currentAnimation = &idleAnimL;
		}
		else if (hitAirAnim2L.loopCount > 0)
		{
			idleAnimL.Reset();
			currentAnimation = &idleAnimL;
		}
		// HIT COLLIDE
		// LEFT
		else if (hitKickAnimL.loopCount > 0)
		{
			idleAnimL.Reset();
			currentAnimation = &idleAnimL;
		}
		else if (hitThrowAnimL.loopCount > 0)
		{
			idleAnimL.Reset();
			currentAnimation = &idleAnimL;
		}
		else if (hitUpAnimL.loopCount > 0)
		{
			idleAnimL.Reset();
			currentAnimation = &idleAnimL;
		}
		else if (hitDownAnimL.loopCount > 0)
		{
			idleAnimL.Reset();
			currentAnimation = &idleAnimL;
		}
		else if (hitPrickAnimL.loopCount > 0)
		{
			idleAnimL.Reset();
			currentAnimation = &idleAnimL;
		}
		else if (hitOverAnimL.loopCount > 0)
		{
			idleAnimL.Reset();
			currentAnimation = &idleAnimL;
		}

		// RIGHT
		else if (hitKickAnimR.loopCount > 0)
		{
			idleAnimR.Reset();
			currentAnimation = &idleAnimR;
		}
		else if (hitThrowAnimR.loopCount > 0)
		{
			idleAnimR.Reset();
			currentAnimation = &idleAnimR;
		}
		else if (hitUpAnimR.loopCount > 0)
		{
			idleAnimR.Reset();
			currentAnimation = &idleAnimR;
		}
		else if (hitDownAnimR.loopCount > 0)
		{
			idleAnimR.Reset();
			currentAnimation = &idleAnimR;
		}
		else if (hitPrickAnimR.loopCount > 0)
		{
			idleAnimR.Reset();
			currentAnimation = &idleAnimR;
		}
		else if (hitOverAnimR.loopCount > 0)
		{
			idleAnimR.Reset();
			currentAnimation = &idleAnimR;
		}

		// Return de LoopCount to 0

		hitKickAnimL.loopCount = 0;
		hitThrowAnimL.loopCount = 0;
		hitUpAnimL.loopCount = 0;
		hitDownAnimL.loopCount = 0;
		hitPrickAnimL.loopCount = 0;
		hitOverAnimL.loopCount = 0;
		hitKickAnimR.loopCount = 0;
		hitThrowAnimR.loopCount = 0;
		hitUpAnimR.loopCount = 0;
		hitDownAnimR.loopCount = 0;
		hitPrickAnimR.loopCount = 0;
		hitOverAnimR.loopCount = 0;
		hitAirAnim1R.loopCount = 0;
		hitAirAnim2R.loopCount = 0;
		hitAirAnim1L.loopCount = 0;
		hitAirAnim2L.loopCount = 0;
	}

	App->render->Blit(AttackQuoteTexture, position.x, position.y - 10, &(AttackQuote.GetCurrentFrame()), 0); // HUD animation

	if (App->render->camera.x == 0)
	{
		App->audio->PlayFx(Scream1);
		App->render->camera.x += 1;

	}


	App->render->Blit(fireTexture, 0, 162, &(frontFire.GetCurrentFrame()), 1); // FrontFire animation
	App->render->Blit(fireTexture, 256, 162, &(frontFire.GetCurrentFrame()), 1); // FrontFire animation
	App->render->Blit(fireTexture, 512, 162, &(frontFire.GetCurrentFrame()), 1); // FrontFire animation
	App->render->Blit(fireTexture, 768, 162, &(frontFire.GetCurrentFrame()), 1); // FrontFire animation
	App->render->Blit(fireTexture, 1024, 162, &(frontFire.GetCurrentFrame()), 1); // FrontFire animation
	App->render->Blit(fireTexture, 1280, 162, &(frontFire.GetCurrentFrame()), 1); // FrontFire animation

	// -------------------------------------------------------------------------------------------- HUD

	App->render->Blit(HUDTexture, 8, 0, &(HUDP1.GetCurrentFrame()), 0); // HUD Square Player1
	App->render->Blit(HUDTexture, 80, 0, &(HUDP234.GetCurrentFrame()), 0); // HUD Square Player2,3,4

	App->render->Blit(HUDTexture, 80, 16, &(insertCoinP2.GetCurrentFrame()), 0); // INSERT COIN Player2
	App->render->Blit(HUDTexture, 151, 16, &(insertCoinP3.GetCurrentFrame()), 0); // INSERT COIN Player3
	App->render->Blit(HUDTexture, 222, 16, &(insertCoinP4.GetCurrentFrame()), 0); // INSERT COIN Player4

	App->render->Blit(HUDTexture, 41, 16, &(lifeP1.GetCurrentFrame()), 0); // Full life P1

	// Draw UI (score) --------------------------------------
	sprintf_s(scoreTextP1, 10, "%3d", scoreP1); //P1
	sprintf_s(scoreTextP234, 10, "%3d", scoreP234); //P234

	App->fonts->BlitText(45, 8, scoreFont, scoreTextP1); // P1
	App->fonts->BlitText(116, 8, scoreFont, scoreTextP234); // P2
	App->fonts->BlitText(187, 8, scoreFont, scoreTextP234); // P3
	App->fonts->BlitText(258, 8, scoreFont, scoreTextP234); // P4


	// Draw UI (NumLifes) --------------------------------------
	sprintf_s(lifeText, 10, "%3d", lifes);

	App->fonts->BlitText(17, 16, lifeFont, lifeText);

	return update_status::UPDATE_CONTINUE;
}

void updateLifeIndicatorPlayer1(unsigned short* lifeIndicatorP1, unsigned short damage)
{
	for (int i = (MAX_LIFE - 1); i >= 0; --i) {

		if (*(lifeIndicatorP1 + i) == 0) {
			++damage;
		}
		else if (*(lifeIndicatorP1 + i) == 1 && i >= (MAX_LIFE - damage)) {
			*(lifeIndicatorP1 + i) = 0;
		}
	}
}

void ModulePlayer::OnCollision(Collider* c1, Collider* c2)
{
	if (c1 == collider && destroyed == false)
	{
		lifeP1.Update();
		updateLifeIndicatorPlayer1(lifesP1, 1);

		// ---------------------------------------------------------------- RIGHT
		if (lifesP1[0] == 0 && lifes != 0 && lastPosition == 0) {
			lifes -= 1;
			deathAnimR.Reset();
			currentAnimation = &deathAnimR;
			blockAnim = true;

			if (deathAnimR.loopCount > 1)
			{
				position.x = 5;
				position.y = 112;

				idleAnimR.Reset();
				currentAnimation = &idleAnimR;
				lifeP1.Reset();

				blockAnim = false;
				// Load Lifes P1 Again
				for (int i = 0; i < MAX_LIFE; ++i) {
					lifesP1[i] = 1;
				}
			}

			deathAnimR.loopCount = 0;
		}

		else if (lifesP1[0] == 0 && lifes == 0 && lastPosition == 0) {
			deathAnimR.Reset();
			currentAnimation = &deathAnimR;
			blockAnim = true;

			if (deathAnimR.loopCount > 1)
			{
				App->player->HIT->pendingToDelete = true;
				App->player->collider->pendingToDelete = true;

				App->player->Disable();
				App->player->CleanUp();

				App->enemies->Disable();
				App->enemies->CleanUp();

				App->sceneLose->Enable();
			}
		}

		// ---------------------------------------------------------------- LEFT
		if (lifesP1[0] == 0 && lifes != 0 && lastPosition == 1) {
			lifes -= 1;
			deathAnimL.Reset();
			currentAnimation = &deathAnimL;
			blockAnim = true;

			if (deathAnimL.loopCount > 1)
			{
				position.x = 5;
				position.y = 112;

				idleAnimR.Reset();
				currentAnimation = &idleAnimR;
				lifeP1.Reset();

				blockAnim = false;
				// Load Lifes P1 Again
				for (int i = 0; i < MAX_LIFE; ++i) {
					lifesP1[i] = 1;
				}
			}

			deathAnimL.loopCount = 0;
		}

		else if (lifesP1[0] == 0 && lifes == 0 && lastPosition == 1) {
			deathAnimL.Reset();
			currentAnimation = &deathAnimL;
			blockAnim = true;

			if (deathAnimL.loopCount > 1)
			{
				App->player->HIT->pendingToDelete = true;
				App->player->collider->pendingToDelete = true;

				App->player->Disable();
				App->player->CleanUp();

				App->enemies->Disable();
				App->enemies->CleanUp();

				App->sceneLose->Enable();
			}
		}
	}
	if (App->collisions->matrix[Collider::Type::ENEMY][Collider::Type::PLAYER_SHOT])
	{
		scoreP1 += 1;
	}
}