#include "Collidable.h"

// Nothing is implemented here other than the 2nd constructor as this is a nearly pure virtual class.
Collidable::Collidable()
	: mAnchor(0,0,0)
	, mPosition(0,0)
{

}

Collidable::Collidable(Texture::ID id)
	: Sprite(id)
	, mAnchor(0, 0, 0)
	, mPosition(0, 0)
{

}

Collidable::~Collidable()
{
}
