#ifndef ENV_CBI_GL_DISPLAYABLE_H
#define ENV_CBI_GL_DISPLAYABLE_H
#include "dllHelper.h"

#ifdef CBI_GL_DISPLAYABLE_DLL // defined if API is compiled as a DLL
  #ifdef CBI_GL_DISPLAYABLE_DLL_EXPORT // defined if we are building the API DLL (instead of using it)
    #define CBI_GL_DISPLAYABLE HELPER_DLL_EXPORT
  #else
    #define CBI_GL_DISPLAYABLE HELPER_DLL_IMPORT
  #endif
  #define CBI_GL_DISPLAYABLE_LOCAL HELPER_DLL_LOCAL
#else // GL_TOOLS_USE_DLL is not defined: this means API is a static lib.
  #define CBI_GL_DISPLAYABLE
  #define CBI_GL_DISPLAYABLE_LOCAL
#endif


#endif
