#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include <string.h>
#include <conio.h>
#include "vendasbiblio.h"

typedef struct {
	float vendas;
	int filial;
	char nome[100];
		
} LOJAS;

LOJAS Rede;

FILE *fp;

void PORTUGUES(){
	
	setlocale(LC_ALL,"Portuguese");
}
int HALL(){
system("cls");
PORTUGUES();	
int escolha=0;
	do {
		system("cls");
		printf("\n\n\n\n\n\n\n");
		printf("\t\t\t\t 1-ADIÇÃO DE VENDAS\n");
		printf("\t\t\t\t 2-RELAÇÃO DE VENDAS\n");
		printf("\t\t\t\t 3-HISTÓRICO DE VENDAS\n");
		printf("\t\t\t\t 4-SAÍDA\n");
		printf("\t\t\t\t 5-LIMPAR HISTÓRICO\n");
		printf("\t\t\t\t 6-ESPECIFICAÇÕES\n");
		printf("ESCOLHA:");
		fflush(stdin);
		scanf("%d",&escolha);
		
	} while(escolha<1 && escolha>5);
return escolha;
}

int CONTINUA() { // RECORRENTE PARA DAR CONTINUIDADE OU NÃOO //
	int escolha2=0;
	do {
		system("cls");
		printf("\n\n\n\n\n\n\n");
		printf("\t\t\t DESEJA CONTINUAR?\n");
		printf("\t\t\t 1-SIM\n");
		printf("\t\t\t 2-NAO\n");
		printf("\t\t\t ESCOLHA:");
		fflush(stdin);
		scanf("%d",&escolha2);
   } while(escolha2<1 || escolha2>2);
   
   if(escolha2==1){
   		return 1;
   }
   else {
   		return 2;
   }
   
}


void ABREARQUIV(){
	fp=fopen("FILIAL.dad","rb+");
	
}
void FECHAARQUIV(){
	fclose(fp);
}

void LIMPAARQUIV(){
	fp=fopen("FILIAL.dad","w");

}



// LISTA TODAS AS POSIÇÕES PREENCHIDAS //
int BUSCA(){ 
int i=0;
	fseek(fp,0,SEEK_SET);
	fread(&Rede,sizeof(LOJAS),1,fp);
		while(!feof(fp)){
			i++;
			fread(&Rede,sizeof(LOJAS),1,fp);
		}
	return i;	
}


int VAZIO(){
	system("cls");
	int i=0,j=0,l=0;
	i=BUSCA();
	j=CONTINUA();
	system("cls");
		if(j==1){
			if(i==0) {// CASO NAO HAJA NADA A SER APAGADO RETORNA 5 //
				printf("\n\n\n\n\n\n\n");
				printf("\t\t\t *** SEM VENDAS ***\n\n");
				Sleep(2000);
				return 5;
			}
			else { // APAGA TODO O HISTÓRICO //
				printf("\n\n\n\n\n\n\n");
				printf("\t\t\t *** APAGANDO ***\n");
					for(l=1;l<=3;l++){
					 printf("\t\t\t ***    %d    *** \n",l);
                     Sleep(500);
					}
            	system("cls");
            	printf("\n\n\n\n\n\n\n");
				printf("\t\t\t *** APAGADO COM SUCESSO ***\n");
				Sleep(2000);
				return 6;
		
			}
		
		 	
		}
	   else{
	   	 return 5;
	   }
		
}


void SALVA() {
	if(fp==NULL){
		printf("ARQUIVO COM PROBLEMAS");
	}
	fseek(fp,0,SEEK_END);
	fwrite(&Rede,sizeof(LOJAS),1,fp);
	
}

int testafilial(char F[1]){
int i=0,erro=0,J=0;	
	if(F[1]==' '){// NAO PERMITE ESPAÇO //
		erro++;
	}
	if(atoi(F)==0){// NAO PERMITE CARACTER ESPECIAL OU LETRA //
	    erro++;
		}
		
	J=atoi(F);
	if(erro>0 || J>4 || J<0){
		printf("\n\n\n\n\n\n\n");
		printf("\t\t\t*** FILIAL INCORRETA ***");
		Sleep(2000);
		return 1;
	}
	else{
		return erro;
	}	
}
// VALIDADE DA VENDA //
int testavendas(char teste[50]){
int teste1=0,i=0,j=0,zero=0;
char testandovendas[3];
	j=strlen(teste);
		for(i=0;i<j;i++) {
	  		testandovendas[0]=teste[i];
	    	if(testandovendas[0]=='0'){
			}
	  		else if(testandovendas[0]==' '){
	  	 		teste1++;
	  		}
	  		else if(testandovendas[0]==','){
	  		
			}
			else if(atoi(testandovendas)==0){
				teste1++;
			}
	}
  zero=atoi(teste);// NAO PERMITE O NUMERO ZERO //
  if(teste1>0 || zero==0){
  	printf("\n\n\n\n\n\n\n");
	printf("\t\t\t*** VALOR INCORRETO***");
	Sleep(2000);
	return teste1+1;
  }
  
  return teste1;
  
}
// VALIDADE DO NOME //
int teste_nome(char nombre1[100]){
	int i=0,erro1=0,j;
		for(i=0;i<1;i++){
		  if(nombre1[i]==' '){// NÃO PERMITE O ESPAÇO NA PRIMEIRA TECLAGEM//
		  	 erro1++;
		  	 printf("\n\n\n\n\n\n\n");
			 printf("\t\t\t*** NOME DO PRODUTO  INCORRETO ***");
			 Sleep(2000);
		  	 return 1;
			}
		}
	return erro1;
}

