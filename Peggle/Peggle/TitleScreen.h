#pragma once
#include "Sprite.h"
#include "ResourceIDs.h"

//////////////////////////////////////////////////////////////////
// Background:
//  ->	This takes care of creating and placing a background image
//		Does not affect gameplay in any way
//////////////////////////////////////////////////////////////////

class TitleScreen :
	public Sprite
{
public:
	TitleScreen();
	~TitleScreen();
private:
	D3DXVECTOR3 mAnchor;
};

