#include "Cannon.h"
#include "ResourceIDs.h"

// Initialisation of all vairables to default values
Cannon::Cannon()
	: Sprite(Texture::ID::CANNON)
	, cannonDirection(0, 0, 0)
	, rotation(0)
	, MAX_ROT_L(-(D3DX_PI))
	, MAX_ROT_R(0)
	, ROT_SPEED(6.0f)
	, numOfBalls(3)
	, ball(nullptr)
{
	mAnchor = D3DXVECTOR3(0, GetTextureInfos()->infos.Height / 2, 0.0f);
	SetPivot(mAnchor);

	rotation = -(D3DX_PI / 2);
	SetRotationRad(0.0, 0.0, rotation);

	int height = gApp->GetParam().BackBufferHeight;
	SetPosition(0.f, height/2);
}
// Destructor for the ball
Cannon::~Cannon()
{
	delete ball;
	ball = nullptr;
}
// This manages the cannon specific mechanics
void Cannon::Update()
{
	Rotate(gTimer->GetDeltaTime());
	Shoot(gTimer->GetDeltaTime());
	if (ball != nullptr)
	{
		numOfBalls = ball->QueryLives();
	}
}
// Called in the update, used to rotate the cannon on from pivot point
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
// Function called when spacebar is pressed. Also checked in the update
void Cannon::Shoot(float deltaTime)
{
	if (gDInput->keyPressed(DIKEYBOARD_SPACE))
	{
		if (numOfBalls > 0)
		{
			if (ball != nullptr)
			{
				if (!ball->InPlayQuery())
				{
					cannonDirection = D3DXVECTOR3(cos(rotation), sin(rotation), 0.0f);
					D3DXVECTOR3 offset = D3DXVECTOR3(cannonDirection.x, cannonDirection.y, 0.f) * texInfos->infos.Width;
					ball->Fire(GetPosition() + offset, rotation);
				}
			}
			else
			{
				cannonDirection = D3DXVECTOR3(cos(rotation), sin(rotation), 0.0f);
				D3DXVECTOR3 offset = D3DXVECTOR3(cannonDirection.x, cannonDirection.y, 0.f) * texInfos->infos.Width;
				ball = new Ball(GetPosition() + offset, rotation);
			}
		}
	}
 }
// Reset for when the end screen is seen
void Cannon::Reset()
{
	ball->SetLives(3);
}