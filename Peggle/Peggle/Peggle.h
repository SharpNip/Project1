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

private:
	void LoadAssets();

	Basket* basket;
	//RedOrb* redOrb;
	//BlueOrb* blueOrb;
	Ball* ball;
	Cannon* cannon;
	//Overlay* overlay;
	Background* background;
};

