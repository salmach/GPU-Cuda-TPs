#ifndef TDOMAINEMATH_H_
#define TDOMAINEMATH_H_

#include "envGLImage.h"
#include "DomaineEcran.h"
#include <iostream>

using std::ostream;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/**
 * Only Data and statique methode.
 * Afin de pouvoir être utilisable avec Cuda
 */
class CBI_GLIMAGE TDomaineMath
    {
    public :

	static TDomaineMath* extractDomaineFromSelection(const TDomaineMath& domaineMath, const DomaineEcran& selection, int dxFrame, int dyFrame);

	/**
	 * call by API
	 */
	static void computeDxDy(TDomaineMath* ptrDomaine,int w, int h);

    public:

	//Input
	double x0;
	double y0;
	double x1;
	double y1;

    protected :

	double dxdw; // var only used for computing toXY
	double dydw; // var only used for computing toXY


    };

/*----------------------------------------------------------------------*\
 |*			Procedures 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/


CBI_GLIMAGE ostream& operator<<(ostream& stream, const TDomaineMath& domaine);

#endif


/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
