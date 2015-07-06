#pragma once
#include "Sprite.h"
#include "ResourceIDs.h"
#include "Ball.h"

class Counter :
	public Sprite
{
public:
	Counter();
	Counter(D3DXVECTOR2 position);
	
	~Counter();

	void Update();

private:
	int numOfLives;
	D3DXVECTOR2 mPosition;
	D3DXVECTOR3 mAnchor;
};

