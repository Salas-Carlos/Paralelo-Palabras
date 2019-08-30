#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fe("libro.txt");
   int cont=0;
   string palabras;
   while(!fe.eof()) {//Se crea el ciclo para encontrar las palabras
      fe>>palabras;
      cont=cont+1;//se aumenta +1 al contador por cada palabra encontrada
   }
   cout<<cont;//Imprimimos el total de palabras encontradas
   return 0;
}
