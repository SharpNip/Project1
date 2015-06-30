#pragma once
#include "Sprite.h"

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

	D3DXVECTOR3 GetPosition() { return mScreenPos; }
	void SetPosition(float x, float y, float z)
	{
		mScreenPos.x = x; mScreenPos.y = y; mScreenPos.z = z;
	}

private:
	D3DXVECTOR3 mScreenPos;
	bool inPlay;

};