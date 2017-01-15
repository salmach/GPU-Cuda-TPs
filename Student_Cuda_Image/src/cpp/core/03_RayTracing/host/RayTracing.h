#pragma once

#include "cudaTools.h"
#include "MathTools.h"

#include "Variateur_GPU.h"
#include "Animable_I_GPU.h"
#include "Sphere.h"
#include "DomaineMath_GPU.h"

using namespace gpu;

class RayTracing: public Animable_I<uchar4>
    {

public:
	RayTracing(const Grid& grid,int nbSphere, int w, int h, DomaineMath domaineMath, float t);
	virtual ~RayTracing(void);

	virtual void process(uchar4* ptrDevPixels,uint w, uint h, const DomaineMath& domaineMath);

	/**
	 * Call periodicly by the api
	 */
protected:
	void animationStep();

	// transfert to CM
	//void toCM(Sphere* ptrTabSphere);

private:

    // Tools
    Variateur<float> variateurAnimation;
    Sphere *ptrDevSpheres;
    int nbSphere;

    };
