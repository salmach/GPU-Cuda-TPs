/**
 * GLTools project
 * version : 0.0.2
 *
 * Cédric Bilat		cedric.bilat@he-arc.ch
 * Stähli Joaquim	joaquim.stahli@he-arc.ch
 */

//PRIVATE
#ifndef ENV_IMAGE_FREEGLUT_CUDA_H
#define ENV_IMAGE_FREEGLUT_CUDA_H

#include "dllHelper.h"

#ifdef CBI_IMAGE_FREE_GLUT_CUDA_DLL // defined if API is compiled as a DLL
    #ifdef CBI_IMAGE_FREE_GLUT_CUDA_EXPORT // defined if we are building the API DLL (instead of using it)
	#define CBI_IMAGE_FREE_GLUT_CUDA HELPER_DLL_EXPORT
    #else
	#define CBI_IMAGE_FREE_GLUT_CUDA HELPER_DLL_IMPORT
    #endif // GLIMAGE_DLL_EXPORT
    #define CBI_IMAGE_FREE_GLUT_CUDA_LOCAL HELPER_DLL_LOCAL
#else // GLIMAGE_USE_DLL is not defined: this means API is a static lib.
    #define CBI_IMAGE_FREE_GLUT_CUDA
    #define CBI_IMAGE_FREE_GLUT_CUDA_LOCAL
#endif

#endif  /* ENV_GLIMAGE_H */
