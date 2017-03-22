#include <stdio.h>

#define TAM 26

int main(){

	char abecedario[TAM];
	int primeraLetra=97;
	int numero;
	int tamaño=0;
	int contador=0,i,j;

	for (i=0;i<TAM;i++){
		abecedario[i]=primeraLetra;
		primeraLetra++;
	}
	do{
		printf("Introduzca un numero entero y positivo:");
		scanf("%d",&numero);

	}while(numero<=0||numero>26);

	tamaño=numero*2;

	for(i=0;i<numero;i++){
		for (j=0;j<=tamaño;j++){
			if(j==tamaño/2){
				printf(" ");
			}
			if(j<=i){
				printf("%c",abecedario[j]);
				
			}else if((tamaño-1-j)<=i){
				printf("%c",abecedario[tamaño-1-j]);
			}else{
				printf(" ");		
			}
			
		}
		printf("\n");
	}
	return 0;
}