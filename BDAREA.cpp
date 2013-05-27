#include <iostream>
#include <math.h>
using namespace std;

 void BDAREA(bool ABORT) {

     double SAREA,AX,AY,EXTARE,AREAU,AREAUB,SAXUB,SAYUB,AREAL,
            AREALB,SAXLB,SAYLB,AXTB,AYTB,XCB,YCB,XBARB ;

//***  EXECUTIVE FOR BODY PARTS SHADOWED BY MACH LINES


      double A[3],X[4],Y[4],XL[42],YL[42],XLI[42],YLI[42],XT[42],
             YT[42],XTI[42],YTI[42] ;
      double NLOG,NMACH,NALPHA,IG,PI,DEG,UNUSED,RAD, kand, AMUU ;
      double FLC[73],dumflgtcd[87],HTIN[154],XNX,XB[20],SB[20],PB[20],
             RB[20],dum2[48],AHT[195],SYNA[10]  ;

      int ITLI,ILUI,ILLI,ILUIE,ILLIE,ITUI,ITUIE,ITLIE,KIND,II;
      int K=0,J=0,I;

      double NX=XNX ;
      int ILI=0 ;
      int ILIE=0 ;
      int ITI=0 ;
      int ITIE=0 ;
      int SAXB=0 ;
      int SAYB=0 ;
      double AREA=0.0 ;
      double AREAB=0.0 ;

loop1: AMUU=atan(1.0/sqrt(pow(FLC[I+1],2)-1.0)) ;

    while(K<2){

        if(K!=0) goto loop3 ;

loop2:   A[0]=SYNA[5]+(HTIN[3]-HTIN[2])*AHT[61]*cos(SYNA[7]/RAD) ;
         A[1]=SYNA[6]-(A[0]-SYNA[7])*sin(SYNA[7]/RAD)/cos(SYNA[7]/RAD) ;
         A[2]=SYNA[7] ;
         goto loop4 ;
loop3:   A[0]=A[0]+AHT[9]*cos(SYNA[7]/RAD) ;
         A[1]=A[1]-AHT[9]*sin(SYNA[7]/RAD) ;
         goto loop5 ;
loop4:   PTINT2(XB,RB,A,AMUU,XL,YL,XLI,YLI,NX,ILUI,ILLI,ILUIE,ILLIE,ABORT) ;
         if(ABORT) return ;
         goto loop6 ;
loop5:   PTINT2(XB,RB,A,AMUU,XT,YT,XTI,YTI,NX,ITUI,ITLI,ITUIE,ITLIE,ABORT) ;
         if(ABORT) return ;
loop6:    K++;
    }
    while(J<2) {
         SAXB=0.0 ;
         SAYB=0.0 ;
         AREA=0.0 ;
         AREAB=0.0 ;

//     CHECK FOR UPPER OR LOWER AREA

         if(J!=0) goto loop7 ;
         ILI=ILUI ;
         ILIE=ILUIE ;
         ITI=ITUI ;
         ITIE=ITUIE ;
         goto loop8 ;
loop7:   ILI=ILLI ;
         ILIE=ILLIE ;
         ITI=ITLI ;
         ITIE=ITLIE ;
         NX=NX+21 ;
loop8:   if(ITIE!=0) goto loop9 ;

//**** NEITHER MACH LINE INTERSECTS BODY PROFILE EXTENSION ****

         KIND=1 ;
         goto loop11 ;
loop9:   if(ILIE!=0) goto loop10 ;

//**** ONLY THE TRAILING EDGE MACH LINE INTERSECTS BODY PROFILE EXTENSION

         KIND=2 ;
         goto loop11 ;

//**** BOTH MACH LINES INTERSECT BODY PROFILE EXTENSION ****

loop10:  KIND=3 ;
loop11:  if(KIND==1) goto loop12;
         if(KIND==2) goto loop16;
         if(KIND==3) goto loop19;
loop12:  if(ILI!=ITI) goto loop13 ;
         X[0]=0.0 ;
         X[1]=XLI[ILI-1] ;
         X[2]=XTI[ITI-1]+AHT[9] ;
         X[3]=AHT[9] ;
         Y[0]=0.0 ;
         Y[1]=YLI[ILI-1] ;
         Y[2]=YTI[ITI-1] ;
         Y[3]=0.0 ;
         AREA2(X,Y,SAREA,2,AX,AY) ;
         AREA=SAREA ;
         AREAB=AREA ;
         SAXB=AX ;
         SAYB=AY ;
         goto loop20 ;
loop13: II=1 ;
         X[0]=0.0 ;
         X[1]=XLI[ILI-1] ;
         X[2]=XL[ILI+II-1] ;
         X[3]=AHT[9] ;
         Y[0]=0.0 ;
         Y[1]=YLI[ILI-1] ;
         Y[2]=YL[ILI+II-1] ;
         Y[3]=0.0 ;
         AREA2(X,Y,SAREA,2,AX,AY) ;
         AREA=AREA+SAREA ;
         SAXB=SAXB+AX ;
         SAYB=SAYB+AY ;
loop14:  II=II+1 ;
         if(XL[ILI+II-1]>(XTI[ITI-1]+AHT[9])) goto loop15 ;
         X[0]=XL[ILI+II-2] ;
         X[1]=XL[ILI+II-1] ;
         X[2]=AHT[9] ;
         Y[0]=YL[ILI+II-2] ;
         Y[1]=YL[ILI+II-1] ;
         Y[2]=0.0 ;
         AREA2(X,Y,SAREA,3,AX,AY) ;
         AREA=AREA+SAREA ;
         SAXB=SAXB+AX ;
         SAYB=SAYB+AY ;
         goto loop14 ;
loop15:  X[0]=XL[ILI+II-2] ;
         X[1]=XTI[ITI-1]+AHT[9] ;
         X[2]=AHT[9] ;
         Y[0]=YL[ILI+II-2] ;
         Y[1]=YTI[ITI-1] ;
         Y[2]=0.0 ;
         AREA2(X,Y,SAREA,3,AX,AY) ;
         AREA=AREA+SAREA ;
         AREAB=AREA ;
         SAXB=SAXB+AX ;
         SAYB=SAYB+AY ;
         goto loop20 ;
 loop16: II=1 ;
         X[0]=0.0 ;
         X[1]=XLI[ILI-1] ;
         X[2]=XL[ILI+II-1] ;
         X[3]=AHT[9] ;
         Y[0]=0.0 ;
         Y[1]=YLI[ILI-1] ;
         Y[2]=YL[ILI+II-1] ;
         Y[3]=0.0 ;
         AREA2(X,Y,SAREA,2,AX,AY) ;
         AREA=AREA+SAREA ;
         SAXB=SAXB+AX ;
         SAYB=SAYB+AY ;
loop17: if((ILI+II)!=NX) goto loop18 ;
         X[1]=XL[ILI+II] ;
         X[2]=XL[ILI+II+1] ;
         X[3]=AHT[10] ;
         Y[1]=YL[ILI+II] ;
         Y[2]=YL[ILI+II+1] ;
         Y[3]=0.0 ;
         AREA2(X,Y,SAREA,3,AX,AY) ;
         AREA=AREA+SAREA ;
         SAXB=SAXB+AX ;
         SAYB=SAYB+AY ;
         II=II+1 ;
         goto loop17 ;
loop18:  X[0]=XL[ILI+II-1] ;
         X[1]=XTI[ITIE-1]+AHT[9] ;
         X[2]=AHT[9] ;
         Y[0]=YL[ILI+II-1] ;
         Y[1]=YTI[ITIE-1] ;
         Y[2]=0.0 ;
         AREA2(X,Y,SAREA,3,AX,AY) ;
         AREA=AREA+SAREA ;
         SAXB=SAXB+AX ;
         SAYB=SAYB+AY ;
         X[2]=XTI[ITI-1]+AHT[9] ;
         Y[2]=YTI[ITI-1] ;
         AREA2(X,Y,EXTARE,3,AX,AY) ;
         AREAB=AREA-EXTARE ;
         SAXB=SAXB-AX ;
         SAYB=SAYB-AY ;
         goto loop20 ;
loop19:  X[0]=0.0 ;
         X[1]=XLI[ILIE-1] ;
         X[2]=XTI[ITIE-1]+AHT[9] ;
         Y[0]=0.0 ;
         Y[1]=YLI[ILIE-1] ;
         Y[2]=YTI[ITIE-1] ;
         X[3]=AHT[9] ;
         Y[3]=0.0 ;
         AREA2(X,Y,SAREA,2,AX,AY) ;
         AREA=AREA+SAREA ;
         X[1]=XLI[ILI-1] ;
         X[2]=XTI[ITI-1]+AHT[9] ;
         Y[1]=YLI[ILI-1] ;
         Y[2]=YTI[ITI-1] ;
         AREA2(X,Y,SAREA,2,AX,AY) ;
         AREAB=AREAB+SAREA ;
         SAXB=SAXB+AX ;
         SAYB=SAYB+AY ;
loop20:  if(K==1) goto loop21 ;
         AREAU=AREA ;
         AREAUB=AREAB ;
         SAXUB=SAXB ;
         SAYUB=SAYB ;
         goto loop22 ;
loop21:  AREAL=AREA ;
         AREALB=AREAB ;
         SAXLB=SAXB ;
         SAYLB=SAYB ;
loop22:  J++ ;
  }
      HTIN[114+I-1]=AREAUB+AREALB ;;
      HTIN[134+I-1]=AREAU+AREAL ;
      AXTB=SAXUB+SAXLB ;
      AYTB=SAYUB+SAYLB ;
      XCB=AXTB/HTIN[114+I-1] ;
      YCB=AYTB/HTIN[114+I-1] ;
      XBARB=XCB*cos(-SYNA[7]/RAD)-YCB*sin(-SYNA[7]/RAD)+SYNA[5]
            +(HTIN[3]-HTIN[2])*AHT[61]*cos(SYNA[7]/RAD) ;
      HTIN[94+I-1]=XBARB-SYNA[0] ;

}
