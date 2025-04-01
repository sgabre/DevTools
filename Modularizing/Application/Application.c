#include <stdio.h>
#include <stdlib.h> 

#include "Module.h"
#include "getopt.h"

static const char mTrackUsage[] =
"Module <function> \r\n"
"\r\n"
"Functions:\r\n"
"'--read'     \t-- read commandr\n"
"'--write'     \t-- write commandr\n"
"'--addr <value>'     \t-- Memory Address\r\n"
"'--data <value>'     \t-- Value\r\n"
"'--size <value>'     \t-- size to be read/write\r\n";

struct option TrackOption[] = {
	{"addr", required_argument, 0, 'a'},
	{"data", required_argument, 0, 'd'},
	{"size", required_argument, 0, 's'},
	{"write", no_argument, 0, 'o'},
	{"read", no_argument, 0, 'i'},
	{"version", no_argument, 0, 'v'},
	{"help", no_argument, 0, 'h'},
	{0, 0, 0, 0}
};

//Send Application Command over UART Write Memory
//Tx[0x41|0x80|0x08|0x00|0x00|0x00|0x01|0x23|0x45|0x67|0x89|0xAB|0xCD|0xEF]
int main(int argc, char *argv[]) 
{
	int opt = 0;
	ModuleContext_ts Context;
	int oAddress = 0;
	int oValue = 0;
	int oSize = 0;
	int aCommand = 0;
	
	printf("Modularizing Application\n");

	getopt_clear();
	
	while ((opt = getopt_long(argc, argv, "q:L:l:a:i:d:s:T:h", TrackOption, NULL)) != -1)
	{  
		switch(opt)  
		{  
			case 'o': 
				aCommand = 1;
				break;
			case 'i': 
				aCommand = 2;
				break;
			case 'a':
				printf("ADDR: %s\r\n",optarg);
				oAddress = 0;
				break;
			case 'd':
				printf("DATA: %s\r\n",optarg);
				break;
			case 's':
				printf("SIZE: %s\r\n",optarg);
				break;
			case 'v': 
				printf("Version: 0.0.0 - Revision: 0123456789ABCDEF - Build Date & Time: 27/07/1979 @ 10:30:45\r\n");
				break;
			case 'q': 
				printf("quit\r\n");
				break;
			case 'h': 
				printf("%s",mTrackUsage);
				break;
			case '?':  
				printf("unknown option: %c\n", optopt); 
				break;  
		}  
	}  
	
	// optind is for the extra arguments 
	// which are not parsed 
	for(; optind < argc; optind++)
	{      
		printf("extra arguments: %s\n", argv[optind]);  
	} 
	
	//Module_Init(&Context);
	if(aCommand == 1)
		printf("Write Memory(Addr: %d, Value: %d, Size:%d)\n",oAddress, oValue, oSize );
		//printf("Set Parameter(ID: %d, Value: %d)\n",oAddress, oValue );
		//printf("--Transaction--\n");
		//printf("Tx Data[%d]:[%d])\n",oSize, oValue );
		//printf("Rx Data[%d]:[%d])\n",oSize, oValue );
	
	if(aCommand == 2)
		printf("Read Memory(Addr: %d, Size:%d)\n",oAddress, oSize );
		//printf("%d := Get Parameter(ID: %d)\n",oValue, oAddress );
	
	
	return EXIT_SUCCESS;
}

    
	