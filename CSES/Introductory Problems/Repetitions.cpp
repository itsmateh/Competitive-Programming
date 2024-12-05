#include <iostream>
using namespace std;

int main(){
  string text; 
  cin>>text;

  int maximo = 0; 
  int respuesta = 1;
  char ej ='A';

  for(char letra : text){
    if(letra == ej){
      ++maximo;
      respuesta = max(maximo, respuesta);
    }
    else{
      ej = letra;
      maximo = 1;    
    }
  }

  cout<<respuesta;

}