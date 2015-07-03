#include "Basket.h"


Basket::Basket()
	: Sprite(Texture::ID::BASKET)
	, SPEED(100.0f)
	, mStartPos(0, -300)
	, mPos(0,0)
	, leftBound(0)
	, rightBound(0)
	, isGoingLeft(false)
{
	mAnchor = D3DXVECTOR3(GetTextureInfos()->infos.Width / 2, GetTextureInfos()->infos.Height / 2, 0.0f);
	SetPivot(mAnchor);
	SetRotationRad(0.0, 0.0, D3DX_PI);
	SetPosition(mStartPos.x, mStartPos.y);
	mPos = mStartPos;
	// Sets the right border of the play area
	rightBound = (gApp->GetParam().BackBufferWidth / 2);
	// Sets the left border of the play area
	float temp = static_cast<float>(gApp->GetParam().BackBufferWidth / 2);
	leftBound = (temp * -1);

}

Basket::~Basket()
{
}

void Basket::Update()
{
	Patrol(gTimer->GetDeltaTime());
}
void Basket::Patrol(float deltaTime)
{
	if (!isGoingLeft)
	{
		mPos.x += SPEED * deltaTime;
		if (mPos.x >= rightBound)
		{
			isGoingLeft = true;
		}
	}
	else
	{
		mPos.x -= SPEED * deltaTime;
		if (mPos.x <= leftBound)
		{
			isGoingLeft = false;
		}
	}

	SetPosition(mPos.x, mPos.y);
}