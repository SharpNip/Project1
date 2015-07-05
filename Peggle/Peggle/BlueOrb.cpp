#include "BlueOrb.h"


BlueOrb::BlueOrb()
	: Collidable(Texture::ID::BLUE_ORB)
	, RADIUS(GetTextureInfos()->infos.Width/2)
{
	this->SetID(Components::ORB);
	collider = new CCircle(this, 0, 0, RADIUS);
}


BlueOrb::~BlueOrb()
{
}

void BlueOrb::Update()
{

}