#ifndef DOMAINEOVERLAY_H_
#define DOMAINEOVERLAY_H_

#include "OnDomaineChangedListener_I.h"
#include "Graphic2D.h"
#include "Text2D.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class DomaineOverlay : public OnDomaineChangedListener_I
    {
    public:

	DomaineOverlay(const TDomaineMath& homeDomaine);

	virtual~ DomaineOverlay();

	void draw(Graphic2D& ptrGraphic2D);

	void update(const TDomaineMath& domaineMath);

	void onDomaineChanged(const TDomaineMath& domaineMath);

    private:
	const TDomaineMath homeDomaine;
	double homeDx;
	double homeDy;
	Text2D* ptrText2dDomaine;
	Text2D* ptrText2dDomaineZoom;

    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
