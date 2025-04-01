
/**                                                          
 *   @file       Module.c                                                         
 * 
 *   @brief      Module Source File Brief Description                                                             
 */

/*== Includes ================================================================*/
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "DynamicLib.h"

#ifdef _WIN32
#include <windows.h>
#else
#include <dlfcn.h>   // For dlopen(), dlsym(), dlclose()
#endif

void* _LoadLibrary(const char* libName)
{
    void* handle = NULL;
    
#ifdef _WIN32
    handle = LoadLibrary(libName);
    if (handle == NULL)
    {
        printf("Failed to load library: Error Code %lu\n", GetLastError());
        exit(EXIT_FAILURE);
    }
#else
    handle = dlopen(libName, RTLD_LAZY);
    if (handle == NULL)
    {
        printf("Failed to load library: %s\n", dlerror());
        exit(EXIT_FAILURE);
    }
#endif
    
    return handle;
}

void* _GetFunction(void* handle, const char* aFunctionName)
{
    void* Function = NULL;
    
#ifdef _WIN32
    Function = (void*)GetProcAddress((HMODULE)handle, aFunctionName);
#else
    Function = dlsym(handle, aFunctionName);
#endif
    
    if (Function == NULL) 
        {
#ifdef _WIN32
            printf("Failed to get function address (Error Code: %lu)\n", GetLastError());
            FreeLibrary((HMODULE)handle);
#else
            printf("Failed to get function address: %s\n", dlerror());
            dlclose(handle);
#endif
            exit(EXIT_FAILURE);
        }
    
    return Function;
}

int _Close(void* handle)
{
    if (handle == NULL)
        {
            printf("Library handle is NULL, cannot close\n");
            return -1;  // Error: NULL handle
        }
    
#ifdef _WIN32
    if (!FreeLibrary((HMODULE)handle))
        {
            printf("Failed to free library (Error Code: %lu)\n", GetLastError());
            return -1;  // Error: FreeLibrary failed
        }
#else
    if (dlclose(handle) != 0)
        {
            printf("Failed to close library: %s\n", dlerror());
            return -1;  // Error: dlclose failed
        }
#endif
    
    return 0;  // Success
}