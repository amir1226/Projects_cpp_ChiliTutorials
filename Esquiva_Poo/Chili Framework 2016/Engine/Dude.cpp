#include "Dude.h"
#include "Graphics.h"

void Dude::dudeLimit()
{
	const int right = x + width;
	const int bottom = y + height;

	if (right >= Graphics::ScreenWidth-5)
	{
		x = Graphics::ScreenWidth - width - 1 - vx;
	}
	if (x <= 5)
	{
		x = 1 + vx;
	}
	if (bottom >= Graphics::ScreenHeight-5)
	{
		y = Graphics::ScreenHeight - height - 1 - vy;
	}

	if (y <= 5)
	{
		y = 1 + vy;
	}
}
