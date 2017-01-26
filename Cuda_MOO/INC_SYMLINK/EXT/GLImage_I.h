#ifndef GLIMAGE_I_H_
#define GLIMAGE_I_H_

#include "Image_I.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_GLIMAGE GLImage_I
    {
    public:

	virtual ~GLImage_I()
	    {
	    // Nothing
	    }

	virtual void init(Image_I* ptrImage)=0;

	virtual void update(Image_I* ptrImage)=0;

	virtual void draw(Image_I* ptrImage)=0;

	virtual void release()=0;

    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
