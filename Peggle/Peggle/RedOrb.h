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
	RedOrb();
	RedOrb(D3DXVECTOR2 position);
	~RedOrb();

	void Update();
	void Reset();

private:
	CCircle* collider;
	D3DXVECTOR2 mPosition;
	D3DXVECTOR3 mAnchor;

	const float RADIUS;

};

