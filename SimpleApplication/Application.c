#include <stdio.h>
#include <stdlib.h> 

#include "Module.h"

int main(int argc, char *argv[]) 
{
	ModuleContext_ts Context;
	printf("Simple Application\n");
	
	printf("Init...");
	Module_Init(&Context);
	printf("...Completed\n");
	
	int8_t a = 1,b = 3,c = 4;
	int8_t result = Module_PublicFunction(a, b, c);
	printf("Result %d = Function(a=%d, b=%d, c=%d)\n", result, a, b, c);

	return EXIT_SUCCESS;
}