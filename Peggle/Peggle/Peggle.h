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
	// Constructor and Destructor
	Peggle();
	~Peggle();

	//Standard methods
	void Start();
	void Update();
	void Draw();
	void Stop();

	// Originally intended to be a virtual function, but I decided to go with the
	// long way of doing it, just to speed things up a little
	void Reset();
	
	// Getter for the number of balls left for the user
	int GetNumBalls(){ return cannon->GetRemBalls(); }

private:
	// List of private functions, just so we don't get too crazy with access
	void LoadAssets();
	void GameOver();
	void Activate();

	// List of all of the objects used in the project, the ball, however
	// is instatiated in the Cannon class
	Basket* basket;
	Cannon* cannon;
	Background* background;
	TitleScreen* title;
	EndScreen* end;

	// Vectors of the different "peggles" (hardcoded positions)
	std::vector<BlueOrb*> firstRow;
	std::vector<BlueOrb*> secondRow;
	std::vector<RedOrb*> blockers;

	// Used to determine the state of the game, for resetting and so on
	bool gameStart;
	bool gameOver;

	// Constants to avoid "Hardcoding" the position of each row
	int ROW_ONE;
	int ROW_TWO;
	int ROW_THREE;

	// This is used as the Counter for the number of balls that can be shot
	ID3DXFont *mFont;
};
