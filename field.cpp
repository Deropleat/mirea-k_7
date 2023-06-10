#include "field.h"

field::field() 
{
	cells = std::vector<std::vector<int>>(22, std::vector<int>(22, 0));
}

void field::setCell(int x, int y, int value) 
{
	cells[y][x] = value; // установка значения value в клетку с координатами (x, y)
}

int field::getCell(int x, int y) 
{
	return cells[y][x]; // возвращает значение клетки с координатами (x, y)
}

signal field::getAdjacentCells(int x, int y) 
{
	signal signal_;
	signal_.message = "NEARESET CELLS";
	// возвращает значения соседних клеток для клетки с координатами (x, y) left, right, up, down
	signal_.arr.push_back(cells[y][std::max(x - 1, 0)]);
	signal_.arr.push_back(cells[y][std::min(x + 1, SIZE - 1)]);
	signal_.arr.push_back(cells[std::max(y - 1, 0)][x]);
	signal_.arr.push_back(cells[std::min(y + 1, SIZE - 1)][x]);
	return signal_;
}

void field::printField() 
{
	for (int i = 0; i < SIZE; i++) 
	{
		for (int j = 0; j < SIZE; j++) 
		{
			std::cout << bool(cells[i][j] == 1);
		}
		std::cout << '\n';
	}
}

void field::setRow(int row_index, std::vector<int> row) 
{
	cells[row_index] = row;
}