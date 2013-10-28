#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float prima1(float y1, float y2);
float prima2(float y1, float y2);

int main(int argc, char **argv){
/*
  Realiza en proceso del algoritmo de runge kutta
  * INPUT:Lee el archivo de posiciones iniciales data.dat
  * OUTPUT: 5 archivos con las posiciones de las particulas cada 1000 millones de a;os.
  
*/
	if(argc<1){
		printf("We need at least 1 argument beside the name of the executable!\n EXIT!\n");
		exit(1);  
	}

	FILE *fichero;
	fichero=fopen(argv[1],"w");//Lee el archivo de los datos iniciales
	int i;
	int n=2500000;
/*
  Parametros de runge kutta 
  * n=2500000 se realizaran para tener una buena aprox
  * h=2000 el paso en los a;os 
  * Se usan las funciones que se relacionan para la ec. dif de 2do orden
  * k1=(1/6)(k11+2k12+2k13+k14)
  * k2=(1/6)(k21+2k22+2k23+k24)
*/

//Con la aproximaxion del radio se obtinen las velocidades.


	FILE *ina;
	ina=fopen("1000.dat","w");
	FILE *inb;
	inb=fopen("2000.dat","w");
	FILE *inc;
	inc=fopen("3000.dat","w");
	FILE *ind;
	ind=fopen("4000.dat","w");
	FILE *ine;
	ine=fopen("5000.dat","w");

	for (i=1;i<=n;i++){
		
		if(i==1000000000-1){
			
		}
		else if (i==2000000000-1){
			
		}
		else if (i==3000000000-1){
			
		}
		else if (i==4000000000-1){
			
		}
		else if (i==5000000000-1){
			
		}
		
		
	}
		


}


float prima1(float y1, float y2){
	/*
	Funcion intermedia para la ec. de 2do orden.
  
		INPUT: 
			Radio actual  float y1 
			Aceleracion actual float y2
  
		OUTPUT
			y1prima=y2
  
	*/
	return y2;
}

float prima2(float y1, float y2){
	/*
  Funcion para la ec. de 2do orden.
  
		INPUT: 
			Radio actual  float y1 
			Aceleracion actual float y2
  
		OUTPUT
			y2prima= G*M/y1. G:cons. de gravitacion. M:masa del centro
	*/
	float G=4.89*pow(10,(-39));
	float M=pow(10,12);
	
	return (G*M/y1);
}
