#pragma once
#include "Sprite.h"
#include "ResourceIDs.h"
#include "Collidable.h"
#include "BlueOrb.h"

////////////////////////////////////////////////////////////////////
// Balls Class:
// ->	The ball is a bit of a "god" class without being one.
//		It knows of all of the elements on screen, is affected by 
//		gravity (1th of it's real value)
//		And it also has it's own number of lives
////////////////////////////////////////////////////////////////////

class Ball :
	public Collidable
{
public:
	// Ctors and Dtor
	Ball();
	// Used when "instantiating" a ball from the cannon
	Ball(D3DXVECTOR3 position, float angle);
	~Ball();

	// Virtually called function
	void Update();
	
	// This is called when the ball is fired anew (non-instantiation)
	void Fire(D3DXVECTOR3 superPos, float newAngle);
	
	// Setter for the reset option
	void SetLives(int number){ lives = number; }

	// Getters with fancy names for easy "tracking"
	int QueryLives(){ return lives; }
	bool InPlayQuery(){ return mInPlay; }
	bool HitBasketQuery(){ return mHitBasket; }
	
private:
	// Private functions that should not be called oustide of this class
	void Fall(float deltaTime);
	void Desintegrate();
	void CheckForCollision();

	const float SPEED;
	const float RADIUS;
	const float LEFT_WALL;
	const float RIGHT_WALL;
	const float BOTTOM;

	// The angle is used to dtermine the direction of the ball
	float angle;

	// Number of lives the ball has
	int lives;

	// These bools are used to manage the mechanices related to the ball moving around
	bool applyGravity;
	bool mInPlay;
	bool mHitBasket;

	// 2D vector to determine the direction in which the ball is moving.
	D3DXVECTOR2 mDirection;

	// The ball's collider
	CCircle* collider;
};

// A constant for Gravity. However, it's only 1/10th of the real value
#ifndef GRAVITY
#define GRAVITY 0.982f
#endif