// INCLUÍ A VENDA //
void vendas() {
PORTUGUES();
system("cls");
int escolha1=0,escolha2=0;
char vendas[50],FILI[1],nombre[100];
	do {
		system("cls");
		printf("\n\n\n\n\n\n\n");
		printf("\t\t\tCOLOQUE O VALOR DA VENDA:");
			fflush(stdin);
			gets(vendas);
			system("cls");
		printf("\n\n\n\n\n\n\n");
		printf("\t\t\tCOLOQUE O COD DA FILIAL:");
			fflush(stdin);
			gets(FILI);
			system("cls");
		printf("\n\n\n\n\n\n\n");
		printf("\t\t\tCOLOQUE O NOME DO PRODUTO:");
			fflush(stdin);
			gets(nombre);
			system("cls");
			escolha1=testavendas(vendas);
	        	if(escolha1!=0){
	           		escolha1=1;
				}
				else {
					Rede.vendas=atof(vendas);
					escolha1=testafilial(FILI);
					escolha2=teste_nome(nombre);
						if(escolha1!=1 && escolha2!=1){
							strcpy(Rede.nome,nombre);
							Rede.filial=atoi(FILI);
							SALVA();
							escolha1=CONTINUA();
						}
							
					}
	} while(escolha1==1 || escolha2==1);
	
	
	
}
// NOME DE CADA FILIAL PARA SER MANIPULADO //
void FILIAL_NOME(char fili[20],int cod){
	char fili1[]="SUPRA CEL",fili2[]="LX MIL",fili3[]="VICTORIS RED",fili4[]="ESPERANZA";
	if(cod==1){
		strcpy(fili,fili1);
		
	}
	else if(cod==2){
		strcpy(fili,fili2);		
	}

	else if(cod==3){
		strcpy(fili,fili3);
	}

	else{
		strcpy(fili,fili4);
	}			
}

// MAIOR VENDA DENTRE AS FILIAIS //
float  maioridade(){
  float maior2=0,menor2=0;
  	fseek(fp,0,SEEK_SET);
  		while(fread(&Rede,sizeof(LOJAS),1,fp)){
  			if(maior2<Rede.vendas){
  				maior2=Rede.vendas;
			  }	
		 }	
  return maior2;		 	
}


// MENOR VENDA DESTRE A FILIAIS //
float minoridade(){
	float menor2=0;
	menor2=maioridade();
	fseek(fp,0,SEEK_SET);
  		while(fread(&Rede,sizeof(LOJAS),1,fp)){
  			if(menor2>Rede.vendas){
  				menor2=Rede.vendas;
			  }	
		 }
  return menor2;
}






float MAIS_LUCRO(int *K,float *Menorlucro,int *filimenor){
 float s1=0,s2=0,s3=0,s4=0,Lucro=0;
             // FSEEK DE CADA FILIAL //
  		fseek(fp,0,SEEK_SET);
  		while(fread(&Rede,sizeof(LOJAS),1,fp)){
  				if(1==Rede.filial){
  					s1=s1+Rede.vendas;
			  	}	
		 	}
		 fseek(fp,0,SEEK_SET);
  			while(fread(&Rede,sizeof(LOJAS),1,fp)){
  				if(2==Rede.filial){
  					s2=s2+Rede.vendas;

			  	}		
		 	}
		 fseek(fp,0,SEEK_SET);
  			while(fread(&Rede,sizeof(LOJAS),1,fp)){
  				if(3==Rede.filial){
    				s3=s3+Rede.vendas;
					
			  	}	
		 	}
		 fseek(fp,0,SEEK_SET);
  			while(fread(&Rede,sizeof(LOJAS),1,fp)){
  				if(4==Rede.filial){
  					s4=s4+Rede.vendas;
			  	}	
		 	}
		// MAIOR LUCRO //
		 if(s1>s2 && s1>s3 && s1>s4){
			Lucro=s1;
			*K=1;
		}
   		else if(s2>s3 && s2>s4){
			Lucro=s2;
			*K=2;
		}
		else if(s3>s4){
			Lucro=s3;
			*K=3;
		}
		else {
			Lucro=s4;
			*K=4;
			
		}
		 // MENOR LUCRO //
		if(s1<s2 && s1<s3 && s1<s4){
            *Menorlucro=s1;
             *filimenor=1;
 		}
   		else if(s2<s3 && s2<s4){
			*Menorlucro=s2;
			 *filimenor=2;
		}
		else if(s3<s4){
			*Menorlucro=s3;
			 *filimenor=3;
		}
		else {
			*Menorlucro=s4;
			 *filimenor=4;
		}
		
    return Lucro;
}



