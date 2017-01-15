#pragma once

#include "cudaTools.h"
#include "Grid.h"


/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class AddVector
    {
	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/

    public:

	/**
	 * update w by v1+v2
	 */
	AddVector(const Grid& grid, float* ptrV1, float* ptrV2, float* ptrW, int n);

	virtual ~AddVector(void);

	/*--------------------------------------*\
	|*		Methodes		*|
	 \*-------------------------------------*/

    public:

	void run();

	/*--------------------------------------*\
	|*		Attributs		*|
	 \*-------------------------------------*/

    private:

	// Inputs
	dim3 dg;
	dim3 db;
	float* ptrV1;
	float* ptrV2;
	int n;

	// Inputs/Outputs
	float* ptrW;

	// Tools
	float* ptrDevV1; // lorsque on ajoute Dev cad c est un pointeur coté device
	float* ptrDevV2;
	float* ptrDevW;
	size_t sizeOctet;

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
