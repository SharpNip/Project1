#include "Counter.h"


Counter::Counter()
	: Sprite(Texture::ID::THREE)
	, numOfLives(0)
{
}

Counter::Counter(D3DXVECTOR2 position)
	: Sprite(Texture::ID::THREE)
	, mPosition(position)
	, numOfLives(0)
{
	mAnchor = D3DXVECTOR3(GetTextureInfos()->infos.Height / 2, GetTextureInfos()->infos.Width / 2, 0);
	this->Sprite::SetPivot(mAnchor);
	numOfLives = 
}


Counter::~Counter()
{
}


void Counter::Update()
{
	if (numOfLives == 3)
	{
		this->Sprite::SetTexInfos(Texture::ID::THREE);
	}
	else
	
}