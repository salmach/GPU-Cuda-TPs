#include <iostream>
#include <limits.h>

using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

extern bool helloCudaRef(void);
extern bool isAddScalarGPU_Ok(void);

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

bool useReference(void);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/



/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/



bool useReference(void)
    {
    cout << endl << "[Hello Reference ]" << endl;

    bool isOk = true;

    isOk&= helloCudaRef();

    return true;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
