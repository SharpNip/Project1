#include "Cannon.h"
#include "ResourceIDs.h"


Cannon::Cannon()
	: Sprite(Texture::ID::CANNON)
	, mRot(0,0)
{
	mAnchorPoint = D3DXVECTOR3(GetTextureInfos()->infos.Width / 2, GetTextureInfos()->infos.Height / 2, 0.0f);
	SetPivot(&mAnchorPoint);
	SetRotation(0.0, 0.0, D3DX_PI / 2);

	SetPosition(0, -(gApp->GetParam().BackBufferHeight/2));
}


Cannon::~Cannon()
{
}

void Cannon::Init()
{
	
	
}

void Cannon::Rotate()
{

}
void Cannon::Shoot()
{
	
}