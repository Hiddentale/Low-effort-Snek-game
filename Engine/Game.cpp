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


Game::Game(MainWindow& wnd):
	window(wnd), graphics(wnd), screen(graphics), snake({30,30})
{
}

void Game::Go()
{
	graphics.BeginFrame();
	UpdateModel();
	ComposeFrame();
	graphics.EndFrame();
}

void Game::UpdateModel()
{
	if (!gameOver)
	{

		if (window.kbd.KeyIsPressed(VK_LEFT))
		{
			delta = { -1,0 };
		}
		if (window.kbd.KeyIsPressed(VK_UP))
		{
			delta = { 0,-1 };
		}
		if (window.kbd.KeyIsPressed(VK_DOWN))
		{
			delta = { 0,1 };
		}
		if (window.kbd.KeyIsPressed(VK_RIGHT))
		{
			delta = { 1,0 };
		}

		++snakeMoveCounter;
		if (snakeMoveCounter >= snakeMovePeriod)
		{
			snakeMoveCounter = 0;
			if (fruit.hasBeenEaten(snake.getHeadLocation()))
			{
				snake.Grow();
				++totalFruitEaten;
				if (snakeMovePeriod > 0)
				{
					--snakeMovePeriod;
				}
			}
			snake.Move(delta);
			if (snake.isColliding())
			{
				gameOver = true;
			}
		}
	}
}

void Game::ComposeFrame()
{
	if (!gameOver)
	{
		snake.Draw(screen);
		fruit.Draw(screen);
	}
	else {
		SpriteCodex::DrawGameOver(200, 200, graphics);
	}

}
