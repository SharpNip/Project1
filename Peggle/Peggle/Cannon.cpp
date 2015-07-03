#include "Cannon.h"
#include "ResourceIDs.h"


Cannon::Cannon()
	: Sprite(Texture::ID::CANNON)
	, cannonDirection(0, 0, 0)
	, rotation(0)
	, MAX_ROT_L(-(D3DX_PI))
	, MAX_ROT_R(0)
	, ROT_SPEED(6.0f)
{
	mAnchor = D3DXVECTOR3(0, GetTextureInfos()->infos.Height / 2, 0.0f);
	SetPivot(mAnchor);

	rotation = -(D3DX_PI / 2);
	SetRotationRad(0.0, 0.0, rotation);

	int height = gApp->GetParam().BackBufferHeight;
	SetPosition(0.f, height/2);
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
	
}
void Cannon::Shoot(float deltaTime)
{
	if (gDInput->keyPressed(DIKEYBOARD_SPACE))
	{
		//std::cout << "X: " << GetPosition().x << ", Y: " << GetPosition().y << ", Z:" << GetPosition().z << std::endl;

		cannonDirection = D3DXVECTOR3(cos(rotation), sin(rotation), 0.0f);
		D3DXVECTOR3 offset = D3DXVECTOR3(cannonDirection.x, cannonDirection.y, 0.f) * texInfos->infos.Width;

		Ball* b = new Ball(GetPosition() + offset, rotation);

	}
 }