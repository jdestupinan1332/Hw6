#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>


int main(void){
	
//Definici'on de los vectores de posiciones y velocidades en x y en y.
	FILE *in;
	int n=12;
	float x[n];
	float y[n];
	float vx[n];
	float vy[n];
	int i;
	float r=1;
	srand48(time(NULL));
//Inicializar el vector de posiciones (x,y) y el de velocidades(vx, vy) para las 100 part'iculas.
	in=fopen("data.dat","w");
	
	for (i=0; i<n; i++){
		x[i]=r*drand48();
		
		y[i]=sqrt(pow(r,2)-pow(x[i],2));
		if(i>2 && i<6){
			x[i]=-r*drand48();
			y[i]=(sqrt(pow(r,2)-pow(x[i],2)));
		}
		if(i>5){
			x[i]=x[i-6];
			y[i]=-y[i-6];
		}
		
		fprintf(in, "%f %f\n", x[i],y[i]);
		
	}
	
	return ;
}

	
	
