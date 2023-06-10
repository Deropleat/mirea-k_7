#ifndef CONTROLPANEL_H
#define CONTROLPANEL_H

#include <iostream>
#include <string>
#include "reader.h"
#include "output.h"
#include "robot.h"
#include "signal.h"

class controlPanel 
{
public:
	bool processSignal(signal signal_, robot& robot_);
};

#endif