#include <stdio.h>
#include <math.h>
typedef unsigned short PALABRA; //palabra de 16 bits

struct implicante{
    PALABRA t; // bits para variables en 1
    PALABRA f; // bits para variables en 0
};

void decimal_binario(int tabla[][5],int ar_min[],int var,int tam){ //funcion que convierte de decimal a binario
	int i,j;
	for (i=0;i<tam;i++){
		int num = ar_min[i];
		for (j=var-1;j>=0;j--){
			tabla[i][j] = num%2;
			num = num/2;
		}
	}
	
}


int main(){
	int i,j;
    int var;//numero de variables
    int max_min;//número maximo de minterminos
    int tam_ar_min;//tamaño del arreglo de minterminos
    printf("Ingrese la cantidad de variables: \n");
    scanf("%d",&var);
    max_min = pow(2,var);//restringir el numero de minterminos 
    printf("Ingrese el numero de minterminos: \n");
    scanf("%d",&tam_ar_min);
    int ar_min[tam_ar_min];//crear el arreglo para guardar los minterminos 
    if (tam_ar_min>max_min){
        printf("Número de minterminos no valido \n");
    }
    for (i=1;i<=tam_ar_min;i++){ //bucle para pedir los minterminos y guardarlos en un arreglo
    	int mintermino;
        printf("Ingrese el %d° mintermino: \n",i);
        scanf("%d",&mintermino);
        printf("\n");
        ar_min[i-1]=mintermino;
        if (ar_min[i-1]>max_min){
            printf("El mintermino ingresado no es valido \n");
        }
    }
    int tabla[tam_ar_min][var];
    
    decimal_binario(tabla,ar_min,var,tam_ar_min);
	
	
	for (i=0;i<tam_ar_min;i++){
		for (j=0;j<var;j++){
			printf("%d",tabla[i][j]);
		}
		printf("\n");
	}
    
}
    


