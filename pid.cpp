#include "pid.h"

pid::pid(double kp2, double ki2, double kd2, double offset2){
	kp = kp2;
	ki  = ki2;
	kd = kd2;
	offset = offset2;
	k1 = kp + ki + kd;
	k2 = -kp - 2.0 * kd;
	k3 = kd;
	first_update = true;
}

double pid::update(double input){
	time_point = std::chrono::system_clock::now();
	error = goal - input;
	if(first_update){
		int_error = 0.0;
		diff_error = 0.0;
	}else{
		std::chrono::duration<double>
		elapsed_seconds = time_point-previous_time_point;
		dt = elapsed_seconds.count();
		int_error += error * dt;
		diff_error = (error - prev_error) / dt;
	}

//	if(ki<1e-5){ //if ki == 0
//		value = kp * error +
//			kd * diff_error
//			+ offset;
//	}else{
		value =  kp * error +
			ki * int_error +
			kd * diff_error
			+ offset;
//	}

//	value += k1*error + k2*prev_error + k3*prev_prev_error;

	prev_prev_error = prev_error;
	prev_error = error;
	previous_time_point = time_point;
	first_update = false;
	return value;
}

void pid::set_value(double input){
	value = input; 
}

void pid::set_goal(double input){
	goal = input;
}

double pid::read_goal(){
	return goal;
}
