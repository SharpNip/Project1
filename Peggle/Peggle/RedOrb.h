#pragma once
#include "Collidable.h"
#include "ResourceIDs.h"

////////////////////////////////////////////////////////////////////
// Red Orb Class:
// ->	Class specifically takes charge of the blue orb on screen
//		It has at screen position and a collider.
//		It is not affected by gravity, only by colliding with the 
//		player's ball
////////////////////////////////////////////////////////////////////

class RedOrb :
	public Collidable
{
public:
	// Constructors / Destructor
	RedOrb();
	RedOrb(D3DXVECTOR2 position);
	~RedOrb();

	// Public methods, only Reset is called outside of itself 
	void Update();
	void Reset();

private:
	// Radius built with the width of the sprite
	const float RADIUS;

	// Collider for interaction with the player's balls (teehee) 
	CCircle* collider;
	

};

