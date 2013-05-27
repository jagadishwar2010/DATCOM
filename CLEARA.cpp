#include <iostream>

using namespace std;

    void CLEARA(double IFIG[20][121],int ROUTL,MSSCLL){

//***  CLEAR STORAGE ARRAYS FOR EXTRAPOLATION MESSAGES

      int ROUT ;
      double  PB, AFIG01[121], AFIG02[121], dum1[158]    ;   //IBODY/
      double  PW, AFIG03[121], AFIG04[121], dum13[158]   ;  //IWING/
      double  PHT, AFIG05[121], AFIG06[121], dum3[138]   ;  //IHT/
      double  PVT, AFIG07[121], AFIG08[121], dum4[138]   ;  //IVT/
      double  PVF, AFIG09[121], AFIG10[121], dum17[138]  ;  //IVF/
      double  PBW, AFIG11[121], AFIG12[121], dum5[138]   ;  //IBW/
      double  PBH, AFIG13[121], AFIG14[121], dum6[138]   ;  //IBH/
      double  PBV, JFIG01[121], JFIG02[121], dum7[138]   ;  //IBV/
      double  PBWH, JFIG03[121], JFIG04[121], dum8[138]  ;  //IBWH/
      double  PBWV, JFIG05[121], JFIG06[121], dum9[138]  ;  //IBWV/
      double  PBWHV, JFIG07[121], JFIG08[121], dum12[138] ;    //IBWHV/
      double  JFIG09[121]  ;                              //WINGD/
      double  JFIG10[121], JFIG11[121], JFIG12[121]  ;   //SBETA/
      double  JFIG13[121], JFIG14[121], JFIG15[121], JFIG16[121], JFIG17[121] ;    //BDATA/
      double  JFIG18[121] ;                           //WHWB/
      double  JFIG19[121] ;                           //WBHCAL/
      double  JFIG20[121] ;                           //HTDATA/
      double  LFIGN[121],LFIGO[121],IOVLY,IOVL,NSTQ,NSTP,FINALR,      //VTDATA/
              NFIG,IFIGN   ;
      double  LFIGS[121], IFIGST[20], IEXCD[4], MSSCL[2],ROUT[2], XLL[4], XUL[4], IEXTRL[4][2],
              IEXTRU[4][2], XVAL[4], LDUM[121]   ;               //WHAERO/

      DATA IHBL = 4H ;
      int I = 1 ;
      while(I<=121){
      AFIG01[I-1]=0.0 ;
      AFIG02[I-1]=0.0 ;
      AFIG03[I-1]=0.0 ;
      AFIG04[I-1]=0.0 ;
      AFIG05[I-1]=0.0 ;
      AFIG06[I-1]=0.0 ;
      AFIG07[I-1]=0.0 ;
      AFIG08[I-1]=0.0 ;
      AFIG09[I-1]=0.0 ;
      AFIG10[I-1]=0.0 ;
      AFIG11[I-1]=0.0 ;
      AFIG12[I-1]=0.0 ;
      AFIG13[I-1]=0.0 ;
      AFIG14[I-1]=0.0 ;
      JFIG01[I-1]=0 ;
      JFIG02[I-1]=0 ;
      JFIG03[I-1]=0 ;
      JFIG04[I-1]=0 ;
      JFIG05[I-1]=0 ;
      JFIG06[I-1]=0 ;
      JFIG07[I-1]=0 ;
      JFIG08[I-1]=0 ;
      JFIG09[I-1]=0 ;
      JFIG10[I-1]=0 ;
      JFIG11[I-1]=0 ;
      JFIG12[I-1]=0 ;
      JFIG13[I-1]=0 ;
      JFIG14[I-1]=0 ;
      JFIG15[I-1]=0 ;
      JFIG16[I-1]=0 ;
      JFIG17[I-1]=0 ;
      JFIG18[I-1]=0 ;
      JFIG19[I-1]=0 ;
      JFIG20[I-1]=0 ;
      LFIGN[I-1]=0 ;
      LFIGO[I-1]=0 ;
      LFIGS[I-1]=0 ;
      LDUM[120]=0 ;
      I++ ;
     }
     int J = 1 ;
      while(J<=4){
         IEXCD[I-1]=0 ;
         XLL[I-1]=0.0 ;
         XUL[I-1]=0.0 ;
         IEXTRL[I-1][0]=0 ;
         IEXTRU[I-1][0]=0 ;
         IEXTRL[I-1][1]=0 ;
         IEXTRU[I-1][1]=0 ;
         XVAL[I-1]=0.0 ;
         J++ ;
     }
     int K = 1 ;
      while(K<=2){
         ROUT[I-1]=IHBL ;
         MSSCL[I-1]=IHBL ;
         K++ ;
    }
    int L = 1 ;
     while(L<=20){
         IFIGST[I-1]=IHBL ;
         L++ ;
    }
      IOVLY=999 ;
      IOVL=0 ;
      NSTQ=0 ;
      NSTP=0 ;
      FINALR=0.0 ;
      NFIG=0 ;
      IFIGN=0 ;
      ROUTL=IHBL ;
      MSSCLL=IHBL ;
      while(M<=121){
         while(N<=20){
            IFIG[J-1][I-1]=IHBL ;
           }
      M++ ;
      }
      return ;

