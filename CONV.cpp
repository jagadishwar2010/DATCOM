#include <iostream>

using namespace std;
      SUBROUTINE CONV(IDIM,SCALE){

//***  THIS SUBROUTINE PERFORMES THREE FUNCTIONS
//***     1. CONVERTS INPUT DIMENSIONS TO FT-LB-SEC SYSTEM
//***     2. SCALES DATA
//***     3. SHIFTS COORDINATE SYSTEM TO X = 0 AT BODY NOSE

      COMMON /FLGTCD/ FLC(42), RN(20), NGH, GRDH(10), PINF(20), FLC1(3),&
     &                ALT(20), TINF(20), VINF(20), WT, dumflgtcd(3)
      COMMON /OPTION/ SREF, CBARR, ROUGFC, BLREF
      COMMON /SYNTSS/ SYNA(19)
      COMMON /BODYI/  XNX, X(20), S(20), P(20), R(20), ZU(20),          &
     &                ZL(20), BTY(2), BL(3), dum2(3)
      COMMON /WINGI/  WGIN(101)
      COMMON /HTI/    HTIN(154)
      COMMON /VTI/    VTIN(154), TVTIN(8), VFIN(154)
      COMMON /POWER/  PWIN(29), LBIN(21)
      COMMON /FLAPIN/ F(138)

      COMMON /BDATA/  BD(762)
      COMMON /CONSNT/ PI, DEG, UNUSED, RAD,kand
      COMMON /FLOLOG/ FLTC,OPTI,BO,WGPL,WGSC,SYNT,HTPL,HTSC,VTPL,VTSC,
                     HEAD,PRPOWR,JETPOW,LOASRT,TVTPAN,SUPERS,SUBSON,
                     TRANSN,HYPERS,SYMFP,ASYFP,TRIMC,TRIM,DAMP,
                     HYPEF,TRAJET,BUILD,FIRST,DRCONV,PART,
                     VFPL,VFSC,CTAB ;

      REAL LBIN
      bool  FLTC,OPTI,BO,WGPL,WGSC,SYNT,HTPL,HTSC,VTPL,VTSC,
            HEAD,PRPOWR,JETPOW,LOASRT,TVTPAN,SUPERS,SUBSON,
            TRANSN,HYPERS,SYMFP,ASYFP,TRIMC,TRIM,DAMP,
            HYPEF,TRAJET,BUILD,FIRST,DRCONV,PART,
            VFPL,VFSC,CTAB  ;

      EQUIVALENCE (BD(11),X0)

      DIMENSION IDIMT(8)
      DATA IDIMT / 4HF   ,4HT   ,4HI   ,4HN   ,                         &
     &             4HM   ,4H    ,4HC   ,4HM   /


//***  SET CONVERSION FACTORS

      XL = 1.0 ;
      XA = 1.0 ;
      XR = 1.0 ;
      XP = 1.0 ;
      XT = 1.0 ;
      XW = 1.0 ;
      XF = 1.0 ;
      if(IDIM != 2) goto 1000 ;
        XL = 12.0 ;
        XA = 144.0 ;
        XP = 144.0 ;
 1000 continue ;
      if(IDIM < 3) goto 1010 ;
        XL = 0.3048 ;
        XA = 0.09290304 ;
        XR = 0.3048 ;
        XP = 0.0208854 ;
        XT = 1.8 ;
        XW = 0.2248089 ;
        XF = 2.54 ;
 1010 continue ;
      if(IDIM != 4) goto 1020 ;
        XL = 30.48 ;
        XA = 929.0304 ;
        XP = 208.854 ;
 1020 continue ;
      ASCALE = pow(SCALE,2) ;

//***  INPUT UNITS CONVERSION AND SCALING

      if((IDIM == 1) && (SCALE == 1.0)) goto 1160 ;
      int I=1 ;
        while(I<=20){
          if(RN[I-1]   != UNUSED) RN[I-1]   = RN[I-1]*XR ;
          if(ALT[I-1]  != UNUSED) ALT[I-1]  = ALT[I-1]/XL ;
          if(PINF[I-1] != UNUSED) PINF[I-1] = PINF[I-1]*XP ;
          if(TINF[I-1] != UNUSED) TINF[I-1] = TINF[I-1]*XT ;
          if(VINF[I-1] != UNUSED) VINF[I-1] = VINF[I-1]/XL ;
          if(I <= 10 && GRDH[I-1] != UNUSED) GRDH[I-1] = GRDH[I-1]/XL ;
        I++ ; }
        if(WT != UNUSED) WT = WT*XW ;

        if(ROUGFC != UNUSED) ROUGFC = ROUGFC/XF ;
        if(SREF   != UNUSED) SREF   = SREF*ASCALE/XA ;
        if(CBARR  != UNUSED) CBARR  = CBARR*SCALE/XL ;
        if(BLREF  != UNUSED) BLREF  = BLREF*SCALE/XL ;

I=1 ;
        while(I<=19){
          if(I == 4 ) goto 1040 ;
          if(I == 8 ) goto 1040 ;
          if(I == 10) goto 1040 ;
          if(I == 13) goto 1040 ;
          if(I == 18) goto 1040 ;
          if(I == 19) goto 1040 ;
          if(SYNA[I-1] == UNUSED) goto 1040 ;
            SYNA[I-1] = SYNA[I-1]*SCALE/XL ;
 1040   I++ ;
        }
        if(BD[32] != UNUSED) BD[32)]= BD[32]*SCALE/XL ;
        if(BD[64] != UNUSED) BD[64] = BD[64]*SCALE/XL ;
        if(BD[73] != UNUSED) BD[73] = BD[73]*SCALE/XL ;
        if(BD[81] != UNUSED) BD[81] = BD[81]*SCALE/XL ;

