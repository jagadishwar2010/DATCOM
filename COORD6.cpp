#include <iostream>
#include <math.h>
using namespace std;

      void COORD6(){

//***** CALCULATE NACA 6-SERIES AIRFOIL COORDINATES

      double PW, X[60],dum13[340] ;  //IWING/
      double PHT, XU[60],XL[60], dum3[260] ; // IHT /
      double PVT, YUN[60],YLN[60], dum4[260] ;  // IVT /
      double PBW,I,J,K,II,JJ,KK,III,JJJ, dum5[369] ; // IBW /
      double PBH, THN[60],CAM[60],dum6[260] ; // IBH /
      double PBWH,ALPHAI,ALPHAO,AJJ ; //IBWH/
      double PBWHV, RHO,T ; //IBWHV/
      double PI,DEG,UNUSED,RAD,kand ; //CONSNT/
      double A[2][3],B[2],XN[2] ;
      double AA[3][4],BA[3],XM[3] ;
      double AI,AJ,AK,AII,AKK,AIII,AJJJ,NN,ZT,SM,R,D1,D0,LL,SLEQ,D2,D3,A0,
      A1,A2,A3,ZA,C,G,H,S,D,YC,ALPHA,YT,NO,SXU,SXL,SYU,SYL,SMU,SML,RLE  ;
      int L=3 ;
      AI=I ;
      AJ=J ;
      AK=K ;
      AII=II ;
      AJJ=JJ ;
      AKK=KK ;
      AIII=III ;
      AJJJ=JJJ ;
      T=AKK*0.1+AIII*0.01 ;
      NN=2 ;
      if(J==3)goto loop1 ;
      if(J==4)goto loop2 ;
      if(J==5)goto loop3 ;
      ZT=0.45 ;
      SM=-1.268 ;
      R=SM*(T-0.06)+0.873 ;
      D1=R*T ;
      goto loop4 ;
 loop1: ZT=0.35 ;
      SM=-0.6116 ;
      R=SM*(T-0.06)+0.46 ;
      D1=R*T ;
      if(II>0)D1=T ;
      goto loop4 ;
 loop2: ZT=0.40 ;
      SM=-0.6888 ;
      R=SM*(T-0.06)+0.523 ;
      D1=R*T ;
      if(II>0)D1=1.04*T ;
      goto loop4 ;
 loop3: ZT=0.4 ;
      SM=-0.8833 ;
      R=SM*(T-0.06)+0.65 ;
      D1=R*T ;
      if(II>0)D1=1.17*T ;
 loop4: D0=0.0 ;
      A[0][0]=-2.0*(1.0-ZT) ;
      A[0][1]=-3.0*(pow((1.0-ZT),2)) ;
      A[1][0]=pow((1.0-ZT),2) ;
      A[1][1]=pow((1.0-ZT),3) ;
      B[0]=D1 ;
      B[1]=T/2.0-D0-D1*(1.0-ZT) ;
      LL=NN+1 ;
      SLEQ(A,XN,B,NN,LL) ;
      D2=XN[0] ;
      D3=XN[1] ;
      RLE=0.01*(68.682*pow(T,2)+0.0182*T+0.0014) ;
      RHO=RLE ;
      A0=sqrt(2.0*RLE) ;
      AA[0][0]=0.0 ;
      AA[0][1]=2.0 ;
      AA[0][2]=6.0*ZT ;
      BA[0]=2.0*D2+6.0*D3*(1.0-ZT)+A0/(4.0*pow(ZT,1.5)) ;
      AA[1][0]=1.0 ;
      AA[1][1]=2.0*ZT ;
      AA[1][2]=3.0*pow(ZT,2) ;
      BA[1]=-A0/(2.0*pow(ZT,0.5)) ;
      AA[2][0]=ZT ;
      AA[2][1]=pow(ZT,2) ;
      AA[2][2]=pow(ZT,3) ;
      BA[2]=-A0*pow(ZT,0.5)+T/2.0 ;
      NN=3 ;
      LL=NN+1 ;
      SLEQ(AA,XM,BA,NN,LL) ;
      A1=XM[0] ;
      A2=XM[1] ;
      A3=XM[2] ;
      ZA=AJJJ*0.1 ;
      if(AJJJ<1.0)ZA=1.0 ;
      if(ZA==1.0)goto loop5 ;
      C=1.0-ZA ;
      G=(-1.0/C)*((pow(ZA,2))*(0.5*log(ZA)-0.25)+0.25) ;
      H=(1.0/C)*((0.5*pow(C,2))*log(C)-0.25*pow(C,2))+G ;
 loop5: AJJ=AJJ*0.1 ;
      LL=L-1 ;
      int M=2 ;
      while(M<=LL){
         if(ZA==1.0)goto loop6 ;
         S=1.0-X[M-1] ;
         D=ZA-X[M-1] ;
      if(D==0.0) D=1.0E-10 ;
         YC=(AJJ/(2.0*PI*(ZA+1.0)))*((1.0/C)*((0.5*pow(D,2))*log(abs(D))
        -(0.5*pow(S,2))*log(S)+0.25*pow(S,2)-0.25*pow(D,2))-X[M-1]*log(X[M-1])+G-X[M-1]*H) ;
         ALPHA=atan((AJJ/(2.0*PI*(1.0+ZA)))*((1.0/C)*(-D*log(abs(D))
               +S*log(S))-log(X[M-1])-1.0-H)) ;
         goto loop7 ;
 loop6:    YC=-(AJJ/(4.0*PI))*((1.0-X[M-1])*log(1.0-X[M-1])+X[M-1]*log(X[M-1])) ;
         ALPHA=atan((-AJJ/(4.0*PI))*(log(X[M-1])-log(1.0-X[M-1]))) ;
 loop7:    if(X[M-1]==ZT)YT=T/2.0 ;
         if(X[M-1]<ZT)YT=A0*pow(X[M-1],0.5)+A1*X[M-1]+A2*pow(X[M-1],2)+A3*pow(X[M-1],3)  ;
         if(X[M-1]>ZT)YT=D0+D1*(1.0-X[M-1])+D2*pow((1.0-X[M-1]),2)+D3*(1.0-pow(X[M-1],3) ) ;
         XU[M-1]=X[M-1]-YT*sin(ALPHA) ;
         YUN[M-1]=YC+YT*cos(ALPHA) ;
         XL[M-1]=X[M-1]+YT*sin(ALPHA) ;
         YLN[M-1]=YC-YT*cos(ALPHA) ;
         if(XU[M-1]>=0.80&&II>0)goto loop9 ;
         NO=1 ;
 loop8:    continue ;
         CAM[M-1]=YC ;
         if(CAM[M-1] < 1.E-05) CAM[M-1]=0.0 ;
         THN[M-1]=YT ;
         goto loop11 ;
 loop9:    if(NO!=1)goto loop10 ;
         SXU=XU[M-1] ;
         SXL=XL[M-1] ;
         SYU=YUN[M-1] ;
         SYL=YLN[M-1] ;
         SMU=-SYU/(1.0-SXU) ;
         SML=-SYL/(1.0-SXL) ;
         NO=2 ;
         goto loop8 ;
 loop10:    XU[M-1]=XU[M-1]-SXU ;
         XL[M-1]=XL[M-1]-SXL ;
         YUN[M-1]=SMU*XU[M-1]+SYU ;
         YLN[M-1]=SML*XL[M-1]+SYL ;
         XU[M-1]=XU[M-1]+SXU ;
         XL[M-1]=XL[M-1]+SXL ;
         goto loop8 ;
 loop11:    M++ ;
       }

      THN[0]=0.0 ;
      THN[L-1]=0.0 ;
      CAM[0]=0.0 ;
      CAM[L-1]=0.0 ;
      XU[L-1]=1.0 ;
      YUN[L-1]=0.0 ;
      XL[L-1]=1.0 ;
      YLN[L-1]=0.0 ;
      XU[0]=0.0 ;
      YLN[0]=0.0 ;
      XL[0]=0.0 ;
      YUN[0]=0.0 ;
      ALPHAI=0.0 ;
      ALPHAO=-RAD*AJJ/(2.0*PI) ;
      if(ZA == 1.0) return ;
      ALPHAI=ALPHAO*H/(ZA+1.0) ;
      ALPHAO=ALPHAO+ALPHAI ;
      return ;

      }
