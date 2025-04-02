#include <stdio.h>
#include "Wrapper.h"

void Function() 
{
    printf("Hello from MyLibrary!\n");
}

// DllMain : appelé automatiquement par Windows lors du chargement/déchargement
BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) 
{
    switch (fdwReason) 
    {
        case DLL_PROCESS_ATTACH:
            printf("MyLibrary.dll chargée !\n");
            break;
        
        case DLL_PROCESS_DETACH:
            printf("MyLibrary.dll déchargée !\n");
            break;
        
        case DLL_THREAD_ATTACH:
            break;
        
        case DLL_THREAD_DETACH:
            // Ignorer ces événements pour la plupart des cas
            break;
    }
    
    return TRUE;  // OK
}