#ifndef GL_PRIMITIVE_DRAWERS_H
#define GL_PRIMITIVE_DRAWERS_H

#include "envBilatGLDisplayable.h"
#include "Graphic2D.h"
#include "PrimitiveVisitor_I.h"
#include "Panel_A.h"
#include "TextRenderer_A.h"
#include "Line2D.h"
#include "Rect2D.h"
#include "Text2D.h"
#include "WiredRect2D.h"


/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_GL_DISPLAYABLE GLPrimitiveDrawers: public PrimitiveVisitor_I

    {
    public:

	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

	GLPrimitiveDrawers();

	/*--------------------------------------*\
	 |*		Destructor		*|
	 \*-------------------------------------*/

	virtual ~GLPrimitiveDrawers();

	/*--------------------------------------*\
	 |*		Methodes		*|
	 \*-------------------------------------*/

    public:

	/**
	 * Configure an orthogonal projection to render all privimitives store int Graphic2D.
	 * After display all primitive are deleted if needed!
	 */
	void display(Panel_A& panel,Graphic2D* graphic2D);

    private:

	/**
	 * Override
	 */
	virtual void visite(Graphic2D* graphic2D);

	/**
	 * Override
	 */
	virtual void visite(Line2D* ptrLine2D);

	/**
	 * Override
	 */
	virtual void visite(Rect2D* ptrRect2D);

	/**
	 * Override
	 */
	virtual void visite(Text2D* ptrTexte2D);

	/**
	 * Override
	 */
	virtual void visite(WiredRect2D* ptrWiredRect2D);

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    private:
	/**
	 * setBy display !
	 */
	TextRenderer_A* ptrTextRenderer;
	Graphic2dState state;
    };

#endif

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

