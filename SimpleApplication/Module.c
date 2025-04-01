
/**                                                          
 *   @file       Module.c                                                         
 * 
 *   @brief      Module Source File Brief Description                                                             
 */

/*== Includes ================================================================*/
#include <ctype.h>

#include <string.h>

#include "Module.h"


static ModuleContext_ts* mModuleContext; /**< Module context instance */

int8_t Module_PublicFunction(int8_t a, int8_t b, int8_t c)
{
    return (int8_t)(((int16_t)a + (int16_t)b + (int16_t)c) / 3);
}

void Module_Init(void* aContext)
{
    // Ensure aContext is not NULL and then cast it to the correct type
    if (aContext != NULL) 
    {
        mModuleContext = (ModuleContext_ts*)aContext;
        
        // Check if the module has not been initialized, and if so, initialize it
        if (mModuleContext->IsInit != true) 
        {
            mModuleContext->IsInit = true;
        }
    }
}
