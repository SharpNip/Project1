#include "Peggle.h"
#include "ResourceIDs.h"

Peggle::Peggle()
{
	LoadAssets();
	background = new Background();
	cannon = new Cannon();
	basket = new Basket();

	background->SetVisible(false);
	cannon->SetVisible(false);
	basket->SetVisible(false);
	
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
}

void Peggle::Start()
{
}

void Peggle::Update()
{
	if (gDInput->keyPressed(DIK_RETURN))
	{
		Reset();
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
	Textures->LoadTexture(Texture::BASKET, "Sprites/Basket.png");
	Textures->LoadTexture(Texture::BLUE_ORB, "Sprites/BlueBall.png");
	Textures->LoadTexture(Texture::OVERLAY, "Sprites/Overlay.png");
	Textures->LoadTexture(Texture::BALL, "Sprites/Ball.png");
	Textures->LoadTexture(Texture::CANNON, "Sprites/Cannon.png");
	Textures->LoadTexture(Texture::BACKGROUND, "Sprites/Background.png");
}
void Peggle::Reset()
{
	background->SetVisible(true);
	cannon->SetVisible(true);
	basket->SetVisible(true);
}