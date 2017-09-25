#pragma omp once
#include <chrono>
#include <ctime>

class pid{
public:
	void set_value(double input = 0);
	void set_goal(double input = 0);
	double read_goal(void);
	double update(double input = 0);
	pid(double kp2 = 1, double ti2 = 0, double td2 = 0, double offset = 0);
private:
	double kp;
	double ki;
	double kd;
	double k1;
	double k2;
	double k3;
	double offset;
	double dt;
	double goal;
	double value;
	double error;
	double int_error;
	double diff_error;
	double prev_error;
	double prev_prev_error;
	bool first_update;
	std::chrono::time_point<std::chrono::system_clock> time_point;
	std::chrono::time_point<std::chrono::system_clock> previous_time_point;
};
