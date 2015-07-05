#include "Peggle.h"
#include "ResourceIDs.h"

Peggle::Peggle()
{
	LoadAssets();
	
	
	//redOrb		= new Sprite(Texture::RED_ORB);
	//blueOrb		= new BlueOrb();
	
	background  = new Background();
	cannon		= new Cannon();
	//ball		= new Ball();
	basket		= new Basket();
	//overlay		= new Sprite(Texture::OVERLAY);

}

Peggle::~Peggle()
{
	delete basket;
	basket = nullptr;

	//delete blueOrb;
	//blueOrb = nullptr;
	
	delete cannon;
	cannon = nullptr;
	
	delete background;
	background = nullptr;

	//delete overlay;
	//delete redOrb;

	//delete ball;
	//redOrb = nullptr;
	
	//ball = nullptr;
	
	//overlay = nullptr;
	
}

void Peggle::Start()
{
	
}

void Peggle::Update()
{
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
	Textures->LoadTexture(Texture::BALL, "Sprites/Ball.png");
	Textures->LoadTexture(Texture::CANNON, "Sprites/Cannon.png");
	Textures->LoadTexture(Texture::RED_ORB, "Sprites/RedBall.png");
	Textures->LoadTexture(Texture::BACKGROUND, "Sprites/Background.png");
}