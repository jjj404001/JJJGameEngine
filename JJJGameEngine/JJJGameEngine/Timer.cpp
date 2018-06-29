#include "Timer.h"

void Timer::Clock_Start()
{
	m_clock_start = std::chrono::high_resolution_clock::now();
}
double Timer::Clock_End()
{
	m_clock_end = std::chrono::high_resolution_clock::now();

	m_duration = std::chrono::duration_cast<std::chrono::duration<double>>(m_clock_end - m_clock_start);

	return m_duration.count();
}

std::chrono::duration<double> Timer::GetDuration() const
{
	return m_duration;
}
