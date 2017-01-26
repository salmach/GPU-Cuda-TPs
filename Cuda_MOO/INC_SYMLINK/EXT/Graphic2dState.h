#ifndef GRAPHIC2D_STATE_H_
#define GRAPHIC2D_STATE_H_

#include "envBilatDisplayable.h"
#include "Color3f.h"
#include "Font_A.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_DISPLAYABLE Graphic2dState
    {

	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	Graphic2dState(const Font_A* ptrFont=0, Colorf color=Colorf(1.0f,1.0f,1.0f));

	virtual ~Graphic2dState();

	/*--------------------------------------*\
	 |*		Set			*|
	 \*-------------------------------------*/
    public:
	void setColor(Colorf &color);

	void setFont(const Font_A* ptrFont);

	/*--------------------------------------*\
	 |*		Get			*|
	 \*-------------------------------------*/

    public:

	inline const Font_A* getFont() const
	    {
	    return ptrFont;
	    }

	inline Colorf getColor() const
	    {
	    return color;
	    }

	/*--------------------------------------*\
 |*		Attributs			*|
	 \*-------------------------------------*/

    private:
	const Font_A* ptrFont;
	Colorf color;

    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
