#pragma once
#include "Ball.h"

////////////////////////////////////////////////////////////////////
// Player Ball Class:
// ->	Class for the player's ball.
//		Launched using the rotation of the Cannon class
//		It's affected by Gravity
//		It must also have a collider to detect collision between 
//		itself and the blue/red orbs
////////////////////////////////////////////////////////////////////

class PBall :
	public Ball
{
public:
	PBall();
	~PBall();

	void Fall(float dt);


private:
	float velocity;

	const float GRAVITY = 9.81f;
	

};

