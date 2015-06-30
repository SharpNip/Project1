#pragma once
#include "Sprite.h"

////////////////////////////////////////////////////////////////////
// Cannon Class:
// ->	Class specifically takes charge of the player's cannon
//		Its position is to be set at the top of the UI.
//		It does not have its own collider 
//		Its angle is used to launch the player's ball in the direction
//		that the ball should be thrown at
////////////////////////////////////////////////////////////////////

class Cannon :
	public Sprite
{
public:
	Cannon();
	~Cannon();

	void Init();

	void Rotate();
	void Shoot();

private:
	D3DXMATRIX anchorPoint;
	D3DXMATRIX rotation;
};

