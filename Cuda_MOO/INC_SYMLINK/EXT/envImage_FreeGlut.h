/**
 * Bilat_Image_FreeGlut
 * version : 001
 *
 * Cédric Bilat		cedric.bilat@he-arc.ch
 * Stähli Joaquim	joaquim.stahli@he-arc.ch
 */

//PRIVATE
#ifndef ENV_IMAGE_FREE_GLUT_H
#define ENV_IMAGE_FREE_GLUT_H

#include "dllHelper.h"



#ifdef CBI_IMAGE_FREE_GLUT_DLL // defined if API is compiled as a DLL

    #ifdef CBI_IMAGE_FREE_GLUT_EXPORT // defined if we are building the API DLL (instead of using it)
	#define CBI_IMAGE_FREE_GLUT HELPER_DLL_EXPORT
    #else
	#define CBI_IMAGE_FREE_GLUT HELPER_DLL_IMPORT
    #endif // CBI_IMAGE_FREE_GLUT_EXPORT
    #define CBI_IMAGE_FREE_GLUT_LOCAL HELPER_DLL_LOCAL
#else // CBI_IMAGE_FREE_GLUT_DLL is not defined: this means API is a static lib.
    #define CBI_IMAGE_FREE_GLUT
    #define CBI_IMAGE_FREE_GLUT_LOCAL
#endif

#endif
