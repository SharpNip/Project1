#include "Cannon.h"
#include "ResourceIDs.h"


Cannon::Cannon()
	: Sprite(Texture::ID::CANNON)
	, cannonDirection(0, 0, 0)
	, rotation(0)
	, MAX_ROT_L(-(D3DX_PI))
	, MAX_ROT_R(0)
	, ROT_SPEED(6.0f)
	, mPosition(0,0,0)
{
	mAnchor = D3DXVECTOR3(0, GetTextureInfos()->infos.Height / 2, 0.0f);
	SetPivot(mAnchor);
	rotation = -(D3DX_PI / 2);
	SetRotationRad(0.0, 0.0, rotation);
	mPosition = D3DXVECTOR3(0, (gApp->GetParam().BackBufferHeight / 2), 0);
	SetPosition(mPosition.x, mPosition.y);
}

Cannon::~Cannon()
{

}

void Cannon::Update()
{
	Rotate(gTimer->GetDeltaTime());
	Shoot(gTimer->GetDeltaTime());

}


void Cannon::Rotate(float deltaTime)
{
	if (gDInput->keyDown(DIKEYBOARD_A))
	{
		if (rotation > MAX_ROT_L)
		{
			rotation -= ROT_SPEED * deltaTime;
		}
		else
		{
			rotation = MAX_ROT_L;
		}
	}
	if (gDInput->keyDown(DIKEYBOARD_D))
	{
		if (rotation < MAX_ROT_R)
		{
			rotation += ROT_SPEED * deltaTime;
		}
		else
		{
			rotation = MAX_ROT_R;
		}
	}
	this->SetRotationRad(0, 0, rotation);
	cannonDirection = D3DXVECTOR3(-sinf(rotation), cosf(rotation), 0.0f);
}
void Cannon::Shoot(float deltaTime)
{
	if (gDInput->keyPressed(DIKEYBOARD_SPACE))
	{
		std::cout << "Shoot" << std::endl;
	}

}