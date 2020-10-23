/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 
*	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include<time.h>

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
	
}

void Game::UpdateModel()
{

	limit();

	srand(time(NULL));

	if (control)
	{

	}
	else
	{
		x_rand = rand() % (right_lim-left_lim) + (left_lim + width_block);
		y_rand = rand() % (bottom_lim-top_lim) + (top_lim - length_block);
		control = true;
	}
	if (controlVel)
	{

	}
	else
	{
		x_randVel = rand() % (right_lim - left_lim) + (left_lim + width_block);
		y_randVel = rand() % (bottom_lim - top_lim) + (top_lim - length_block);
		controlVel = true;
	}

	growing = grow(x_mov, y_mov, x_rand, y_rand);

	if (growing)
	{
		block(x_mov,y_mov,255,0,0);
		control = false;
		cont += 1;

	}
	else
	{
		block(x_mov, y_mov,0,255,0);
	}

	x_mov = x_mov + xMove();
	y_mov = y_mov + yMove();

	x_aux = x_aux + xMove();
	y_aux = y_aux + yMove();

	
}


void Game::ComposeFrame()
{
	wall();
	block(x_rand, y_rand, 255, 255, 0);
	block(x_randVel, y_randVel,0, 0, 255);


	for (int i = 0; i < cont; i++)
	{
		if (xMove() > 0)
		{
			x_aux = x_mov -1 - ((i + 1)*width_block);
			y_aux = y_mov;
			block(x_aux, y_aux, 255, 255, 255);
		}
		else if (xMove() < 0)
		{
			x_aux = x_mov + 1 + ((i + 1)*width_block);
			y_aux = y_mov;
			block(x_aux, y_aux, 255, 255, 255);
		}
		else if (yMove() > 0)
		{
			x_aux = x_mov ;
			y_aux = y_mov - 1 - ((i + 1)*length_block);
			block(x_aux, y_aux, 255, 255, 255);
		}
		else if (yMove() < 0)
		{
			x_aux = x_mov;
			y_aux = y_mov + 1 + ((i + 1)*length_block);
			block(x_aux, y_aux, 255, 255, 255);
		}
		else
		{
			block(x_aux, y_aux, 255, 255, 255);
		}

	}
	
}

void Game::wall()
{

	for (int i = left_lim; i <= right_lim; i++)
	{
		gfx.PutPixel(i, top_lim, 255, 255, 255);
	}
	for (int i = left_lim; i <= right_lim; i++)
	{
		gfx.PutPixel(i, bottom_lim, 255, 255, 255);
	}
	for (int i = top_lim; i <= bottom_lim; i++)
	{
		gfx.PutPixel(left_lim, i, 255, 255, 255);
	}
	for (int i = top_lim; i <= bottom_lim; i++)
	{
		gfx.PutPixel(right_lim, i, 255, 255, 255);
	}
}

void Game::block(int x, int y, int r, int g, int b)
{
	for (int i = 0; i < width_block; i++)
	{
		for (int j = 0; j < length_block; j++)
		{
			gfx.PutPixel(x+i, y+j, r, g, b);
		}
	}
}

bool Game::grow(int box_movX, int box_movY, int box_fixX, int box_fixY)
{
	const int left_box_movX = box_movX;
	const int right_box_movX = box_movX + width_block;
	const int top_box_movY = box_movY;
	const int bot_box_movY = box_movY + width_block;

	const int left_box_fixX = box_fixX;
	const int right_box_fixX = box_fixX + length_block;
	const int top_box_fixY = box_fixY;
	const int bot_box_fixY = box_fixY + length_block;

	return
		left_box_movX <= right_box_fixX &&
		right_box_movX >= left_box_fixX &&
		top_box_movY <= bot_box_fixY &&
		bot_box_movY >= top_box_fixY;
}


int Game::yMove()
{

	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
			if (inhibitUp)
			{

			}
			else
			{
				vy = vy - 1;
				inhibitUp = true;
			}

	}
	else
	{
		inhibitUp = false;
	}
	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{


			if (inhibitDown)
			{

			}
			else
			{
				vy = vy + 1;
				inhibitDown = true;
			}

	}
	else
	{
		inhibitDown = false;
	}

	return vy;
}

int Game::xMove()
{
	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{

		if (inhibitRight)
		{



		}
		else
		{
			vx = vx + 1;
			inhibitRight = true;
		}
	}
	else
	{
		inhibitRight = false;
	}

	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		if (inhibitLeft)
		{

		}
		else
		{
			vx = vx - 1;
			inhibitLeft = true;
		}
	}
	else
	{
		inhibitLeft = false;
	}
	return vx;
}

void Game::limit()
{
	if (x_mov < left_lim)
	{
		x_mov = right_lim - width_block;
	}
	if (x_mov + width_block > right_lim)
	{
		x_mov = left_lim + width_block;
	}
	if (y_mov < top_lim)
	{
		y_mov = bottom_lim - width_block;
	}
	if (y_mov + length_block > bottom_lim)
	{
		y_mov = top_lim + width_block;
	}
}

