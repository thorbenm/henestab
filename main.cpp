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
const int pwm_max = 1023;

int main(){
	softPwmCreate (pwm_pin, 0, pwm_max) ;
	int output = pwm_max / 2;
     	softPwmWrite (pwm_pin, output);
//	for(;;){
//	        for(int j = 0; j <= pwm_max; j++){
//		      	softPwmWrite (pwm_pin, j);
//			usleep(5000000 / pwm_max);
//	        }
//	}
	for(;;){
		// print time nicely
		time_t rawtime;
		struct tm * timeinfo;
		char buffer[80];
		time (&rawtime);
		timeinfo = localtime(&rawtime);
		strftime(buffer,sizeof(buffer),"%Y-%m-%d %I:%M:%S",timeinfo);
		std::string str(buffer);
		std::cout << str << "\t";

		//print time in seconds
		time_t seconds;
		seconds = time (NULL);
		std::cout << seconds << "\t";

		std::cout << output << "\t" << pwm_max << "\t";

		std::cout << signal.read() << std::endl;
		usleep(1000000);
	}
	return 0;
}
