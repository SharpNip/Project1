#include "Background.h"


Background::Background()
	: Sprite(Texture::ID::BACKGROUND)
{
	mAnchor = D3DXVECTOR3(GetTextureInfos()->infos.Width / 2, GetTextureInfos()->infos.Height / 2, 0.0f);
	SetPivot(&mAnchor);
}


Background::~Background()
{
}
