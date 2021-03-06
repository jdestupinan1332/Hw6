#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float aceleracion1(float id,float x,float y);
void evolve(char condini[25], char condfinal[25]);
float *rungekutta(float id,float x0, float y0,float vx0, float vy0,int lmax, float x1,float y1, float vx1, float vy1, float x2,float y2 , float vx2, float vy2);
float aceleracion2(double id,float x,float y,float vx,float vy ,float distx ,float disty);



int main(){
  /* makes everything ;) */
  evolve("data1.dat","data2.dat");
  evolve("data2.dat","data3.dat");
  evolve("data3.dat","data4.dat");
  evolve("data4.dat","data5.dat");
  evolve("data5.dat","data6.dat");
}


float *rungekutta(float id,float x0, float y0,float vx0, float vy0,int lmax, float x1,float y1, float vx1, float vy1, float x2,float y2 , float vx2, float vy2){
  
  float *salida;
  int i;
  int dt=10000;
  int n=100000;// numero de iteraciones
  float xn=x0-x1;
  float yn=y0;
  float vxn=vx0;
  float vyn=vy0;
  float x, y, vx, vy, a;
  
  if(!(salida=malloc(5 *sizeof(double)))){
    fprintf(stderr,"Problem with allocation");
    exit (1);
  }
  
  if(lmax>121){
	  
	  x=xn;
	  y=yn;
      vx=vxn; 
      vy=vyn;
      //distancia entre los centros
      
      float distx=x1-x2;
      float disty=y1-y2;
      
    
    //radio velocidad aceleracion;
    a=aceleracion2(id,x,y,vx,vy,distx, disty);
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
    
    x = xn+ 0.5 * k1x;
    y = yn+ 0.5 * k1y;
    teta= atan2(y,x);
				
    vx= vxn + 0.5* l1x;
    vy= vyn + 0.5 *l1y;
    
    a=aceleracion2(id,x,y,vx,vy,distx, disty); 
    
    ax=a*cos(teta);
    ay= a*sin(teta);
    
    
    float k2x= vx*dt;
    float k2y= vy*dt;
    float l2x= ax*dt;
    float l2y= ay*dt;
    
    //TERCER PASO
    
    x = xn+ 0.5 * k2x;
    y = yn+ 0.5 * k2y;
    teta= atan2(y,x);
    
    vx= vxn + 0.5* l2x;
    vy= vyn + 0.5 *l2y;
    
    a=aceleracion2(id,x,y,vx, vy,distx, disty);
    
    ax= a*cos(teta);
    ay= a*sin(teta);
    
    
    float k3x= vx*dt;
    float k3y= vy*dt;
    float l3x= ax*dt;
    float l3y= ay*dt;
    
    //CUARTO PASO
    
    x = xn+ k3x;
    y = yn+ k3y;
    teta= atan2(y,x);
    
    vx= vxn + l3x;
    vy= vyn + l3y;
    
    a=aceleracion2(id,x,y,vx,vy,distx, disty);
    
    ax= a*cos(teta);
    ay= a*sin(teta);
    
    
    float k4x= vx*dt;
    float k4y= vy*dt;
    float l4x= ax*dt;
    float l4y= ay*dt;
    
    //FINAL
    
    float kx=(1.0/6.0)*(k1x + 2.0*k2x + 2.0*k3x + k4x);
    float ky=(1.0/6.0)*(k1y + 2.0*k2y + 2.0*k3y + k4y);
    
    float lx=(1.0/6.0)*(l1x + 2.0*l2x + 2.0*l3x + l4x);
    float ly=(1.0/6.0)*(l1y + 2.0*l2y + 2.0*l3y + l4y);

    
    
    //Reasignacion
    
    xn=xn+kx;
    yn=yn+ky;
    vxn=vxn+lx;
    vyn=vyn+ly;
}
  
  
  
  for (i=0;i<n;i++){
    x=xn;
    y=yn;
    vx=vxn; 
    vy=vyn;
    
    //radio velocidad aceleracion;
    a=aceleracion1(id,x,y);
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
    
    x = xn+ 0.5 * k1x;
    y = yn+ 0.5 * k1y;
    teta= atan2(y,x);
				
    vx= vxn + 0.5* l1x;
    vy= vyn + 0.5 *l1y;
    
    a=aceleracion1(id,x,y); 
    
    ax=a*cos(teta);
    ay= a*sin(teta);
    
    
    float k2x= vx*dt;
    float k2y= vy*dt;
    float l2x= ax*dt;
    float l2y= ay*dt;
    
    //TERCER PASO
    
    x = xn+ 0.5 * k2x;
    y = yn+ 0.5 * k2y;
    teta= atan2(y,x);
    
    vx= vxn + 0.5* l2x;
    vy= vyn + 0.5 *l2y;
    
    a=aceleracion1(id,x,y);
    
    ax= a*cos(teta);
    ay= a*sin(teta);
    
    
    float k3x= vx*dt;
    float k3y= vy*dt;
    float l3x= ax*dt;
    float l3y= ay*dt;
    
    //CUARTO PASO
    
    x = xn+ k3x;
    y = yn+ k3y;
    teta= atan2(y,x);
    
    vx= vxn + l3x;
    vy= vyn + l3y;
    
    a=aceleracion1(id,x,y);
    
    ax= a*cos(teta);
    ay= a*sin(teta);
    
    
    float k4x= vx*dt;
    float k4y= vy*dt;
    float l4x= ax*dt;
    float l4y= ay*dt;
    
    //FINAL
    
    float kx=(1.0/6.0)*(k1x + 2.0*k2x + 2.0*k3x + k4x);
    float ky=(1.0/6.0)*(k1y + 2.0*k2y + 2.0*k3y + k4y);
    
    float lx=(1.0/6.0)*(l1x + 2.0*l2x + 2.0*l3x + l4x);
    float ly=(1.0/6.0)*(l1y + 2.0*l2y + 2.0*l3y + l4y);

    
    
    //Reasignacion
    
    xn=xn+kx;
    yn=yn+ky;
    vxn=vxn+lx;
    vyn=vyn+ly;
    
  }
  
  salida[0]=xn;
  salida[1]=yn;
  salida[2]=vxn;
  salida[3]=vyn;
  
  return salida;
}

