#ifndef ONDOMAINECHANGEDLISTENER_I_H_
#define ONDOMAINECHANGEDLISTENER_I_H_

#include "TDomaineMath.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class OnDomaineChangedListener_I
    {
    public:
	virtual ~OnDomaineChangedListener_I()
	    {

	    }

	virtual void onDomaineChanged(const TDomaineMath& domaineMath)=0;
    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
