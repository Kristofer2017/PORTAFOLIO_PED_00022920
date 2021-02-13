#include <iostream>
#include <string>
using namespace std;

int convertirABinario(int);

int main(void){
   int numero;
   cout << endl << "CONVERTIR UN NUMERO DECIMAL A BINARIO USANDO RECURSIVIDAD" << endl << endl;

   cout << "Ingresa el numero a convertir: ";
   cin >> numero;

   cout << endl << "El numeor en binario es: " << convertirABinario(numero) << endl << endl;
   return 0;
}

int convertirABinario(int numero){
   if(numero >= 2){
      cout << numero % convertirABinario(numero / 2) * 2;
      return numero;
   }else{
      cout << numero;
      return numero;
   }
}