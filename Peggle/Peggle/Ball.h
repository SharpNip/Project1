#pragma once
#include "Sprite.h"
#include "ResourceIDs.h"

////////////////////////////////////////////////////////////////////
// Balls Class:
// ->	Parent class to all balls. Here will be defined all of the 
//		ball related mechanics.
//		Only the player's ball is affected by gravity
//		The rest don't need to be.
////////////////////////////////////////////////////////////////////

class Ball :
	public Sprite
{
public:
	 Ball();
	~Ball();

	void Update();
	void Fall(float deltaTime);
	//bool Collide();
	void Instantiate();
	void Desintegrate();

private:
	D3DXVECTOR3 mScreenPos;
	bool mInPlay;

	D3DXVECTOR2 mDirection;

};