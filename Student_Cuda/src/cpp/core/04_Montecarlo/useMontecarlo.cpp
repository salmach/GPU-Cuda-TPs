
#include <iostream>
#include <omp.h>
#include "Grid.h"
#include "Device.h"

#include "Montecarlo.h"

using std::cout;
using std::endl;

bool useMontecarloMono()
    {
    const uint FLECHETTES = 1000000000;
//    const int MP = Device::getMPCount();
//    const int CORE_MP = Device::getCoreCountMP();
//    const int DIM = 4;
    const int MP = 240;
    const int CORE_MP = 256;
    const int DIM = 1;

    dim3 dg = dim3(MP, DIM, 1);
    dim3 db = dim3(CORE_MP, DIM, 1);
    Device::gridHeuristic(dg, db);
    Grid grid(dg,db);

    HANDLE_ERROR(cudaSetDevice(3));

    cout << "[Start Montecarlo Mono]" << endl;
    Montecarlo montecarlo(grid, FLECHETTES);
    montecarlo.run();
    // % de fléchettes dans la zone * aire de l'ensemble de la fonction utilisée (soit 2)
    float piHat = ( ((float)montecarlo.resultat / (float)FLECHETTES) * 2.0 ) * 2.0;
    cout << "Flèchettes dans la zone: " << montecarlo.resultat << " sur " << FLECHETTES << endl;
    cout << "Resultat: " << piHat << endl;

    return true;
    }

bool useMontecarloMulti()
    {
    const uint FLECHETTES = 1000000000;
//    const int MP = Device::getMPCount();
//    const int CORE_MP = Device::getCoreCountMP();
//    const int DIM = 4;
    const int MP = 24;
    const int CORE_MP = 256;
    const int DIM = 1;

    dim3 dg = dim3(MP, DIM, 1);
    dim3 db = dim3(CORE_MP, DIM, 1);
    Device::gridHeuristic(dg, db);
    Grid grid(dg,db);

    int nbDevices = Device::getDeviceCount();
    uint total = 0;
    uint result[nbDevices];

    cout << "[Start Montecarlo Multi]" << endl;

#pragma omp parallel for
    for(int id=0; id<nbDevices; ++id)
	{
	HANDLE_ERROR(cudaSetDevice(id));

	uint fracFlechettes = (id < nbDevices-1) ? (FLECHETTES/nbDevices) : (FLECHETTES/nbDevices)+(FLECHETTES%nbDevices);

	Montecarlo montecarlo(grid, fracFlechettes);
	montecarlo.run();
	result[id] = montecarlo.resultat;
	}

    for(int i=0; i<nbDevices; ++i)
	{
	total += result[i];
	}

    // % de fléchettes dans la zone * aire de l'ensemble de la fonction utilisée (soit 2)
    float piHat = ( ((float)total / (float)FLECHETTES) * 2 ) * 2;
    cout << "Flèchettes dans la zone: " << total << " sur " << FLECHETTES << endl;
    cout << "Resultat: " << piHat << endl;

    return true;
    }
