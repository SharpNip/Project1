#include "Ball.h"

Ball::Ball()
	: Sprite(Texture::ID::BALL)
	, speed(0)
	, angle(0)
	, RADIUS(GetTextureInfos()->infos.Height/2)
{
	mAnchor = D3DXVECTOR3(GetTextureInfos()->infos.Height / 2, GetTextureInfos()->infos.Width / 2, 0);
	SetPivot(mAnchor);
	SetPosition(0, 0);
	std::cout << "Cout!" << std::endl; 
	this->SetID(Components::BALL);
}

Ball::Ball(D3DXVECTOR3 position, float angle)
	: Sprite(Texture::ID::BALL)
	, speed(0)
	, angle(angle)
	, RADIUS(GetTextureInfos()->infos.Height / 2)
{
	this->SetID(Components::BALL);
	mAnchor = D3DXVECTOR3(GetTextureInfos()->infos.Height / 2, GetTextureInfos()->infos.Width / 2, 0);
	SetPivot(mAnchor);
	SetPosition(position.x, position.y);
	mDirection = D3DXVECTOR2(cos(angle), sin(angle));
	collider = new CCircle(this, 0, 0, RADIUS);

	speed = 0;
}


Ball::~Ball()
{
}

void Ball::Update()
{
	float deltaTime = gTimer->GetDeltaTime();
	
	Fall(deltaTime);
	//mDirection = CheckForCollision();

}

void Ball::Desintegrate()
{
	this->SetVisible(false);
	this->mInPlay = false;
}

void Ball::Fall(float deltaTime)
{
	speed += (GRAVITY * deltaTime);
	D3DXVECTOR3 currentPos = GetPosition();

	currentPos.x += mDirection.x * speed;
	currentPos.y += mDirection.y * speed;

	SetPosition(currentPos.x, currentPos.y);
}
D3DXVECTOR2 Ball::CheckForCollision()
{
	D3DXVECTOR2 resultVector = mDirection;
	//Go through each collider collided with though the LookForCollision Function
	for each (Collider* col in collider->LookForCollisions())
	{
		//If one of the collider is a block
		if (col->GetGameObject()->GetID() == Components::WALL)
		{
			//Consider that collider's component a block and make him shout
			mDirection = D3DXVECTOR2(mDirection.x *-1, mDirection.y);
		}
		if (col->GetGameObject()->GetID() == Components::ORB)
		{
			//Consider that collider's component a block and make him shout
			D3DXVECTOR3 otherPos = static_cast<Collidable*>(col->GetGameObject())->GetPosition();
			D3DXVECTOR2 myPos = mDirection;
			resultVector = D3DXVECTOR2(otherPos.x - myPos.x, otherPos.y - myPos.y);
			D3DXVec2Normalize(&resultVector, &resultVector);
		}
		if (col->GetGameObject()->GetID() == Components::BASKET)
		{
			//Consider that collider's component a block and make him shout
			//static_cast<Collidable*>(col->GetGameObject())->Shout();
		}
		if (col->GetGameObject()->GetID() == Components::BOTTOM)
		{
			//Consider that collider's component a block and make him shout
			
		}
	}
	return resultVector;
}

void Ball::Fired()
{
	this->SetVisible(true);
	this->mInPlay = true;
}