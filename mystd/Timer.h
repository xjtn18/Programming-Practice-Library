#pragma once
#include <chrono>


class Timer {
public:
	Timer()
		: beg(clock::now()) 
	{}

	void reset() {
		beg = clock::now();
	}

	double elapsed() const { 
	return std::chrono::duration_cast<second> (clock::now() - beg).count();
	}

private:
	typedef std::chrono::high_resolution_clock clock;
	typedef std::chrono::duration<double, std::ratio<1> > second;
	std::chrono::time_point<clock> beg;
};

