#pragma once
#include "Sprite.h"
#include "ResourceIDs.h"

//////////////////////////////////////////////////////////////////
// End Screen Class:
//  ->	This takes care of creating and placing an image
//		to show the end of the game, be it win or lose.
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

