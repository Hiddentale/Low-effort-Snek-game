#include "Snek.h"
#include <assert.h>

Snek::Snek(const Location& location)
{
	snekbodies[0].InitHead(location);
}

bool Snek::isColliding()
{
	for (int i = nSegments - 1; i > 0; --i)
	{
		if (snekbodies[0].getLocation() == snekbodies[i].getLocation()) {
			return true;
		}
	}
}

void Snek::Segment::MoveBy(const Location& delta)
{
	assert(abs(delta.xPosition) + abs(delta.yPosition) == 1);
	loc.add(delta);
}

void Snek::Segment::InitHead(const Location& location)
{ 
	loc = location;
	c = Snek::headColor;
}

void Snek::Segment::InitBody()
{
	c = Snek::bodyColor;
}

 Location& Snek::getHeadLocation()
{
	return snekbodies[0].getLocation();
}
 Location& Snek::Segment::getLocation()
{
	return loc;
}

void Snek::Segment::FollowSegment(Segment& previousSegment)
{
	loc = previousSegment.loc;
}

void Snek::Segment::Draw(Board & brd) const
{
	brd.DrawCell(loc, c);
}

void Snek::Move(const Location& delta)
{
	for (int i = nSegments - 1; i > 0; --i)
	{
		snekbodies[i].FollowSegment(snekbodies[i - 1]);
	}
	snekbodies[0].MoveBy(delta);
}

void Snek::Draw(Board& brd) const
{
	for (int i = 0; i < nSegments; ++i)
	{
		snekbodies[i].Draw(brd);
	}
}

void Snek::Grow()
{
	if (nSegments <= maximumSizeOfSnek)
	{
		snekbodies[nSegments].InitBody();
		++nSegments;
	}
}