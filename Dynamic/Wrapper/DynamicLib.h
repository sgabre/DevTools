#ifndef _MODULE_H_
#define _MODULE_H_

#include <stdbool.h>
#include <stdint.h>

void* _LoadLibrary(const char* libName);
void* _GetFunction(void* handle, const char* aFunctionName);
int _Close(void* handle);



#endif /* _MODULE_H_ */
