#pragma once
#include <chrono>

class Timer
{
	std::chrono::high_resolution_clock::time_point m_clock_start;
	std::chrono::high_resolution_clock::time_point m_clock_end;
	std::chrono::duration<double> m_duration;

public:
	void Clock_Start();
	double Clock_End();
	std::chrono::duration<double> GetDuration() const;
};