void MEDIA_TOTAL() {
PORTUGUES();
int cod=0,cod1=0,i,t=0,VAZIO1=0,relaciona=0;
float media,soma,maior,menor,maioridade1,minoridade1,Lucro1,Lucromenos;
char fili_nome[20],fili_lucra[20],fili_menos[20];
	do {
		media=0,soma=0,i=0,maior=0;
		do {
			system("cls");
			printf("\n\n\n\n\n\n\n");
			printf("\t\t\t0-Relação Geral\n");
			printf("\t\t\t1-Relação específica\n");
			printf("ESCOLHA:");
			fflush(stdin);
			scanf("%d",&relaciona);
		}while(relaciona!=1 && relaciona!= 0);
		if(relaciona==1){
		do {
			system("cls");
			printf("\n\n\n\n\n\n\n");
			printf("\t\t\tCOLOQUE O CÓDIGO DA FILIAL:");
			scanf("%d",&cod);
		} while(cod<1 || cod >4);
		FILIAL_NOME(fili_nome,cod);
		VAZIO1=BUSCA();
		system("cls");
		     // HISTORICO VAZIO //
			if(VAZIO1==0){
				printf("\n\n\n\n\n\n\n");
		    	printf("\t\t\t*** SEM VENDAS ***\n\n");
				printf("ENTER:");
				getch();
				t=2;
			}
			else {
			    // MAIOR VENDA E SOMA DE TODAS AS VENDAS DA FILIAL ESPECIFICA //
				fseek(fp,0,SEEK_SET);
				while(fread(&Rede,sizeof(LOJAS),1,fp)){
					if(cod==Rede.filial){
						soma=soma+Rede.vendas;
						i++;
					     if(maior<Rede.vendas){
					     	maior=Rede.vendas;
						}
					}
			 	}
			 	media=soma/i;
			 	menor=maior;
			 	
			 	// MENOR VENDA //
			 	fseek(fp,0,SEEK_SET);
					while(fread(&Rede,sizeof(LOJAS),1,fp)){
						if(cod==Rede.filial){
							if(menor>Rede.vendas){
								menor=Rede.vendas;
							}	
						}
					}
					// SEM VENDAS //
					if(soma==0){
						printf("\n\n\n\n\n\n\n");
		    			printf("\t\t\t*** SEM VENDAS ***\n\n");
						printf("ENTER:");
						getch();
					}
				  // COM VENDAS //
				  else {
				  	
				  	   if(i==1){
				  	   	   media=0,menor=0,maior=0;
						 }
					   if(i>1 && maior==menor){
					   	  menor=0,maior=0;
					   }
		                //                             VENDAS ESPECÍFICAS                                        //                                 
					   printf("\n\n\n\n\n\n\n");
					   printf("\t\t\t\t*** VENDAS ***\n\n");
				       printf("-------------------------------------------------------------------------------\n");
					   printf("\t\t\tFILIAL: %s \n",fili_nome);
					   printf("-------------------------------------------------------------------------------\n");
   					   printf("\t\t\tTOTAL DE VENDAS DESTA FILIAL: $%.2f\n",soma);
   					   printf("-------------------------------------------------------------------------------\n");
   					   printf("\t\t\tMÉDIA DE VENDAS DESTA FILIAL: $%.2f\n",media);	
   					   printf("-------------------------------------------------------------------------------\n");
   					   printf("\t\t\tMAIOR VENDA DESTA FILIAL: $%.2f\n",maior);
    				   printf("-------------------------------------------------------------------------------\n");
					   printf("\t\t\tMENOR VENDA DESTA FILIAL: $%.2f\n",menor);
    				   printf("-------------------------------------------------------------------------------\n\n");
    				
   						printf("ENTER:");
   						getch();
		 			}
		 		}			
		 	}
		    else{ 
		    	 cod=0;
		    	  system("cls");
				  maioridade1=maioridade();
			 	  minoridade1=minoridade();
				  Lucro1=MAIS_LUCRO(&cod,&Lucromenos,&cod1);
			 	  FILIAL_NOME(fili_lucra,cod);
			 	  FILIAL_NOME(fili_menos,cod1);
			 	  //                               VENDAS GERAIS                                   //
			 	   	printf("\n\n\n\n\n\n\n");
			 	  	printf("\t\t\t\t*** VENDAS ***\n\n");
					printf("-------------------------------------------------------------------------------\n");
		    		printf("\t\t\tMAIOR VENDA DENTRE TODAS AS FILIAIS: $%.2f\n",maioridade1);
    				printf("-------------------------------------------------------------------------------\n");
    				printf("\t\t\tMENOR VENDA DENTRE TODAS AS FILIAIS: $%.2f\n",minoridade1);
    				printf("-------------------------------------------------------------------------------\n");
    				printf("\t\t\tFILIAL MAIS LUCRATIVA: %s - $%.2f -\n",fili_lucra,Lucro1);
   					printf("-------------------------------------------------------------------------------\n");
   					printf("\t\t\tFILIAL MENOS LUCRATIVA: %s - $%.2f -\n",fili_menos,Lucromenos);
   					printf("-------------------------------------------------------------------------------\n\n");
					
					   printf("ENTER:");
   					getch();
			}	
				t=CONTINUA();	 
    
    } while(t==1);


}

