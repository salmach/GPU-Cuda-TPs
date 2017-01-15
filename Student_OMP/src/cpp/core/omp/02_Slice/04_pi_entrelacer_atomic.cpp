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

bool isPiOMPEntrelacerAtomic_Ok(int n);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

static double piOMPEntrelacerAtomic(int n);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

bool isPiOMPEntrelacerAtomic_Ok(int n)
    {
    return isAlgoPI_OK(piOMPEntrelacerAtomic,  n, "Pi OMP Entrelacer atomic");
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/**
 * Bonne performance, si!
 */
double piOMPEntrelacerAtomic(int n)
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
   #pragma omp atomic
/*seul l op apres doit etre faite de facon atomique dnc on n a pas a mettre les accollades
 **/
        somme+=sommeThread;

        }
        somme = DX*somme;
        return somme;
       }
/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

