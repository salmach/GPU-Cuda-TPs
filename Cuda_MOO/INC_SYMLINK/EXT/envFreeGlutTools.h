/**
 * Bilat_FreeGlut_Tools
 *
 * version : 002
 *
 * Cédric Bilat		cedric.bilat@he-arc.ch
 * Stähli Joaquim	joaquim.stahli@he-arc.ch
 */

#ifndef ENV_FREEGLUT_TOOLS_H
#define ENV_FREEGLUT_TOOLS_H

#include "dllHelper.h"

#ifdef CBI_FREEGLUT_TOOLS_DLL // defined if API is compiled as a DLL
  #ifdef CBI_FREEGLUT_TOOLS_EXPORT // defined if we are building the API DLL (instead of using it)
    #define CBI_FREEGLUT_TOOLS HELPER_DLL_EXPORT
  #else
    #define CBI_FREEGLUT_TOOLS HELPER_DLL_IMPORT
  #endif
  #define CBI_FREEGLUT_TOOLS_LOCAL HELPER_DLL_LOCAL
#else // CBI_FREEGLUT_TOOLS_DLL is not defined: this means API is a static lib.
  #define CBI_FREEGLUT_TOOLS
  #define CBI_FREEGLUT_TOOLS_LOCAL
#endif


#endif
