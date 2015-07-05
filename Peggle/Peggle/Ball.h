#pragma once
#include "Sprite.h"
#include "ResourceIDs.h"
#include "Collidable.h"
#include "BlueOrb.h"

////////////////////////////////////////////////////////////////////
// Balls Class:
// ->	Here will be defined all of the 
//		ball related mechanics.
//		Only the player's ball is affected by gravity
//		The rest don't need to be.
////////////////////////////////////////////////////////////////////

class Ball :
	public Collidable
{
public:
	Ball();
	Ball(D3DXVECTOR3 position, float angle);
	~Ball();

	void Update();
	
	void Desintegrate();
	void Fire(D3DXVECTOR3 superPos, float newAngle);

	bool InPlayQuery(){ return mInPlay; }
	bool HitBasketQuery(){ return mHitBasket; }
	
private:
	void Fall(float deltaTime);
	void CheckForCollision();

	float speed;
	float angle;

	std::string check;

	bool applyGravity;
	bool mInPlay;
	bool mHitBasket;

	const float RADIUS;
	const float LEFT_WALL;
	const float RIGHT_WALL;
	
	D3DXVECTOR3 mAnchor;
	D3DXVECTOR2 mDirection;

	CCircle* collider;
};


#ifndef GRAVITY
#define GRAVITY 09.82f
#endif