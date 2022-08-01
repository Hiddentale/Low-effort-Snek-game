#include "Fruit.h"

Fruit::Fruit(Location& location)
{
	fruitLocation = location;
}

void Fruit::Draw(Board& screen)
{
	screen.DrawCell(fruitLocation, color);
}

bool Fruit::hasBeenEaten(Location& snakeHeadLocation)
{
	if (snakeHeadLocation == fruitLocation)
	{
		std::random_device rd;
		std::mt19937 rng(rd());
		std::uniform_int_distribution<int> xDist(0, 40);
		std::uniform_int_distribution<int> yDist(0, 40);
		fruitLocation = {xDist(rng), yDist(rng)};
		return true;
	}
	else
	{
		return false;
	}
}