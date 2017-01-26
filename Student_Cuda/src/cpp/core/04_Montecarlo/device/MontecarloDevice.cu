#include <stdio.h>
#include <Indice2D.h>
#include <chrono>

#include "curand_kernel.h"
#include "Calibreur_GPU.h"
#include "Grid.h"

#include "Montecarlo.h"
#include "ReductionTools.h"

using namespace gpu;

__global__ void setup_kernel(curandState* ptrDevGenerators, int deviceId);
__global__ void work_kernel(curandState* ptrDevGenerators, ullong* ptrDevTotal, ullong n);
static __device__ bool isInside(float x, float y, float m, float(*fct)(float));
static __device__ float f(float x);
static __device__ float g(float x);

// Make this function compatible in mono / multi GPU
__global__ void setup_kernel(curandState* ptrDevGenerators, int deviceId, bool useClock)
    {
    const int TID = Indice2D::tid();

    int deltaSeed = deviceId * INT_MAX;
    int deltaSequence = deviceId * 100;
    int deltaOffset = deviceId * 100;

    int seed = (useClock) ? clock64() + deltaSeed : 1234 + deltaSeed;
    int sequenceNumber = TID + deltaSequence;
    int offset = deltaOffset;

    curand_init(seed, sequenceNumber, offset, &ptrDevGenerators[TID]);
    }

__global__ void work_kernel(curandState* ptrDevGenerators, ullong* ptrDevTotal, ullong n)
    {
    extern __shared__ ullong tabSM[];

    const int TID = Indice2D::tid();
    const int NB_THREAD = Indice2D::nbThread();
    curandState localGenerator = ptrDevGenerators[TID];

    ullong somme = 0;
    ullong s = TID;

    // ATTENTION: dépend de la fonction utilisée dans isInside()
    // m >= y Max de la fonction
    float m = 1;

    while(s<n)
	{
	// Call isInside() with f() as testing function.
	// Can be replace by g() or any function with the same signature
	somme += isInside(curand_uniform(&localGenerator), curand_uniform(&localGenerator), m, f);
	s += NB_THREAD;
	}

    tabSM[Indice2D::tidLocal()] = somme;
    __syncthreads();

    ReductionTools::reductionADD(tabSM, ptrDevTotal);
    }

// Fonction déterminant si la fleche est dans la fonction
__device__ bool isInside(float x, float y, float m, float(*fct)(float))
    {
    	Calibreur<float> calY(Interval<float>(0,1), Interval<float>(0, m));
    	calY.calibrer(y);
	return (y <= fct(x)) ? 1 : 0;
    }

// Fonction pour x de -1 à 1
__device__ float f(float x)
    {
	Calibreur<float> calX(Interval<float>(0,1), Interval<float>(-1, 1));
    	calX.calibrer(x);
    	return sqrt(1 - x * x);
    }

// Fonction pour x de 0 à 1
__device__ float g(float x)
    {
	Calibreur<float> calX(Interval<float>(0,1), Interval<float>(0, 1));
    	calX.calibrer(x);
    	return 1 / (1 + x * x);
    }
