#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include <string.h>
#include <conio.h>
FILE *fp;
int i=0,c=0,posi=0,k=61,N=0,PK[220],contador=0,M=0,F=0,L=0,cont=0,kli=0,teste=0,maioral[61],final[61],T=-1,v=0,z=0,y=0,p=1;

void Zera(){
	i=0,c=0,posi=0,k=61,N=0,contador=0,M=0,F=0,L=0,cont=0,kli=0,teste=0,T=-1,v=0,z=0,y=0,p=1;
}
void ABREARQUIV(){
	fp=fopen("TELECIN.txt","r+");
	
}
void FECHAARQUIV(){
	fclose(fp);
}
void PORTUGUES(){
	setlocale(LC_ALL,"Portuguese");
}
void BEMVINDO(){
  while(p<=2){
  
   for(z=0;z<70;z++){
   		printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  BEM VINDO  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
    }
    Sleep(200);
    system("cls");
    Sleep(200);
	for(y=0;y<70;y++){
		printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^  TELE CENA ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
   
   
   }
   Sleep(200);
   system("cls");
   Sleep(200);
   p++;
  }
}

int PEQUENOHALL(){
PORTUGUES();
BEMVINDO();
int escolha=0;
	 do {
	 	system("cls");
		printf("\n\n\n\n\n\n\n\n");
		printf("\t\t\t 1-NÚMEROS MAIS SORTEADOS\n");
		printf("\t\t\t 2-RELAÇÃO DE PRÊMIOS\n");
		printf("\t\t\t 3-SAIDA\n");
		printf("\t\t\t 4-VERIFICAR NÚMERO\n");
		printf("ESCOLHA:");
		scanf("%d",&escolha);
	}while(escolha <1 ||  escolha>4);
return escolha;
}
	


void Leitura(int guarda[61]){
	PORTUGUES();
	system("cls");
	Zera();
	for(i=0;i<=60;i++){
		while((fscanf(fp,"%d",&PK[kli]))!=EOF){
			kli++;
		}
		for(N=0;N<kli;N++){   // for que compara os números inseridos  // 
			if(PK[N]==c){
				contador++;         // conta quantas vezez o número repete //
			 	guarda[c]=contador; // passa o valor repetido para seu respectivo numéro no vetor /
			}
		}
		if(contador==0){
			guarda[c]=-1;
		}
		contador=0;
		c++;
}   
printf("%d",guarda[0]);
	
   for(i=0;i<=60;i++){        // Testar os 60 números //
   	  for(N=0;N<61;N++){    // Compara todos os algarismos entre si //
   	    if(guarda[N]!=-1){ 
   	    	if(guarda[N]>=guarda[i]){ // Compara e ordena o valor das repetições do menor para o maior //
   	  			if(guarda[N]>=maioral[i]){
   	  				maioral[i]=guarda[N];
			  		teste=N;                // impossibilita a comparação de numéros ja comparados //
				}
				
   	  	 	}
   	  	
		}	    		
   }
   	guarda[teste]=-1;
}
  // PASSO 2 //
  c=-1;
  for(M=1;M<=10;M++){        // Os 10 mais sorteados em forma de algarismo //
  	for(i=0;i<=60;i++){ 	
  		c++;
  		cont=0;
		
		for(L=0;L<120;L++){
			if(PK[L]==c){
			cont++;
			}
		}
	  if(maioral[M]==cont){ // Compara 
	  	   if(c!=T){
	  	   		final[M]=c;
	  	   		v=c;
			 }
			 else{
	  	   		break;
			 }
		}
	}
   T=v;
   c=-1;
}
     //PASSO 3// 	
	printf("\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t    VALORES\n");
	printf("--------------------------------------------------------------------------------\n");
 for(i=1;i<=10;i++){
 	Sleep(200);
	printf("\t\t\t\t %d° Valor\t%d\n",i,final[i]);
	printf("--------------------------------------------------------------------------------\n");
	}			
}

void VERIFICAR(){
int kx=0,l1=0,k1=0,x1=0,xl=5,i1=0,teste1=0,teste2=0,PK1[220],kli1=0,L1=0,vetor[5];

	PORTUGUES();
	system("cls");
	printf("\n\n\n\n\n\n\n\n");
	printf("\t\t\t   COLOQUE OS NÚMEROS DO JOGO\n");
	printf("--------------------------------------------------------------------------------\n");
		for(l1=0;l1<=5;l1++){
	  		printf("\t\t\t\t  Número %d: ",l1+1);
	  		fflush(stdin);
	  		scanf("%d",&vetor[l1]);
	  		printf("--------------------------------------------------------------------------------\n");

		}
		L=1;
		while((fscanf(fp,"%d",&PK1[kli1]))!=EOF){
			kli1++;
		
	  }
		for(L1=0;L1<20;L1++){
			for(i1=kx;i1<=xl;i1++){
				if(vetor[x1]==PK1[i1]){
					teste1++;
				}
		    	x1++;
			}

				if(teste1==6){
	    		break;	
			}
			teste1=0;

			x1=0;
			kx=kx+5+1;
			xl=kx+5;				

	    	
			
		}
		
     if(teste1==6){
     	system("cls");
     	printf("\n\n\n\n\n\n\n\n");
     	printf("\t\t\t-------------------------\n");
     	printf("\t\t\tESSE JOGO JÁ FOI SORTEADO\n");
     	printf("\t\t\t-------------------------\n\n");
	 }
	 else{
	 	system("cls");
	 	printf("\n\n\n\n\n\n\n\n");
	 	printf("\t\t\t---------------------------\n");
	 	printf("\t\t\tESSE JOGO NÃO FOI SORTEADO\n");
	 	printf("\t\t\t---------------------------\n\n");

	 }
	printf("ENTER:");
	getch();

}
  void PREMIOS(){
  system("cls");
  PORTUGUES();
  Zera();
  int escolha=0;
  float premio[220],maior=0,menor=0;
    do {
    	system("cls");
    	printf("\n\n\n\n\n\n\n\n");
    	printf("\t\t\t TODOS OS PRÊMIOS -1-\n");
		printf("\t\t\t MAIOR E MENOR PRÊMIO -2-\n");
		printf("ESCOLHA:");
		scanf("%d",&escolha);
	} while(escolha<1 || escolha>2);
			
	while((fscanf(fp,"%f",&premio[kli]))!=EOF){
			kli++;
		}
	system("cls");
	printf("\n\n\n\n\n\n\n\n");
  	printf("\t\t\t       REGISTRO DE PRÊMIOS\n");
	if(escolha==2){
		for(i=120;i<=139;i++){
			if(maior<premio[i]){
				maior=premio[i];
			}
		}	
   		menor=maior;
   		for(L=120;L<=139;L++){
   	   		if(menor>=premio[L]){
   	   			menor=premio[L];
		  	}
   		}
  		
  		printf("--------------------------------------------------------------------------------\n");
  		printf("\t\t\t MAIOR PRÊMIO REGISTRADO:%.2f\n",maior);
  		printf("--------------------------------------------------------------------------------\n");
  		printf("\t\t\t MENOR PRÊMIO REGISTRADO:%.2f\n",menor);
  		printf("--------------------------------------------------------------------------------\n");
  		printf("ENTER:");
  		getch();
	}
	else{
		printf("--------------------------------------------------------------------------------\n");
		for(M=120;M<=139;M++){
		printf("\t\t\t  PREMIO:\t%.2f\n",premio[M]);
		printf("--------------------------------------------------------------------------------\n");

		}
		printf("ENTER:");
  		getch();
	}
	
}
