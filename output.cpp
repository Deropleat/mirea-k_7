#include "output.h"

void output::printMessage(std::string message, bool isEndlRequired) 
{
	if (isEndlRequired && !firstOutput) std::cout << std::endl;
	std::cout << message;
}

void output::changeFirstOutputValue(bool value) 
{
	firstOutput = value;
}