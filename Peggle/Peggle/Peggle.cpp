#include "Peggle.h"
#include "Sprite.h"
#include "ResourceIDs.h"
#include "Cannon.h"

Peggle::Peggle()
{
	Textures->LoadTexture(Texture::BASKET, "Sprites/Basket.png");
	Textures->LoadTexture(Texture::BLUE_ORB, "Sprites/BlueBall.png");
	Textures->LoadTexture(Texture::OVERLAY, "Sprites/Overlay.png");
	Textures->LoadTexture(Texture::BALL, "Sprites/PlayerBall.png");
	Textures->LoadTexture(Texture::CANNON, "Sprites/PlayerCannon.png");
	Textures->LoadTexture(Texture::RED_ORB, "Sprites/RedBall.png");
	Textures->LoadTexture(Texture::BACKGROUND, "Sprites/Background.png");
	
	//basket		= new Sprite(Texture::BASKET);
	//redOrb		= new Sprite(Texture::RED_ORB);
	//blueOrb		= new Sprite(Texture::BLUE_ORB);	
	//ball		= new Sprite(Texture::BALL);
	cannon		= new Cannon();
	//background  = new Sprite(Texture::BACKGROUND);
	//overlay		= new Sprite(Texture::OVERLAY);
	D3DXVECTOR3 anchor(cannon->GetTextureInfos()->infos.Width / 2, cannon->GetTextureInfos()->infos.Height / 2, 0.0f);
	
	cannon->SetPivot(&anchor);
	
	cannon->SetRotation(0.0f, 0.0f, D3DX_PI / 2);
}

Peggle::~Peggle()
{
	//delete basket;
	//delete redOrb;
	//delete blueOrb;
	//delete ball;
	delete cannon;
	//delete overlay;
	//delete background;

	//basket = nullptr;
	//redOrb = nullptr;
	//blueOrb = nullptr;
	//ball = nullptr;
	cannon = nullptr;
	//overlay = nullptr;
	//background = nullptr;


}

void Peggle::Start()
{
	
}

void Peggle::Update()
{
	float deltaTime = gTimer->GetDeltaTime();

	if (gDInput->keyPressed(DIKEYBOARD_A))
	{
		cannon->SetVisible(false);
	}
	else if (gDInput->keyPressed(DIKEYBOARD_D))
	{
		cannon->SetVisible(true);
	}

	if (gDInput->keyPressed(DIKEYBOARD_SPACE))
	{
		std::cout << "Pew" << std::endl; 
	}

}

void Peggle::Draw()
{

}

void Peggle::Stop()
{

}
void Peggle::LoadAssets()
{

}