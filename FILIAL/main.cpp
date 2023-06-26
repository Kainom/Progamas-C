#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include <string.h>
#include "biblio.h"
#include "vendasbiblio.h"
#include <conio.h>



int main(){
	int cont=0;
	do {
		ABREARQUIV();

			do {
	 	
	   			cont=HALL();
	   			switch(cont) {
	   				
					case 1:
					vendas();
					break;	
	   	
					case 2:
					MEDIA_TOTAL();
					break;
	   	
	   	
	   				case 3:
	   				HISTORICO();
	   				break;	
	   		
	   				case 4:
	   				system("cls");
	   				system("pause");
	   				FECHAARQUIV();
		        	exit(0);
	   				break;
	   				
	   				case 5:
	   					cont=VAZIO();
	   					
	   				break;
	   				
	   				case 6:
	   				   especificando();
	   			       cont=7;
	   			    break;
	   			}
	 	
		 } while(cont!=6);
		 
		LIMPAARQUIV();
	 	FECHAARQUIV();
	} while(cont==6);
	 
		
}
