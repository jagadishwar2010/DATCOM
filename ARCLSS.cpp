#include<iostream>
#include<math.h>
using namespace std;
void ARCLSS(A[])
     {
//
//    ----CLASSIFIES ASPECT RATIO
//
      double ROUTID[2];
      double Q3417B[3];
      double X[11],Y[11],C[6],A[195];
      ROUTID[2] = { 4HARCL, 4HSS } ;
      Q3417B[3] = { 4H4.1., 4H3.4-, 4H24B } ;
      X[11] = { 0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9,1.0 } ;
      Y[11] = { 0.0, 0.225, 0.47, 0.496, 0.43, 0.32, 0.21, 0.125, 0.075, 0.0475, 0.0 } ;
      int IN = 0 ;
      int NP = 11 ;
//
//    ----FIGURE 4.1.3.4-24B
//
      TBFUNX(A[27],A[123],DYDX,NP,X,Y,C,IN,MI,NG,0,0,Q3417B,3,ROUTID) ;
      ANGLES(1,A[34]) ;
      A[123]=(A[122]+1.0)*A[36] ;
      A[124]=A[127]/A[123] ;

     }
