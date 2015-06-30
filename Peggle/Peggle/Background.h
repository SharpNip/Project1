#pragma once
#include "Sprite.h"

//////////////////////////////////////////////////////////////////
// Background:
//  ->	This takes care of creating and placing a background image
//		Does not affect gameplay in any way
//////////////////////////////////////////////////////////////////

class Background :
	public Sprite
{
public:
	Background();
	~Background();
private:
	D3DXVECTOR3 mAnchor;
};

