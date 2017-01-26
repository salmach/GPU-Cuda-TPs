#include "Device.h"
#include "Montecarlo.h"
#include "curand_kernel.h"

extern __global__ void setup_kernel(curandState* ptrDevGenerators, int deviceId);
extern __global__ void work_kernel(curandState* ptrDevGenerators, uint* ptrDevTotal, uint n);

Montecarlo::Montecarlo(const Grid& grid, uint n) :
	dg(grid.dg), db(grid.db), nbFleches(n)
    {
    const size_t NB_GENERATORS = grid.threadCounts() * sizeof(curandState);

    this->resultat = 0;
    this->deviceId = Device::getDeviceId();
    this->ptrDevTotal = nullptr;
    this->ptrDevGenerators = nullptr;

    HANDLE_ERROR(cudaMalloc(&ptrDevGenerators, NB_GENERATORS));
    HANDLE_ERROR(cudaMalloc(&ptrDevTotal, sizeof(uint)));
    Device::lastCudaError("Montecarlo MM (end allocation)");
    }

Montecarlo::~Montecarlo()
    {
    HANDLE_ERROR(cudaFree(ptrDevGenerators));
    HANDLE_ERROR(cudaFree(ptrDevTotal));
    Device::lastCudaError("Montecarlo MM (end deallocation)");
    }

void Montecarlo::setDeviceId(int id)
    {
    // Permet de changer le deviceId manuellement. Pas utilisé.
    this->deviceId = id;
    }

void Montecarlo::run()
    {
    const size_t SIZE_SM = db.x * sizeof(uint);
    HANDLE_ERROR(cudaMemset(this->ptrDevTotal, 0, sizeof(uint)));

    setup_kernel<<<dg,db>>>(this->ptrDevGenerators, this->deviceId);
    work_kernel<<<dg,db,SIZE_SM>>>(this->ptrDevGenerators, this->ptrDevTotal, this->nbFleches);

    uint temp;
    HANDLE_ERROR(cudaMemcpy(&temp, this->ptrDevTotal, sizeof(uint), cudaMemcpyDeviceToHost));
    this->resultat = (uint)temp;
    }
