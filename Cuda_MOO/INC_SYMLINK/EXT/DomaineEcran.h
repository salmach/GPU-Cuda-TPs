#ifndef DOMAINEECRAN_H_
#define DOMAINEECRAN_H_

#include "envGLImage.h"
#include <iostream>
using std::ostream;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

struct DomaineEcran
    {
	int x0;
	int y0;
	int dx;
	int dy;
    };

/*--------------------------------------*\
 |*		Methodes		*|
 \*-------------------------------------*/

CBI_GLIMAGE ostream& operator<<(ostream& stream, const DomaineEcran& domaine);

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
