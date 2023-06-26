#include "biblios.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <locale.h>
#include <math.h>
#include <conio.h>


typedef struct {
   double armazena;	
	
} Calculator;

 Calculator historico;

		
FILE *fp;

int hall() {
	char b = 'd';
	int k = b;
	char teste1[]="Calculadora",teste2[]="Historico",teste3[]="Sair",teste4[]="Limpar Historico",teste5[]="Como Usar",teste6[17];
	int escolha;
	do {
	Sleep(100);	 
    system("cls");
	printf("\n\n\n\n\n\n\n");	
	printf("\t\t\t\t**    Calculadora      **\n");
	printf("\t\t\t\t**    Historico        ** \n");
	printf("\t\t\t\t**    Sair             **  \n");
	printf("\t\t\t\t**    Limpar Historico ** \n");
	printf("\t\t\t\t**    Como Usar        ** \n");
	printf("\n Escolha:");
	fflush(stdin);
	gets(teste6);
	 if(strcmp(teste6,teste1)==0){
	 	escolha=1;
	 }
	 else if(strcmp(teste6,teste2)==0){
	 	escolha=2;
	 }
	 else if(strcmp(teste6,teste3)==0){
	 	escolha=3;
	 }
	 else if(strcmp(teste6,teste4)==0){
	 	escolha=4;
	 }
	 else if(strcmp(teste6,teste5)==0){
	 	escolha=5;
	 }
	  else {
	  	escolha=6;
	  }

	} while(escolha==6);   // Repete enquanto a escolha estiver errada //
	
	 return escolha; // Retorna Qual Case foi escolhido //
	}


void PORTUGUES() {
	setlocale(LC_ALL,"Portuguese");
}

void ABREARQUIV() {
  fp=fopen("Calculo.dad","rb+");  
  
}
void SAVEARQUIV() {
  if(fp==NULL){
  	printf("!!! NÃO FOI POSSÍVEL ABRIR O ARQUIVO !!!");
  }
 fseek(fp,0,SEEK_END);
 fwrite(&historico,sizeof(Calculator),1,fp);  
}

void FECHAARQUIV(){
	fclose(fp);
}

void LIMPAARQUIV(){ 
 fp=fopen("Calculo.dad","w");  
}

int ARQUIVOLIMPO(int teste){
	system("cls");
	if(teste==0){
	printf("\n\n\n\n\n\n\n");	
	printf("\t\t\t\t** Historico Vazio **");
	Sleep(2000);
    return 1;
	}
   else{
   	 APAGANDO();
   	
   	return 7;
   }
}

int ESCOLHA(){
	system("cls");
	PORTUGUES();
	int escolha3=0;
	char SIM[]="SIM",NAO[]="NAO",ESCO[4];
	do {
	system("cls");
	printf("\n\n\n\n\n\n\n");	
	printf("\t\t\t\t** DESEJA LIMPAR O HISTORICO ? **\n");
	printf("\t\t\t\t** SIM  **\n");
    printf("\t\t\t\t** NAO  **\n");
	printf("\nEscolha:");
	fflush(stdin);
	fgets(ESCO,4,stdin);
	
    if(strcmp(ESCO,SIM)==0) {
    	return 7;
	}
	else if(strcmp(ESCO,NAO)==0) {
		return 2;
	}
	else {
		escolha3=4;
	}
	
	} while(escolha3==4);
	
	return escolha3;
}

int BUSCA() {
	int i=0;
	fseek(fp,0,SEEK_SET);
	fread(&historico,sizeof(Calculator),1,fp);

	while(!feof(fp)){                       // lê todo o arquivo e me dá a ultima posiçao // ;
		i++; 
    	fread(&historico,sizeof(Calculator),1,fp);
   
	}
  

 return i;
 
}

void  HISTORICO() {
  PORTUGUES();
   int posicao=0,pos=0;
   pos=BUSCA();
   if(pos<3) {
   	 pos=3;
   }   
    fseek(fp,(pos-3)*sizeof(Calculator),SEEK_SET);
    fread(&historico,sizeof(Calculator),1,fp);
    printf("\n\n");
	printf("*** HISTORICO ***\n\n");	
    while(!feof(fp)){
    	
    posicao++;
   	printf("** %.3lf **  :%d°",historico.armazena,posicao);
   	printf("\n");
    fread(&historico,sizeof(Calculator),1,fp);
   	Sleep(500);

   }
   
  
}

