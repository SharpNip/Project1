#pragma once
#include "Sprite.h"
#include "ResourceIDs.h"

//////////////////////////////////////////////////////////////////
// Title Screen:
//  ->	This takes care of creating and placing a Titlescreen image
//		Does not affect gameplay in any way
//		Both this and the end screen are somehow backwards, so the
//		source files are backwards too. Laziness FTW
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

