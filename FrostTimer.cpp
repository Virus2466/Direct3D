#include "FrostTimer.h"

using namespace std::chrono;

FrostTimer::FrostTimer()
{
	last = steady_clock::now();
}

float FrostTimer::Mark()
{
	const auto old = last;
	last = steady_clock::now();
	const duration<float> frameTime = last - old;
	return frameTime.count();
}

float FrostTimer::Peek() const
{
	return duration<float>(steady_clock::now() - last).count();
}