// PERMITE O USUÁRIO ANALISAR TODO O HISTÓRICO OU APENAS A FILIAL DESEJADA //
int HISTORICO_ESCOLHA() {
 int O1=0;
   		do {
   			system("cls");
   			printf("\n\n\n\n\n\n\n");
			printf("\t\t\t***  Para histórico geral digite 0.     ***\n");
			printf("\t\t\t***  Para o específico digite a filial. *** \n");
			printf("ESCOLHA:");
			fflush(stdin);
			scanf("%d",&O1);
   		}while(O1<0 || O1>4);
return O1;

}

void HISTORICO(){
PORTUGUES();
 system("cls");
 int L,VAZIO=0,O=0,Continuar2=0;
 char filial_desejada[20];
	VAZIO=BUSCA();	
	if(VAZIO==0){
		printf("\n\n\n\n\n\n\n");
		printf("\t\t\t *** SEM VENDAS ***\n\n");
		Sleep(2000);
	}
	else{   
		do {
			L=0;
			O=HISTORICO_ESCOLHA();
			FILIAL_NOME(filial_desejada,O);
			system("cls");
	    	if(O==0){
	    		fseek(fp,0,SEEK_SET);
				fread(&Rede,sizeof(LOJAS),1,fp);
				printf("\n\n\n\n\n\n\n");
				printf("\t\t\t\t *** VENDAS ***\n\n");
				printf("-------------------------------------------------------------------------------\n");
					while(!feof(fp)){
						L++;
						Sleep(200);
		 				printf("%d°Produto: %s  Valor: $%.2f  Filial: %d\n",L,Rede.nome,Rede.vendas,Rede.filial);
		 				printf("-------------------------------------------------------------------------------\n");
						fread(&Rede,sizeof(LOJAS),1,fp);	
	    			}
				}	
			else {
				fseek(fp,0,SEEK_SET);
				printf("\n\n\n\n\n\n\n");
				printf("\t\t\t\t *** VENDAS ***\n\n");
				printf("-------------------------------------------------------------------------------\n");
				printf("\t\t\t\t FILIAL:%s\n",filial_desejada);
				printf("-------------------------------------------------------------------------------\n");
					while(fread(&Rede,sizeof(LOJAS),1,fp)){
						if(O==Rede.filial){
							L++;
				    		Sleep(200);
							printf("%d°Produto: %s  Valor: $%.2f  Filial: %d\n",L,Rede.nome,Rede.vendas,Rede.filial);
							printf("-------------------------------------------------------------------------------\n");
						}
					}
					
						
						  if(L==0) {
							printf("*** 0 VENDAS ***\n");

							printf("-------------------------------------------------------------------------------\n");
						}
				}	
	 	printf("ENTER:");
	 	getch();
	  	Continuar2=CONTINUA();    		
	 }while(Continuar2==1);		
	}
}


void especificando(){
    system("cls");
    int i=0;
    char filimostra[20];
	PORTUGUES();
	printf("\n\n\n\n\n\n\n");
    printf("\t\t\t  *** CÓDIGO DAS FILIAIS ***\n\n");
    printf("-------------------------------------------------------------------------------\n");
    	for(i=1;i<=4;i++){
    		Sleep(200);
    		FILIAL_NOME(filimostra,i);
            printf("\t\t\t\t   %s        \tCOD:%d  \n",filimostra,i);
            printf("-------------------------------------------------------------------------------\n");

		}
 printf("ENTER:");
 getch();
}









