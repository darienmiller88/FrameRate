#pragma once
#include <iostream>
#include <Windows.h>
#include <chrono>
#include <ctime>

using chronoClock = std::chrono::system_clock;
using durationMilli = std::chrono::duration<double, std::milli>;

class FrameRate{
	public:
		FrameRate();
		void calculate();
		void limitTo60FPS();
		friend std::ostream &operator <<(std::ostream &os, const FrameRate &f);
	private:
		const int MAX_FPS;
		const durationMilli ONE_THOUSAND_MILLI_SECS;
		int frameRate, frameCount;
		durationMilli delta;
		chronoClock::time_point lastTime, startTicksFor60FPS;
};

