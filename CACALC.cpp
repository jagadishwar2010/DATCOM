#include <iostream>

using namespace std;

      void CACALC(double B[1],double WING[1]){

//***  COMPUTES WING CN,CA


      double PI,DR,UNUSED,RAD,kand ;
      double NLOG,NMACH,I,NALPHA ;
      int M=1 ;
      while(M<=NALPHA){

//*********     REVISED EQUATION FOR (CN)WING AND (CA)WING
//             COMPUTE SIN(ALPHA) AND COS(ALPHA)

         CA= cos(B[M+21]/RAD) ;
         SA= sin(B[M+21]/RAD) ;

//***     COMPUTE REVISED (CN)WING AND STORE IN WING(M+60)

         WING[M+59]= WING[M+19]*CA + WING[M-1]*SA ;

//***     COMPUTE (CA) WING AND STORE IN WING(M+80)

         WING[M+79]= WING[M-1]*CA - WING[M+19]*SA ;
         M++ ;
    }

}
