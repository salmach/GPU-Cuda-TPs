#pragma once

#include "Shape.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class Line: public Shape
    {

	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	Line(AppearanceShape* ptrAppearance, cv::Point p1, cv::Point p2);

	virtual ~Line();

	/*--------------------------------------*\
	|*		Methodes		*|
	 \*-------------------------------------*/

	void draw(cv::Mat* ptrImage);

	/*--------------------------------------*\
	 |*		Get			*|
	 \*-------------------------------------*/

	inline cv::Point getP1() const
	    {
	    return p1;
	    }

	inline cv::Point getP2() const
	    {
	    return p2;
	    }

	/*--------------------------------------*\
	|*		Set			*|
	 \*-------------------------------------*/

	void setP1(cv::Point p1);

	void setP2(cv::Point p2);

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    private:

	// Inputs
	cv::Point p1;
	cv::Point p2;
    };



/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
