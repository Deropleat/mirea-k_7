#include "controlPanel.h"

bool controlPanel::processSignal(signal signal_, robot& robot_) 
{
	if (signal_.message == "MOVE_UP") 
	{
		robot_.move(0, -1);
		return true;
	}
	else if (signal_.message == "MOVE_DOWN") 
	{
		robot_.move(0, 1);
		return true;
	}
	else if (signal_.message == "MOVE_RIGHT") 
	{
		robot_.move(1, 0);
		return true;
	}
	else if (signal_.message == "MOVE_LEFT") 
	{
		robot_.move(-1, 0);
		return true;
	}
	return false;
}