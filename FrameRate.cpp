#include "FrameRate.h"

FrameRate::FrameRate() : startTicksFor60FPS(chronoClock::now()), lastTime(chronoClock::now()), frameCount(0),
	frameRate(0), MAX_FPS(60), delta(0), ONE_THOUSAND_MILLI_SECS(1000){
}

void FrameRate::calculate(){
	startTicksFor60FPS = chronoClock::now();
	auto current = chronoClock::now();
	delta += current - lastTime;
	lastTime = current;
	frameCount++; 

	//std::cout << "delta: " << delta.count() << "\n";
	if (delta.count() > 1000.0) {
		delta -= ONE_THOUSAND_MILLI_SECS;
		frameRate = frameCount;
		frameCount = 0;
	}
}

void FrameRate::limitTo60FPS(){
	durationMilli frameTicks = chronoClock::now() - startTicksFor60FPS;

	//std::cout << "1000 / MAX_FPS: " << 1000 / MAX_FPS << " > " << frameTicks.count() * 1000 << "\n";
	if (1000 / MAX_FPS > frameTicks.count() ) {
		Sleep((1000.0 / (double)MAX_FPS) - (frameTicks.count() ));
	}
		
}

std::ostream & operator<<(std::ostream & os, const FrameRate &f){
	return os << f.frameRate << "\n";
}
