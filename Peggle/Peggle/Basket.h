#pragma once
#include "Sprite.h"

////////////////////////////////////////////////////////////////////
// Basket Class
//
// -> This class is used to represent the basket at the bottom
//	  of the UI. Moves in a constant motion from left to right
//	  to catch the falling ball. 
//	  It has an automatic movement, not-controlled by the player
////////////////////////////////////////////////////////////////////

class Basket :
	public Sprite
{
public:
	Basket();
	~Basket();

private:
	// Middle anchor point for the sprite
	D3DXVECTOR3 mCenter;
	// constant of speed (which will probably be a MAX speed.
	const float SPEED;
	// Suggestions: use the built-in function lerp to have it move from a to be

};

