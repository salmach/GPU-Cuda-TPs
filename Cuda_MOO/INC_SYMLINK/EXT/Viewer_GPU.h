#pragma once

#include <iostream>
#include "ImageOption.h"

#include "GLUTImageViewers_GPU.h"
#include "Provider_I_GPU.h"

using std::cout;
using std::endl;
using std::string;

// TProvider doit fournir
//    Image_I*
// see Image_GPU and Provider_I_GPU
namespace gpu
    {
    template<class TProvider>
    class Viewer
	{

	    /*--------------------------------------*\
	|*		Constructor		*|
	     \*-------------------------------------*/

	public:

	    Viewer(ImageOption imageOption, int pxFrame = 0, int pyFrame = 0) :
		    ptrImage(TProvider().createImageGL()), glutViewer(ptrImage, imageOption, pxFrame, pyFrame)
		{
		// Rien
		}

	    ~Viewer()
		{
		delete ptrImage; // car TProvider::createImageGL() fournit un pointeur d'un objet dynamique
		}
	    
	    /*--------------------------------------*\
	|*		Methodes		*|
	     \*-------------------------------------*/

	public:

	    void setSize(int w, int h)
		{
		glutViewer.getGLUTWindowImage()->setSize(w, h);
		}

	    void setPosition(int px, int py)
		{
		glutViewer.getGLUTWindowImage()->setPosition(px, py);
		}

	    GLUTImageViewers* getGlutImageViewers()
		{
		return &glutViewer;
		}

	    GLUTWindowImage* getGLUTWindowImage()
		{
		return glutViewer.getGLUTWindowImage();
		}

	    /*--------------------------------------*\
	|*		Attributs		*|
	     \*-------------------------------------*/

	private:
	    
	    // Input
	    Image_I* ptrImage;

	    // Tools
	    GLUTImageViewers glutViewer;
	    
	};
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
