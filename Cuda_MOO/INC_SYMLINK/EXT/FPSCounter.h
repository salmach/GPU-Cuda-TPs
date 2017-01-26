#ifndef FPS_COUNTER_H
#define FPS_COUNTER_H

#include "envBilatDisplayable.h"
#include <time.h>

class CBI_DISPLAYABLE FPSCounter
    {
    public:
	FPSCounter();

	virtual ~FPSCounter();

	void frame();

	int getFPS() const;

    private:
	//Output
	int fps;

	// Tools
	int frameCount;
	time_t startTimeMs;
    };

#endif
