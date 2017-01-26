#ifndef MOUSE_WHEEL_EVENT_H
#define MOUSE_WHEEL_EVENT_H

#include "MouseEvent.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

enum WheelDirection
    {
    WHEEL_POSITIVE,
    WHEEL_NEGATIVE
    };

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_DISPLAYABLE MouseWheelEvent: public MouseEvent
    {

    public:
	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

	MouseWheelEvent(const Panel_A &ptrPanelSource);

	MouseWheelEvent(const MouseWheelEvent& source);

	/*--------------------------------------*\
	 |*		Destructor		*|
	 \*-------------------------------------*/

	virtual ~MouseWheelEvent();

	/*--------------------------------------*\
	 |*		Get			*|
	 \*-------------------------------------*/

	WheelDirection getDirection() const;
	int getWheelNumber() const;

	/*--------------------------------------*\
	 |*		Set			*|
	 \*-------------------------------------*/

	void setDirection(WheelDirection direction);

	void setWheelNumber(int wheelNumber);

    private:
	int wheelNumber;
	WheelDirection direction;
    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
