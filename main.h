#pragma once

#include <iostream>
#include "../spi/spi.h"
#include "../pid/pid.h"
#include <unistd.h> //usleep
#include <wiringPi.h>
#include <softPwm.h>

const double MHz = 1000000.0;
const double kHz = 1000.0;

