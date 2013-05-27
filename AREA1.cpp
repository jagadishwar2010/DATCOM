 #include<iostream>
#include<math.h>
using namespace std;
void AREA1(X,Y,AREA,NSUM){
//
//***  CALCULATES INCREMEMTAL AREA OF VERTICAL TAIL SHADOWED BY MACH LINE
//
      double X[4],Y[4];
      AREA2=0.0;
      A=sqrt(pow((X[1]-X[0]),2)+pow((Y[1]-Y[0]),2)) ;
      B=sqrt(pow((X[2]-X[1]),2)+pow((Y[2]-Y[1]),2)) ;
      C=sqrt(pow((X[0]-X[2]),2)+pow((Y[0]-Y[2]),2)) ;
      S=(A+B+C)/2.0 ;
      AREA=sqrt(S*(S-A)*(S-B)*(S-C)) ;
      IF(NSUM!=4 && NSUM!=6) goto loop ;
      A2=sqrt(pow((X[3]-X[2]),2)+pow((Y[3]-Y[2]),2)) ;
      B2=sqrt(pow((X[0]-X[3]),2)+pow((Y[0]-Y[3]),2)) ;
      S2=(A2+B2+C)/2.0 ;
      AREA2=sqrt(S2*(S2-A2)*(S2-B2)*(S2-C)) ;
loop: AREA=AREA+AREA2 ;

      }
