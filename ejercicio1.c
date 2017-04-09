//LAURA GONZALEZ DEL RIO

#include <stdio.h>
#include <math.h>

int menu();
float area(float xlado1,float ylado1,float xlado2,float ylado2,float xlado3,float ylado3);
float distancia(float x1,float y1,float x2, float y2);
int sumaDivisores(int numero);
int esAmigo(int amigo1,int amigo2);

int main(){
	int eleccion=0;
	float xpunto1,ypunto1,xpunto2,ypunto2,xpunto3,ypunto3;
	int numero1,numero2;
	float triangulo=0.0;
	int resultado=0;
	do{
		eleccion=menu();
		switch(eleccion){
			case 1:
				printf("Coordenada X del punto 1\n");
				scanf("%f",&xpunto1);
				printf("Coordenada Y del punto 1\n");
				scanf("%f",&ypunto1);
				printf("Coordenada X del punto 2\n");
				scanf("%f",&xpunto2);
				printf("Coordenada Y del punto 2\n");
				scanf("%f",&ypunto2);
				printf("Coordenada X del punto 3\n");
				scanf("%f",&xpunto3);
				printf("Coordenada Y del punto 3\n");
				scanf("%f",&ypunto3);
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
	}while(eleccion!=3);
	return 0;
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

float area(float xlado1,float ylado1,float xlado2,float ylado2,float xlado3,float ylado3){
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

float distancia(float x1,float y1,float x2, float y2){
	float lado=0.0;
	lado=sqrt(pow((x2-x1),2)+pow((y2-y1),2));
	return lado;
}

int sumaDivisores(int numero){
	int i=0;
	int suma=0;

	for (i=1;i<=numero;i++){
		if(numero%i==0){
			suma=suma+i;
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