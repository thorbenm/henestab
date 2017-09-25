#pragma once

#include <iostream>
#include "spi.h"
#include "pid.h"
#include <unistd.h> //usleep
#include <wiringPi.h>
#include <softPwm.h>
#include <ctime>

const double MHz = 1000000.0;
const double kHz = 1000.0;

