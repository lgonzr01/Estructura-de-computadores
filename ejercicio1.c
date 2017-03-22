#include <stdio.h>
#include <math.h>

// Prueba clonar y modificación en github

int menu();
float area(int x1,int y1,int x2,int y2,int x3,int y3);
float distancia(int x1,int y1,int x2, int y2);
int sumaDivisores(int numero);
int esAmigo(int amigo1,int amigo2);

int main(){
	int eleccion=0;
	int xpunto1,ypunto1,xpunto2,ypunto2,xpunto3,ypunto3;
	int numero1,numero2;
	float triangulo=0.0;
	int resultado=0;
	eleccion=menu();
	switch(eleccion){
		case 1:
			printf("Coordenada X del punto 1\n");
			scanf("%d",&xpunto1);
			printf("Coordenada Y del punto 1\n");
			scanf("%d",&ypunto1);
			printf("Coordenada X del punto 2\n");
			scanf("%d",&xpunto2);
			printf("Coordenada Y del punto 2\n");
			scanf("%d",&ypunto2);
			printf("Coordenada X del punto 3\n");
			scanf("%d",&xpunto3);
			printf("Coordenada Y del punto 3\n");
			scanf("%d",&ypunto3);
			triangulo=area(xpunto1,ypunto1,xpunto2,ypunto2,xpunto3,ypunto3);	
			printf("El area del triangulo es %f:\n",triangulo);
		break;

		case 2:
			do{
				printf("Introduzca el primero numero \n");
				scanf("%d",&numero1);
				printf("introduzca el segundo numero\n");
				scanf("%d",&numero2);
				if(numero1<=0|| numero2<=0){
					printf("Introduzca dos numero positivos y mayores de 0\n");
				}
			}while(numero1<=0|| numero2<=0);
			resultado=esAmigo(numero1,numero2);

			if (resultado==1){
				printf("Los números %d y %d SON amigos\n",numero1,numero2);
			}else{	
				printf("Los números %d y %d NO son amigos\n",numero1,numero2);
			}
		break;

		case 3:
			printf("Ha salido del programa\n");
		break;

		default:
			printf("ERROR\n");
		break;
	}
}



int menu(){
	int opcion=0;
	do{
		printf("Seleccione una opción\n1.Calcular el área de un triángulo conociendo sus vértices.\n2.Saber si un número es amigo de otro.\n3.Salir\n");
		scanf("%d",&opcion);

		if(opcion>3||opcion<=0){
			printf("ERROR\nElija un número del 1 al 3\n");
		}
		
	}while(opcion>3||opcion<=0);
	
	return opcion;
}

float area(int xlado1,int ylado1,int xlado2,int ylado2,int xlado3,int ylado3){
	float a=0.0,b=0.0,c=0.0;
	float resultado=0.0;
	float p=0.0;
	a=distancia(xlado1,ylado1,xlado2,ylado2);
	b=distancia(xlado1,ylado1,xlado3,ylado3);
	c=distancia(xlado3,ylado3,xlado2,ylado2);
	p=(a+b+c)/2.0;
	resultado=sqrt(p*(p-a)*(p-b)*(p-c));
	
	return resultado;
}

float distancia(int x1,int y1,int x2,int y2){
	float lado=0.0;
	lado=sqrt(pow((x2-x1),2)+pow((y2-y1),2));
	return lado;
}

int sumaDivisores(int numero){
	int i=0;
	int suma=0;

	for (i=1;i<=numero/2;i++){
		if(numero%i==0){
			suma=suma+numero;
		}else{
			suma=suma;
		}
	}
	return suma;
}

int esAmigo(int amigo1,int amigo2){
	int resultado1=0,resultado2=0;
	int amigos=0;
	resultado1=sumaDivisores(amigo1);
	resultado1=resultado1-amigo1;
	resultado2=sumaDivisores(amigo2);
	resultado2=resultado2-amigo2;

	if(resultado1==amigo2 && resultado2==amigo1){
		amigos=1;
	}else{
		amigos=0;
	}

	return amigos;
}