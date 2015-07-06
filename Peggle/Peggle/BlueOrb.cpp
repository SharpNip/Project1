#include "BlueOrb.h"


BlueOrb::BlueOrb()
	: Collidable(Texture::ID::BLUEORB)
	, RADIUS(GetTextureInfos()->infos.Width / 2)
{
}
BlueOrb::BlueOrb(D3DXVECTOR2 position)
	: Collidable(Texture::ID::BLUEORB)
	, RADIUS(GetTextureInfos()->infos.Width / 2)
	, mPosition(position)
{
	this->SetID(Components::BLUEORB);
	mAnchor = D3DXVECTOR3(GetTextureInfos()->infos.Height / 2, GetTextureInfos()->infos.Width / 2, 0);
	this->Sprite::SetPivot(mAnchor);
	this->Sprite::SetPosition(mPosition.x, mPosition.y);
	collider = new CCircle(this, 0, 0, RADIUS);
	collider->SetPosition(mPosition.x, mPosition.y);
}
BlueOrb::~BlueOrb()
{
}

void BlueOrb::Update()
{

}
void BlueOrb::Crack()
{
	collider->SetEnabled(false);
	this->Sprite::SetVisible(false);
}

void BlueOrb::Reset()
{
	collider->SetEnabled(true);
	this->Sprite::SetVisible(true);
}