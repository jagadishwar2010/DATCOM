#include<iostream>
#include<math.h>
using namespace std;

//       A ROUTINE TO COMPUTE THE FOLLOWING ELEMENTS OF AN ANGLE,
//       GIVEN ANY OF THEM.  INTERNAL TESTING IS DONE TO PRECLUDE
//       RECALCULATION OF ANY OR ALL KNOWN ELEMENTS.
//       ARG(0)---ANGLE IN DEGREES
//       ARG(1)---ANGLE IN RADIANS
//       ARG(2)---SINE OF THE ANGLE
//       ARG(3)---COSINE OF THE ANGLE
//       ARG(4)---TANGENT OF THE ANGLE
//       ARG(5)---TEST VALUE (SET INTERNALLY)
//       Ffunctions used  --- abs,atan2,
//                           cos,sin,
//                           sqrt
//       SINGLE PRECISION --- NO STOPS


void ANGLES(int INTRY,ARG[]){
double ARG[6],C,S,T,A2=0,A1=0,A3=0,A4=0;
int I,j=0,k=1;
int INTRY =6 ;
double CON=1.74532925199433E-2, HPI=1.57079632679489E+0 ,
       OPI=3.14159265358979E+0, TPI=6.28318530717959E+0 ,
       EPS=1.52587890625000E-5, SPE=1.04857600000000E+6 ,
       ZER=0.E+0, ONE=1.E+0 ;
I=abs(INTRY);
if(I==1)goto loop0;
if(I==2)goto loop1;
if(I==3)goto loop2;
if(I==4)goto loop3;
if(I==5)goto loop4;
if(I==6)goto loop5;
loop0: while(I<=6){
                  ARG[I-1]=ZER;
                  I++;}
       ARG[3]=ONE;
     return ;

loop1: A2=ARG[0]*CON;
       j=1 ;
      goto loop3;
loop2: A2=ARG[1];
loop3: A2=(A2+TPI)-((A2+TPI)/TPI)*TPI ;
      if(A2>OPI) A2=A2-TPI ;
      if( abs(A2-ARG[5])<=EPS) return ;
      if( abs(A2)<=EPS) goto loop0;
      ARG[0]=A2/CON;
      ARG[1]=A2;
if(j==1) goto loop4;
if(j==2) goto loop6;

loop4: ARG[2]= sin(A2);
      if(abs(ARG[2])<=EPS) ARG[2]=ZER ;
      ARG[3]= cos(A2);
      if(abs(ARG[3])>EPS) goto loop5 ;
      ARG[3]=ZER ;
      ARG[4]= abs(SPE)*(abs(A2)/A2) ;
      goto loop6 ;
loop5: ARG[4]=ARG[2]/ARG[3] ;
loop6: ARG[5]=A2 ;
return ;

loop7: A3=ARG[2] ;
loop8: if( abs(A3)<=EPS) goto loop0;
      if( abs(A3)>=(ONE-EPS)) goto loop5;
      A4= sqrt(ONE-pow(A3,2)) ;
     if( abs(A4-ARG[3])<=EPS && A3*ARG[2]>=ZER) return ;
      goto loop4;
loop9:  A4=ARG[3] ;
loop10: if( abs(A4)>=(ONE-EPS)) A4= abs(ONE)*(abs(A4)/A4) ;
      A3= sqrt(ONE-pow(A4,2));
      if( abs(A4)<=EPS) goto loop15;
      if( abs(A3-ARG[2])<=EPS && A4*ARG[3]>=ZER) return ;
      goto loop14;
 loop11:  A1=ARG[4];
 loop12:  if( abs(A1)>SPE) A1= abs(SPE)*(abs(A1)/A1);
      A2=A1/ sqrt(ONE+pow(A1,2));
      A3= abs(A2)*(abs(A1)/A1);
      goto loop8;
 loop13:  A3=ARG[2];
      A4=ARG[3];
      A1= sqrt(pow(A3,2)+pow(A4,2));
     if(A1==ZER) goto loop0;
      A3=A3/A1 ;
      A4=A4/A1 ;
 loop14:  if( abs(A4)<=EPS) goto loop15;
      if( abs(A3)<=EPS) A3=ZER ;
      A2= atan2(A3,A4) ;
      ARG[2]=A3 ;
      ARG[3]=A4 ;
      ARG[4]=A3/A4 ;
      j=2 ;
      goto loop3;
 loop15:  A2= abs(HPI)*(abs(A3)/A3);
      ARG[2]= abs(ONE)*(abs(A3)/A3);
      ARG[3]= ZER ;
      ARG[4]= abs(SPE)*(abs(A3)/A3) ;
      j=2 ;
      goto loop3;


}
