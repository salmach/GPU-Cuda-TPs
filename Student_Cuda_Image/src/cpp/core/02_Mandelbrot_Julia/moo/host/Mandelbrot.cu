#include "Fractale.h"
#include "FractaleMath.h"
#include "MandelbrotMath.h"
#include "Mandelbrot.h"

#include "IndiceTools_GPU.h"
#include "DomaineMath_GPU.h"

#include <iostream>
#include <assert.h>

using std::cout;
using std::endl;

extern __global__ void MandelbrotKernel(uchar4* ptrDevPixels, uint w, uint h,const DomaineMath &domaineMath, uint n, float t);

Mandelbrot::Mandelbrot(const Grid& grid, uint w, uint h, const DomaineMath& domaineMath): Fractale(grid,w,h,domaineMath){}
Mandelbrot::~Mandelbrot(){}


void Mandelbrot::process(uchar4* ptrDevPixels, uint w, uint h, const DomaineMath& domaineMath)
    {
    Device::lastCudaError("Fractale rgba uchar4 (before)"); // facultatif, for debug only, remove for release

    MandelbrotKernel<<<dg,db>>>(ptrDevPixels,w,h,domaineMath,n,t);

    Device::lastCudaError("Fractale rgba uchar4 (after)"); // facultatif, for debug only, remove for release
    }

//__device__
//void Mandelbrot::workPixel(uchar4* ptrColorIJ, int i, int j, const DomaineMath& domaineMath, FractaleMath* ptrFractaleMath)
//    {
//    // (i,j) domaine ecran dans N2
//    // (x,y) domaine math dans R2
//
//    double x;
//    double y;
//    domaineMath.toXY(i, j, &x, &y); // fill (x,y) from (i,j)
//
//    // float t=variateurAnimation.get();
//
//    ptrFractaleMath->colorXY(ptrColorIJ, x, y); // in [01]
//    }
