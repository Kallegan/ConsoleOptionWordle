#pragma once
#include <chrono>
#include <thread>


struct Timer // feedback: is this struct used anywhere?
{
	std::chrono::time_point <std::chrono::steady_clock> start{};
	std::chrono::time_point <std::chrono::steady_clock> stop{};	
	std::chrono::duration<float> duration{};

	Timer();	

	~Timer();	
};