#pragma once
#include "Sprite.h"
#include "ResourceIDs.h"

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
	//bool CheckForCollision();
	void Desintegrate();

private:
	const float mGRAVITY;

	bool mInPlay;
	float speed;
	float angle;
	
	D3DXVECTOR3 mAnchor;
	D3DXVECTOR2 mDirection;
};