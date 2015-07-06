#include "TitleScreen.h"


TitleScreen::TitleScreen()
	: Sprite(Texture::ID::TITLE)
	, mAnchor(0,0,0)
{
	// Sets the anchor to the middle of the image and makes the required transformations to it
	mAnchor = D3DXVECTOR3(GetTextureInfos()->infos.Width / 2, GetTextureInfos()->infos.Height / 2, 0.0f);
	SetPivot(mAnchor);
	SetRotationRad(0, 0, D3DX_PI);
}


TitleScreen::~TitleScreen()
{
}
