#include<iostream>
#include<math.h>
#include<cmath>
using namespace std;
      void BODOPT(){

//***  COMPUTES ASYMMETRICAL BODY AERODYNAMICS

      double  A[195], B[48], BD[762], BODY[400], X[20], S[20], P[20],
              R[20], ZU[20], ZL[20], dum2[3],CLALPA[20], CLMAX[20],
              SLOPE[6],FLC[73], dumflgtcd[87], CONST[5],ROUTID[2],
              Q15127[3],Q95MX[3],QKPARB[3],QKVARB[3],QALFR[3] ;


      double  XNX,BNOSE,BTAIL,BLN,BLA,DS,CHRDTP,SSPNOP,SSPNE,SSPN,
              CHRDBP,CHRDR,SAVSI,SAVSO,CHSTAT,SWAFP,TWISTA,SSPNDD,DHDADI,
              DHDADO,TYPE,TOVC,DELTAY,XOVC,CLI,ALPHAI,CMO,LERI,LERO,CAMBER,
              TOVCO,XOVCO,CMOT,CLMAXL,CLAMO,TCEFF,KSHARP,NLOG,NMACH,M,NALPHA,
              IG,SREF,LREF,ROUGFC, XCG,XW,ZW,ALIW,ZCG,XH,ZH,ALIH,XV,VERTUP,
              HINAX,XVF,SCALE,ZV,ZVF,YV,YF,PHIV,PHIF  ;


      bool    PBODY,VERTUP,FLTC,OPTI,BO,WGPL,WGSC,SYNT,HTPL,HTSC,VTPL,VTSC,
              HEAD,PRPOWR,JETPOW,LOASRT,TVTPAN,SUPERS,SUBSON,TRANSN,HYPERS,
              SYMFP,ASYFP,TRIMC,TRIM,DAMP,HYPEF,TRAJET,BUILD,FIRST,DRCONV,PART,
              VFPL,VFSC,CTAB ;


      EQUIVALENCE (PI,CONST(1)), (RAD,CONST(4))
      EQUIVALENCE (UNUSED,CONST(3))

      double LREF ;
      double ROUTID[2],Q15127[3],Q95MX[3],QKPARB[3],QKVARB[3],QALFR[3] ;
      double ALPH[20],CMP[20] ;
      double D[20] ;
      double XE[20],XOLE[20],ZPOLE[20],SE[20],DSEDX[20],YE[20],PE[20] ;
      double CY95[6] ;
      double XBA1[9],YBA1[9],CBA1[6] ;
      double XBA2[9],YBA2[9],CBA2[6] ;
      double X1BA3[5],X2BA3[12],YBA3[60] ;
      double TX95[20],TY95[20] ;
      double XE95[20],YE95[20]PE95[20],SE95[20],DYEDX[20] ;
      double RP[20],RS[20] ;
      double DELA[20] ;
      double X27M[4],X27I[4],C27[6] ;

      ROUTID[2]={4HBODO,4HPT } ;
      Q15127[3]={4H4.1.,4H5.1-,4H27} ;
      Q95MX[3] ={4HFIND,4H .95,4HYMAX} ;
      QKPARB[3]={4H4.2.,4H1.2-,4H36A } ;
      QKVARB[3]={4H4.2.,4H1.2-,4H36B } ;
      QALFR[3] ={4H4.2.,4H1.2-,4H37 } ;
      X27I[4]  ={1.57780,1.67221,1.98509,2.28874} ;
      X27M[4]  ={0.0,1.0,2.0,3.0} ;
      I27 =0 ;
      RP  =20*1.0 ;
      RS  =20*1.0 ;

//---------     FIGURE  BA1   ( KP VS ASPECT RATIO )         ------------

      double XBA1[9]={0.0,0.5,1.0,1.5,2.0,2.5,3.0,3.5,4.0} ;
      double YBA1[9]={0.0,.72,1.33,1.83,2.225,2.575,2.88,3.125,3.37} ;

//---------     FIGURE BA2    ( KV VS ASPECT RATIO )         ------------

      double XBA2[9]={0.0,0.5,1.0,1.5,2.0,2.5,3.0,3.5,4.0} ;
      double YBA2[9]={3.14,3.14,3.15,3.19,3.21,3.626,3.31,3.9,3.47} ;

//---------  FIGURE 4.2.1.2-37

      double X1BA3[5] ={1.,2.,3.,4.,100.} ;
      double X2BA3[12]={0.,1.,2.,3.,4.,5.,6.,7.,8.,9.,10.,100.} ;
      double YBA3[60] ={34.85,31.20,27.55,23.90,20.25,16.60,12.95,11.25,
           10.30,9.75,9.40,0.0,30.65,25.90,21.15,16.40,11.65,9.10,
           7.60,6.70,6.10,5.70,5.50,0.0,26.70,20.00,13.30,9.10,
           7.50,4.90,4.00,3.50,3.10,2.90,2.75,0.0, 22.70,16.00,9.30,
           7.20,5.00,3.95,3.00,2.40,2.05,1.85,1.70,0.0,12*0.} ;

      IY95=0 ;
      IBA1=0 ;
      IBA2=0 ;

//     ------CALCULATE CD0 -------------

      NX=XNX+0.5 ;
      BD[0]=X[NX-1] ;
      BD[56]=S[NX-1] ;
      GETMAX(X,S,NX,BD[2],BD[3],IMAX) ;
      BD[55]=BD[3] ;

//*****ADJUST BASE AREA IF BODY IS BOAT TAILED ********

      if(BD(56)<=0.3*BD[55]) BD[56]=0.30*BD[55] ;
      BD[54]=12.0*BD[0]/ROUGFC ;

//     ------FIGURE 4.1.5.1-27-----------

      TBFUNX(B[1],CEPT,DYDX,4,X27M,X27I,C27,I27,MI,NG,0,0,Q15127,3,ROUTID) ;
      BD[90]=pow(BD[54],1.0482)*pow(10.0,CEPT) ;
      BD[89]=FLC[M+41]*BD[0] ;
      RUSE=BD[89] ;
      if(BD[90]<BD[89])RUSE=BD[90] ;

//     ------FIGURE 4.1.5.1-26-----------

      FIG26(RUSE,B[1],BD[92]) ;

//     ------CALCULATE SS=PIN -----------

      EQSPCE(X,R,P,S,NX,XE,YE,PE,SE,20,DSEDX) ;
      TRAPZ (PE,20,XE,PIN,1) ;
      BD[92]=PIN ;
      BD[85]=sqrt(BD[56]*4.0/PI) ;
      BD[84]=sqrt(BD[55]*4.0/PI) ;
      BD[74]=BD[0]/BD[84] ;
      BD[58]=BD[91]*[1.0+60.0/(BD[74]**3)+0.0025*BD[74])*BD[92]/BD[55] ;
      BD[59]=0.029*((BD[85]/BD[84])**3/sqrt(BD[58])*BD[55]/SREF) ;
      BD[58]=BD[58]*BD[55]/SREF ;
      BD[60]=BD[58]+BD[59] ;
      BD[9]=BD[60] ;

//---------     COMPUTE SLOPE OF LINE CONNECTING END MIDPOINTS    -------

      N=1 ;
      Z0= 0.5*(ZU[N-1]+ZL[N-1]);
      N=NX ;
      ZNX= 0.5*(ZU[N-1]+ZL[N-1]) ;
      DZDX= (ZNX-Z0)/(X[N-1]-X[0]) ;
loop1: TEMPD=atan(DZDX)*RAD ;

      while(N<=NX){

//---------     COMPUTE BODY DEPTH ARRAY, D                       -------

         D[N-1]= ZU[N-1]-ZL[N-1] ;
         if(D[N-1]==0.0 && N!=0)D[N-1]=UNUSED ;

//---------     COMPUTE LOCUS OF BODY MIDPOINTS (Z-PRIME ARRAY ) --------

 loop2:  BD[N+739]=ZL[N-1]+ 0.5*D[N-1] - (X[N-1]*DZDX + Z0 ) ;

//---------     COMPUTE Z-PRIME OVER REFERENCE LENGTH (ZPOL-ARRAY ) -----

 loop3:  BD[N+719]=BD[N+739]/X(NX) ;

//---------     COMPUTE (X)N OVER REFERENCE LENGTH   ( XOL-ARRAY ) ------

 loop4:  BD[N+699]=X[N-1]/X[NX-1] ;
         N++;
         }

//---------     COMPUTE (X)CG/L,  XOVLCG

         XOVLCG= XCG/X[NX-1] ;

//---------     EQUAL SPACE X,XOL,ZPOL, AND S                ------------

         EQSPCE (X,BD[701],BD[721],S,NX,XE,XOLE,ZPOLE,SE,20,DSEDX) ;

//---------     COMPUTE NEW ARRAYS OF VALUES TO BE INTEGRATED     -------

     while(L<=20){ DO 1080 L=1,20 ;
         if(L>1) goto loop5 ;
         ALPH[L-1]=0.0 ;
         CMP[L-1]=0.0 ;
         goto loop7 ;
 loop5:  continue ;
         if(L<20) goto loop6 ;
         ALPH(L-1)=0.0 ;
         CMP(L-1)=0.0 ;
         goto loop7 ;
 loop6:  continue ;
         ALPH[L-1] = ZPOLE[L-1]/((1.0-XOLE[L-1])*sqrt(XOLE[L-1]-pow(XOLE[L-1],2))) ;
         CMP[L-1]= ZPOLE[L-1]*((1.0-2.0*XOLE[L-1])/sqrt(XOLE[L-1]-(XOLE[L-1],2))) ;
 loop7:  L++;
         }

//---------     COMPUTE ALPHA-ZERO                      -----------------

      TRAPZ(ALPH,19,XOLE,ALZERO,1) ;
 loop8: ALPHZR=-ALZERO/PI ;
 loop9: ALPHZD=ALPHZR*RAD ;
      BD[80]=ALPHZD ;

//---------     COMPUTE TOTAL BODY PLANFORM AREA, SP              -------

 loop10:  EQSPCE(X,R,BD[701],S,NX,XE,YE,XOLE,SE,20,DSEDX) ;
       TRAPZ(YE,20,XE,SP,1) ;
 loop11: SP = 2.0 * SP ;

//---------     COMPUTE CM-ZERO                              ------------

      TRAPZ(CMP,20,XOLE,CMZP,1) ;
 loop12: CM0=2.0*CMZP*(SP/SREF)*(X[NX-1]/LREF) ;
      BD[61]=CM0 ;

//---------     COMPUTE ASPECT RATIO FOR BODY ALONE, ARB     ------------
//             FIND Y-MAX OF PLANFORM VIEW

      GETMAX(X,R,NX,XMAX,YMAX,IMAX) ;
 loop13: ARB= (4.0*YMAX*YMAX)/SP ;

//     -------    LOCATE BODY STATION OF .96 YMAX  ------

 loop14: Y95=0.96*YMAX ;
      IM=IMAX-1 ;
      X95=X[IM-1]+(X[IMAX-1]-X[IM-1])*(Y95-R[IM-1])/(R[IMAX-1]-R[IM-1]) ;

//---------     FIGURE BA-1 ( KP VS ARB )                    ------------

      TBFUNX(ARB,AKP,DKPDAR,9,XBA1,YBA1,CBA1,IBA1,MI,NG,0,2,QKPARB,3,ROUTID) ;

//---------     FIGURE BA-2 (KV VS ARB )                     ------------

 loop15: TBFUNX(ARB,AKV,DKVDAR,9,XBA2,YBA2,CBA2,IBA2,MI,NG,0,2,QKVARB,3,ROUTID) ;

//---------     FIND SMAX, XSMAX, AND NMAX AT DSDX= ZERO          -------

      SMAX=S[NX-1] ;
      DEFF=sqrt(4.0*SMAX/PI) ;
      if(DEFF==0.0) goto loop18 ;

//---------     COMPUTE FINENESS RATIO, FR                   ------------

 loop16: FR= X[NX-1]/DEFF ;

//---------     FIND DEPTH AND WIDTH AT SMAX                 ------------

      YSMAX=R[NX-1] ;
      DSMAX=D[NX-1] ;
 loop17: RATIO= 2.0*YSMAX/DSMAX ;
      goto loop19 ;
 loop18: RATIO=3.0 ;
      FR=10.0 ;
 loop19: continue ;

//     -------    COMPUTE PLANFORM AREA FOR BODY LENGTH X95 AT .96YMAX --
//    -------    FIND INDEX OF LOCATION OF .96XMAX

     while(I<=NX) {
         TX95[I-1]= X[I-1] ;
         TY95[I-1]= R[I-1] ;
         if(X95>X[I]) goto loop20 ;
         N95= I ;
         TX95[I-1]= X95 ;
         TY95[I-1]= Y95 ;
         goto loop21 ;
 loop20:    I++ ;
         }
 loop21: continue ;

//---------     EQUAL SPACE X AND Y ARRAYS FROM X(1) TO X95       -------

      EQSPCE(TX95,TY95,RP,RS,N95,XE95,YE95,PE95,SE95,20,DYEDX) ;

//---------     COMPUTE PLANFORM AREA FOR BODY LENGTH X95         -------

 loop22: TRAPZ(YE95,20,XE95,A95,1) ;
 loop23: A95MAX=2.0*A95 ;

//---------     FIGURE BA-3 ( ALPHV VS FR FOR SEVERAL A/B )       -------

      TLINEX(X1BA3,X2BA3,YBA3,5,12,RATIO,FR,ALPHV,2,2,2,2,QALFR,3,ROUTID) ;

//---------     COMPUTE EXPONENT FOR (X/L) CNP CALCULATIONS       -------

 loop24: EXPON= (2.0*Y95*X95)/A95MAX-1.00 ;

//---------     COMPUTE ( X/L )CNP,  XOLCNP                       -------

      XOLCNP= 2.0*EXPON/(2.0*EXPON+1.0) ;

//---------     COMPUTE   DELTA(X)/L , DELXOL                     -------

      DELXOL= XOVLCG-XOLCNP*(X95  /X(NX)) ;

//              COMPUTE AREA ARRAY, DELA

      TRAPZ(YE,20,XE,DELA,0) ;
      while(J<=19){
 loop25: DELA[J-1]= DELA[J]-DELA[J-1] ;
       }
      SUM=0.0 ;

//---------     COMPUTE PLANFORM AREA MOMENT OF BODY, SUM         -------

      while(NUM<=19){
 loop26: SUM = SUM + 2.0*DELA[NUM-1] * (XE[NUM-1]+(XE[NUM]-XE[NUM-1])/2.0) ;
        }

//---------     COMPUTE (X/L).CA.,  XOVLCA                        -------

      XOVLCA= (SUM/SP)/X[NX-1] ;

//********           ALPHA LOOP

      BD[93]=FLC[1] ;
      NALPHA=BD[93]+0.5 ;
      J=1 ;
      while(J<=NALPHA){

//     ---------     REVISED ANGLE-OF-ATTACK  (29 MARCH 71 )

 loop27:    ANGD= FLC[J+21] - ALPHZD ;
         ANGR= ANGD/RAD ;
         SA= sin[ANGR-1] ;
         CA= cos[ANGR] ;

//---------     COMPUTE (CNP)J,   BD(680+J)                       -------

         BD[J+679]=AKP*SA*CA ;

//---------     COMPUTE (CNV)J,   BD(660+J)                       -------

         BD[J+659]=AKV*pow((sin((FLC[J+21]-ALPHV)/RAD)),2) ;
         if(FLC[J+21]<=ALPHV) BD[J+659]=0.0 ;

//---------     COMPUTE (CNTOT)J   BODY(J+40)                     -------

 loop28:    BODY[J+59]=(BD[J+679]+BD[J+659])*(SP/SREF) ;

//-----------------COMPUTE (CD)J -----------------------

         BODY[J-1]=BODY[J+59]*SA + BD[9] ;

//---------     COMPUTE  (CM)CNP ,   BD(234+J)                    -------

         BD[J+233]= BD[J+679]*(DELXOL)*(SP/SREF)*(X[NX-1]/LREF) ;

//---------     COMPUTE (CM) CNV     BD(114+J)                    -------

         BD[J+113]= BD[J+659]*(XOVLCG-XOVLCA)*(SP/SREF)*(X[NX-1]/LREF) ;

//---------     COMPUTE (CM)J,  BODY(40+J)                        -------

         BODY[J+39]= CM0 + BD[J+233] + BD[J+113] ;

//     ------CALCULATE CL AND CA --------

         BODY[J+19]=(BODY[J+59]-BODY[J-1]*sin(FLC[J+21]/RAD))/cos
                     (FLC[J+21]/RAD) ;
         BODY[J+79]=BODY[J]*cos(FLC[J+21]/RAD)-BODY[J+19]*sin(FLC[J+21]/
                    RAD) ;
         B[J+21]=FLC[J+21]+ALIW ;
         BD[J+213]=BODY[J+59]*SA ;
 loop29:   J++ ;
        }
      BODY[120]=AKP*DELXOL*(SP/SREF)*(X[NX-1]/LREF)/RAD ;
      BODY[100]=(AKP*SP)/(RAD*SREF) ;

      }
