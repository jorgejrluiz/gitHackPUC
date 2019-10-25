/**
Algoritmo e Estrutura de Dados II
PUC
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define bool      short
#define true      1
#define false     0
#define equals(a, b) (((strcmp(a, b) == 0) ? true : false))
#define NUMENTRADA 1000
#define TAMLINHA   1000

int contarLetrasMaiusculas(char* s);
int contarLetrasMaiusculasWithContador (char* s, int contador);

bool isMaiuscula (char carac){
   return (carac >= 'A' && carac <= 'Z');
}

bool isFim(char* s){
   return (strlen(s) >= 3 && s[0] == 'F' && s[1] == 'I' && s[2] == 'M');
}

int contarLetrasMaiusculas(char* s){
   return contarLetrasMaiusculasWithContador(s, 0);
}

int contarLetrasMaiusculasWithContador (char* s, int contador){
   int quantidadeMaiuscula = 0;

   if(contador < strlen(s)){
      if(isMaiuscula(s[contador]) == true){
         quantidadeMaiuscula ++; 
      }
      quantidadeMaiuscula += contarLetrasMaiusculasWithContador(s, contador++);
   }

   return quantidadeMaiuscula;
}

int main(int argc, char** argv){
   char entrada[NUMENTRADA][TAMLINHA];
   int numEntrada = 0;

   //Leitura da entrada padrao
   do {
      fgets(entrada[numEntrada], TAMLINHA, stdin);
   } while (isFim(entrada[numEntrada++]) == false);
   numEntrada--;   //Desconsiderar ultima linha contendo a palavra FIM

   //Para cada linha de entrada, gerando uma de saida contendo o numero de letras maiusculas da entrada
   for(int i = 0; i < numEntrada; i++){
      printf("%i\n",contarLetrasMaiusculas(entrada[i]));
   }
}
