#ifndef INPUT_EVENT_H
#define INPUT_EVENT_H

#include "envBilatDisplayable.h"
#include "Panel_A.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

enum ModifierType
    {
    MODIFIER_SHIFT,
    MODIFIER_CTRL,
    MODIFIER_ALT,
    MODIFIER_NONE
    };

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_DISPLAYABLE InputEvent
    {
    public:
	InputEvent(const Panel_A &ptrPanelSource);

	InputEvent(const InputEvent& source);

	virtual ~InputEvent();

	/*--------------------------------------*\
	 |*		Get			*|
	 \*-------------------------------------*/

	ModifierType getModifier() const;
	const Panel_A* getSource() const;

	/*--------------------------------------*\
	 |*		Set			*|
	 \*-------------------------------------*/

	void setModifier(ModifierType modifierType);

    private:
	ModifierType modifierType;
	const Panel_A* ptrPanelSource;
    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
