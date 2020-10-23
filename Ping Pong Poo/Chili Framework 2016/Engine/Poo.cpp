#include "Poo.h"
#include "Graphics.h"
#include "Bar.h"


void Poo::pooMove()
{
	 x= x + vx;
	 y= y + vy;

	const int right = x + width;
	const int bottom = y + height;
	if (x <= 0)
	{
		x = 1;
		vx = -vx;
	}
	if (right >= Graphics::ScreenWidth)
	{
		x = Graphics::ScreenWidth - 1 - width;
		vx = -vx;
	}

	if (y <= 0)
	{
		y = Bar::height;
		finishGame = true;
	}
	if (bottom >= Graphics::ScreenHeight)
	{
		y = Graphics::ScreenHeight - Bar::height - height;
		finishGame = true;
	}
}

void Poo::barTouch(int xBar, int yBar, int widthBar, int heightBar)
{
	const int rightBar = x + widthBar;
	const int botBar = x + heightBar;

	if (x + width >= xBar  &&
		x <= xBar + widthBar &&
		y + height >= yBar &&
		y <= yBar + heightBar)
	{
		vy = -vy;
		if (vy > 0)
		{
			vy += 1;
		}
		else
		{
			vy -= 1;
		}
	}

}
