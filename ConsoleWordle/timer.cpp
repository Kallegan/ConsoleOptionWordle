#include "timer.h"

	Timer::Timer()
	{
		Timer::start = std::chrono::high_resolution_clock::now();
	}

	Timer::~Timer()
	{
		stop = std::chrono::high_resolution_clock::now();
		duration = stop - start;

		float ms = duration.count() * 1000.0f;
		printf("Timer duration: %f ms \n", ms);
	}
