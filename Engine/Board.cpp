#include "Board.h"

Board::Board(Graphics& graphics):
	gfx(graphics)
{
}

void Board::DrawCell(Location loc, Color c)
{
	gfx.DrawRectDim(loc.xPosition * dimensionCell, loc.yPosition * dimensionCell, width, height, c);
}