#include<stdio.h>
int main()
{
   long double NF=0,NT=0,x=0,i=1;
   long double qnf=70,qnd=39.375,qnw=20.625,qnv,qnl;
   long double xf=0.65,xd=0.98,xw=0.02,y=xd,ye;
   long double R,Rmin,coe=1.6,a=1.14;
   printf("alpha=%.2Lf\r\n", a);
   ye=(a*xf)/(1+(a-1)*xf);
   printf("ye=%.2Lf\r\n", ye);
   Rmin=(xd-ye)/(ye-xf);
   printf("Rmin=%.2Lf\r\n", Rmin);
   R=coe*Rmin;/*calculate the reflux retio*/
   printf("R=%.2Lf\r\n", R);
   qnl=R*qnd;
   for(x=y/(a-(a-1)*y);x>=xw;)
{
if(x>=xf)
         {
            y=R/(R+1)*x+xd/(R+1);
NF = i+1; }
else
{
y=(qnl+qnf)*x/(qnl+qnf-qnw)-(qnw*xw/(qnl+qnf-qnw));
NT=i+1; }
       i=i+1;
       x=y/(a-(a-1)*y);
       printf("[plate%.0Lf:(%.4Lf,%.4Lf)]; ",i-1,x,y);
}
   NF=NF-1;
   NT=NT-1;
   printf("\r\n");
   printf("\r\n");
printf("NF=%.2Lf,NT=%.2Lf",NF, NT);
return 0; 
}