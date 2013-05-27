#include<iostream>
#include<math.h>
using namespace std;
void ALI(double Q,double R,double XST,double XRT,double XSLT){
double AL[4];
Q=2.0,R=4.0,XST=6.0,XRT=8.0,XSLT=15.0;
double FF,F,H,FST,FRT,RT2,H2,ALI;
      FF=R;
      F=R;
      H=Q;
int MK=0;
double AB,BB;
while(MK<4){
AB = log((pow(H,2)+pow((F-XST),2))/(pow(H,2)+pow((F-XRT),2)));
if(H!=0.0){goto loop1;}
BB=XST-XRT;
goto loop2;
loop1:   FST=(F-XST)/H ;
         FRT=(F-XRT)/H ;
         BB=(FST/abs(FST))*H*atan(abs(FST)) ;
         BB=BB-(FRT/abs(FRT))*H*atan(abs(FRT))+(XST-XRT) ;
loop2:   AL[MK]=((XST-XRT*XSLT)-F*(1.0-XSLT))/(2.0*(XST-XRT)) ;
         AL[MK]=AL[MK]*AB-((1.0-XSLT)/(XST-XRT))*BB ;
         F=-F ;
if(MK!=1)
 goto loop4;
if(MK==1)
 goto loop3;
loop3:   RT2=XRT*XRT ;
         H2=H*H ;
         F=(F*RT2)/(pow(F,2)+H2) ;
         H=(H*RT2)/(pow(FF,2)+H2) ;
loop4:   MK++;
}
ALI=(2.0/(1.0+XSLT))*(AL[0]-AL[1]-AL[2]+AL[3]) ;
cout<<ALI<<endl;
}
