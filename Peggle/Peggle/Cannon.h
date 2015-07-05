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
	Cannon();
	~Cannon();

	void Init();

	void Rotate(float dt);
	void Shoot(float dt);
	void Update();

	int GetRemBalls(){ return numOfBalls; }

private:
	D3DXVECTOR3 mAnchor;
	float rotation;
	D3DXVECTOR3 cannonDirection;

	void CheckAmmo(Ball* ball);

	int numOfBalls;
	Ball* ball;
	// Constants for the Cannon
	const float ROT_SPEED;
	const float MAX_ROT_L;
	const float MAX_ROT_R;

};

