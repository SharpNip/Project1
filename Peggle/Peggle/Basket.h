#pragma once
#include "Sprite.h"
#include "ResourceIDs.h"
#include "Collidable.h"

////////////////////////////////////////////////////////////////////
// Basket Class
//
// -> This class is used to represent the basket at the bottom
//	  of the UI. Moves in a constant motion from left to right
//	  to catch the falling ball. 
//	  It has an automatic movement, not-controlled by the player
////////////////////////////////////////////////////////////////////

class Basket :
	public Collidable
{
public:
	Basket();
	~Basket();

	void Update();
	void Patrol(float deltaTime);

private:
	// Middle anchor point for the sprite
	D3DXVECTOR3 mAnchor;
	
	// Constant of speed 
	const float SPEED;

	// Takes care of the patrolling effect of the basket at the bottom
	// True-> is moving towards the left / False-> towards the right
	bool isGoingLeft;

	// Les deux cotés de l'écran
	const float LEFT_WALL;
	const float RIGHT_WALL;

	const float WIDTH;
	
	// Sets the starting position and uses that to then affect the movement
	const D3DXVECTOR3 mStartPos;
	D3DXVECTOR3 mPos;

	CRectangle* collider;

};

