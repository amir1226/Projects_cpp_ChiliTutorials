/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
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
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	/********************************/
	void wall();
	void block(int x, int y, int r, int g, int b);
	bool grow( int box_movX, int box_movY, int box_fixX, int box_fixY);
	int xMove();
	int yMove();
	void limit();

private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	/********************************/
	int matrizAux[1][100];
	int x_mov = 100;
	int y_mov = 100;
	int width_block = 6;
	int length_block = 6;
	int x_rand = 60;
	int y_rand = 60;
	const int left_lim = 50;
	const int top_lim = 50;
	const int right_lim = 750;
	const int bottom_lim = 550;
	bool control = false;
	bool controlVel = false;
	int x_randVel = 0;
	int y_randVel = 0;
	int vx = 0;
	int vy = 0;
	int cont = 0;
	bool growing = false;
	bool inhibitUp = false;
	bool inhibitRight = false;
	bool inhibitLeft = false;
	bool inhibitDown = false;
	int x_aux=100;
	int y_aux=100;
};