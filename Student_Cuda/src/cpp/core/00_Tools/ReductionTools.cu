#include "ReductionTools.h"
#include "cudaTools.h"
#include <iostream>
#include <assert.h>

using std::cout;
using std::endl;

//host facultatif  __global__
bool testReductionTools(void);

__global__  static void kernelReductionTools(float* all);



__global__ void kernelReductionTools(float* all)
    {
    extern __shared__ float tabSM[];
    tabSM[Indice2D::tidLocal()] = 1;
    ReductionTools::reductionADD(tabSM, all);
    }


__host__ bool testReductionTools(void)
    {

    const int MP = Device::getMPCount();
    const int CORE_MP = Device::getCoreCountMP();
    const int DIM = 4;

    dim3 dg = dim3(MP,DIM,1);
    dim3 db = dim3(CORE_MP,DIM,1);
    Device::gridHeuristic(dg, db);

    float ptrTotal = 0;
    float* ptrDevTotal;
    const size_t S = sizeof(float);
    const size_t SIZE_SM = S * MP * CORE_MP * DIM;

    HANDLE_ERROR(cudaMalloc(&ptrDevTotal, S));
    HANDLE_ERROR(cudaMemset(ptrDevTotal, 0, S));  // l'interBlock

    Device::lastCudaError("kernelReductionTools (before)"); // temp debug
    kernelReductionTools<<<dg,db,SIZE_SM>>>(ptrDevTotal);  // asynchrone !!
    Device::lastCudaError("kernelReductionTools (after)"); // temp debug

    HANDLE_ERROR(cudaMemcpy(&ptrTotal, ptrDevTotal, S, cudaMemcpyDeviceToHost));

    cout << endl << "final value : " << ptrTotal << endl;

    HANDLE_ERROR(cudaFree(ptrDevTotal));

    return true;
    }
