#include "Indice2D.h"
#include "cudaTools.h"
#include "Sphere.h"

#include "IndiceTools_GPU.h"
#include "DomaineMath_GPU.h"

#include "ColorTools_GPU.h"

using namespace gpu;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/


__device__ void calculColorPixel(int i, int j, Sphere* ptrDevSphere, int n, uchar4 &color, int t);
__global__ void rayTracingKernel(uchar4* ptrDevPixels, uint w, uint h, float t,Sphere* ptrDevSpheres,int nbSphere);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

__global__ void rayTracingKernel(uchar4* ptrDevPixels, uint w, uint h, float t,Sphere* ptrDevSpheres,int nbSphere)
    {


    const int TID = Indice2D::tid();
    const int NB_THREAD = Indice2D::nbThread();
    const int WH = w * h;

    double x;
    double y;

    int i;// in [0,h[
    int j;// in [0,w[

    int s = TID;
    while (s < WH)
	{

	IndiceTools::toIJ(s, w, &i, &j); // update (i, j)

	//color of Pixel
	uchar4 color;

	calculColorPixel(i,j, ptrDevSpheres, nbSphere, color, t);

	//setpixel avec color
	ptrDevPixels[s] = color;

	s += NB_THREAD;
	}

    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/



__device__
void calculColorPixel(int i, int j, Sphere* ptrDevSphere, int n, uchar4 &color, int t)
    {
    float3 hue01;
    hue01.x = 0; // h
    hue01.y = 1; // s
    hue01.z = 0; // b

    for (int k = 0; k < n; k++)
	{
	float minDist = 10000000.0;

	float2 xySol;
	xySol.x = i;
	xySol.y = j;
	//Calculer h 2
	float hCarre = ptrDevSphere[k].hCarre(xySol);

	bool isEndessous = ptrDevSphere[k].isEnDessous(hCarre);

	if (isEndessous == true)
	    {
	    //Calculer dz
	    float dz = ptrDevSphere[k].dz(hCarre);
	    //Calculer distance
	    float distance = ptrDevSphere[k].distance(dz);
	    //Calculer brightnesse
	    if (distance < minDist)
		{
		minDist = distance;
		hue01.z = ptrDevSphere[k].brightness(dz);
		hue01.x = ptrDevSphere[k].hue(t);
		}

	    }
	}

    color.w = 255;
    ColorTools::HSB_TO_RVB(hue01, &color); // update color

    }
