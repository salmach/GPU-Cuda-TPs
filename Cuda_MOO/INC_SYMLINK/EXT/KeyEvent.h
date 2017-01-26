#ifndef KEY_EVENT_H
#define KEY_EVENT_H

#include "envBilatDisplayable.h"
#include "InputEvent.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

enum SpecialKeyType
    {
    KEY_UNKNOWN,
    KEY_F1,
    KEY_F2,
    KEY_F3,
    KEY_F4,
    KEY_F5,
    KEY_F6,
    KEY_F7,
    KEY_F8,
    KEY_F9,
    KEY_F10,
    KEY_F11,
    KEY_F12,
    KEY_LEFT,
    KEY_UP,
    KEY_RIGHT,
    KEY_DOWN,
    KEY_PAGE_UP,
    KEY_PAGE_DOWN,
    KEY_HOME,
    KEY_END,
    KEY_INSERT,
    };

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_DISPLAYABLE KeyEvent: public InputEvent
    {
    public:
	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

	KeyEvent(const Panel_A &ptrPanelSource);

	KeyEvent(const KeyEvent& source);

	/*--------------------------------------*\
	 |*		Destructor		*|
	 \*-------------------------------------*/

	virtual ~KeyEvent();

	/*--------------------------------------*\
	 |*		Get			*|
	 \*-------------------------------------*/

	unsigned char getKey() const;

	SpecialKeyType getSpecialKey() const;

	/*--------------------------------------*\
	 |*		Set			*|
	 \*-------------------------------------*/

	void setKey(unsigned char key);

	void setSpecialKey(SpecialKeyType specialKey);

	/*--------------------------------------*\
	 |*		Is			*|
	 \*-------------------------------------*/

	bool isNumeric() const;

	bool isChar() const;

	bool isSpecial() const;

    private:
	SpecialKeyType specialKey;
	unsigned char key;
    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
