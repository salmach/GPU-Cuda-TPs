#pragma once
#define MONTE_DEBUG

#include "cudaTools.h"
#include "curand_kernel.h"

typedef unsigned long long int ullong;

class Montecarlo
    {
    public:
	Montecarlo (const Grid& grid, ullong n);
	virtual ~Montecarlo (void);

    public:
	void setDeviceId(int id);
	void run();
	ullong resultat;

    private:
	// Inputs
	dim3 dg;
	dim3 db;
	int deviceId;
	curandState* ptrDevGenerators;
	ullong* ptrDevTotal;
	ullong nbFleches;
    };
