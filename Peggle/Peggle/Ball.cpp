#include "Ball.h"

Ball::Ball()
	: Sprite(Texture::ID::BALL)
	, speed(0)
	, mGRAVITY(9.82f)
{
	mAnchor = D3DXVECTOR3(GetTextureInfos()->infos.Height / 2, GetTextureInfos()->infos.Width / 2, 0);
	SetPivot(mAnchor);
	SetPosition(0, 0);
	std::cout << "Cout!" << std::endl; 
}

Ball::Ball(D3DXVECTOR3 position, float angle)
	: Sprite(Texture::ID::BALL)
	, speed(0)
	, mGRAVITY(9.82f)
	, angle(angle)

{
	mAnchor = D3DXVECTOR3(GetTextureInfos()->infos.Height / 2, GetTextureInfos()->infos.Width / 2, 0);
	SetPivot(mAnchor);

	SetPosition(position.x, position.y);

	mDirection = D3DXVECTOR2(cos(angle), sin(angle));

	speed = 35;
}


Ball::~Ball()
{
}

void Ball::Update()
{
	float dt = gTimer->GetDeltaTime();

	D3DXVECTOR3 currentPos = GetPosition();

	currentPos.x += mDirection.x * speed * dt;
	currentPos.y += mDirection.y * speed * dt;

	SetPosition(currentPos.x, currentPos.y);
}

void Ball::Desintegrate()
{
}
