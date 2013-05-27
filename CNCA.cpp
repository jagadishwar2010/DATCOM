#include <iostream>

using namespace std;

      void CNCA(){

//***  CALCULATES CN AND CA

      double  PBOD, BODY[400] ;    //IBODY/
      double  PWNG, WING[400]  ;   //IWING/
      double  PHT,  HT[380] ;      //IHT/
      double  PBW,  BW[380] ;  //IBW/
      double  PBH,  BH[380] ;  //IBH/
      double  PBV,  BV[380] ;  //IBV/
      double  PBWH, BWH[380] ; //IBWH/
      double  PBWV, BWV[380] ; //IBWV/
      double  PBWT, BWT[380] ; //IBWHV/
      double  FLC[22],ALP[20], dumflgtcd[118] ; //FLGTCD/
      double  PI,DEG,UNUSED,RAD,kand  ;   //CONSNT/
      double  NLOG,NMACH,I ;  //OVERLY/
      double C[6],ROUTID[2] ;
      bool FLAG ;
      DATA ROUTID /4HCNCA, 4H    /
      int NA ,J=1;

      while(J<=NA){
         SA = sin(ALP[J-1]/RAD) ;
         CA = cos(ALP[J-1]/RAD) ;

         FLAG = abs(BODY[J+19])!= UNUSED ;
         IN = 0 ;
         if(FLAG && J >= 2)
            TBFUNX(ALP(J),Y,BODY(J+100),NA,ALP,BODY[21],C,IN,MI,NG,0,0,4HCLA ,1,ROUTID) ;
         FLAG = FLAG && abs(BODY[J-1]) != UNUSED ;
         if(FLAG) BODY[J+59] = BODY[J+19]*CA+BODY[J-1]*SA ;
         if(FLAG) BODY[J+79] = BODY[J-1]*CA-BODY[J+19]*SA ;

         FLAG = abs(WING[J+39]) != UNUSED && abs(WING[41]) != UNUSED ;
         IN = 0 ;
         if(FLAG)  TBFUNX(ALP(J),Y,WING(J+120),NA,ALP,WING[41],C,IN,MI,NG,0,0,4HCMA ,1,ROUTID) ;
         FLAG = abs(WING[J+19]) != UNUSED ;
         IN = 0 ;
         if(FLAG && J >= 2) TBFUNX(ALP[J],Y,WING[J+100],NA,ALP,WING[21],C,IN,MI,NG,0,0,4HCLA ,1,ROUTID) ;

         FLAG = FLAG && abs(WING[J-1]) != UNUSED ;
         if(FLAG) WING[J+59] = WING[J+19]*CA+WING[J-1]*SA ;
         if(FLAG) WING[J+79] = WING[J-1]*CA-WING[J+19]*SA ;

         FLAG = abs(HT[J+19]) != UNUSED ;
         IN = 0 ;
         if(FLAG && J >= 2) TBFUNX(ALP[J],Y,HT[J+100],NA,ALP,HT[21],C,IN,MI,NG,0,0,4HCLA ,1,ROUTID) ;
         FLAG = FLAG && abs(HT[J-1]) != UNUSED ;
         if(FLAG) HT[J+59] = HT[J+19]*CA+HT[J-1]*SA  ;
         if(FLAG) HT[J+79] = HT[J-1]*CA-HT[J+19]*SA ;

         FLAG = abs(BW[J+19]) != UNUSED ;
         IN = 0 ;
         if(FLAG && J >= 2) TBFUNX(ALP[J],Y,BW[J+100],NA,ALP,BW[21],C,IN,MI,NG,0,0,4HCLA ,1,ROUTID) ;
         FLAG = FLAG && abs(BW[J-1]) != UNUSED ;
         if(FLAG) BW[J+59] = BW[J+19]*CA+BW[J-1]*SA ;
         if(FLAG) BW[J+79] = BW[J-1]*CA-BW[J+19]*SA ;

         FLAG = abs(BH[J+19])  UNUSED ;
         IN = 0 ;
         if(FLAG && J >= 2) TBFUNX(ALP[J],Y,BH[J+100],NA,ALP,BH[21],C,IN,MI,NG,0,0,4HCLA ,1,ROUTID) ;
         FLAG = FLAG && abs(BH[J-1]) != UNUSED ;
         if(FLAG) BH[J+59] = BH[J+19]*CA+BH[J-1]*SA ;
         if(FLAG) BH[J+79] = BH[J-1]*CA-BH[J+19]*SA ;

         FLAG = abs(BV[J+19]) != UNUSED ;
         IN = 0 ;
         if(FLAG && J >= 2) TBFUNX(ALP[J],Y,BV[J+100],NA,ALP,BV(21),C,IN,MI,NG,0,0,4HCLA ,1,ROUTID) ;
         FLAG = FLAG && abs(BV[J-1]) != UNUSED ;
         if(FLAG) BV[J+59] = BV[J+19]*CA+BV[J-1]*SA ;
         if(FLAG) BV[J+79] = BV[J-1]*CA-BV[J+19]*SA ;

         FLAG = abs(BWH[J+19]) != UNUSED ;
         IN = 0 ;
         if(FLAG && J >= 2) TBFUNX(ALP[J],Y,BWH[J+10]),NA,ALP,BWH[21],C,IN,MI,NG,0,0,4HCLA ,1,ROUTID) ;
         FLAG = FLAG && abs(BWH[J-1]) != UNUSED ;
         if(FLAG) BWH[J+59] = BWH[J+19]*CA+BWH[J-1]*SA ;
         if(FLAG) BWH[J+79] = BWH[J-1]*CA-BWH[J+19]*SA ;

         FLAG = abs(BWV[J+19]) != UNUSED  ;
         IN = 0 ;
         if(FLAG && J >= 2) TBFUNX(ALP[J],Y,BWV[J+100],NA,ALP,BWV[21],C,IN,MI,NG,0,0,4HCLA ,1,ROUTID) ;
         FLAG = FLAG && abs(BWV[J-1]) != UNUSED ;
         if(FLAG) BWV[J+59] = BWV[J+19]*CA+BWV[J-1]*SA ;
         if(FLAG) BWV[J+79] = BWV[J-1]*CA-BWV[J+19]*SA ;

         FLAG = abs(BWT[J+19]) != UNUSED ;
         IN = 0 ;
         if(FLAG && J >= 2) TBFUNX(ALP[J],Y,BWT[J+100],NA,ALP,BWT[21],C,IN,MI,NG,0,0,4HCLA ,1,ROUTID)  ;
         FLAG = FLAG && abs(BWT[J-1]) != UNUSED ;
         if(FLAG) BWT[J+59] = BWT[J+19]*CA+BWT[J-1]*SA ;
         if(FLAG) BWT[J+79] = BWT[J-1]*CA-BWT[J+19]*SA ;
         J++ ;
    }
      return ;
}

