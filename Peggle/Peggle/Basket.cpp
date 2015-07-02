#include "Basket.h"


Basket::Basket()
	: Sprite(Texture::ID::BASKET)
	, SPEED(250.0f)
{
	mAnchor = D3DXVECTOR3(GetTextureInfos()->infos.Width / 2, GetTextureInfos()->infos.Height / 2, 0.0f);
	SetPivot(&mAnchor);
	SetRotation(0.0, 0.0, D3DX_PI);
	SetPosition(0, 0);
}


Basket::~Basket()
{
}

void Basket::Update()
{
	Patrol(gTimer->GetDeltaTime());

}
void Basket::Patrol(float deltaTime)
{



}