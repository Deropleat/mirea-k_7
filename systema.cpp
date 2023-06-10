#include "systema.h"

int systema::run()
{
	// ���� ������ ���������������� �������
	signal move_signal;
	for (int i = 0; i < SIZE; i++) field_.setRow(i, reader_.readOneRowData().arr);
	while (!foundExit)
	{
		if (robot_.getX() == 0 && robot_.getY() == 0)
		{
			move_signal.message = "MOVE_RIGHT";
			panel.processSignal(move_signal, robot_);
			continue;
		}
		else if (robot_.getX() == SIZE - 1 && robot_.getY() == 0)
		{
			move_signal.message = "MOVE_DOWN";
			panel.processSignal(move_signal, robot_);
			continue;
		}
		else if (robot_.getX() == SIZE - 1 && robot_.getY() == SIZE - 1)
		{
			move_signal.message = "MOVE_LEFT";
			panel.processSignal(move_signal, robot_);
			continue;
		}
		else if (robot_.getX() == 0 && robot_.getY() == SIZE - 1)
		{
			move_signal.message = "MOVE_UP";
			panel.processSignal(move_signal, robot_);
			continue;
		}

		std::vector<int> neighbors = field_.getAdjacentCells(robot_.getX(), robot_.getY()).arr;
		if (robot_.getY() != 0 && robot_.getX() == 0 && robot_.getY() != SIZE - 1) // ��������� �� ����� ������� �� �� �� ������ ������ � �� �� ���������
		{
			if (neighbors[1] != 1) // ������� ��� ������ �� ������
			{
				robot_.getY() << '\n';
				if (robot_.theoreticRecurMove(robot_.getX() + 1, robot_.getY(), field_, robot_.getX(), robot_.getY()))
				{
					output_.printMessage("Maze (" + std::to_string(robot_.getY() + 1) + ", " + std::to_string(robot_.getX() + 1) + ") (" + std::to_string(robot_.getYExit() + 1) + ", " + std::to_string(robot_.getXExit() + 1) + ")", 1);
					foundExit = true;
					continue;
				}
				else output_.printMessage("There is no way out of the maze (" + std::to_string(robot_.getY() + 1) + ", " + std::to_string(robot_.getX() + 1) + ")", 1);
				output_.changeFirstOutputValue(false);
			}
			move_signal.message = "MOVE_UP";
			panel.processSignal(move_signal, robot_);
		}
		else if (robot_.getY() == 0 && robot_.getX() != 0 && robot_.getX() != SIZE - 1) // ��������� �� ������� ������� �� �� � ������ ������� � �� � ���������
		{
			if (neighbors[3] != 1) // ������� ��� ����� �� ������
			{
				if (robot_.theoreticRecurMove(robot_.getX(), robot_.getY() + 1, field_, robot_.getX(), robot_.getY()))
				{
					output_.printMessage("Maze (" + std::to_string(robot_.getY() + 1) + ", " + std::to_string(robot_.getX() + 1) + ") (" + std::to_string(robot_.getYExit() + 1) + ", " + std::to_string(robot_.getXExit() + 1) + ")", 1);
					foundExit = true;
					continue;
				}
				else output_.printMessage("There is no way out of the maze (" + std::to_string(robot_.getY() + 1) + ", " + std::to_string(robot_.getX() + 1) + ")", 1);
				output_.changeFirstOutputValue(false);
			}
			move_signal.message = "MOVE_RIGHT";
			panel.processSignal(move_signal, robot_);
		}
		else if (robot_.getY() != 0 && robot_.getX() == SIZE - 1 && robot_.getY() != SIZE - 1) // ��������� � ������ ������ �� �� �� ������ ������ � �� �� ��������� ������
		{
			if (neighbors[0] != 1) // ������� ��� ����� �� ������
			{
				if (robot_.theoreticRecurMove(robot_.getX() - 1, robot_.getY(), field_, robot_.getX(), robot_.getY()))
				{
					output_.printMessage("Maze (" + std::to_string(robot_.getY() + 1) + ", " + std::to_string(robot_.getX() + 1) + ") (" + std::to_string(robot_.getYExit() + 1) + ", " + std::to_string(robot_.getXExit() + 1) + ")", 1);
					foundExit = true;
					continue;
				}
				else output_.printMessage("There is no way out of the maze (" + std::to_string(robot_.getY() + 1) + ", " + std::to_string(robot_.getX() + 1) + ")", 1);
				output_.changeFirstOutputValue(false);
			}
			move_signal.message = "MOVE_DOWN";
			panel.processSignal(move_signal, robot_);
		}
		else if (robot_.getY() == SIZE - 1 && robot_.getX() != SIZE - 1 && robot_.getX() != 0) // ��������� �� ������ ������� �� �� � ������ ������� � �� � ���������
		{
			if (neighbors[2] != 1) // ������� ��� ������ �� ������
			{
				if (robot_.theoreticRecurMove(robot_.getX(), robot_.getY() - 1, field_, robot_.getX(), robot_.getY()))
				{
					output_.printMessage("Maze (" + std::to_string(robot_.getY() + 1) + ", " + std::to_string(robot_.getX() + 1) + ") (" + std::to_string(robot_.getYExit() + 1) + ", " + std::to_string(robot_.getXExit() + 1) + ")", 1);
					foundExit = true;
					continue;
				}
				else output_.printMessage("There is no way out of the maze (" + std::to_string(robot_.getY() + 1) + ", " + std::to_string(robot_.getX() + 1) + ")", 1);
				output_.changeFirstOutputValue(false);
			}
			move_signal.message = "MOVE_LEFT";
			panel.processSignal(move_signal, robot_);
		}
		if (robot_.getX() == 0 && robot_.getY() == 2) return 1;
	}
	return 0;
}

void systema::showTreeObject() 
{
	std::string command;
	std::cin >> command;
	if (command == "SHOWTREE") std::cout << "systema\n panel\n reader_\n field_\n robot_\n output_";
}