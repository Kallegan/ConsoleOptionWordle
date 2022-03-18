#pragma once
#include <chrono>
#include <thread>


struct Timer
{
	std::chrono::time_point <std::chrono::steady_clock> start{};
	std::chrono::time_point <std::chrono::steady_clock> stop{};	
	std::chrono::duration<float> duration{};

	Timer();	

	~Timer();	
};