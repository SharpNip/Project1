#include "PBall.h"


PBall::PBall()
{
}


PBall::~PBall()
{
}

void PBall::Fall(float dt)
{
	velocity += GRAVITY * dt;
}