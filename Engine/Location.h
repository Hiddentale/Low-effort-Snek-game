#pragma once

class Location
{
public:
	void add(const Location& value)
	{ 
		xPosition += value.xPosition; 
		yPosition += value.yPosition; 
	}
	bool operator == (const Location& value) const
	{
		return value.xPosition == xPosition && value.yPosition == yPosition;
	}
	int xPosition;
	int yPosition;
};
