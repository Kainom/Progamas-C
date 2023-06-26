#include "biblios.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <locale.h>
#include <math.h>
#include <conio.h>



int main() {
int cont,escolha,teste;
do {
   
   	ABREARQUIV();

   do {
   	cont=hall();// Recebe a escolha do usuário //

   	 switch(cont){
   		case 1:  // Calculadora //
			   do {
				   system("cls");
   			 	   CALCULAINI();
				   cont=CONTINUAR();

			} while(cont==1);
		break;
		
		case 2: // Histórico //
			HISTORICOGERAL();
		    cont=2;
		break;
		
		case 3: // Saída //
		system("cls");
		system("pause");
		exit(0); // comando que sinaliza a saida pra o compilador //
		break;
		
   	   case 4: // Limpeza //
   	   	cont=ESCOLHA();
   	   	if(cont==7){
   	   	 teste=BUSCA();
		 cont=ARQUIVOLIMPO(teste);
		}	
   	   break;
   	   
   	  case 5:  // Especificações de uso //
   	  	COMOUSAR();
	}  
	
	
   } while(cont!=7);// Repete até o usuário decidir limpar o histórico //
   
   	LIMPAARQUIV();
    FECHAARQUIV();
    
  }while(cont==7); // Assegura que o programa não acabe até o usuário decidir sair  //
}
