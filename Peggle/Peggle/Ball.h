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
	Ball(D3DXVECTOR3 position);
	~Ball();

	void Update();
	void Fall(float deltaTime);
	//bool CheckForCollision();
	void Instantiate(D3DXVECTOR3 pos);
	void Desintegrate();

private:
	D3DXVECTOR3 mAnchor;
	D3DXVECTOR3 mPosition;
	
	bool mInPlay;


	D3DXVECTOR2 mDirection;
	
	float speed;
	const float mGRAVITY;
};