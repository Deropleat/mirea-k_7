#ifndef OUTPUT_H
#define OUTPUT_H

#include <iostream>
#include <string>

class output
{
	bool firstOutput = true;
public:
	void printMessage(std::string message, bool isEndlRequired);
	void changeFirstOutputValue(bool value);
};

#endif