#ifndef FIELD_H
#define FIELD_H

#include <iostream>
#include <vector>
#include <string>
#include "reader.h"
#include "settings.h"
#include "signal.h"

class field 
{
	std::vector<std::vector<int>> cells; // ����, ��������� �� ������
public:
	field();
	void setCell(int x, int y, int value); // ��������� �������� value � ������ � ������������(x, y)
	int getCell(int x, int y); // ���������� �������� ������ � ������������ (x, y)
	signal getAdjacentCells(int x, int y);
	void printField();
	void setRow(int row_index, std::vector<int> row);
};
#endif
