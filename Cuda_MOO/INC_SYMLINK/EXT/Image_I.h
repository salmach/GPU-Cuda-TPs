#ifndef IMAGE_I_H_
#define IMAGE_I_H_

#include "envGLImage.h"
#include "KeyListener_I.h"
#include "MouseListener_I.h"
#include "ImageObserver_I.h"
#include "Graphic2D.h"
#include "ImageOption.h"
#include "DomaineHistory.h"

#include "OnDomaineChangedListener_I.h"

#include <iostream>
#include <string>
#include <vector>

#include "TDomaineMath.h"
using std::vector;
using std::string;
using std::ostream;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

enum ColorModel
    {
    RGBA,
    RGB,
    HSB,
    HSBA,
    HUE,
    GRAY,
    BGR,
    BGRA
    };

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_GLIMAGE Image_I: public OnDomaineChangedListener_I
    {

	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	/**
	 * channelCount in 1,3 or 4
	 * pixelFormat : GL_FLOAT, GL_UNSIGNED_BYTE
	 */
	Image_I(int _w, int _h, ColorModel colorModel, int pixelFormat, TDomaineMath initialDomaine);

	/**
	 * With domaineMath [x0,x1]x[y0,y1] = [0,w]x[0,h]
	 */
	Image_I(int _w, int _h, ColorModel colorModel, int pixelFormat);

	virtual ~Image_I();

	/*--------------------------------------*\
	 |*		Abstrait		*|
	 \*-------------------------------------*/

    public:

	/**
	 * A redefinir par l'utilisateur
	 * Note same name with Image_A to avoid, the hidden methode warnings
	 */
	virtual void fillRawImage(void* ptrTabPixel)=0;

	/**
	 * A redefinir par l'utilisateur
	 */
	virtual size_t sizeOctet() const = 0;

	/**
	 * A redefinir par l'utilisateur
	 */
	virtual void animationStep(bool& isNeedUpdateView)=0;

	/**
	 * A redefinir par l'utilisateur
	 */
	virtual void paintPrimitives(Graphic2D& ptrGraphic2D)=0;

	/*--------------------------------------*\
	 |*		Surcharge		*|
	 \*-------------------------------------*/

	virtual void onDomaineChanged(const TDomaineMath& domaineMath);

	/*--------------------------------------*\
	 |*		Methodes		*|
	 \*-------------------------------------*/

    public:

	/**
	 * call by API
	 * call animationStep
	 */
	void animationStepAPI(bool& isNeedUpdateView);

	void print(ostream& stream) const;

	void registerImageObserver(ImageObserver_I &ptrObserver);

	void unregisterImageObserver(ImageObserver_I &ptrObserver);

	/*
	 * Notify all registred ImageObserver_I
	 * @see registerImageObserver
	 */
	void update() const;

	/**
	 * Last Domaine push in History
	 */
	void goToPreviousDomaine();

	/**
	 * First Domaine of History
	 */
	void goToDomaineInit();

	/*--------------------------------------*\
	|*		Set			*|
	 \*-------------------------------------*/

    public:

	/**
	 * push domain in history
	 */
	void setCurrentDomaine(TDomaineMath domaine);

	/**
	 * set new initialDomaine and set current
	 * ie domaine to set wenn call goToDomaineInit!
	 */
	void setInitialDomaine(TDomaineMath &domaine);

	void setKeyListener(KeyListener_I* ptrKeyListener);

	void setMouseListener(MouseListener_I* ptrMouseListener);

	/*--------------------------------------*\
	 |*		Get			*|
	 \*-------------------------------------*/

    public:

	DomaineHistory* getDomaineHistory() const;

//	const TDomaineMath* getCurrentDomaine() const;
//
//	inline const TDomaineMath* getInitialDomaine() const
//	    {
//	    return &initialDomaine;
//	    }

	inline int size() const
	    {
	    return w * h;
	    }

	inline bool hastAlphaChannel() const
	    {
	    return getChannelCount() > 4;
	    }

	inline KeyListener_I* getKeyListener() const
	    {
	    return ptrKeyListener;
	    }

	inline MouseListener_I* getMouseListener() const
	    {
	    return ptrMouseListener;
	    }

	/**
	 * The number of color componant
	 *
	 * 	Type	ChannelCount
	 *
	 * 	RGBA	4
	 * 	RGB	3
	 * 	Gray	1
	 *
	 * @return 1,3 or 4
	 */
	int getChannelCount() const;

	inline int getW() const
	    {
	    return w;
	    }

	inline int getH() const
	    {
	    return h;
	    }


	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    public:
	// Inputs, read-only!
	const int w;
	const int h;
	const ColorModel colorModel; //1,3 or 4
	const int pixelFormat;
	TDomaineMath initialDomaine; // not read only, computeDxDy!

    protected :

	// Tools
	KeyListener_I* ptrKeyListener;
	MouseListener_I* ptrMouseListener;
	vector<ImageObserver_I*> vectorObservable;
	DomaineHistory* domaineHistory;

    };

/*--------------------------------------*\
|*		Friend			*|
 \*-------------------------------------*/

/**
 * call image.print(stream)
 */
CBI_GLIMAGE ostream& operator<<(ostream& stream, const Image_I& image);

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
