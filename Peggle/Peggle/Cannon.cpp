#include "Cannon.h"
#include "ResourceIDs.h"


Cannon::Cannon()
	: Sprite(Texture::ID::CANNON)
	, canDirect(0,0,0)
	, rotation(0)
	, MAX_ROT_L(-(D3DX_PI))
	, MAX_ROT_R(0.0f)
	, ROT_SPEED(6.0f)
{
	mAnchorPoint = D3DXVECTOR3(0, GetTextureInfos()->infos.Height/2, 0.0f);
	SetPivot(mAnchorPoint);
	rotation = -(D3DX_PI / 2);
	SetRotationRad(0.0, 0.0, rotation);
	SetPosition(0, (gApp->GetParam().BackBufferHeight/2));
}

Cannon::~Cannon()
{

}

void Cannon::Update()
{
	Rotate(gTimer->GetDeltaTime());
}


void Cannon::Rotate(float dt)
{
	if (gDInput->keyDown(DIKEYBOARD_A))
	{
		if (rotation > MAX_ROT_L)
		{
			rotation -= ROT_SPEED * dt;
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
			rotation += ROT_SPEED * dt;
		}
		else
		{
			rotation = MAX_ROT_R;
		}
	}
	this->SetRotationRad(0, 0, rotation);
	canDirect = D3DXVECTOR3(-sinf(rotation), cosf(rotation), 0.0f);	
}
void Cannon::Shoot()
{
	
}