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
Ball::Ball(D3DXVECTOR3 position)
	: Sprite(Texture::ID::BALL)
	, speed(0)
	, mGRAVITY(9.82f)
	, mPosition(position)

{
	mAnchor = D3DXVECTOR3(GetTextureInfos()->infos.Height / 2, GetTextureInfos()->infos.Width / 2, 0);
	SetPivot(mAnchor);
	SetPosition(mPosition.x, mPosition.y);

	speed = 35;
}


Ball::~Ball()
{
}

void Ball::Update()
{
	Fall(gTimer->GetDeltaTime());
}

void Ball::Instantiate(D3DXVECTOR3 direction)
{
	this->SetPosition(direction.x, direction.y);
	this->SetVisible(true);
	mDirection.x = direction.x;
	mDirection.y = direction.y;
}

void Ball::Desintegrate()
{
}

void Ball::Fall(float deltaTime)
{
	mDirection.x += speed * deltaTime;
	mDirection.y += speed * deltaTime;

	SetPosition(mDirection.x, mDirection.y);
}