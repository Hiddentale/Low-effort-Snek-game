#pragma once
#include "Location.h"
#include "Graphics.h"
class Board
{
public:
	Board(Graphics& graphics);
	void DrawCell(Location loc, Color c);
private:
	Graphics& gfx;
	static constexpr int dimensionCell = 10;
	static constexpr int width = 10;
	static constexpr int height = 10;
};

