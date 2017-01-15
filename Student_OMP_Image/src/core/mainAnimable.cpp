#include <iostream>
#include <stdlib.h>

#include "RipplingProvider.h"
#include "Animateur_CPU.h"
#include "Settings_CPU.h"

#include "JuliaProvider.h"
#include "MandelbrotProvider.h"
using namespace cpu;

using std::cout;
using std::endl;
using std::string;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

int mainAnimable(Settings& settings);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

static void rippling();
static void mandelbrot();
static void julia();

// Tools
template<typename T>
static void animer(Provider_I<T>* ptrProvider, int nbIteration);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

int mainAnimable(Settings& settings)
    {
    cout << "\n[Animable] mode" << endl;

    //rippling();
    julia();
    //mandelbrot();

    cout << "\n[Animable] end" << endl;

    return EXIT_SUCCESS;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

void rippling()
    {
    const int NB_ITERATION = 1000;

    RipplingProvider provider;
    animer<uchar4>(&provider, NB_ITERATION);
    }


void mandelbrot()
    {
    const int NB_ITERATION = 1000;

    MandelbrotProvider provider;
    animer<uchar4>(&provider, NB_ITERATION);
    }

void julia()
    {
    const int NB_ITERATION = 1000;

    JuliaProvider provider;
    animer<uchar4>(&provider, NB_ITERATION);
    }



/*-----------------------------------*\
 |*		Tools	        	*|
 \*-----------------------------------*/

template<typename T>
void animer(Provider_I<T>* ptrProvider, int nbIteration)
    {
    Animateur<T> animateur(ptrProvider, nbIteration);
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

