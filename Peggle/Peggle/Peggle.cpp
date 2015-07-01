#include "Peggle.h"
#include "ResourceIDs.h"

Peggle::Peggle()
{
	LoadAssets();
	
	//basket		= new Sprite(Texture::BASKET);
	//redOrb		= new Sprite(Texture::RED_ORB);
	//blueOrb		= new Sprite(Texture::BLUE_ORB);	
	//ball		= new Sprite(Texture::BALL);
	background = new Background();
	cannon		= new Cannon();

	
	//overlay		= new Sprite(Texture::OVERLAY);

}

Peggle::~Peggle()
{
	//delete basket;
	//delete redOrb;
	//delete blueOrb;
	//delete ball;
	delete cannon;
	//delete overlay;
	delete background;

	//basket = nullptr;
	//redOrb = nullptr;
	//blueOrb = nullptr;
	//ball = nullptr;
	cannon = nullptr;
	//overlay = nullptr;
	background = nullptr;
}

void Peggle::Start()
{
	
}

void Peggle::Update()
{
	//float deltaTime = gTimer->GetDeltaTime();
	//
	//if (gDInput->keyPressed(DIKEYBOARD_A))
	//{
	//	cannon->SetVisible(false);
	//}
	//else if (gDInput->keyPressed(DIKEYBOARD_D))
	//{
	//	cannon->SetVisible(true);
	//}
	//
	//if (gDInput->keyPressed(DIKEYBOARD_SPACE))
	//{
	//	std::cout << "Pew" << std::endl; 
	//}

}

void Peggle::Draw()
{
	
}

void Peggle::Stop()
{

}
void Peggle::LoadAssets()
{
	Textures->LoadTexture(Texture::BASKET, "Sprites/Basket.png");
	Textures->LoadTexture(Texture::BLUE_ORB, "Sprites/BlueBall.png");
	Textures->LoadTexture(Texture::OVERLAY, "Sprites/Overlay.png");
	Textures->LoadTexture(Texture::BALL, "Sprites/PlayerBall.png");
	Textures->LoadTexture(Texture::CANNON, "Sprites/Cannon.png");
	Textures->LoadTexture(Texture::RED_ORB, "Sprites/RedBall.png");
	Textures->LoadTexture(Texture::BACKGROUND, "Sprites/Background.png");
}