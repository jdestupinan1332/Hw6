#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

void ini_pos(int n,float r,float x0,float y0,float vx0,float vy0, int ni);



int main(int argc, char **argv){
	
	if(argc<5){
		printf("We need at least 4 argument beside the name of the executable!\n EXIT!\n");
		exit(1);  
	}
	float a= atof(argv[1]);
	float b= atof(argv[2]);
	float c= atof(argv[3]);
	float d= atof(argv[4]);
	
	
	FILE *in;
	in=fopen("data.dat","w");
	fprintf(in, "%d %f %f %e %e\n",-1, a,b,c,d);
	fclose(in);
	
	ini_pos(12,10.0,a,b,c,d,0);
	ini_pos(18,20.0,a,b,c,d,12);
	ini_pos(24,30.0,a,b,c,d,18+12);
	ini_pos(30,40.0,a,b,c,d,18+12+24);
	ini_pos(36,50.0,a,b,c,d,18+12+24+30);
	
		
	
		return 0;
}
	
void ini_pos(int n,float r,float x0,float y0,float vx0,float vy0, int ni){
	
//Definici'on de los vectores de posiciones y velocidades en x y en y.
	FILE *in;
	float x[n];
	float y[n];
	float vx[n];
	float vy[n];
	int ID[n];
	int i=0;
	float G=4.864*pow(10,(-24)); //kPc^3 M^-1 yr ^-2
	float M=pow(10,12);

	srand48(time(NULL));

//Inicializar el vector de posiciones (x,y) y el de velocidades(vx, vy) para las 100 part'iculas.
	in=fopen("data.dat","a");
	float v=sqrt(M*G/r);
	for (i=0; i<n; i++){
		ID[i]=i+ni;
		
		x[i]=r*drand48();	
		y[i]=sqrt(pow(r,2)-pow(x[i],2));
		
		
		if(i>(n/4)+1 && i<=(n/2)-1){
			x[i]=-r*drand48();
			y[i]=(sqrt(pow(r,2)-pow(x[i],2)));
		}
		if(i>(n/2)-1){
			x[i]=x[i-(n/2)];
			y[i]=-y[i-(n/2)];
		}
		if(n%4!=0){
			x[n-1]=r*drand48();
			x[n-2]=-x[n-1];
			y[n-1]=sqrt(pow(r,2)-pow(x[n-1],2));
			y[n-2]=y[n-1];
		
		}	
		
		vx[i]=v*sin(atan2(y[i],x[i]));
		vy[i]=v*cos(atan2(y[i],x[i]));
		
		fprintf(in, "%d %f %f %e %e\n",ID[i], x[i]+x0,y[i]+y0,vx[i]+vx0,vy[i]+vy0);
		
	}
	fclose(in);

}
	
	
