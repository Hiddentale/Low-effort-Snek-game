#pragma once
#include "Board.h"

class Snek
{
private:
	class Segment
	{
	public:
		void MoveBy(const Location& delta);
		void InitHead(const Location& location);
		void InitBody();
		Location& getLocation();
		void FollowSegment(Segment& previousSegment);
		void Draw(Board& brd) const;
	private:
		Location loc;
		Color c;
	};
public:
	Snek(const Location& location);
	Location& getHeadLocation();
	void Move(const Location& delta);
	void Grow();
	void Draw(Board& brd) const;
	bool isColliding();
private:
	static constexpr int maximumSizeOfSnek = 20;
	Segment snekbodies[maximumSizeOfSnek];
	int nSegments = 1;
	static constexpr Color headColor = Colors::Yellow;
	static constexpr Color bodyColor = Colors::Magenta;
};

