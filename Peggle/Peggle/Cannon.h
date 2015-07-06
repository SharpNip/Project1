#pragma once
#include "Sprite.h"
#include "Ball.h"

////////////////////////////////////////////////////////////////////
// Cannon Class:
// ->	Class specifically takes charge of the player's cannon
//		Its position is to be set at the top of the UI.
//		It does not have its own collider 
//		Its angle is used to launch the player's ball in the direction
//		that the ball should be thrown at
////////////////////////////////////////////////////////////////////

class Cannon :
	public Sprite
{
public:
	// Default Ctor and Dtor
	Cannon();
	~Cannon();

	// Virtually called update to manage the object
	void Update();

	// Reset function to more easily just put everything back to their default values
	void Reset();

	// Getter to determing the number of balls the player has remaining
	int GetRemBalls(){ return numOfBalls; }

private:
	// Private to this class only, these two functions are secluded to avoid
	// outside calling
	void Rotate(float dt);
	void Shoot(float dt);

	// Constants for the Cannon
	const float ROT_SPEED;
	const float MAX_ROT_L;
	const float MAX_ROT_R;

	// Vectors for the position and orientation of the cannon
	D3DXVECTOR3 mAnchor;
	D3DXVECTOR3 cannonDirection;
	
	// The rotation of the cannon is passed to the ball when shot
	float rotation;

	// A intermidiary value just for easy transfert between the ball and the main game
	int numOfBalls;
	
	// The cannon has only a single ball, but it's position and stats are reset
	// when it is fired again (can't be respawned and this prevents memleaks)
	Ball* ball;
};

