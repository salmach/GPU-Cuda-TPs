#include <limits.h>

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

extern bool isPiMontecarloSequentiel_OK(int n);
extern bool isPiMonteCarloOMPEntrelacerPromotionTab_Ok(int n);
extern bool isPiMonteCarloOMPEntrelacerAtomic_Ok(int n);
extern bool isPiMonteCarloOMPforAtomic_Ok(int n);

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

bool usePIMonteCarlo(void);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

bool usePIMonteCarlo(void)
    {
    int n = INT_MAX / 10;
    // int n = 1000000000;
    bool isOk = true;
    isOk &= isPiMontecarloSequentiel_OK(n);
    //isOk &= isPiMonteCarloOMPEntrelacerPromotionTab_Ok(n);
    //isOk &= isPiMonteCarloOMPEntrelacerAtomic_Ok(n);
    //isOk &= isPiMonteCarloOMPforAtomic_Ok(n);

    return isOk;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