void HISTORICOGERAL(){
    system("cls");
	PORTUGUES();
	int j=0,U=0;
	char click[2];
	U=BUSCA();
	fseek(fp,0,SEEK_SET);
	fread(&historico,sizeof(Calculator),1,fp);
	printf("\n\n\n\n\n\n\n");	
	printf("\t\t\t\t*** HISTORICO ***\n\n");
	if(U==0){
	    printf("\n\t\t\t\t***   VAZIO   ***\n\n");
	}
	else {
	printf("-----------------------------------------------------------------------------------------------------------------------\n");
	 while(!feof(fp)){
        j++;
   	    printf("\t\t\t\t***   %.3lf     \t\t\t\t\t\t\t %d°\n",historico.armazena,j);
   	    printf("-----------------------------------------------------------------------------------------------------------------------\n");
        fread(&historico,sizeof(Calculator),1,fp);
   	    Sleep(500);
			
	}
		
   }
printf("ENTER:");
getch();   
}
	
void APAGANDO(){
 int i;
 	printf("\n\n\n\n\n\n\n");	
	printf("\t\t\t\t** APAGANDO **\n");
	 for(i=1;i<=3;i++){
	  Sleep(500);
	  printf("\t\t\t\t**    %d     **\n   ",i);
	 }
	 Sleep(500);
	 system("cls");
	 printf("\n\n\n\n\n\n\n");	
	 printf("\t\t\t\t** HISTORICO APAGADO COM SUCESSO **\n");
	Sleep(3000);
}
	
	
int CONTINUAR() {
	system("cls");
	char SIM[]="SIM",NAO[]="NAO",ESCO[5];
	int escolha1;
	do {
	escolha1=0;
	system("cls");
	printf("\n\n\n\n\n\n\n");	
	printf("\t\t\t\t** Deseja Continuar  **\n");
	printf("\t\t\t\t** SIM  **\n");
    printf("\t\t\t\t** NAO  **\n");
	printf("\nEscolha:");
	fflush(stdin);
	gets(ESCO);
    if(strcmp(ESCO,SIM)==0) {
    	return 1;
	}
	else if(strcmp(ESCO,NAO)==0) {
		return 2;
	}
	else {
		escolha1=4;
	}
	} while(escolha1==4);
}

void COMOUSAR(){
	PORTUGUES();
	char T[1];
	system("cls");
	printf("\n\n\n\n\n\n\n");
	printf("\t\t\t\t*** OPERADORES ***\n\n");
	printf("--------------------------------------------------------------------------------\n");
	printf("\t\t\t\t   ADIÇÃO        ( + ) \n\n");
	printf("--------------------------------------------------------------------------------\n");
	Sleep(500);
	printf("\t\t\t\t   SUBTRAÇÃO     ( - ) \n\n");
	printf("--------------------------------------------------------------------------------\n");
	Sleep(500);
	printf("\t\t\t\t   MULTIPLICAÇÃO ( * ) \n\n");
	printf("--------------------------------------------------------------------------------\n");
	Sleep(500);
	printf("\t\t\t\t   DIVISÃO       ( / ) \n\n");
	printf("--------------------------------------------------------------------------------\n");
	Sleep(500);
	printf("\t\t\t\t   RADICIAÇÃO   ( // ) \n\n");
	printf("--------------------------------------------------------------------------------\n");
	Sleep(500);
	printf("\t\t\t\t   POTÊNCIA     ( ^ )  \n\n");
	printf("--------------------------------------------------------------------------------\n");
	Sleep(500);
	printf("\t\t\t\t   PORCENTAGEM  ( %% ) \n\n");
	printf("--------------------------------------------------------------------------------\n");
	printf("\t\t\ ESCOLHA N=1(CONTINUA APARTIR DO ANTERIOR)\n\n");
	printf("--------------------------------------------------------------------------------\n");
   	printf("\t\t\ ESCOLHA N DIFERENTE DE 1 (NOVO CÁLCULO)\n\n");
	printf("--------------------------------------------------------------------------------\n");
    printf("ENTER:");
getch();

}

void  REPETIDO() {
	system("cls");
	printf("\n\n\n\n\n\n\n");	
	printf("\t\t\t\t1°Número:%.3lf\n",historico.armazena);
}

