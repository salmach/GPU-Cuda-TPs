#pragma once

#include "cudaTools.h"
#include "curand_kernel.h"

class Montecarlo
    {
    public:
	Montecarlo (const Grid& grid, uint n);
	virtual ~Montecarlo (void);

    public:
	void setDeviceId(int id);
	void run();
	uint resultat;

    private:
	// Inputs
	dim3 dg;
	dim3 db;
	int deviceId;
	curandState* ptrDevGenerators;
	uint* ptrDevTotal;
	uint nbFleches;
    };
