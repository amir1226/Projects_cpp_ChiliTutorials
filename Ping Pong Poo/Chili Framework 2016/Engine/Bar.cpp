#include "Bar.h"
#include "Graphics.h"

void Bar::limitBar()
{
		const int right = x + width;
		if (x <= 0)
		{
			x = 2;
		}
		if (right >= Graphics::ScreenWidth)
		{
			x =  Graphics::ScreenWidth - 2 - width;
		}
}
