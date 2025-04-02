#include <stdio.h>
#include <windows.h>

typedef void (*FunctionCallBack)();  // Définition du type de la fonction hello()

int main() {
    // Charger la DLL
    HINSTANCE hDll = LoadLibrary("Wrapper.dll");
    if (!hDll) {
        printf("Erreur: Impossible de charger la DLL !\n");
        return 1;
    }

    // Obtenir l'adresse de la fonction hello()
    FunctionCallBack Function = (FunctionCallBack) GetProcAddress(hDll, "hello");
    if (!Function) {
        printf("Erreur: Impossible de trouver la fonction hello() !\n");
        FreeLibrary(hDll);
        return 1;
    }

    // Appeler la fonction
    Function();

    // Libérer la DLL
    FreeLibrary(hDll);
    return 0;
}