int  CALCULAINI() {
double X,Y;
int escolha3,R=0,I=0;

char Opera[5],Opera1[]="*",Opera2[]="+",Opera3[]="/",Opera4[]="^", Opera5[]="%",Opera6[]="//",Opera7[]="-";

PORTUGUES();

do {
  if(R!=1){
  	system("cls");
	printf("\n\n\n\n\n\n\n");		
	printf("\t\t\t\t1°Número: ");
	fflush(stdin);
	scanf("%lf",&X);	
  }
  else {
  	REPETIDO();
  	
  }
	printf("\t\t\t\tOperação: ");
	fflush(stdin);
	scanf("%s",&Opera);
		if(strcmp(Opera,Opera6)!=0) {
  			printf("\t\t\t\t2°Número: ");
  			fflush(stdin);
  			scanf("%lf",&Y);
		}
		  	
		
		escolha3=0;
		 system("cls");
		if(strcmp(Opera,Opera1)==0){
			multiplicacao(X,Y,R);
	
		}
		else if(strcmp(Opera,Opera2)==0){
   			adicao(X,Y,R);

		}
		else if(strcmp(Opera,Opera3)==0){
  			 divisao(X,Y,R);
 		} 
 		else if(strcmp(Opera,Opera4)==0){
 			pontecia(X,Y,R);
 		}
 		else if(strcmp(Opera,Opera5)==0){
    		porcentagem(X,Y,R);
 	
 		}
 		else if(strcmp(Opera,Opera6)==0){
 	 		raiz(X,R);
 		}
 		else if (strcmp(Opera,Opera7)==0){
 			subtrai(X,Y,R);
 		}
  		else {
  			escolha3=8;
  		}
  		
        if(escolha3!=8){
          printf("\n\nN:");
          fflush(stdin);
          scanf("%d",&R);
          I++;
		}
		
  		if(escolha3==8){
  			system("cls");
  		}
  		else if(R==1 && I>=1){
  			 escolha3=8;
		  }
  		
  		else {
   			SAVEARQUIV();
   			HISTORICO(); 
   			printf("\n\nENTER:");
   			getch();	 
  		}
  
 } while(escolha3==8); // Repete enquanto houver erro //
  
   return 7;
 }



  double multiplicacao(double  X1, double Y1,int R1){
  if(R1!=1){
  		historico.armazena=X1*Y1;
	}
    else{
    	historico.armazena=historico.armazena*Y1;
	}
     printf("\n*** RESULTADO %.3lf ***\n\n",historico.armazena); 	
  }
  
  double  adicao( double  X2, double Y2,int R1) {
  	if(R1!=1){
  		historico.armazena=X2+Y2;
	}
    else{
    	historico.armazena=historico.armazena+Y2;
	}
  	
  	
     printf("\n*** RESULTADO %.3lf ***\n\n",historico.armazena); 	
	  			
}
  double divisao(double  X3, double Y3,int R1){
	if(R1!=1){
  		historico.armazena=X3/Y3;
	}
    else{
    	historico.armazena=historico.armazena/Y3;
	}

     printf("\n*** RESULTADO %.3lf ***\n\n",historico.armazena); 	
  }
  
  double pontecia(double X4,double Y4,int R1) {
	if(R1!=1){
  		historico.armazena=pow(X4,Y4);
	}
    else{
    	historico.armazena=pow(historico.armazena,Y4);
	}  	


     printf("\n*** RESULTADO %.3lf ***\n\n",historico.armazena); 	

  }
  
  double porcentagem(double X5,double Y5,int R1) {
  	if(R1!=1){
  		historico.armazena=(Y5*100)/X5;
	}
    else{
    	historico.armazena=(Y5*100)/historico.armazena;
	}

     printf("\n*** RESULTADO %.3lf ***\n\n",historico.armazena); 	
}
  
  
  double raiz(double X6,int R1) {
  	if(R1!=1){
  		printf("\n*** RESULTADO %.3lf ***\n\n",historico.armazena=sqrt(X6));
	}
	else{
	   printf("\n*** RESULTADO %.3lf ***\n\n",historico.armazena=sqrt(historico.armazena));

	}
 	
}
	
 double subtrai(double X7,double Y7,int R1){
 	if(R1!=1){
  		historico.armazena=X7-Y7;
	}
    else{
    	historico.armazena=historico.armazena-Y7;
	}
 	printf("\n*** RESULTADO %.3lf ***\n\n",historico.armazena);
 }


  
  

