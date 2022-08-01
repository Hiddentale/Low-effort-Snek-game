#pragma once
#include "Location.h"
#include "Board.h"
#include <random>

class Fruit
{
public:
	Fruit::Fruit(Location& location);
	void Draw(Board& screen);
	bool hasBeenEaten(Location& snekHeadLocation);
private:
	Location fruitLocation = {0,0};
	Color color = Colors::Green;
};

