#include "AddVector.h"

#include <iostream>

#include "Device.h"

using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

extern __global__ void addVector(float* ptrDevV1, float* ptrDevV2, float* ptrDevW,int n);

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Constructeur			*|
 \*-------------------------------------*/

AddVector::AddVector(const Grid& grid,float* ptrV1, float* ptrV2, float* ptrW, int n) :
	ptrV1(ptrV1), ptrV2(ptrV2), ptrW(ptrW), n(n)
    {
    this->sizeOctet = n * sizeof(float); // octet

    // MM
	{
	// MM (malloc Device)
	    {
	    HANDLE_ERROR(cudaMalloc(&ptrDevV1, sizeOctet));
	    //on a passerr l adresse de ptrDevV1 puisque la valeur du parametre change avant et aprese l appel de la fct
	    HANDLE_ERROR(cudaMalloc(&ptrDevV2, sizeOctet));
	    HANDLE_ERROR(cudaMalloc(&ptrDevW, sizeOctet));
	    }

	// MM (memset Device)
	    {
	    HANDLE_ERROR(cudaMemset(ptrDevW, 0, sizeOctet));
	    //eviter d avoir les resultats de l execution d avant
	    }

	// MM (copy Host->Device)
	    {
	    // Pour info , ci dessous : ptrDevV1=ptrV1
	    HANDLE_ERROR(cudaMemcpy(ptrDevV1, ptrV1, sizeOctet, cudaMemcpyHostToDevice));
	    HANDLE_ERROR(cudaMemcpy(ptrDevV2, ptrV2, sizeOctet, cudaMemcpyHostToDevice));

	    }

	Device::lastCudaError("AddVector MM (end allocation)"); // temp debug, facultatif
	}

    // Grid
	{
	this->dg=grid.dg;
	this->db=grid.db;
	}
    }

AddVector::~AddVector(void)
    {
    //MM (device free)
	{
	HANDLE_ERROR(cudaFree(ptrDevV1));
	HANDLE_ERROR(cudaFree(ptrDevV2));
	HANDLE_ERROR(cudaFree(ptrDevW));

	//Pour etre sur qu on n a pas d erreures !! a mettre tjrs
	Device::lastCudaError("AddVector MM (end deallocation)"); // temp debug, facultatif
	}
    }

/*--------------------------------------*\
 |*		Methode			*|
 \*-------------------------------------*/

void AddVector::run()
    {
    Device::lastCudaError("addVecteur (before)"); // temp debug
    //on n a pas le droit de mettre un attribut de type pointeur ici de facon direct ou indirect
    //on evite le goulet d etranglement entre cpu et gpu, on evite de passer l objet sphere ici au device
    addVector<<<dg,db>>>(ptrDevV1, ptrDevV2, ptrDevW, n); // assynchrone
    Device::lastCudaError("addVecteur (after)"); // temp debug

   //Ceci est une barriere exclplicite de synchronisation pour obliger le GPU d attendre que le calcul de addVector soit fini pour executer le device a gost
    Device::synchronize(); // Temp,debug, only for printf in  GPU

    // MM (Device -> Host)
	{
	HANDLE_ERROR(cudaMemcpy(ptrW, ptrDevW, sizeOctet, cudaMemcpyDeviceToHost)); // barriere synchronisation implicite
	}
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
