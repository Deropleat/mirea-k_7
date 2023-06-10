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
	std::vector<std::vector<int>> cells; // поле, состоящее из клеток
public:
	field();
	void setCell(int x, int y, int value); // установка значения value в клетку с координатами(x, y)
	int getCell(int x, int y); // возвращает значение клетки с координатами (x, y)
	signal getAdjacentCells(int x, int y);
	void printField();
	void setRow(int row_index, std::vector<int> row);
};
#endif
