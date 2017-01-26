#ifndef MOUSE_LISTENER_I_H
#define MOUSE_LISTENER_I_H

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

#include "MouseEvent.h"
#include "MouseWheelEvent.h"
/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_DISPLAYABLE MouseListener_I
    {
    public:
	virtual ~MouseListener_I()
	    {
	    //Nothing
	    }

	virtual void onMouseMoved(const MouseEvent& event)=0;
	virtual void onMousePressed(const MouseEvent& event)=0;
	virtual void onMouseReleased(const MouseEvent& event)=0;
	virtual void onMouseWheel(const MouseWheelEvent& event)=0;
    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
