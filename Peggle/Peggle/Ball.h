#pragma once
#include "Sprite.h"
#include "ResourceIDs.h"
#include "CCircle.h"
#include "Collidable.h"

////////////////////////////////////////////////////////////////////
// Balls Class:
// ->	Here will be defined all of the 
//		ball related mechanics.
//		Only the player's ball is affected by gravity
//		The rest don't need to be.
////////////////////////////////////////////////////////////////////

class Ball :
	public Sprite
{
public:
	Ball();
	Ball(D3DXVECTOR3 position, float angle);
	~Ball();

	void Update();
	void Fall(float deltaTime);
	D3DXVECTOR2 CheckForCollision();
	void Desintegrate();
	void Fired();

	CCircle* collider;

	bool mInPlay;

private:
	float speed;
	float angle;
	const float RADIUS;
	
	D3DXVECTOR3 mAnchor;
	D3DXVECTOR2 mDirection;
};


#ifndef GRAVITY
#define GRAVITY 0.0982f
#endif