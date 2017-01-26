#ifndef DISPLAYABLE_A_H
#define DISPLAYABLE_A_H

/**
 * version : 0.0.2
 * Date 02.06.2014
 *
 * v 0.0.2 : remove de la methode repaint
 */
#include "envBilatDisplayable.h"
#include "KeyListener_I.h"
#include "MouseListener_I.h"
#include "TextRenderer_A.h"
#include "FPSCounter.h"
#include "Panel_A.h"
#include "Graphic2D.h"
#include <algorithm>
#include "PrimitiveVisitor_I.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

typedef PrimitiveVisitor_I PrimitiveRenderer;

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_DISPLAYABLE Displayable_A
    {
    public:
	/*--------------------------------------*\
	 |*		Destructor		*|
	 \*-------------------------------------*/

	Displayable_A();
	virtual ~Displayable_A();

	/*--------------------------------------*\
	 |*		Methodes		*|
	 \*-------------------------------------*/

	void displayRoot(Panel_A &panel);
	virtual void init(Panel_A &panel)=0;
	virtual void reshape(Panel_A &panel, int w, int h)=0;
	virtual void display(Panel_A &panel)=0;
	virtual void release(Panel_A &panel)=0;

	/**
	 * Non!
	 * Car sinon il faut cr�er un Displayable par "Context" (par exemple un pour GLUT et un pour X11)
	 * 	S1 ) setTextRenderer(TextRenderer* ...)
	 * 	S2 ) display(TextRenderer* ...)
	 */
	//virtual TextRenderer_A* getTextRenderer() = 0;
	/*--------------------------------------*\
	 |*		Get			*|
	 \*-------------------------------------*/

	KeyListener_I* getKeyListener();
	MouseListener_I* getMouseListener();
	int getFPS() const;


	/*--------------------------------------*\
	 |*		Set			*|
	 \*-------------------------------------*/

	void setKeyListener(KeyListener_I* ptrKeyListener);

	void setMouseListener(MouseListener_I* ptrMouseListener);
    private:
	KeyListener_I* ptrKeyListener;
	MouseListener_I* ptrMouseListener;
	FPSCounter fpsCounter;


    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
