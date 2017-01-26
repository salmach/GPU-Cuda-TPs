#include <omp.h>
#include "00_pi_tools.h"
#include "OmpTools.h"
#include "AleaTools.h"
#include "math.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

bool isPiMonteCarloOMPforAtomic_Ok(int n);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

static double piMonteCarloOMPforAtomic(int n);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

bool isPiMonteCarloOMPforAtomic_Ok(int n)
    {
    return isAlgoPIMonteCarlo_OK(piMonteCarloOMPforAtomic, n, "Pi Montecarlo OMP for atomic");
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/**
 * synchronisation couteuse!
 */
double piMonteCarloOMPforAtomic(int n)
    {

    double somme = 0;
    int sommeSousLaCourbe = 0;
    double* xAlea = new double[n];
    double* yAlea = new double[n];
    double m = 1.0;
    double xmin = -1.0;
    double xmax = 1.0;

    for (int i = 0; i < n; i++)
	{

	AleaTools aleaTools = AleaTools();
	xAlea[i] = aleaTools.uniformeAB(xmin, xmax);
	yAlea[i] = aleaTools.uniformeAB(0.0, m);

	}

    // Par défaut tout est shared
#pragma omp parallel for
    for (int i = 0; i < n; i++)
	{
	double x = xAlea[i];
	double y = yAlea[i];
	if (sqrt(1 - x * x) > y)
	    {
#pragma omp atomic
	    sommeSousLaCourbe++;

	    }
	}
    return 2 * ((((double) sommeSousLaCourbe) / n) * (xmax - xmin) * m);
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
