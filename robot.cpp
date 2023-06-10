#include "robot.h"

void robot::move(int dx, int dy) 
{
	this->x += dx; // перемещение робота на dx клеток по горизонтали
	this->y += dy; // перемещение робота на dy клеток по вертикали
}

int robot::getX() 
{
	return this->x; // возвращает текущую позицию робота по горизонтали
}

int robot::getXExit() 
{
	return x_exit_coord; // возвращает выходную позицию робота по горизонтали
}

int robot::getYExit() 
{
	return y_exit_coord; // возвращает выходную позицию робота по вертикали
}

int robot::getY() 
{
	return this->y; // возвращает текущую позицию робота по вертикали
}

bool robot::theoreticRecurMove(int x, int y, field& field_, int x_start_coord, int y_start_coord) 
{
	if (x == 0 || x == SIZE - 1 || y == 0 || y == SIZE - 1) 
	{
		if (!(x == x_start_coord && y == y_start_coord)) 
		{
			x_exit_coord = x;
			y_exit_coord = y;
			return true;
		}
		else return false;
	}
	if (field_.getCell(x, y) == 1 || field_.getCell(x, y) == 2) return false;

	field_.setCell(x, y, 2);
	return theoreticRecurMove(x + 1, y, field_, x_start_coord, y_start_coord) || theoreticRecurMove(x - 1, y, field_, x_start_coord, y_start_coord) || theoreticRecurMove(x, y + 1, field_, x_start_coord, y_start_coord) || theoreticRecurMove(x, y - 1, field_, x_start_coord, y_start_coord);
}