#pragma once
#include "Sprite.h"
#include "CCircle.h"
#include "CRectangle.h"

////////////////////////////////////////////////////////////////////
// Collidable Class:
// ->	This class takes care of all of the objects on the scene
//		that require collision. It wasn't required, but I added it
//		for practise ("useless" virtual class)
////////////////////////////////////////////////////////////////////

class Collidable :
	public Sprite
{
public:
	// Constructors / Virutal Destructor to kill the children first
	Collidable();
	Collidable(Texture::ID id);
	virtual ~Collidable();

	// Pure virtual method, as there's no such thing as just a collidable
	virtual void Update() = 0;

protected:
	// All collidables require these, seeing as this class is virtual, 
	// might as well make them implicitly created with each class
	D3DXVECTOR2 mPosition;
	D3DXVECTOR3 mAnchor;

};

