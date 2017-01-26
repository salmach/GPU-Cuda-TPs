#ifndef CORE_HEADER_TIMAGE_2_H_
#define CORE_HEADER_TIMAGE_2_H_

#include "Image_I.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/**
 * T 		: float,float3,float4,uchar,uchar3,uchar4 must be logic with PIXEL_FORMAT
 * ColorModel 	: RGBA,RGB,HSB,HSBA,GRAY,BGR,BGRA
 * PixelFormat  : GL_FLOAT, GL_UNSIGNED_BYTE
 * DomaineMath  : Class representing a domaine need :
 */
template<typename T, ColorModel ColorModel, int PixelFormat, class DomaineMath>
class Image_A: public Image_I
    {
	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	Image_A(int w, int h, DomaineMath initialDomaine) :
		Image_I(w, h, ColorModel, PixelFormat, initialDomaine),currentDomaineMath(initialDomaine)
	    {
	    TDomaineMath::computeDxDy(&currentDomaineMath,w,h);
	    }

	/**
	 * With domaineMath [x0,x1]x[y0,y1] = [0,w]x[0,h]
	 * Usefull for bitmap image
	 */
	Image_A(int w, int h) :
		//double x0, double y0, double x1, double y1, int w = 2, int h = 2
		Image_I(w, h, ColorModel, PixelFormat, DomaineMath(0, 0, w, h, w, h)),currentDomaineMath(DomaineMath(0, w, 0, h, w, h))
	    {
	    TDomaineMath::computeDxDy(&currentDomaineMath,w,h);
	    }

	virtual ~Image_A()
	    {
	    // Rien
	    }

	/*--------------------------------------*\
	 |*		Methodes		*|
	 \*-------------------------------------*/

    public:

	/**
	 * A redefinir obligatoirement par l'utilisateur
	 */
	virtual void fillImage(T* ptrPixel, int w, int h, const DomaineMath& domaineMath) = 0;

	/**
	 * Override
	 * A redefinir par l'utilisateur
	 */
	void animationStep(bool& isNeedUpdateView)
	    {
	    //rien
	    }

	/**
	 * Override
	 * A redefinir par l'utilisateur
	 */
	void paintPrimitives(Graphic2D& ptrGraphic2D)
	    {
	    //rien
	    }

	/*
	 * redefinir par l'utilisateur
	 */
	void onDomaineChanged(const DomaineMath& domaineMath)
	    {
	    // Rien
	    }

	// Override
	virtual inline size_t sizeOctet() const
	    {
	    return size() * sizeof(T);
	    }

	/*--------------------------------------*\
 |*		Get			*|
	 \*-------------------------------------*/

    public:

	inline const DomaineMath getCurrentDomaine() const
	    {
	    //TDomaineMath domaine = getDomaineHistory()->getCurrentDomaine();
	    return currentDomaineMath;
	    }

	inline const DomaineMath getInitialDomaine() const
	    {
	    DomaineMath initDomaine=DomaineMath(initialDomaine.x0,initialDomaine.y0,initialDomaine.x1,initialDomaine.y1);
	    TDomaineMath::computeDxDy(&initDomaine,w,h);
	    return initDomaine;
	    }

	/*--------------------------------------*\
	 |*		Surcharge		*|
	 \*-------------------------------------*/

    public:

	// Override
	void fillRawImage(void* ptrTabPixel)
	    {
	    fillImage((T*) ptrTabPixel, w, h, currentDomaineMath);
	    }

	void onDomaineChanged(const TDomaineMath& domaineMathData)
	    {
	    currentDomaineMath=DomaineMath(domaineMathData.x0,domaineMathData.y0,domaineMathData.x1,domaineMathData.y1,w,h);
	    //TDomaineMath::computeDxDy(&currentDomaineMath,w,h);
	    onDomaineChanged(currentDomaineMath);

	    Image_I::onDomaineChanged(domaineMathData);
	    }

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    private :
	// Tools
	DomaineMath currentDomaineMath;

    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
