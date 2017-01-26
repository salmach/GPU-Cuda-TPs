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

bool isPiMonteCarloOMPEntrelacerPromotionTab_Ok(int n);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

static double piMonteCarloOMPEntrelacerPromotionTab(int n);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

bool isPiMonteCarloOMPEntrelacerPromotionTab_Ok(int n)
    {
    return isAlgoPIMonteCarlo_OK(piMonteCarloOMPEntrelacerPromotionTab, n, "Pi Montecarlo OMP Entrelacer promotionTab");
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/**
 * pattern cuda : excellent!
 */
double piMonteCarloOMPEntrelacerPromotionTab(int n)
    {
    const int NBTHREAD = OmpTools::getNbThread();
    int* tabSommeSousLaCourbeThread = new int[NBTHREAD];
    double* xAlea = new double[n];
    double* yAlea = new double[n];
    double m = 1.0;
    double xmin = -1.0;
    double xmax = 1.0;

    for (int i = 0; i < NBTHREAD; i++)
	{
	tabSommeSousLaCourbeThread[i] = 0;
	}
    for (int i = 0; i < n; i++)
	{
	AleaTools aleaTools = AleaTools();
		xAlea[i] = aleaTools.uniformeAB(xmin, xmax);
		yAlea[i] = aleaTools.uniformeAB(0.0, m);
	}

#pragma omp parallel
	{
	int tid = omp_get_thread_num();
	int i = tid;

	while (i < n)
	    {
	    double x = xAlea[i];
	    double y = yAlea[i];
	    if (sqrt(1 - x * x) > y)
		{
		tabSommeSousLaCourbeThread[tid]++;
		}
	    i += NBTHREAD;
	    }
	}

    int sommeSousLaCourbe = 0;
    for (int i = 0; i < NBTHREAD; i++)
	{
	sommeSousLaCourbe += tabSommeSousLaCourbeThread[i];
	}
    delete[] tabSommeSousLaCourbeThread;
    return 2 * ((((double) sommeSousLaCourbe) / n) * (xmax - xmin) * m);

    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
