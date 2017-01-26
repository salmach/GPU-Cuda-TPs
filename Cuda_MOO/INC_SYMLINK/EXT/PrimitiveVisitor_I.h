#ifndef PRIMITIVE_VISITOR_H
#define PRIMITIVE_VISITOR_H

#include "envBilatDisplayable.h"
#include "TextRenderer_A.h"

class Graphic2D;
class Line2D;
class Rect2D;
class WiredRect2D;
class Text2D;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_DISPLAYABLE PrimitiveVisitor_I
    {
    public:

	/*--------------------------------------*\
	 |*		Destructor		*|
	 \*-------------------------------------*/


	virtual ~PrimitiveVisitor_I()
	    {
	    //Nothing
	    }

	/*--------------------------------------*\
	|*		Methodes		*|
	 \*-------------------------------------*/

	virtual void visite(Graphic2D* ptrGraphic2D)=0;

	virtual void visite(Line2D* ptrLine2D)=0;

	virtual void visite(Rect2D* ptrRect2D)=0;

	virtual void visite(WiredRect2D* ptrWiredRect2Ds)=0;

	virtual void visite(Text2D* ptrTexte2D)=0;

    };

#endif

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
