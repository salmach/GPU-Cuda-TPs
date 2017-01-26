#ifndef GRAPHIC2DS_H
#define GRAPHIC2DS_H

#include "envBilatDisplayable.h"

#include "Panel_A.h"
#include "Font_A.h"
#include "Color3f.h"
#include "Primitive_A.h"
#include "Line2D.h"
#include "Rect2D.h"
#include "Text2D.h"
#include "WiredRect2D.h"
#include "Graphic2dState.h"
#include <string>
#include <queue>

using std::queue;
using std::string;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_DISPLAYABLE Graphic2D
    {
    public:

	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

	Graphic2D(int width = 1, int height = 1);

	/*--------------------------------------*\
	 |*		Destructor		*|
	 \*-------------------------------------*/

	virtual ~Graphic2D();

	/*--------------------------------------*\
	 |*		Methodes		*|
	 \*-------------------------------------*/

	/*--------------*\
	 |*	User	*|
	 \*-------------*/

    public:

	void setFont(const Font_A* font);

	void setFont(const string &fontName);

	void setFont(FontType type = HELVETICA_12);

	void setColor(Colorf colorf);

	void setColorRGB(float r01, float g01, float b01, float a01 = 1.0f);

	void setColorHSB(float h01, float s01, float b01, float a01 = 1.0f);

	void drawLigne(int x1, int y1, int x2, int y2);

	void drawVerticalLigne(int x, int y, int height);

	void drawHorizontalLigne(int x, int y, int width);

	void drawWiredRect2D(int x, int y, int width, int height);

	void drawRect2D(int x, int y, int width, int height);

	void drawText(int x, int y, const string &texte);

	void drawTitleTop(const string &texte);

	void drawTitleMiddle(const string &texte);

	void drawTitleBottom(const string &texte);

	/*
	 * return currentFont
	 */
	const Font_A* getFont() const;

	const Font_A* createFont(string fontname);

	const Font_A* createFont(FontType type = HELVETICA_12);

	int texteWidth(const string &texte) const;

	int texteHeight(const string &texte) const;

	inline int getWidth() const
	    {
	    return width;
	    }

	inline int getHeight() const
	    {
	    return height;
	    }

	/*--------------*\
	|*  Developer	*|
	 \*--------------*/

	unsigned int getSize();

	bool isEmpty();

	void reshape(int width, int height);

	void startPainPrimitive(Panel_A &ptrPanel);

	void drawPrimitive(Primitive_A* primitive);

	Primitive_A* popPrimitive();

	Graphic2dState popState();

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/
    private:

	// Inputs
	int width;
	int height;
	Panel_A* ptrPanel;

	// Tools
	Graphic2dState currentState;
	queue<Graphic2dState> queueStates;
	queue<Primitive_A*> queuePrimitives;

//	int frameWidth;
//	int frameHeight;
    };

#endif

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