I=1 ;
        while(I<=20){
          if(X[I-1]  != UNUSED) X[I-1]  = X[I-1]*SCALE/XL ;
          if(S[I-1]  != UNUSED) S[I-1]  = S[I-1]*ASCALE/XA ;
          if(P[I-1]  != UNUSED) P[I-1]  = P[I-1]*SCALE/XL ;
          if(R[I-1]  != UNUSED) R[I-1]  = R[I-1]*SCALE/XL ;
          if(ZU[I-1] != UNUSED) ZU[I-1] = ZU[I-1]*SCALE/XL ;
          if(ZL[I-1] != UNUSED) ZL[I-1] = ZL[I-1]*SCALE/XL ;
          if((I <= 3) && (BL[I-1] != UNUSED))
                              BL[I-1] = BL[I-1]*SCALE/XL ;
       I++ ;
       }
 I=1 ;
        while(I<=6){DO 1060 I=1,6
          if(WGIN[I-1] != UNUSED) WGIN[I-1] = WGIN[I-1]*SCALE/XL ;
          if(HTIN[I-1] != UNUSED) HTIN[I-1] = HTIN[I-1]*SCALE/XL ;
          if(VTIN[I-1] != UNUSED) VTIN[I-1] = VTIN[I-1]*SCALE/XL ;
          if(VFIN[I-1] != UNUSED) VFIN[I-1] = VFIN[I-1]*SCALE/XL ;
        I++ ;
        }
        if(WGIN[11] != UNUSED) WGIN[11] = WGIN[11]*SCALE/XL ;
        if(HTIN[11] != UNUSED) HTIN[11] = HTIN[11]*SCALE/XL ;
        if(VTIN[11] != UNUSED) VTIN[11] = VTIN[11]*SCALE/XL ;
        if(VFIN[11] != UNUSED) VFIN[11] = VFIN[11]*SCALE/XL ;
        I=95 ;
        while(I<=154){
          if(VTIN[I-1] != UNUSED) VTIN[I-1] = VTIN[I-1]*ASCALE/XA ;
          if(VFIN[I-1] != UNUSED) VFIN[I-1] = VFIN[I-1]*ASCALE/XA ;
          if((I >= 115) && (HTIN[I-1] != UNUSED))
                                 HTIN[I-1] = HTIN[I-1]*ASCALE/XA  ;
          if((I <= 114) && (HTIN[I-1] != UNUSED))
                                 HTIN[I-1] = HTIN[I-1]*SCALE/XL   ;
          I++ ;
          }

        if(PWIN[3]  != UNUSED) PWIN[3]  = PWIN[3]*SCALE/XL ;
        if(PWIN[4]  != UNUSED) PWIN[4]  = PWIN[4]*SCALE/XL  ;
        if(PWIN[5]  != UNUSED) PWIN[5]  = PWIN[5]*SCALE/XL ;
        if(PWIN[7]  != UNUSED) PWIN[7]  = PWIN[7]*SCALE/XL ;
        if(PWIN[8]  != UNUSED) PWIN[8]  = PWIN[8]*SCALE/XL ;
        if(PWIN[9]  != UNUSED) PWIN[9]  = PWIN[9]*SCALE/XL ;
        if(PWIN[15] != UNUSED) PWIN[15] = PWIN[15]*SCALE/XL ;
        if(PWIN[16] != UNUSED) PWIN[16] = PWIN[16]*SCALE/XL ;
        if(PWIN[17] != UNUSED) PWIN[17] = PWIN[17]*SCALE/XL ;
        if(PWIN[18] != UNUSED) PWIN[18] = PWIN[18]*ASCALE/XA ;
        if(PWIN[20] != UNUSED) PWIN[20] = PWIN[20]/XL ;
        if(PWIN[21] != UNUSED) PWIN[21] = PWIN[21]*XT ;
        if(PWIN[22] != UNUSED) PWIN[22] = PWIN[22]*XT ;
        if(PWIN[23] != UNUSED) PWIN[23] = PWIN[23]*SCALE/XL ;
        if(PWIN[24] != UNUSED) PWIN[24] = PWIN[24]*XP ;
        if(PWIN[25] != UNUSED) PWIN[25] = PWIN[25]*XP ;
        if(PWIN[26] != UNUSED) PWIN[26] = PWIN[26]*SCALE/XL ;
        if(PWIN[27] != UNUSED) PWIN[27] = PWIN[27]*SCALE/XL ;

 I=1 ;
        while(I<=4){
          if(TVTIN[I-1] != UNUSED) TVTIN[I-1] = TVTIN[I-1]*SCALE/XL ;
        I++ ;
        }
        if(TVTIN[4] != UNUSED) TVTIN[4] = TVTIN[4]*ASCALE/XA ;
        if(TVTIN[6] != UNUSED) TVTIN[6] = TVTIN[6]*SCALE/XL ;
        if(TVTIN[7] !=. UNUSED) TVTIN[7] = TVTIN[7]*SCALE/XL ;

        if(.NOT. SYMFP) goto 1100 ;

        I=12 ;
          while(I<=125){
            if((I >= 16)  && (I <=. 38))  goto 1090 ;
            if((I >= 61)  && (I <= 84))  goto 1090 ;
            if((I >= 105) && (I <= 114)) goto 1090 ;
            if( I >= 117)  goto 1090 ;
            if(F[I-1] != UNUSED) F[I-1] = F[I-1]*SCALE/XL ;
         I++ ;
         }
          if(F[132] != UNUSED) F[132] = F[132]*XL ;
          if(F[133] != UNUSED) F[133] = F[133]*XL ;
          if(F[134] != UNUSED) F[134] = F[134]*XP ;
 1100   continue ;
        IF(.NOT. ASYFP) goto 1120 ;
