#include "Basket.h"


Basket::Basket()
	: Sprite(Texture::ID::BASKET)
	, SPEED(100.0f)
	, mStartPos(0, -300)
	, mPos(0,0)
	, leftBound(0)
	, rightBound(0)
{
	mAnchor = D3DXVECTOR3(GetTextureInfos()->infos.Width / 2, GetTextureInfos()->infos.Height / 2, 0.0f);
	SetPivot(mAnchor);
	SetRotationRad(0.0, 0.0, D3DX_PI);
	SetPosition(mStartPos.x, mStartPos.y);
	mPos = mStartPos;

	rightBound = (gApp->GetParam().BackBufferWidth / 2);
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
	if (mPos.x < gApp->GetParam().BackBufferWidth/2)
	{
		mPos.x += SPEED * deltaTime;
	}
	std::cout << mPos.x << "   " << (gApp->GetParam().BackBufferWidth) << std::endl;

	SetPosition(mPos.x, mPos.y);
}