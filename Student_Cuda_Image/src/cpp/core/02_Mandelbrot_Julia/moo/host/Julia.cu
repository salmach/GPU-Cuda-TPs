#include "Fractale.h"
#include "FractaleMath.h"

#include "Julia.h"

#include "IndiceTools_GPU.h"
#include "DomaineMath_GPU.h"

#include <iostream>
#include <assert.h>


extern __global__ void JuliaKernel(uchar4* ptrDevPixels, uint w, uint h,const DomaineMath &domaineMath, uint n, float t);

Julia::Julia(const Grid& grid, uint w, uint h, const DomaineMath& domaineMath): Fractale(grid,w,h,domaineMath){}
Julia::~Julia(){}

void Julia::process(uchar4* ptrDevPixels, uint w, uint h, const DomaineMath& domaineMath)
    {
    Device::lastCudaError("Fractale Julia rgba uchar4 (before)"); // facultatif, for debug only, remove for release

    JuliaKernel<<<dg,db>>>(ptrDevPixels,w,h,domaineMath,n,t);

    Device::lastCudaError("Fractale Julia rgba uchar4 (after)"); // facultatif, for debug only, remove for release
    }

__device__
void Julia::workPixel(uchar4* ptrColorIJ, int i, int j, const DomaineMath& domaineMath, JuliaMath* ptrJuliaMath)
    {
    // (i,j) domaine ecran dans N2
    // (x,y) domaine math dans R2

    double x;
    double y;
    domaineMath.toXY(i, j, &x, &y); // fill (x,y) from (i,j)

    // float t=variateurAnimation.get();

    //ptrJuliaMath->colorXY(ptrColorIJ, x, y); // in [01]
    }

