#pragma once
#include "Ball.h"

////////////////////////////////////////////////////////////////////
// Blue Orb Class:
// ->	Class specifically takes charge of the blue orb on screen
//		It has at screen position and a collider.
//		It is not affected by gravity, only by colliding with the 
//		player's ball
////////////////////////////////////////////////////////////////////

class BlueOrb :
	public Ball
{
public:
	BlueOrb();
	~BlueOrb();

private:
	bool isLit;


};

