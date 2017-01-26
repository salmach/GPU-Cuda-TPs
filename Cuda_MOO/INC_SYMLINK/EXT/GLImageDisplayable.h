#ifndef GLIMAGE_DISPLAYABLE_H_
#define GLIMAGE_DISPLAYABLE_H_

#include "DomaineHistory.h"
#include "Displayable_A.h"
#include "ImageObserver_I.h"
#include "GLImageFactory_I.h"
#include "GLImage_I.h"
#include "Image_I.h"
#include "Viewport.h"
#include "GLPrimitiveDrawers.h"
#include "DomaineOverlay.h"
#include "Graphic2D.h"
#include "DomaineEcran.h"
#include "DomaineOverlay.h"
#include <GL/glew.h>
#include "ImageOption.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_GLIMAGE GLImageDisplayable: public Displayable_A, public KeyListener_I, public MouseListener_I, public ImageObserver_I
    {
    public:

	GLImageDisplayable(GLImageFactory_I* ptrImageFactory, Image_I* ptrImage,ImageOption imageOption);

	virtual ~GLImageDisplayable();

	/*--------------------------------------*\
	 |*		Surcharge		*|
	 \*-------------------------------------*/

    public:

	virtual void init(Panel_A &panel);

	virtual void reshape(Panel_A &panel, int w, int h);

	virtual void display(Panel_A &panel);

	virtual void release(Panel_A &panel);

	virtual void onKeyPressed(const KeyEvent &event);

	virtual void onKeyReleased(const KeyEvent& event);

	virtual void onMouseMoved(const MouseEvent &event);

	virtual void onMousePressed(const MouseEvent &event);

	virtual void onMouseReleased(const MouseEvent &event);

	virtual void onMouseWheel(const MouseWheelEvent &event);

	virtual void onImageUpdate();

	void animationStep(bool& isNeedUpdateView);

    protected:

	virtual void drawPrimitives(Panel_A &panel);

    private:


	void drawKeyboardTooltip(Panel_A &panel);

	void drawCredit(Panel_A &panel);

	/*
	 * x in [0,frameWidth[
	 * y in [0, frameHeight[
	 * imageX [1,imageWidth]
	 * imageY [1,imageHeight]
	 */
	void toImageSpaceCoordinate(int x, int y, int &imageX, int &imageY);

	void drawSelection();

	void beginSelection(int x, int y);

	void dragSelection(int x, int y);

	void stopSelection(int x, int y);

	void selectionPerformed();

    public:

	/*--------------------------------------*\
	 |*		Get			*|
	 \*-------------------------------------*/

	inline Viewport getFrame() const
	    {
	    return frame;
	    }

	inline Image_I* getImage() const
	    {
	    return ptrImage;
	    }

	/*--------------------------------------*\
	 |*		Is			*|
	 \*-------------------------------------*/

    public:

	bool isAnimationEnable() const;

	bool isOverlayDomaineEnable() const;

	bool isSelectionEnable() const;

	/*--------------------------------------*\
	 |*		Set			*|
	 \*-------------------------------------*/

	void setImageOption(ImageOption imageOption);

	void setAnimationEnable(bool isEnable);

	void setOverlayDomaineEnable(bool isEnable);

	void setSelectionEnable(bool isEnable);

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    private:

	// Inputs
	Image_I* ptrImage;
	ImageOption imageOption;

	// Tools
	Viewport frame;
	Graphic2D graphique2D;
	DomaineEcran domaineSelection;
	DomaineOverlay domaineOverlay;
	bool isMouseLeftBtnPressed;
	bool isShowHelp;

	// OpenGL
	GLImage_I* ptrGLImageRenderer;
	GLPrimitiveDrawers glPrimitiveDrawer;

    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
