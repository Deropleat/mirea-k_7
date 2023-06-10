#ifndef SYSTEMA_H
#define SYSTEMA_H

#include "field.h"
#include "robot.h"
#include "reader.h"
#include "controlPanel.h"
#include "signal.h"
#include "output.h"

class systema 
{
	controlPanel panel;
	reader reader_;
	field field_;
	robot robot_;
	output output_;
	bool foundExit = false;
public:
	int run();
	void showTreeObject();
};

#endif