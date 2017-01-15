#include "Indice2D.h"
#include "Indice1D.h"
#include "cudaTools.h"

#include <stdio.h>



/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/


/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

__global__ void addVector(float* ptrDevV1, float* ptrDevV2, float* ptrDevW,int n);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/


static __device__ void secondaire(float* ptrDevV1, float* ptrDevV2, float* ptrDevW,int n);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/


/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/**
 * output : void required !!
 */
__global__ void addVector(float* ptrDevV1, float* ptrDevV2, float* ptrDevW,int n)
    {
    secondaire(ptrDevV1, ptrDevV2, ptrDevW, n); // pas necessaire, just for fun
    }


/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/


__device__ void secondaire(float* ptrDevV1, float* ptrDevV2, float* ptrDevW,int n)
    {
    const int NB_THREAD=Indice2D::nbThread();
    const int TID=Indice2D::tid();

    // Debug, facultatif
    //si on met ca on doit mettre synchronise coté host qd on active ca les printf
    //faut tjours conditionner sinn cava etre activé par ts les threads
//    if (TID==0)
//	{
//	printf("Coucou from device tid = %d",TID); //required   Device::synchronize(); after the call of kernel
//	}

   int s = TID;
   while(s<n){
       ptrDevW[s] = ptrDevV1[s] + ptrDevV2[s];
       s += NB_THREAD;
       }
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

