#include "RayTracing.h"
#include "SphereCreator.h"



__global__ void rayTracingKernel(uchar4* ptrDevPixels, uint w, uint h, float t, Sphere* ptrDevSpheres,int nbSphere);


RayTracing::RayTracing(const Grid& grid,int nbSphere, int w, int h, DomaineMath domaineMath, float t) :
	Animable_I<uchar4>(grid, w, h, "RayTracing", domaineMath), variateurAnimation(Interval<float>(0, 2 * PI), t)
    {

    this-> nbSphere = nbSphere ;

    SphereCreator sphereCreator(nbSphere, w, h); // sur la pile
    Sphere* ptrTabSphere = sphereCreator.getTabSphere();

     // transfert to GM
   //  ptrDevSpheres = 0 ;

     size_t sizeTabSphere = nbSphere * sizeof(Sphere);

     HANDLE_ERROR(cudaMalloc((void**) &ptrDevSpheres, sizeTabSphere));

     HANDLE_ERROR(cudaMemcpy(ptrDevSpheres, ptrTabSphere, sizeTabSphere, cudaMemcpyHostToDevice));

     // transfert to CM
    //toCM(ptrTabSphere); // a implemneter

    } // shereCreator qui est sur la pile est détruit ici
// ce qui détruit les sphères cotés host, via son destructeur


// transfert to CM
/*void RayTracing::toCM(Sphere* ptrTabSphere)
    {
    //TODO
    }
*/

void RayTracing::process(uchar4* ptrDevPixels, uint w, uint h, const DomaineMath& domaineMath)
    {
    //RayTracing::lastCudaError("Raaaa rgba uchar4 (before)"); // facultatif, for debug only, remove for release

    rayTracingKernel<<<dg,db>>>(ptrDevPixels,w,h,t,ptrDevSpheres,nbSphere);

    //RayTracing::lastCudaError("Ra rgba uchar4 (after)"); // facultatif, for debug only, remove for release
    }

void RayTracing::animationStep()
    {
    this->t = variateurAnimation.varierAndGet(); // in [0,2pi]
    }

RayTracing::~RayTracing()
    {
    HANDLE_ERROR(cudaFree(ptrDevSpheres));
    }