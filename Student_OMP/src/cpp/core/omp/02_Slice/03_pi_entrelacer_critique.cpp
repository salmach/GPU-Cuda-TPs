#include <omp.h>
#include "OmpTools.h"
#include "../02_Slice/00_pi_tools.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

bool isPiOMPEntrelacerCritical_Ok(int n);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

static double piOMPEntrelacerCritical(int n);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

bool isPiOMPEntrelacerCritical_Ok(int n)
    {
    return isAlgoPI_OK(piOMPEntrelacerCritical, n, "Pi OMP Entrelacer critical");
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

double piOMPEntrelacerCritical(int n)
    {
     const int NB_THREAD = OmpTools ::setAndGetNaturalGranularity();
     const double DX = 1/(double)n;
     double somme = 0;
 #pragma omp parallel
     {
     const int TID = OmpTools::getTid();
     int s = TID;
     double sommeThread=0;
     while(s<n)
 	{
 	double xs = s*DX;
 	sommeThread+=fpi(xs);
 	s+=NB_THREAD;
 	}
#pragma omp critical(blabla)
     {
     somme+=sommeThread;
     }
     }
     somme = DX*somme;
     return somme;
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

