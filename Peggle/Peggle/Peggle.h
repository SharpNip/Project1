#pragma once

#include "Engine.h"
#include "Sprite.h"
#include "AllAssets.h"

////////////////////////////////////////////////////////////////////
// Main Game Class:
// ->	Takes care of the main game and looping.
////////////////////////////////////////////////////////////////////


class Peggle :
	public Component
{
public:
	Peggle();
	~Peggle();

	void Start();
	void Update();
	void Draw();
	void Stop();

	virtual void Reset();

	int GetNumBalls(){ return cannon->GetRemBalls(); }

private:
	void LoadAssets();
	void GameOver();
	void Activate();

	Basket* basket;
	Cannon* cannon;
	Background* background;
	TitleScreen* title;
	EndScreen* end;

	std::vector<BlueOrb*> firstRow;
	std::vector<BlueOrb*> secondRow;
	std::vector<RedOrb*> blockers;

	bool gameStart;
	bool gameOver;

	ID3DXFont *mFont;
};
