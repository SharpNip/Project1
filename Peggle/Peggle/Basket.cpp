#include "Basket.h"

Basket::Basket()
	: Collidable(Texture::ID::BASKET)
	, SPEED(100.0f)
	, mStartPos(0, -300, 0)
	, mPos(0,0,0)
	, LEFT_WALL(-static_cast<float>(gApp->GetParam().BackBufferWidth / 2))
	, RIGHT_WALL((gApp->GetParam().BackBufferWidth / 2))
	, WIDTH(GetTextureInfos()->infos.Width / 2)
	, isGoingLeft(false)
	, collider(nullptr)
{
	mAnchor = D3DXVECTOR3(GetTextureInfos()->infos.Width / 2, GetTextureInfos()->infos.Height / 2, 0.0f);
	this->SetPivot(mAnchor);
	this->SetRotationRad(0.0, 0.0, D3DX_PI);
	this->Sprite::SetPosition(mStartPos.x, mStartPos.y);
	this->mPos = mStartPos;
	collider = new CRectangle(this, 0 - static_cast<float>(GetTextureInfos()->infos.Width / 2), -300, GetTextureInfos()->infos.Width, 50);
	this->SetID(Components::BASKET);
}

Basket::~Basket()
{
	delete collider;
	collider = nullptr;
}

void Basket::Update()
{
	Patrol(gTimer->GetDeltaTime());
	if (gDInput->keyPressed(DIK_B))
	{
		std::cout << "Center X: " << GetPosition().x << " Center Y: " << GetPosition().y << std::endl;
		std::cout << "Collider Left: " << collider->GetPosition().x << std::endl;
		std::cout << "Collider Right: " << collider->GetPosition().x + collider->GetWidth() << std::endl;
		std::cout << "Collider Up:" << collider->GetPosition().y << std::endl;
		std::cout << "Collider Down:" << collider->GetPosition().y + collider->GetHeight() << std::endl;
	}
	
}
void Basket::Patrol(float deltaTime)
{
	if (!isGoingLeft)
	{
		mPos.x += SPEED * deltaTime;
		this->collider->SetPosition(this->collider->GetPosition().x + SPEED * deltaTime, mPos.y);
		if ((mPos.x + WIDTH) > RIGHT_WALL)
		{
			isGoingLeft = true;
		}
	}
	else
	{
		mPos.x -= SPEED * deltaTime;
		this->collider->SetPosition(this->collider->GetPosition().x - SPEED * deltaTime, mPos.y);
		if ((mPos.x - WIDTH) < LEFT_WALL)
		{
			isGoingLeft = false;
		}
	}

	this->Sprite::SetPosition(mPos.x, mPos.y);
	
}