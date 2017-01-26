#ifndef DOMAINEMATH_CPU_H_
#define DOMAINEMATH_CPU_H_

#include "TDomaineMath.h"
#include <iostream>
using std::ostream;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

namespace cpu
    {
    class CBI_GLIMAGE DomaineMath: public TDomaineMath
	{

	    /*--------------------------------------*\
	    |*		Constructor		*|
	     \*-------------------------------------*/

	public:

	    DomaineMath(double x0, double y0, double x1, double y1, int w = 2, int h = 2);

	    /*--------------------------------------*\
	    |*		Methodes		*|
	     \*-------------------------------------*/

	public:

	    double dx() const;

	    double dy() const;

	    void toXY(int i, int j, double* ptrX, double* ptrY) const;

	    /**
	     * Compute dxdy value used int toXY
	     * Call automaticly by Image_A!
	     */
	    void computeDxDy(int w, int h);

	};
    }

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
