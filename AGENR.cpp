#include <math.h>
#include <iostream>
using namespace std;
int  AGENR(double BOAK[],double SB){

//GENERATES COEFFICIENTS FOR G/DELTA CALCULATIONS BY GDELTA

double PI, DEG=0, UNUSED, RAD, kand;
double BOCH,RCPLBC=0.0,BOC2=0.0,BOCTN=0.0,TBOCTN,TMP,FST,DENOM=0.0 ;
double BOCO16[4],AL[16];

double C1[16] = {-0.07612,0.00001,0.21677,0.54120,-0.29289,-0.21677,
                 0.00001,0.32443,-0.61732,-0.54120,-0.32443,0.00001,
                 -1.0,-0.92388,-0.70711,-0.38267 };
double C2[16] = {1.92388,1.84776,1.63099,1.30656,1.70711,1.63099,
                 1.41422,1.08979,1.38268,1.30655,1.08979,0.76536,
                 1.0,0.92388,0.70711,0.38267} ;
double C3[4] = {0.92388,0.70711,0.38268,0.00001} ;

double F1[4]= {5.2262,1.0360,0.0,0.11208};
double F2[4]= {1.91433,2.8284,0.91418,0.0};
double F3[4]= {0.0,1.1944,2.1634,1.5772};
double F4[4]= {0.14645,0.0,0.85357,2.0};

int K=0, KP=2 ;
int i=0;
while (i<16)
    {
      if(KP==K){
            goto loop;
               }
      KP = K ;
      BOCH=BOAK[K] ;
      BOCO16[K]=-BOCH/16 ;
      RCPLBC=1.0/BOCH ;
      BOC2=pow(BOCH,2.0) ;
      BOCTN=BOCH  *tan(DEG*SB) ;
      TBOCTN=2.0*BOCTN ;
      DENOM=1+C3[K]*TBOCTN ;
loop: TMP=pow((1+C1[i]*BOCTN),2.0) ;
      AL[i]=(RCPLBC/C1[i])*(sqrt(TMP+BOC2*pow(C1[i],2))-1.0)
             -(RCPLBC/C2[i])*((sqrt(TMP+BOC2*pow(C2[i],2))/DENOM)-1.0)
             -2.0*tan(DEG*SB)*(sqrt(pow((1.0+C3[K]*BOCTN),2)+BOC2*pow(C3[K],2))/DENOM);
      if(4*((i+1)/4)==(i+1))K++;
      i++;
    }


 int  P=0 ,L=0,j=0 ;
 while(j<4)
    {
      FST=-2*F1[j] ;
      if(j==0)FST=-FST ;
      A[L]=FST+BOCO16[j]*(2.6131*AL[P]+2*(-0.70711*AL[P+1]-0.76537*AL[P+2]+0.20711*AL[P+3])) ;
      L=L+1 ;
      FST=-2*F2[j] ;
      if(j==1)FST=-FST ;
      A[L]=FST+BOCO16[j]*(-1.4142*AL[P]+2.*(1.8478*AL[P+1]-0.50000*AL[P+2]-0.76537*AL[P+3])) ;
      L=L+1 ;
      FST=-2*F3[j] ;
      if(j==2)FST=-FST ;
      A[L]=FST+BOCO16[j]*(1.0824*AL[P]+2.*(-1.2071*AL[P+1]+1.8478*AL[P+2]-0.70711*AL[P+3])) ;
      L=L+1 ;
      FST=-2*F4[j] ;
      if(j==3)FST=-FST ;
      A[L]=FST+BOCO16[j]*(-0.5*AL[P]+1.0824*AL[P+1]-1.4142*AL[P+2]+2.6131*AL[P+3]) ;
      L=L+1 ;
      P=L ;
      j++;
    }
for(int l=0;l<16;l++)
    {
      return A[l];
    }
