#include "ImageVideo.h"
#include "ImageVideoProvider.h"

#include "MathTools.h"
#include "Grid.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

static string nameVideo();

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/**
 * Override
 */
Animable_I<uchar4>* ImageVideoProvider::createAnimable()
    {
    // video
    string videoName = nameVideo();

    // Dimension
    int dw = 1920;
    int dh = 1080;

    // Grid Cuda
    dim3 dg = dim3(32, 2, 1);  		// disons a optimiser, depend du gpu
    dim3 db = dim3(16, 16, 1);   	// disons a optimiser, depend du gpu
    Grid grid(dg, db);

    return new ImageVideo(grid,dw, dh, videoName);
    }

/**
 * Override
 */
Image_I* ImageVideoProvider::createImageGL(void)
    {
    ColorRGB_01 colorTexte(1, 0, 0); // red
    return new ImageAnimable_RGBA_uchar4(createAnimable(), colorTexte);
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

string nameVideo()
    {
    // Important de tester en haute definition (autoroute.mp4) pour vallider la dll ffmpeg
    // petite video ne l'utilise pas!

#ifdef _WIN32
    // Work
	{
	//return "C:\\Users\\cedric.bilat\\Desktop\\neilPryde.avi";// ok
	//return"C:\\Users\\cedric.bilat\\Desktop\\autoroute.mp4";//ok
	}

    // Home
	{
	//  return "C:\\Users\\bilat\\Desktop\\neilPryde.avi"; // ok
	return "C:\\Users\\bilat\\Desktop\\autoroute.mp4";// ok
	}
#elif  __arm__
	{
	// return"/opt/data/neilPryde.avi"; //ok
	return "/opt/data/autoroute.mp4";// ok
	}
#else
	{
	//return "/media/Data/Video/neilPryde.avi"; // ok
	//return "/media/Data/Video/autoroute.mp4"; // ok

	 //return "/media/data/data/video/neilPryde.avi"; // ok
	 return "/media/data/data/video/autoroute.mp4"; // ok
	}
#endif
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