I=12 ;
          while(I<=15){
            if(F[I-1] != UNUSED) F[I-1] = F[I-1]*SCALE/XL ;
          I++ ;
          }
 1120   continue ;
        if(.NOT. TRAJET) goto 1140 ;
I=12 ;
          while(I<=21){
            if(F[I-1] != UNUSED) F[I-1] = F[I-1]*XW ;
         I++ ;
         }
          if(F[33] != UNUSED) F[33] = F[33]/XL ;
          if(F[37] != UNUSED) F[37] = F[37]/XL ;
 1140   continue ;
        if(.NOT. HYPEF) goto 1150 ;
          if(F[0] != UNUSED) F[0] = F[0]/XL ;
          if(F[1] != UNUSED) F[1] = F[1]/XL ;
          if(F[3] != UNUSED) F[3] = F[3]/XL ;
 1150   continue ;

        if(LBIN[1]  != UNUSED)  LBIN[1]  = LBIN[1]/XA ;
        if(LBIN[3]  !=  UNUSED) LBIN[3]  = LBIN[3]/XA ;
        if(LBIN[8]  !=  UNUSED) LBIN[8]  = LBIN[8]/XA ;
        if(LBIN[10] !=  UNUSED) LBIN[10] = LBIN[10]/XA ;
        if(LBIN[17] !=  UNUSED) LBIN[17] = LBIN[17]/XA ;
        if(LBIN[18] !=  UNUSED) LBIN[18] = LBIN[18]/XA ;
        if(LBIN[0]  !=  UNUSED) LBIN[0]  = LBIN[0]/XL ;
        if(LBIN[7]  !=  UNUSED) LBIN[7]  = LBIN[7]/XL ;
        if(LBIN[9] !=  UNUSED)  LBIN[9]  = LBIN[9]/XL ;
        if(LBIN[11] !=  UNUSED) LBIN[11] = LBIN[11]/XL ;
        if(LBIN[12] !=  UNUSED) LBIN[12] = LBIN[12]/XL ;
        if(LBIN[14] !=  UNUSED) LBIN[14] = LBIN[14]/XL ;
        if(LBIN[19] !=  UNUSED) LBIN[19] = LBIN[19]/XL ;
        if(LBIN[20] !=  UNUSED) LBIN[20] = LBIN[20]/XL ;
 1160 continue ;

//***  SET NOSE LOCATION

      X0 = X[0] ;
      if(abs(X0) <= UNUSED) goto 1180 ;
        NX = XNX+0.5 ;
I=1 ;
        while(I<=NX){
          X(I-1) = X(I-1)-X0 ;
        I++ ;
        }
        SYNA[0]  = SYNA[0] -X0 ;
        SYNA[1]  = SYNA[1] -X0 ;
        SYNA[5]  = SYNA[5] -X0 ;
        SYNA[8]  = SYNA[8] -X0 ;
        if(SYNA[10] != UNUSED) SYNA[10] = SYNA[10]-X0 ;
        if(SYNA[11] != UNUSED) SYNA[11] = SYNA[11]-X0 ;
        PWIN[3]  = PWIN[3] -X0 ;
        PWIN[15] = PWIN[15]-X0 ;
        PWIN[17] = PWIN[17]-X0 ;
        BD[32]   = BD[32]  -X0 ;
        BD[64]   = BD[64]  -X0 ;
 1180 continue ;
      I1 = 1+2*(IDIM-1) ;
      I2 = I1+1 ;
      WRITE(6,1190) (IDIMT(I),I=I1,I2), SCALE ;
      return ;
 1190 FORMAT(1H0,25H INPUT DIMENSIONS ARE IN ,2A1,18H, SCALE FACTOR IS ,F6.4/)
      }
