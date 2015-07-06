#pragma once
#include "Sprite.h"
#include "ResourceIDs.h"

//////////////////////////////////////////////////////////////////
// Background:
//  ->	This takes care of creating and placing a background image
//		Does not affect gameplay in any way
//////////////////////////////////////////////////////////////////

class EndScreen :
	public Sprite
{
public:
	EndScreen();
	~EndScreen();
private:
	D3DXVECTOR3 mAnchor;
};

