#include "BlueOrb.h"


BlueOrb::BlueOrb()
	: Collidable(Texture::ID::BLUE_ORB)
{
	this->SetID(Components::ORB);
}


BlueOrb::~BlueOrb()
{
}
