#include <iostream>
#include "VectorTools.h"
#include "Grid.h"
#include "Device.h"

using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

#include "AddVector.h"

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

bool useAddVecteur(void);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

bool useAddVecteur()
    {
    int n = 9;

    float* ptrV1 = VectorTools::createV1(n);
    float* ptrV2 = VectorTools::createV2(n);
    float* ptrW = new float[n];

    // Partie interessante GPGPU
	{
	int mp = Device::getCoreCountMP();
	int corebymp = Device::getCoreCountMP();

	// il faut que la multiplication des 3 soit = 24!!!!
    	dim3 dg(mp, 4, 1); // disons, a optimiser selon le gpu, peut drastiqument ameliorer ou baisser les performances
    	dim3 db(corebymp, 4, 1); // disons, a optimiser selon le gpu, peut drastiqument ameliorer ou baisser les performances
	Grid grid(dg,db);
	Device::gridHeuristic(dg, db); // facultatif regarder si les heureistiques sont respectées ou pas

	AddVector addVector(grid,ptrV1, ptrV2, ptrW, n); // on passse la grille à AddVector pour pouvoir facilement la faire varier de l'extérieur (ici) pour trouver l'optimum
	addVector.run();
	}

    VectorTools::print(ptrW, n); // check result

    bool isOk = VectorTools::isAddVector_Ok(ptrV1, ptrV2, ptrW, n);

    delete[] ptrV1;
    delete[] ptrV2;
    delete[] ptrW;

    return isOk;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