float aceleracion1(float id,float x,float y){
	
  float G=4.86*pow(10,(-24));
  float M=pow(10,12);
  float r;
  float a;
  
  //Si es una particula cualquiera
  if ( id>=0 ){
    r=sqrt(pow(x,2)+pow(y,2));
    a=-(G*M/pow(r,2));
  }
  //Si es el centro  
  else if( id<0 ){
    a=0;
  }
  
  return a;

}

float aceleracion2(double id,float x,float y,float vx,float vy ,float distx ,float disty){
  float G=4.86*pow(10,(-24));
  float M=pow(10,12);
  float r=sqrt(pow(x,2)+pow(y,2));
  float a;
 
  if(id>0){
    
    float x2= x+ distx;
    float y2= y+ disty;
    float r2=sqrt(pow(x2,2)+pow(y2,2));//distancia al centro 2
		
    a=-G*M*((1/pow(r,2))+(1/pow(r2,2)));
    
  }
  else if(id<0){
    
    float distc=sqrt(pow(distx,2)+pow(disty,2));
		
    a=-G*M*(1/pow(distc,2));
  }
  return a;

}

void evolve (char condini[25], char condfin[25]){
  FILE *ini;
  FILE *fin;
  float posx=0.0;
  float posy=0.0;
  float velx=0.0;
  float vely=0.0;
  int id = 0;
  float *M;
  float *var;
  int i, lmax, l, n;
  int test;
 
  /*Opens file*/
  ini = fopen(condini, "r");
  if(!ini){
    printf("problems opening the file %s\n",condini);
    exit(1);
  }
  
  lmax = 0;
  /*Count lines*/
  do{
    i = fgetc(ini);
    if (i == '\n') lmax++;
  }while (i != EOF);
  fclose(ini);

  /*memory allocation*/
  if (!(M = malloc(5 * lmax*  sizeof(double)))){
    fprintf(stderr, "Problem with memory allocation\n");
    exit(1);
  }

  ini = fopen(condini, "r");
  n = 0;
  for (l=0;l<lmax;l++){
    n = 5*l;
    test = fscanf(ini, "%d %f %f %e %e\n", &id, &posx, &posy, &velx, &vely);
    M[n] = id;
    M[n+1] = posx;
    M[n+2] = posy;
    M[n+3] = velx;
    M[n+4] = vely;
  }
  fclose(ini);
    
  /*RungeKutta*/
  n = 0;
  fin = fopen(condfin, "a");
  if(!fin){
    printf("problems opening the file %s\n",condfin);
    exit(1);
  }  
  
  for (l=0;l<lmax;l++){
	n = 5*l;  
	  
	  if(lmax<120){
		  var = rungekutta(M[n],M[n+1],M[n+2],M[n+3],M[n+4],lmax, M[1] ,M[2],M[3],M[4],0.0,0.0 ,0.0,0.0);
		 
	  }
    else {
		var = rungekutta(M[n],M[n+1],M[n+2],M[n+3],M[n+4],lmax, M[1] ,M[2],M[3],M[4],M[121*5],M[(121*5)+1] ,M[(121*5)+2],M[(121*5)+3]);
	}
    
    fprintf(fin, "%d %f %f %e %e\n",(int)M[n], var[0], var[1],var[2], var[3]);
  }
  fclose(fin);
}



