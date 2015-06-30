#pragma once

#include "Engine.h"
#include "Component.h"
#include "Sprite.h"

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

	const float GRAVITY = 9.78f;

private:
	void LoadAssets();

	Sprite* basket;
	Sprite* redOrb;
	Sprite* blueOrb;
	Sprite* ball;
	Sprite* cannon;
	Sprite* overlay;
	Sprite* background;
};

