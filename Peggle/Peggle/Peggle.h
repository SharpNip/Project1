#pragma once

#include "Engine.h"
#include "Sprite.h"
#include "AllAssets.h"

////////////////////////////////////////////////////////////////////
// Cannon Class:
// ->	Class specifically takes charge of the player's cannon
//		Its position is to be set at the top of the UI.
//		It does not have its own collider 
//		Its angle is used to launch the player's ball in the direction
//		that the ball should be thrown at
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

	//Basket* basket;
	//RedOrb* redOrb;
	//BlueOrb* blueOrb;
	//Ball* ball;
	Cannon* cannon;
	//Overlay* overlay;
	Background* background;
};

