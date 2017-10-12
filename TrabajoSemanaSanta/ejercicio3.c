//LAURA GONZALEZ DEL RIO

#include <stdio.h>

#define FILAS 6
#define COLS 4

void inicializaAusencias(int ausencias[FILAS][COLS]);
void horaExtra(int extras[FILAS][COLS]);
void ausencia(int horasTarde[FILAS][COLS]);
void imprimeDepartamento(int ausenciasDepartamento[FILAS][COLS], int departamentoAusente);
void imprimeTodo(int todasAusencias[FILAS][COLS]);
void imprimeEmpleado(int ausenciasEmpleado[FILAS][COLS],int departamentoEmpleado,int puestoEmpleado);

int main(){
	int matriz[FILAS][COLS];
	inicializaAusencias(matriz);
	int departamento;
	int puesto;
	int opcion;
	do{
		printf("Seleccione la operación a realizar\n1)Empleado que llega una hora tarde\n2)Empleado que hace una hora extra\n3)Mostrar el número de ausencias de los empleados de un departamento\n4)Mostrar el numero de ausencias de todos los empleados de la empresa\n5)Mostrar las ausencias de un empleado\n6)Salir\n");
		scanf("%d",&opcion);
		switch(opcion){
			case 1:
				ausencia(matriz);
			break;
			case 2:	
				horaExtra(matriz);
			break;
			case 3:
				do{
					printf("¿De que departamento quiere ver las ausencias?\n");
					scanf("%d",&departamento);
					if( departamento>FILAS || departamento<1){
						printf("ERROR. DATOS INCORRECTOS\n");
					}
				}while( departamento>FILAS || departamento<1);

				imprimeDepartamento(matriz, departamento);

			break;
			case 4:
				imprimeTodo(matriz);
			break;
			case 5:
				do{
					printf("¿En que departamento trabaja el empleado?\n");
					scanf("%d",&departamento);
					printf("¿En que puesto trabaja el empleado?\n");
					scanf("%d",&puesto);
					if( departamento>FILAS || departamento<1 || puesto>COLS || puesto<1){
					printf("ERROR. DATOS INCORRECTOS\n");
				}
				}while( departamento>FILAS || departamento<1 || puesto>COLS || puesto<1);
				imprimeEmpleado(matriz,departamento,puesto);

				
			break;
			case 6:
				printf("El programa ha terminado\n");
			break;
			default:
				printf("ERROR\n");
			break;
			}	

	}while(opcion!=6);

	return 0;

}

void inicializaAusencias(int matriz[FILAS][COLS]){
	int i=0,j=0;
	for (i=0;i<FILAS;i++){
		for(j=0;j<COLS;j++){
			matriz[i][j]=0;
		}
	}

}

void horaExtra(int extras[FILAS][COLS]){
	int departamento,puesto;
	do{
		printf("¿En que departamento trabaja el empleado?\n");
		scanf("%d",&departamento);
		printf("¿En que puesto trabaja el empleado?\n");
		scanf("%d",&puesto);
		if( departamento>FILAS || departamento<1 || puesto>COLS || puesto<1){
			printf("ERROR. DATOS INCORRECTOS\n");
		}
	}while( departamento>FILAS || departamento<1 || puesto>COLS || puesto<1);
	extras[departamento-1][puesto-1]=(extras[departamento-1][puesto-1])+1;
	
}
void ausencia(int horasTarde[FILAS][COLS]){
	int departamento,puesto;
	do{
		printf("¿En que departamento trabaja el empleado?\n");
		scanf("%d",&departamento);
		printf("¿En que puesto trabaja el empleado?\n");
		scanf("%d",&puesto);
		if( departamento>FILAS || departamento<1 || puesto>COLS || puesto<1){
			printf("ERROR. DATOS INCORRECTOS\n");
		}
	}while( departamento>FILAS || departamento<1 || puesto>COLS || puesto<1);
	horasTarde[departamento-1][puesto-1]=(horasTarde[departamento-1][puesto-1])-1;
	
}

void imprimeDepartamento(int ausenciasDepartamento[FILAS][COLS],int departamentoAusente){
	int i;
	for (i=0;i<COLS;i++){
		printf("Ausencias del empleado %d: %d\n",i+1,ausenciasDepartamento[departamentoAusente-1][i]);
	}
}

void imprimeTodo(int todasAusencias[FILAS][COLS]){
	int i=0;
	int j=0;
	for (i=0;i<FILAS;i++){
		for(j=0;j<COLS;j++){
			printf("%d\t",todasAusencias[i][j]);
		}
		printf("\n");
	}
}
void imprimeEmpleado(int ausenciasEmpleado[FILAS][COLS],int departamentoEmpleado,int puestoEmpleado){
	
	printf("Ausencias del empleado %d en el puesto %d es %d\n",puestoEmpleado,departamentoEmpleado,ausenciasEmpleado[departamentoEmpleado-1][puestoEmpleado-1]);
	
}
