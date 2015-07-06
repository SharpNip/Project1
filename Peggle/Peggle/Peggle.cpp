#include "Peggle.h"
#include "ResourceIDs.h"

Peggle::Peggle()
	: gameStart(false)
	, gameOver(false)
	, ROW_ONE(-350)
	, ROW_TWO(-300)
	, ROW_THREE(-300)
{
	LoadAssets();

	title	= new TitleScreen();
	end		= new EndScreen();
	end->SetVisible(false);
	
	// This is copied/pasted from the FontApp project we made. 
	// I was too lazy to implement something more substantial right away
	D3DXFONT_DESC fontDesc;
	fontDesc.Height = 80;
	fontDesc.Width = 40;
	fontDesc.MipLevels = 0;
	fontDesc.Italic = true;
	fontDesc.CharSet = DEFAULT_CHARSET;
	fontDesc.OutputPrecision = OUT_DEFAULT_PRECIS;
	fontDesc.PitchAndFamily = DEFAULT_PITCH | FF_DONTCARE;
	fontDesc.Quality = DEFAULT_QUALITY;
	strcpy_s(fontDesc.FaceName, _T("Times New Roman"));
	D3DXCreateFontIndirect(gD3DDevice, &fontDesc, &mFont);
}

Peggle::~Peggle()
{
	ReleaseCOM(mFont);
	if (gameStart)
	{
		delete basket;
		basket = nullptr;

		delete cannon;
		cannon = nullptr;

		delete background;
		background = nullptr;

		auto it = blockers.begin();
		while (it != blockers.end())
		{
			it = blockers.erase(it);
		}

		auto itt = firstRow.begin();
		while (itt != firstRow.end())
		{
			itt = firstRow.erase(itt);
		}
		auto ittt = secondRow.begin();
		while (ittt != secondRow.end())
		{
			ittt = secondRow.erase(ittt);
		}
	}
	delete title;
	title = nullptr;

	delete end;
	end = nullptr;

}
// Nothing here!
void Peggle::Start()
{
}
// This update checks for variations of game states through the 2 booleans in the class
void Peggle::Update()
{
	if (gDInput->keyPressed(DIK_RETURN))
	{
		if (gameStart)
		{
			if (gameOver)
			{
				Reset();
			}
		}
		else
		{
			Activate();
		}
	}
	if (gameStart)
	{
		if (GetNumBalls() == 0 )
		{
			GameOver();
		}
	}
}
// Mainly takes care of drawing the "HUD" to tell the number of balls the player has remaining
void Peggle::Draw()
{
	if (gameStart)
	{
		RECT fontRect;
		int livesRemaining = GetNumBalls();
		switch (livesRemaining)
		{
		case 1:
			::GetClientRect(gApp->GetMainWindow(), &fontRect);
			mFont->DrawTextA(0, _T("1"), -1, &fontRect, DT_LEFT | DT_TOP | DT_SINGLELINE, D3DCOLOR_XRGB(255, 255, 255));
			break;
		case 2:
			::GetClientRect(gApp->GetMainWindow(), &fontRect);
			mFont->DrawTextA(0, _T("2"), -1, &fontRect, DT_LEFT | DT_TOP | DT_SINGLELINE, D3DCOLOR_XRGB(255, 255, 255));
			break;
		case 3:
			::GetClientRect(gApp->GetMainWindow(), &fontRect);
			mFont->DrawTextA(0, _T("3"), -1, &fontRect, DT_LEFT | DT_TOP | DT_SINGLELINE, D3DCOLOR_XRGB(255, 255, 255));
			break;
		default:
			::GetClientRect(gApp->GetMainWindow(), &fontRect);
			mFont->DrawTextA(0, _T(""), -1, &fontRect, DT_LEFT | DT_TOP | DT_SINGLELINE, D3DCOLOR_XRGB(255, 255, 255));
			break;
		}
	}
}
// Nothing Here!
void Peggle::Stop()
{
}
// This is used only to alleviate the constructor of the class
void Peggle::LoadAssets()
{
	Textures->LoadTexture(Texture::BASKET, "Sprites/Basket.png");
	Textures->LoadTexture(Texture::BLUEORB, "Sprites/BlueBall.png");
	Textures->LoadTexture(Texture::REDORB, "Sprites/RedBall.png");
	Textures->LoadTexture(Texture::TITLE, "Sprites/TitleScreen.png");
	Textures->LoadTexture(Texture::END, "Sprites/EndScreen.png");
	Textures->LoadTexture(Texture::BALL, "Sprites/Ball.png");
	Textures->LoadTexture(Texture::CANNON, "Sprites/Cannon.png");
	Textures->LoadTexture(Texture::BACKGROUND, "Sprites/Background.png");
}
// Reset function used to set the game back to its original state
void Peggle::Reset()
{
	for each(BlueOrb* blue in firstRow)
	{
		blue->Reset();
	}
	for each(BlueOrb* blue in secondRow)
	{
		blue->Reset();
	}
	for each(RedOrb* red in blockers)
	{
		red->Reset();
	}
	cannon->Reset();
	background->SetVisible(true);
	cannon->SetVisible(true);
	basket->SetVisible(true);
	end->SetVisible(false);
	gameOver = false;
}
// THis is called only the first time the game is created, allowing the title screen to remain "clean" of any gameplay bugs
void Peggle::Activate()
{
	background = new Background();
	cannon = new Cannon();
	basket = new Basket();
	
	int temp	= ROW_ONE;
	int temp2	= ROW_TWO;
	int temp3	= ROW_THREE;

	for (int i = 0; i < 6; i++)
	{
		firstRow.push_back(new BlueOrb(D3DXVECTOR2((float)temp, -100.f)));
		temp += gApp->GetParam().BackBufferWidth / 6;
	}

	for (int i = 0; i < 4; i++)
	{
		secondRow.push_back(new BlueOrb(D3DXVECTOR2((float)temp2, -200.f)));
		temp2 += gApp->GetParam().BackBufferWidth / 4;
	}

	for (int i = 0; i < 4; i++)
	{
		blockers.push_back(new RedOrb(D3DXVECTOR2((float)temp3, 0.f)));
		temp3 += gApp->GetParam().BackBufferWidth / 4;
	}
	gameStart = true;
}
// Used when the END Screen is seen
void Peggle::GameOver()
{
	background->SetVisible(false);
	cannon->SetVisible(false);
	basket->SetVisible(false);
	end->SetVisible(true);
	gameOver = true;
	
	for each(BlueOrb* blue in firstRow)
	{
		blue->SetVisible(false);
	}
	for each(BlueOrb* blue in secondRow)
	{
		blue->SetVisible(false);
	}
	for each(RedOrb* red in blockers)
	{
		red->SetVisible(false);
	}
}