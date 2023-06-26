#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include <string.h>
#include <conio.h>
#include "biblio.h"

 

int main(){
//BEMVINDO();
int maiores[61],esco=0;
do {
  system("cls");
  esco=PEQUENOHALL();
  switch(esco){

  	
  	case 1:
  	ABREARQUIV();
	Leitura(maiores);
	printf("\n\nENTER:");
	getch();
	//FECHAARQUIV();
	break;
	
	case 2:
	ABREARQUIV();
    PREMIOS();
    esco=1;
	break;
	
	case 3:
	FECHAARQUIV();
	return 0;
	break;
	
	case 4:
	ABREARQUIV();
	VERIFICAR();
	esco=1;
	break;
}
	
FECHAARQUIV();
}while(esco==1);
 	
return 0;

}


