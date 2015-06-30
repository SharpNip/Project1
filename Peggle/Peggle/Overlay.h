#pragma once
#include "Sprite.h"

////////////////////////////////////////////////////////////////////
// Overlay Class:
// ->	This class takes care of all of the interface where
//		the user gets to see his score and number of remaining balls
//		Ths inside borders should be "used" for the 
//		approx. visualisation of the boundaries of the "level"
////////////////////////////////////////////////////////////////////

class Overlay :
	public Sprite
{
public:
	Overlay();
	~Overlay();

	void SetPosition(float x, float y, float z)
	{
		mScreenPos.x = x; mScreenPos.y = y; mScreenPos.z = z;
	}

private:
	D3DXVECTOR3 mScreenPos;

};

