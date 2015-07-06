#pragma once
#include "Collidable.h"
#include "ResourceIDs.h"

////////////////////////////////////////////////////////////////////
// Blue Orb Class:
// ->	Class specifically takes charge of the blue orb on screen
//		It has at screen position and a collider.
//		It is not affected by gravity, only by colliding with the 
//		player's ball
////////////////////////////////////////////////////////////////////

class BlueOrb :
	public Collidable
{
public:
	// Constructors / Destructor
	BlueOrb();
	BlueOrb(D3DXVECTOR2 position);
	~BlueOrb();
	
	// Public methods, Reset is called to reset all the position
	// Cracked is called through the Ball class to make the item disappear
	void Update();
	void Crack();
	void Reset();

private:
	// Radius built with the width of the sprite
	const float RADIUS;

	// Collider for interaction with the player's balls (teehee) 
	CCircle* collider;
	

};

