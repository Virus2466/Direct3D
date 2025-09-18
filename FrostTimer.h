#pragma once
#include<chrono>

class FrostTimer
{
public:
	FrostTimer();
	float Mark();
	float Peek() const;
private:
	std::chrono::steady_clock::time_point last;
};

