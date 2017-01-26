#ifndef VIEWPORT_H
#define VIEWPORT_H

#include "envBilatGL.h"

class CBI_GL Viewport
    {
    public:
	Viewport(int x=0,int y=0,int w=0,int h=0);
	double getRatio() const;

    public:
	int x;
	int y;
	int w;
	int h;

    };

#endif
