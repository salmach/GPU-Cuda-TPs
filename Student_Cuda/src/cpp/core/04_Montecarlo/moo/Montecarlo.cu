#include <stdio.h>

#include "Chrono.h"
#include "Device.h"
#include "Montecarlo.h"
#include "curand_kernel.h"

using namespace std;

extern __global__ void setup_kernel(curandState* ptrDevGenerators, int deviceId, bool useClock);
extern __global__ void work_kernel(curandState* ptrDevGenerators, ullong* ptrDevTotal, ullong n);

Montecarlo::Montecarlo(const Grid& grid, ullong n) :
	dg(grid.dg), db(grid.db), nbFleches(n)
    {
    const size_t NB_GENERATORS = grid.threadCounts() * sizeof(curandState);

    this->resultat = 0;
    this->deviceId = Device::getDeviceId();
    this->ptrDevTotal = nullptr;
    this->ptrDevGenerators = nullptr;

    HANDLE_ERROR(cudaMalloc(&ptrDevGenerators, NB_GENERATORS));
    HANDLE_ERROR(cudaMalloc(&ptrDevTotal, sizeof(ullong)));
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
    const size_t SIZE_SM = db.x * sizeof(ullong);
    HANDLE_ERROR(cudaMemset(this->ptrDevTotal, 0, sizeof(ullong)));

#ifdef MONTE_DEBUG
    Chrono chrono1;
#endif
    setup_kernel<<<dg,db>>>(this->ptrDevGenerators, this->deviceId, clock);
#ifdef MONTE_DEBUG
    Device::synchronize();
    chrono1.stop();

    Chrono chrono2;
#endif
    work_kernel<<<dg,db,SIZE_SM>>>(this->ptrDevGenerators, this->ptrDevTotal, this->nbFleches);
#ifdef MONTE_DEBUG
    Device::synchronize();
    chrono2.stop();

    double chronoTotal = chrono1.getDeltaTime() + chrono2.getDeltaTime();
    cout << "Temps Générateurs: " << chrono1.getDeltaTime() << " sec." << endl;
    cout << "Temps Calculs: " << chrono2.getDeltaTime() << " sec." << endl;
    cout << "Temps Total: " << chronoTotal << " sec." << endl;
#endif

    ullong temp;
    HANDLE_ERROR(cudaMemcpy(&temp, this->ptrDevTotal, sizeof(ullong), cudaMemcpyDeviceToHost));
    this->resultat = (ullong)temp;
    }
