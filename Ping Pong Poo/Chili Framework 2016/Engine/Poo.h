#pragma once

class Poo
{
public:
	void pooMove();
	void barTouch(int xBar, int yBar, int widthBar, int heightBar);
	int x;
	int y;
	int vx;
	int vy;
	static constexpr int width = 24;
	static constexpr int height = 24;
	bool finishGame = false;
};