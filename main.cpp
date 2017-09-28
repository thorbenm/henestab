#include "main.h"

int digital_analog_converter::LDAC = 6; //pi pin used for LDAC control (set negative to turn off LDAC)

analog_digital_converter signal(
		3.6 * MHz,			//clock speed
		10,				//bits
		0.0,				//min_voltage (dac output at transmitting 0}
		3.0,				//max_voltage (dac output at transmitting 2^bits-1 BEWARE ORIENTATION!!!)
		1				//Chip select
		);

pid control(1,0,0,500,-1);

const int pwm_pin = 0;
const int pwm_max = 1023;
int goal = 550;
int input;
int output;

int main(){
	softPwmCreate (pwm_pin, 0, pwm_max) ;
	control.set_goal(goal);
	input = signal.read();
	control.set_value(input);
	for(;;){
		// update:
		input = signal.read();
		output = control.update(input);
		if(output > pwm_max){
			output = pwm_max;
		}
		if(output < 0){
			output = 0;
		}
     		softPwmWrite (pwm_pin, output);

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

		std::cout << input << "\t";

		std::cout << output << std::endl;
		usleep(1000000);
	}
	return 0;
}
