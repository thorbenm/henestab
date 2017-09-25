#include "main.h"

int digital_analog_converter::LDAC = 6; //pi pin used for LDAC control (set negative to turn off LDAC)

analog_digital_converter signal(
		3.6 * MHz,			//clock speed
		10,				//bits
		0.0,				//min_voltage (dac output at transmitting 0}
		3.0,				//max_voltage (dac output at transmitting 2^bits-1 BEWARE ORIENTATION!!!)
		1				//Chip select
		);

const int pwm_pin = 0;

int main(){
	softPwmCreate (pwm_pin, 0, 1023) ;
	softPwmWrite (pwm_pin, 512) ;
	for(;;){
		std::cout << signal.read() << std::endl;
		usleep(1000000);
	}
	return 0;
}
