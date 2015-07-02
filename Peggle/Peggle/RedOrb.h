#pragma once
#include "Collidable.h"

////////////////////////////////////////////////////////////////////
// Red Orb Class:
// -> Class specifically takes charge of the red orb on screen
//	  It has at screen position and a collider.
//	  It is not affected by gravity, only by colliding with the 
//	  player's ball
////////////////////////////////////////////////////////////////////

class RedOrb :
	public Collidable
{
public:
	RedOrb();
	~RedOrb();

private:
	bool isLit;
	

};