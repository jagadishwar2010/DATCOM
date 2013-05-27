      void ASMINT(NPT,X,Y,NVAL,XVAL,YVAL){
//
//***  NON-LINEAR INTERPOLATION ROUTINE FOR AIRFOIL MODULE
//
      int RP ;
      double X[1],Y[1],XVAL[1],YVAL[1],YP[2] ;
//
//  METHOD - SLOPES ARE DEFINED AT EACH DATA POINT AS A VALUE HALF WAY
//           BETWEEN THE LINEAR SLOPES TO THE RIGHT AND LEFT OF THE
//           POINT. A THIRD ORDER POLYNOMIAL IS DETERMINED FOR EACH
//           INTERVAL BETWEEN DATA POINTS BY USING THE TWO END POINTS
//           AND TWO END POINT SLOPES. SECOND ORDER POLYNOMIALS ARE
//           DETERMINED FOR THE LEFT AND RIGHT END INTERVALS (AND FOR
//           LEFT AND RIGHT EXTRAPOLATION) USING THE TWO END POINTS
//           AT EACH END OF THE DATA AND THE SLOPES AT THE NEXT-TO-THE
//           LAST DATA POINTS AT EACH END OF THE DATA. HENCE, THE OVER-
//           ALL CURVE CONSISTS OF A LEFT END PARABOLA JOINED TO A
//           SERIES OF JOINED CUBIC CURVES FINALLY JOINED TO A RIGHT
//           END PARABOLA. THE OVERALL CURVE IS CONTINUOUS EVERYWHERE,
//           HAS CONTINUOUS DERIVATIVES EVERYWHERE, AND CAN BE EXTRAP-
//           OLATED TO THE RIGHT AND LEFT INDEFINITELY.
//
//  NPT      NUMBER OF POINTS IN X AND Y ARRAYS
//  X        ABSCISSAS OF INPUT DATA
//  Y        ORDINATES OF INPUT DATA
//
//  NVAL     NUMBER OF POINTS TO BE INTERPOLATED
//  XVAL     ABSCISSA VALUES AT WHICH INTERPOLATION TO BE PERFORMED
//  YVAL     INTERPOLATED ORDINATE VALUES
//
      NP1= NPT-1 ;
      NP2= NPT-2 ;
      int I = 0,J=1,N=0;
      while(I<NVAL) {
         if(XVAL[I]<X[1]) goto loop3 ;
         if(XVAL[I]>X[NP1-1]) goto loop4 ;
            while(J<NP2){
            if(XVAL[I-1]!=X[J-1]) goto loop1 ;
            YVAL[I-1]= Y[J-1] ;
            goto  loop9 ;
 loop1:      K= J+1 ;
            if(XVAL[I-1]>=X[K-1])goto loop2 ;
            LOCATE= 2 ;
            goto loop5 ;
 loop2:       j++;
            }
         YVAL[I-1]= Y[K-1] ;
        goto loop9 ;
 loop3:    J=2 ;
         K=3 ;
         LOCATE= 1 ;
         goto loop5 ;
 loop4:   J=NP1 ;
         K=NPT ;
         LOCATE= 3 ;
         goto loop5 ;
 loop5:    while(N<2) {
            LP= J+N-2 ;
            MP= J+N-1 ;
            RP= K+N-1 ;
            SL= (Y[LP-1]-Y[MP-1])/(X[LP-1]-X[MP-1]) ;
            SR= (Y[MP-1]-Y[RP-1])/(X[MP-1]-X[RP-1]) ;
            ANGL= atan(SL) ;
            ANGR= atan(SR) ;
            ANGAV=(ANGL+ANGR)/2.0 ;
            YP[N-1]= sin(ANGAV)/cos(ANGAV) ;
            if(LOCATE==1) goto loop8 ;
            if(LOCATE==2) goto loop6 ;
            if(LOCATE==3) goto loop8
                ;
 loop6:      N++ ;
            }

         X1S = X[J-1]*X[J-1] ;
         X2S = X[K-1]*X[K-1] ;
         X12F = X[J-1]-X[K-1] ;
         Y12F = Y[J-1]-Y[K-1] ;
         X12S = X1S-X2S ;
         X12C = X1S*X[J-1]-X2S*X[K-1] ;
         Y12P = YP[0]-YP[1] ;

         TW = 2.0 ;
         TH = 3.0 ;
         RED = TW*X[K-1]*X12F - X12S ;
         GRN = TH*X2S*X12F - X12C ;
         YEL = YP[1]*X12F-Y12F ;
         E = TH*X12S*RED - TW*X12F*GRN ;
         A = Y12P*RED - TW*X12F*YEL ;
         A = A/E ;
         B = TH*X12S*YEL - Y12P*GRN ;
         B = B/E ;
         C = (Y12F-A*X12C-B*X12S)/X12F ;
         D = Y[K-1]-A*X2S*X[K]-B*X2S-C*X[K-1] ;

 loop7:    YVAL[I-1]=(((A*XVAL[I-1] +B)*XVAL[I-1])+C)*XVAL[I-1]+D ;
         goto loop9 ;

 loop8:    J=1 ;
         IF(LOCATE==3) J=NP1 ;
         K=J+1 ;
         L=2 ;
         IF(LOCATE==3) L=NP1 ;
         Z=(Y[J-1]-Y[K-1])/(X[J-1]-X[K-1]) ;
         A=0.0 ;
         B=(YP[0]-Z)/(2.0*X[L-1]-X[J-1]-X[K-1]) ;
         C=YP[1]-2.0*B*X[L-1] ;
         D=Y[J-1]-((B*X[J-1]+C)*X[J-1]) ;
         goto loop7 ;
 loop:   continue ;
}


