#include <iostream>

using namespace std;

      SUBROUTINE COORD4(){

//***** CALCULATE NACA FOUR DIGIT AIRFOIL COORDINATES

      COMMON /IWING/ PW, X(60),dum13(340)
      COMMON / IHT / PHT, XU(60),XL(60), dum3(260)
      COMMON / IVT / PVT, YUN(60),YLN(60), dum4(260)
      COMMON / IBW / PBW,L,I,J,K,II,JJ,KK,III,JJJ, dum5(369)
      COMMON / IBH / PBH, THN(60),CAM(60), dum6(260)
      COMMON /IBWHV/ PBWHV, RHO,T,DELTAY,XOVC,TOVC,ZM,ZP
      AI=I ;
      AJ=J ;
      AK=K ;
      AII=II ;
      AJJ=JJ ;
      AKK=KK ;
      ZM=AI*0.01 ;
      ZP=AJ*0.1 ;
      T=AK*0.1+AII*0.01+AJJ*0.001+AKK*0.0001 ;
      RHO=1.1019*(powT,2) ;
      ine M=1 ;
      while(M<=L){
         YT=5.0*T*(0.2969*sqrt(X[M-1])-0.126*X[M-1]-0.3516*pow(X[M-1],2)+
                   0.2843*pow(X[M-1],3)-0.1015*pow(X[M-1],4)) ;
         if(X[M-1]== ZP)YC=ZM ;
         if(X[M-1]== ZP)ALPHA=0.0 ;
         if(X[M-1] < ZP)YC=(2.0*ZP*X[M-1]-pow(X[M-1],2))*ZM/(ZP,2) ;
         if(X[M-1] < ZP)ALPHA=atan((2.0*ZM/pow(ZP,2))*(ZP-X[M-1])) ;
         if(X[M-1] > ZP)
         YC=(ZM/(pow((1.0-ZP),2)))*(1.0-2.0*ZP+2.0*ZP*X[M-1]-pow(X[M-1],2)) ;
         if(X[M-1] > ZP)ALPHA=atan((2.0*ZM/(pow((1.0-ZP),2)))*((ZP-X[M-1]))) ;
         XU[M-1]=X[M-1]-YT*sin(ALPHA) ;
         YUN[M-1]=YC+YT*cos(ALPHA) ;
         XL[M-1]=X[M-1]+YT*sin(ALPHA) ;
         YLN[M-1]=YC-YT*cos(ALPHA) ;
         CAM[M-1]=YC ;
         if(CAM[M-1] < 1.E-05) CAM[M-1]=0.0 ;
         THN[M-1]=YT ;
     M++ ;
     }
      THN[0]=0.0 ;
      THN[L-1]=0.0 ;
      CAM[0]=0.0 ;
      CAM[L-1]=0.0 ;
      XU[L-]=1.0 ;
      YUN[L-1]=0.0 ;
      XL[L-1]=1.0 ;
      YLN[L-1]=0.0 ;
      XU[0]=0.0 ;
      YLN[0]=0.0 ;
      return ;

      }
