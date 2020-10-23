#pragma once
class Poo
{
public:
	void pooMove();
	bool dudeTouch(int xDude, int yDude, int widthDude, int heightDude);
	int x;
	int y;
	int vx;
	int vy;
	static constexpr int width = 24;
	static constexpr int height = 24;
	int sum = 0;
};

