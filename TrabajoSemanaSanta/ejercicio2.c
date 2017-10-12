//LAURA GONZALEZ DEL RIO

#include <stdio.h>

#define TAM 26

int main(){

	char abecedario[TAM];
	int primeraLetra=97;
	int numero;
	int tamano=0;
	int contador=0,i,j;

	for (i=0;i<TAM;i++){
		abecedario[i]=primeraLetra;
		primeraLetra++;
	}
	do{
		printf("Introduzca un numero entero y positivo:");
		scanf("%d",&numero);
		if(numero<=0){
			printf("ERROR\nIntroduzca un numero del 1-26\n");		
		}
	}while(numero<=0||numero>TAM);

	tamano=numero*2;

	for(i=0;i<numero;i++){
		for (j=0;j<=tamano;j++){

			if(j==tamano/2 && i!=(numero-1)){
				printf(" ");
			}

			if(j==tamano/2 && i==(numero-1)){
				printf("*");
			}

			if(j<=i){
				printf("%c",abecedario[j]);
				
			}else if((tamano-1-j)<=i){
				printf("%c",abecedario[tamano-1-j]);

			}else{
				printf(" ");		
			}
			
		}
		printf("\n");
	}
	return 0;
}