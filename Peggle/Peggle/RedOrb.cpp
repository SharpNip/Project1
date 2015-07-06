#include "RedOrb.h"

RedOrb::RedOrb()
	: Collidable(Texture::ID::REDORB)
	, RADIUS(GetTextureInfos()->infos.Width / 2)
{
}
RedOrb::RedOrb(D3DXVECTOR2 position)
	: Collidable(Texture::ID::REDORB)
	, RADIUS(GetTextureInfos()->infos.Width / 2)
{
	mPosition = position;
	this->SetID(Components::REDORB);
	mAnchor = D3DXVECTOR3(GetTextureInfos()->infos.Height / 2, GetTextureInfos()->infos.Width / 2, 0);
	this->Sprite::SetPivot(mAnchor);
	this->Sprite::SetPosition(mPosition.x, mPosition.y);
	collider = new CCircle(this, 0, 0, RADIUS);
	collider->SetPosition(mPosition.x, mPosition.y);
}
RedOrb::~RedOrb()
{
	delete collider;
	collider = nullptr;
}
void RedOrb::Update()
{
}
void RedOrb::Reset()
{
	this->Sprite::SetVisible(true);
}