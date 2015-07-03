#pragma once
#include "Sprite.h"
class Collidable :
	public Sprite
{
public:
	Collidable();
	Collidable(Sprite());
	virtual ~Collidable();

	D3DXVECTOR3 GetPosition() { return mScreenPos; }
	void SetPosition(float x, float y, float z)
	{
		mScreenPos.x = x; mScreenPos.y = y; mScreenPos.z = z;
	}

private:
	D3DXVECTOR3 mScreenPos;
	bool inPlay;
	bool isLit;
};

