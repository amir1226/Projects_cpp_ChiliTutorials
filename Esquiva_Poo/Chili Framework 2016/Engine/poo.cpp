#include "poo.h"
#include "Graphics.h"
#include "Dude.h"

void Poo::pooMove()
{
	x = x + vx;
	y = y + vy;
	const int right = x + width;
	const int bottom = y + height;
	if (right >= Graphics::ScreenWidth)
	{
		x = Graphics::ScreenWidth - width - 1;
		if (vx <0)
		{
			vx = -vx + 1;
		}
		else 
		{
			vx = -vx - 1;
		}
		sum += 1;
	}
	if (x <= 0)
	{
		x = 1;
		if (vx < 0)
		{
			vx = -vx + 1;
		}
		else
		{
			vx = -vx - 1;
		}
		sum += 1;
	}
	if (bottom >= Graphics::ScreenHeight)
	{
		y = Graphics::ScreenHeight - height - 1;
		if (vy < 0)
		{
			vy = -vy + 1;
		}
		else
		{
			vy = -vy - 1;
		}
		sum += 1;
	}

	if (y <= 0)
	{
		y = 1;
		if (vy < 0)
		{
			vy = -vy + 1;
		}
		else
		{
			vy = -vy - 1;
		}
		sum += 1;
	}
}

bool Poo::dudeTouch(int xDude, int yDude, int widthDude, int heightDude)
{
	const int rightDude = xDude + widthDude;
	const int bottomDude = yDude + heightDude;

	const int rightPoo = x + width;
	const int bottomPoo = y + height;

	return rightDude >= x && xDude <= rightPoo && bottomDude >= y && yDude <= bottomPoo;

}

