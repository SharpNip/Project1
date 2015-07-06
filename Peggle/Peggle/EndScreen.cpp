#include "EndScreen.h"


EndScreen::EndScreen()
	: Sprite(Texture::ID::END)
{
	mAnchor = D3DXVECTOR3(GetTextureInfos()->infos.Width / 2, GetTextureInfos()->infos.Height / 2, 0.0f);
	SetPivot(mAnchor);
	SetRotationRad(0, 0, D3DX_PI);
}


EndScreen::~EndScreen()
{
}
