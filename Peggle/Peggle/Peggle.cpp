#include "Peggle.h"
#include "Sprite.h"
#include "ResourceIDs.h"

Peggle::Peggle()
{
	Textures->LoadTexture(Texture::BASKET, "Sprites/Basket.png");
	Textures->LoadTexture(Texture::BLUE_ORB, "Sprites/BlueBall.png");
	Textures->LoadTexture(Texture::OVERLAY, "Sprites/Overlay.png");
	Textures->LoadTexture(Texture::BALL, "Sprites/PlayerBall.png");
	Textures->LoadTexture(Texture::CANNON, "Sprites/PlayerCannon.png");
	Textures->LoadTexture(Texture::RED_ORB, "Sprites/RedBall.png");
	Textures->LoadTexture(Texture::BACKGROUND, "Sprites/Background.png");
	
	Sprite* basket		= new Sprite(Texture::BASKET);
	Sprite* redOrb		= new Sprite(Texture::RED_ORB);
	Sprite* blueOrb		= new Sprite(Texture::BLUE_ORB);	
	Sprite* ball		= new Sprite(Texture::BALL);
	Sprite* cannon		= new Sprite(Texture::CANNON);
	Sprite* overlay		= new Sprite(Texture::OVERLAY);
	Sprite* background	= new Sprite(Texture::BACKGROUND);

}

Peggle::~Peggle()
{

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
