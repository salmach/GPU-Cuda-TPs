#include <iostream>
#include <stdlib.h>


using std::cout;
using std::endl;


//extern bool useHello(void);
//extern bool useAddVecteur(void);
extern bool useSlice(void);
extern bool testReductionTools(void);
extern bool useMontecarloMono(void);
extern bool useMontecarloMulti(void);
/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

int mainCore();

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/



/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

int mainCore()
    {
    bool isOk = true;
    //isOk &= useHello();
    //isOk &=useAddVecteur();
    //isOk &= useSlice();
    //isOk &=testReductionTools();
    //isOk &= useMontecarloMono();
    isOk &= useMontecarloMulti();


    cout << "\nisOK = " << isOk << endl;
    cout << "\nEnd : mainCore" << endl;

    return isOk ? EXIT_SUCCESS : EXIT_FAILURE;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/



/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

