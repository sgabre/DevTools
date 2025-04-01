#ifndef _MODULE_H_
#define _MODULE_H_

#include <stdbool.h>
#include <stdint.h>

typedef struct ModuleContext_s  
{
    bool    IsInit; /**< Indicates if the module is initialized */
    uint8_t State;  /**< Current module state */
    uint8_t Event;  /**< Current module event */
}ModuleContext_ts;

int8_t Module_PublicFunction(int8_t a, int8_t b, int8_t c);

void Module_Init(void* aContext);



#endif /* _MODULE_H_ */
