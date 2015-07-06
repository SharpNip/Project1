#pragma once
#include "Sprite.h"
#include "ResourceIDs.h"
#include "Collidable.h"

////////////////////////////////////////////////////////////////////
// Basket Class:
//
// -> This class is used to represent the basket at the bottom
//	  of the GUI. Moves in a constant motion from left to right
//	  to catch the falling ball. 
//	  It has an automatic movement, not-controlled by the player
//	  It also has it's own collider to help with the game behavior
////////////////////////////////////////////////////////////////////

class Basket :
	public Collidable
{
public:
	//Constructor / Destructor
	Basket();
	~Basket();

	// Update called virtually through the inherited class to update various elements
	void Update();

private:
	// Private method to remove the possibility of illegal access; it is used
	// for the back and forth motion of the basket
	void Patrol(float deltaTime);

	// Middle anchor point for the sprite
	D3DXVECTOR3 mAnchor;
	
	// Constant of speed 
	const float SPEED;

	// Takes care of the patrolling effect of the basket at the bottom
	// True-> is moving towards the left / False-> towards the right
	bool isGoingLeft;

	// Sides of the screen for movement limitation (used with backbuffer)
	const float LEFT_WALL;
	const float RIGHT_WALL;

	// Width of the Basket so it doesn't completely exit the bounds of the screen
	const float WIDTH;
	
	// Sets the starting position and uses that to then affect the movement
	const D3DXVECTOR3 mStartPos;
	D3DXVECTOR3 mPos;

	// Rectangular collider to "catch" the ball with
	CRectangle* collider;
};