#ifndef ROBOT_H
#define ROBOT_H

#include <vector>
#include "field.h"

class robot 
{
	int x = 0; // ������� ������� ������ �� �����������
	int y = 1; // ������� ������� ������ �� ���������
	int x_exit_coord = -1;
	int y_exit_coord = -1;
public:
	void move(int dx, int dy);
	int getX();
	int getY();
	int getXExit();
	int getYExit();
	bool theoreticRecurMove(int x, int y, field& field_, int x_start_coord, int y_start_coord);
};

#endif