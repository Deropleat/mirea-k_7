#include <iostream>
#include <vector>
#include "reader.h"
#include "settings.h"
#include "field.h"
#include "signal.h"

signal reader::readOneRowData() 
{
	signal signal_;
	std::string row;
	std::cin >> row;
	for (int i = 0; i < SIZE; i++) 
	{
		signal_.arr.push_back((row[i] == '1'));
		signal_.message += std::to_string(row[i]);
	}
	return signal_;
}