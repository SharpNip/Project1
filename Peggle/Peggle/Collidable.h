#pragma once
#include "Sprite.h"
#include "CCircle.h"
#include "CRectangle.h"


class Collidable :
	public Sprite
{
public:
	Collidable();
	Collidable(Texture::ID id);
	virtual ~Collidable();

	virtual void Update() = 0;


private:
	bool inPlay;
	bool isHit;
};

