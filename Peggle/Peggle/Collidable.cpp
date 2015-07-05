#include "Collidable.h"


Collidable::Collidable()
	: inPlay(false)
	, isHit(false)
{

}

Collidable::Collidable(Texture::ID id)
	: Sprite(id)
	, inPlay(false)
	, isHit(false)
{

}

Collidable::~Collidable()
{
}
