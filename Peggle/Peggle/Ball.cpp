#include "Ball.h"

Ball::Ball()
	: Collidable(Texture::ID::BALL)
	, speed(0)
	, angle(0)
	, RADIUS(GetTextureInfos()->infos.Height/2)
	, applyGravity(false)
	, RIGHT_WALL(gApp->GetParam().BackBufferWidth/2)
	, LEFT_WALL(-static_cast<float>(gApp->GetParam().BackBufferWidth/2))
	//THis is just a debug thing to check if it works.
	, check("WORKS!")
{
	this->SetID(Components::BALL);
	mAnchor = D3DXVECTOR3(GetTextureInfos()->infos.Height / 2, GetTextureInfos()->infos.Width / 2, 0);
	this->Sprite::SetPivot(mAnchor);
	this->Sprite::SetPosition(0, 0);
}

Ball::Ball(D3DXVECTOR3 position, float angle)
	: Collidable(Texture::ID::BALL)
	, speed(0)
	, angle(angle)
	, RADIUS(GetTextureInfos()->infos.Height / 2)
	, applyGravity(false)
	, RIGHT_WALL(gApp->GetParam().BackBufferWidth/2)
	, LEFT_WALL(-static_cast<float>(gApp->GetParam().BackBufferWidth/2))
	, mHitBasket(false)
{
	this->SetID(Components::BALL);
	mAnchor = D3DXVECTOR3(GetTextureInfos()->infos.Height / 2, GetTextureInfos()->infos.Width / 2, 0);
	this->Sprite::SetPivot(mAnchor);
	this->Sprite::SetPosition(position.x, position.y);
	mDirection = D3DXVECTOR2(cos(angle), sin(angle));
	collider = new CCircle(this, 0, 0, RADIUS);
	mInPlay = true;

	speed = 200;
}


Ball::~Ball()
{
	delete collider;
	collider = nullptr;
}

void Ball::Update()
{
	float deltaTime = gTimer->GetDeltaTime();

	Fall(deltaTime);
	
	CheckForCollision();

}

void Ball::Desintegrate()
{
	this->Sprite::SetVisible(false);
	mInPlay = false;
}

void Ball::Fall(float deltaTime)
{
	D3DXVECTOR3 currentPos = GetPosition();

	if (applyGravity)
	{
		mDirection.y -= (GRAVITY * deltaTime);
	}
	if ((GetPosition().x - RADIUS) > LEFT_WALL)
	{
		mDirection = D3DXVECTOR2(mDirection.x *-1, mDirection.y);
		applyGravity = true;
	}
	if ((GetPosition().x + RADIUS) < RIGHT_WALL)
	{
		mDirection = D3DXVECTOR2(mDirection.x *-1, mDirection.y);
		applyGravity = true;
	}

	currentPos.x += mDirection.x * speed * deltaTime;
	currentPos.y += mDirection.y * speed * deltaTime;

	this->Sprite::SetPosition(currentPos.x, currentPos.y);
	this->collider->SetPosition(currentPos.x, currentPos.y);
}
void Ball::CheckForCollision()
{
	D3DXVECTOR2 resultVector = mDirection;
	for each (Collider* col in collider->LookForCollisions())
	{
		if (col->GetGameObject()->GetID() == Components::ORB)
		{
			D3DXVECTOR3 otherPos = static_cast<BlueOrb*>(col->GetGameObject())->GetPosition();
			float otherRad = static_cast<BlueOrb*>(col->GetGameObject())->GetRadius();
			D3DXVECTOR2 myPos = mDirection;
			resultVector = D3DXVECTOR2(cos(myPos.x - otherPos.x), sin(myPos.y - otherPos.y));
			D3DXVec2Normalize(&resultVector, &resultVector);
			mDirection = resultVector;
		}
		if (col->GetGameObject()->GetID() == Components::BASKET)
		{
			mHitBasket = true;
			Desintegrate();
		}
	}
}

void Ball::Fire(D3DXVECTOR3 superPos, float newAngle)
{
	this->Sprite::SetVisible(true);
	this->Sprite::SetPosition(superPos.x, superPos.y);
	this->mDirection = D3DXVECTOR2(cos(newAngle), sin(newAngle));
	mInPlay = true;
	mHitBasket = false;
}