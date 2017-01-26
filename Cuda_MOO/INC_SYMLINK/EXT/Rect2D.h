#ifndef RECT_2D_H
#define RECT_2D_H

#include "Primitive_A.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_DISPLAYABLE Rect2D: public Primitive_A
    {
    public:

	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

	/*
	 * (x,y) coin superieur gauche
	 */
	Rect2D(int x, int y, int width, int height);

	/*--------------------------------------*\
	 |*		Destructor		*|
	 \*-------------------------------------*/

	virtual ~Rect2D();

	/*--------------------------------------*\
	 |*		Methodes		*|
	 \*-------------------------------------*/

    public:

	/**
	 * Override
	 */
	virtual void accept(PrimitiveVisitor_I &visitor);

	/*--------------------------------------*\
	 |*		Get			*|
	 \*-------------------------------------*/

	inline int getX()
	    {
	    return x;
	    }

	inline int getY()
	    {
	    return y;
	    }

	inline int getWidth()
	    {
	    return width;
	    }

	inline int getHeight()
	    {
	    return height;
	    }

	/*--------------------------------------*\
	 |*		Set			*|
	 \*-------------------------------------*/

	void setXY(int x, int y);

	void setSize(int width, int height);

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    public:

	//Input
	int x;
	int y;
	int width;
	int height;
    };

#endif

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
