#ifndef MOUSE_EVENT_H
#define MOUSE_EVENT_H

#include "InputEvent.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

enum MouseButtonType
    {
    MOUSE_LEFT_BUTTON,
    MOUSE_RIGHT_BUTTON,
    MOUSE_MIDDLE_BUTTON,
    MOUSE_UNKNOWN_BUTTON
    };

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_DISPLAYABLE MouseEvent: public InputEvent
    {
    public:
	MouseEvent(const Panel_A &ptrPanelSource);
	MouseEvent(const MouseEvent& source);
	virtual ~MouseEvent();

	/*--------------------------------------*\
	 |*		Get			*|
	 \*-------------------------------------*/

	int getX() const;
	int getY() const;
	MouseButtonType getButtonType() const;

	/*--------------------------------------*\
	 |*		Set			*|
	 \*-------------------------------------*/

	void setXY(int x, int y);
	void setMouseButtonType(MouseButtonType buttonType);

    private:
	int x;
	int y;
	MouseButtonType buttonType;
    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
