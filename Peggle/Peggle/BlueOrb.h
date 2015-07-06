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
	BlueOrb();
	BlueOrb(D3DXVECTOR2 position);
	~BlueOrb();
	
	void Update();
	void Crack();
	void Reset();

private:
	CCircle* collider;
	D3DXVECTOR2 mPosition;
	D3DXVECTOR3 mAnchor;

	const float RADIUS;

};

