#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float aceleracion(float x,float y,float vx,float vy);
void evolve(char condini[25], char condfinal[25]);
float *rungekutta(float x0, float y0,float vx0, float vy0);



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
	int n=500000;//numero de puntos en tiempo
	int dt=10000;//pasos en el tiempo
	int masas =120;//numero de cuerpos que conforman la galaxia.		
	int t;//tiempo
	//Iteraciones
	
	int i;//iteracion en cuerpos
	int j;//iteracion en tiempo
	
	
	//en coordenadas
	float x;
	float y;
	float vx;
	float vy;
	float ax;
	float ay;
	
	
	
	//si es una sola galaxia.
	if (argc==2){
		
		galaxia1=fopen(argv[1],"w");
	}
		
		
	
	
}



float[] rungekutta(float x0, float y0,float vx0, float vy0){
	
	int i;
	int dt=10000;
	int t;
	int n=100000;// numero de iteraciones
	float xn=x0;
	float yn=y0;
	float vxn=vx0;
	float vyn=vy0;
	float salida[4];
	
	
	for (i=0; i<n;i++){
		
		t=i*dt;
		float x=xn;
		float y=yn;
		float vx=vxn;
		float vy=vyn;
		
		//radio velocidad aceleracion
		float r=sqrt(pow(x,2)+pow(y,2));
		float v=sqrt(pow(vx,2)+pow(vy,2));
		float a=aceleracion(x,y,vx,vy);
		//angulo
		float teta = atan2(y,x); //arctan(y/x)
		//coordenadas aceleracion
		float ax= a*cos(teta);
		float ay= a*sin(teta);
	
		//PRIMER PASO
	
		float k1x = vx*dt;
		float k1y = vy*dt;
		float l1x = ax*dt;
		float l1y = ay*dt;
	
		//SEGUNDO PASO
		
		float x1 = x+ 0.5 * k1x;
		float y1 = y+ 0.5 * k1y;
		float teta1= atan2(y1,x1);
				
		float vx1= vx + 0.5* l1x;
		float vy1= vy + 0.5 *l1y;
				
		float a1=aceleracion(x1,y1,vx1,vy1);
	
		float ax1=a1*cos(teta1);
		float ay1= a1*sin(teta1);
	
	
		float k2x= vx1*dt;
		float k2y= vy1*dt;
		float l2x= ax1*dt;
		float l2y= ay1*dt;
	
		//TERCER PASO
	
		float x2 = x+ 0.5 * k2x;
		float y2 = y+ 0.5 * k2y;
		float teta2= atan2(y1,x1);
				
		float vx2= vx + 0.5* l2x;
		float vy2= vy + 0.5 *l2y;
				
		float a2=aceleracion(x2,y2,vx2,vy2);
	
		float ax2= a2*cos(teta2);
		float ay2= a2*sin(teta2);
	
	
		float k3x= vx2*dt;
		float k3y= vy2*dt;
		float l3x= ax2*dt;
		float l3y= ay2*dt;
	
		//CUARTO PASO
	
		float x3 = x+ k3x;
		float y3 = y+ k3y;
		float teta3= atan2(y3,x3);
				
		float vx3= vx + l3x;
		float vy3= vy + l3y;
				
		float a3=aceleracion(x3,y3,vx3,vy3);
	
		float ax3= a3*cos(teta3);
		float ay3= a3*sin(teta3);
	
	
		float k4x= vx3*dt;
		float k4y= vy3*dt;
		float l4x= ax3*dt;
		float l4y= ay3*dt;
	
		//FINAL
			
		float kx=(1.0/6.0)*(k1x + 2.0*k2x + 2.0*k3x + k4x);
		float ky=(1.0/6.0)*(k1y + 2.0*k2y + 2.0*k3y + k4y);
	
		float lx=(1.0/6.0)*(l1x + 2.0*l2x + 2.0*l3x + l4x);
		float ly=(1.0/6.0)*(l1y + 2.0*l2y + 2.0*l3y + l4y);
		
		
		//Reasignacion
		
		xn=x+kx;
		yn=y+ky;
		vxn=vx+lx;
		vyn=vy+ly;
		
	}
	
	salida[0]=xn;
	salida[1]=yn;
	salida[2]=vxn;
	salida[3]=vyn;
	
	return salida;
}


float aceleracion(float x,float y,float vx,float vy){
	
	float G=4.89*pow(10,(-39));
	float M=pow(10,12);
	float r=sqrt(pow(x,2)+pow(y,2));
	float a=-(G*M/pow(r,2));
	
	return a;
}

void evolve (char condini[25], char condfin[25]){
  FILE *ini;
  FILE *fin;
  float posx, posy, velx, vely;
  int id;
  float *M;
  float var[4];
  int i, lmax, l, n;
 
  /*Opens file*/
  ini = fopen(condini, "r");
  if(!ini){
    printf("problems opening the file %s\n",condini);
    exit(1);
  }
  
  /*Count lines*/
  do{
    i = fgetc(ini);
    if (i == '\n') lmax++;
  }while (i != EOF);

  /*memory allocation*/
  if (!(M = malloc(5 * lmax*  sizeof(double)))){
    fprintf(stderr, "Problem with memory allocation\n");
    exit(1);
  }
  
  n = 0;
  for (l=0;l<lmax;l++){
    n = 5*l;
    fscanf(ini, "%d %f %f %e %e\n", &id, &posx, &posy, &velx, &vely);
    M[n] = id;
    M[n+1] = posx;
    M[n+2] = posy;
    M[n+3] = velx;
    M[n+4] = vely;   
  }
  fclose(ini);

  /*buscar centros de galaxias*/
  
  /*RungeKutta*/
  n = 0;
  fin = fopen(condfin, "a");
  if(!fin){
    printf("problems opening the file %s\n",condfin);
    exit(1);
  }  
  
  for (l=0;l<lmax;l++){
    n = 5*l;
    var = rungekutta(M[n+1],M[n+2],M[n+3],M[n+4]);
    fprintf(fin, "%d %f %f %e %e\n",l-1, var[0], var[1],var[2], var[3]);
  }
  fclose(fin);
}


