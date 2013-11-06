#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

float aceleracion(float x,float y,float vx,float vy);

int main(int argc, char **argv){
	
	if(argc<2){
		printf("We need at least 1 argument beside the name of the executable!\n EXIT!\n");
		exit(1);
	}
	//archivos de las galaxias
	
	FILE *galaxia1;
	FILE *galaxia2;
	FILE *galaxias;
	
	//archivos de las posiciones a los aos requeridos
		
	FILE *aos1000;
	FILE *aos2000;
	FILE *aos3000;
	FILE *aos4000;
	FILE *aos5000;
	
	//variables
	int t;//tiempo
	int n=2500000;//tiempo maximo
	int dt=2000;//pasos en el tiempo
	float x;
	float y;
	float vx;
	float vy;
	
	
	//si es una sola galaxia.
	if (argc==2){
		
		galaxia1=fopen(argv[1],"w");
		int i;
		int masas =120;//numero de cuerpos que conforman la galaxia.		
		
		for (t=1;t<n;t+1999){//n el numero de a;os 5000 millones. desde 1 porque ya tenemos en el tiempo 0
			
			for (i=1; i<masas ; i++){//desde 1 porque la primera es el centro
				
				//primer paso
				
				
				float r=sqrt(pow(x,2)+pow(y,2));
				float a1=aceleracion(x,y,vx,vy);
				float v1=sqrt(pow(vx,2)+pow(vy,2));
		
				
				float k1 = v1*dt;
				float l1 = a1*dt;
		
				//Segundo paso
		
				float x1 = x+ 0.5 * k1;
				float y1 = y+ 0.5 * k1;
				
				float vx1= vx + 0.5* l1;
				float vy1= vy + 0.5 *l1;
				
				float v2=sqrt(pow(vx1,2)+pow(vy1,2));
				float a2=aceleracion(x1,y1,vx1,vy1);
				
				float k2= v2*dt;
				float l2= a2*dt;
					
				//tercer paso
				
				float x2 = x+ 0.5 * k2;
				float y2 = y+ 0.5* k2;
		
				float vx2 = vx + 0.5* l2;
				float vy2 = vy + 0.5 *l2;
				
				float v3=sqrt(pow(vx2,2)+pow(vy2,2));
				float a3= aceleracion(x2,y2,vx2,vy2);
				
				float k3= v3*dt;
				float l3= a3*dt;
		
				//cuarto paso
				
				float x3 = x+ k3;
				float y3 = y +k3;
				
				float vx3 = vx + l3;
				float vy3 = vy + l3;
				
				float v4=sqrt(pow(vx3,2)+pow(vy3,2));
				float a4= aceleracion(x2,y2,vx2,vy2);
				
				float k4=v4*dt;
				float l4=a4*dt;
				
				//final
				
				float k=(1.0/6.0)*(k1 + 2.0*k2 + 2.0*k3 + k4);
				float l=(1.0/6.0)*(l1 + 2.0*l2 + 2.0*l3 + l4);
				
				Reasignacion
				
				x=x+k;
				y=y+k;
				vx=vx+l;
				vy=vy+l;
				
		
				
			}
			
		
			
			//fprintf(in, "%d %f %f %e %e\n",-1, a,b,c,d);
			
		}
		
		
	}
	
	if (argc>2){
		galaxia1=fopen(argv[1],"w+");
		galaxia2=fopen(argv[2],"w+");
		
		
		
	}
	
	
}



float acelaracion(float x,float y,float vx,float vy){
	
	float G=4.89*pow(10,(-39));
	float M=pow(10,12);
	float r=sqrt(pow(x,2)+pow(y,2));
	float a=(G*M/pow(r,2));
	
	return a;
}
