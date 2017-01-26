// Attention : Extension .cu

#include <iostream>
#include "cudaTools.h"
#include "Device.h"

using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

__host__ bool helloCudaRef(void); //__host__ facultatif

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

__global__ static void kernelRef(void);
__device__ static void doSomethingHello(void);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/**
 * resumer commande cuda:
 * http://developer.download.nvidia.com/compute/cuda/4_2/rel/toolkit/docs/online/index.html
 */
__host__ bool helloCudaRef(void) //__host__ facultatif
    {
    cout << endl << "[Hello Cuda 1 Ref] : kernel empty" << endl;

    const int MP = 24;
    const int CORE_MP = 256;
    const int DIM = 1;

    dim3 dg = dim3(MP, DIM, 1);
    dim3 db = dim3(CORE_MP, DIM, 1);
    Device::gridHeuristic(dg, db);
    Grid grid(dg,db);


    Device::lastCudaError("kernelHello Ref(before)"); // temp debug
    kernelRef<<<dg,db>>>();  // asynchrone !!
    Device::lastCudaError("kernelHello Ref(after)"); // temp debug

    return true;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/**
 * output : void
 */
__global__ void kernelRef(void)
    {


    doSomethingHello();
    }

/**
 * Can be call only by device
 * inliner by nvcc (nvidia compiler)
 */
__device__ void doSomethingHello(void)
    {
    // rien
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
