#include "EndScreen.h"

EndScreen::EndScreen()
	: Sprite(Texture::ID::END)
	, mAnchor(0,0,0)
{
	// Sets the anchor in the middle of the image and "forgets" about it
	mAnchor = D3DXVECTOR3(GetTextureInfos()->infos.Width / 2, GetTextureInfos()->infos.Height / 2, 0.0f);
	SetPivot(mAnchor);
	SetRotationRad(0, 0, D3DX_PI);
}


EndScreen::~EndScreen()
{
}
