#ifndef DOMAINEMATH_GPU_H_
#define DOMAINEMATH_GPU_H_

#include "TDomaineMath.h"
#include "envGLImageCudas.h"
#include <math.h>

#ifndef __BOTH__

#ifdef __CUDACC__
#define __BOTH__ __device__ __host__
#else
#define __BOTH__

#endif //__CUDACC__

#endif //__BOTH__

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

namespace gpu
    {
    class DomaineMath: public TDomaineMath
	{
	    /*--------------------------------------*\
	    |*		Constructor		*|
	     \*-------------------------------------*/

	public:

	    __BOTH__
	    DomaineMath(double x0, double y0, double x1, double y1, int w = 2, int h = 2)
		{
		this->x0 = x0;
		this->y0 = y0;
		this->x1 = x1;
		this->y1 = y1;
		computeDxDy(w, h);
		}

	    __BOTH__
	    DomaineMath(const DomaineMath& src)
		{
		x0 = src.x0;
		y0 = src.y0;
		x1 = src.x1;
		y1 = src.y1;
		dxdw = src.dxdw;
		dydw = src.dydw;
		}

	    /*--------------------------------------*\
|*		Destructor		*|
	     \*-------------------------------------*/

	    __BOTH__
	    ~DomaineMath()
		{
		// Nothing
		}

	    /*--------------------------------------*\
		     |*		Methodes		*|
	     \*-------------------------------------*/

	public:

	    __BOTH__
	    DomaineMath& operator=(const DomaineMath& src)
		{
		x0 = src.x0;
		y0 = src.y0;
		x1 = src.x1;
		y1 = src.y1;
		dxdw = src.dxdw;
		dydw = src.dydw;
		return *this;
		}

	    __BOTH__
	    double dx() const
		{
		return fabs(x1 - x0);
		}

	    __BOTH__
	    double dy() const
		{
		return fabs(y1 - y0);
		}

	    __BOTH__
	    void toXY(int i, int j, double* ptrX, double* ptrY) const
		{
		*ptrX = x0 + j * dxdw;
		*ptrY = y0 + i * dydw;
		}

	    /**
	     * Compute dxdy value used int toXY
	     * Call automaticly by Image_A!
	     */
	    __BOTH__
	    void computeDxDy(int w, int h)
		{
		dxdw = (x1 - x0) / (w - 1);
		dydw = (y1 - y0) / (h - 1);
		}

	};

    }

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
