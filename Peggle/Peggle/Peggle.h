#pragma once

#include "Engine.h"
#include "Sprite.h"
#include "AllAssets.h"

////////////////////////////////////////////////////////////////////
// Main Game Class:
// ->	Takes care of the main game and looping.
////////////////////////////////////////////////////////////////////


class Peggle :
	public Component
{
public:
	Peggle();
	~Peggle();

	void Start();
	void Update();
	void Draw();
	void Stop();

	int GetNumBalls(){ return cannon->GetRemBalls(); }

private:
	void LoadAssets();
	void Reset();

	Basket* basket;
	Cannon* cannon;
	Background* background;

	// Static instance to check if the game has been officially started.
	static bool gameStart;
};
