#include <stdio.h>
#include <stdlib.h> 

#include <DynamicLib.h>  // Required for dlopen and dlsym

#ifdef _WIN32
#define DYNAMIC_NAME_LIB "Module.dll"
#elif __APPLE__
#define DYNAMIC_NAME_LIB  "./Module.dylib"
#else
#define DYNAMIC_NAME_LIB "./libModule.so"
#endif

int main(int argc, char *argv[]) 
{
	void*  aContext = NULL;
	void*  aFunction = NULL;
	printf("Modularizing Application\n");
	
	printf("Dynamic Libraries Loading...");
	aContext = _LoadLibrary(DYNAMIC_NAME_LIB);
	printf("...Completed\n");
	
	/*
	printf("Getting function address...");
	aFunction = (ModuleFunction)_GetFunction(aContext, "Module_PublicFunction");
	
	if (!aFunction)
		{
			printf("Error: Failed to get function address\n");
			_Close(aContext);
			return EXIT_FAILURE;
		}
	printf("...Completed\n");
	*/
	
	printf("Dynamic Libraries Closing...");
	_Close(aContext);
	printf("...Completed\n");

	return EXIT_SUCCESS;
}