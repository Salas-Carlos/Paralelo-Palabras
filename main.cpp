#include <iostream>
#include <fstream>
#include <omp.h>
#include <vector>

using namespace std;

int main() {
  string libro;
  ifstream fe;
  fe.open("libro.txt");//Importamos el fichero
  int cont=0;
  int p=0;
  string cont1;
  vector<string> palabras;
  while(getline(fe,cont1)) {//se crea el ciclo para recorrer cada linea del fichero

    cont=cont+1;//cada linea se le agrega +1 al contador
    palabras.push_back(cont1);//iremos guardando las palabras
     }

 

  #pragma omp parallel reduction(+:p)//creamos el paralelo
  {
  int s;
  int T;
  bool x=true;
  T=int(cont/omp_get_num_threads());//calculamos el numero de filas para cada hilo
  s=T*(omp_get_thread_num()+1);
  if (omp_get_thread_num()==(omp_get_num_threads()-1)){//si no es equivalente, las filas que sobren se les asignaran al ultimo hilo
    s=cont;
    }
   for(int i=(T*omp_get_thread_num()); i<s;i++){
   x=true;
  for(int j=0; j<palabras[i].size();j++){
  if(palabras[i][j]==' '){//verifica si encuentra un espacio
  x=true;
}else
{
 if(x)
{
  p=p+1; //se van sumando +1 por cada palabra encontrada
  }
 x=false;
    }
}

}




}
  cout<<p<<endl;
  return 0;
}