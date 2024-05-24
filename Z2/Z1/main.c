#include <stdio.h>
#include<math.h>
#define epsilon 0.00001
int main() {
int n,i;
double a,b,h,suma=0,clan=1,suma1=0,suma2=0,suma3=0,suma4=0,pom;
printf("Unesite prvu tacku intervala: ");
scanf("%lf", &a);
if(a<1)
{
    printf("Nedozvoljena vrijednost!\n");
    return 0;
}
printf("Unesite drugu tacku intervala: ");
scanf("%lf", &b);
if(b<1)
{
    printf("Nedozvoljena vrijednost!\n");
    return 0;
}
if(b-a>100|| b<=a)
{
    printf("Neispravan interval!\n");
    return 0;
}
printf("Unesite eksponent: ");
scanf("%d",&n);
if(n<-10 || n>10)
{
    printf("Neispravan eksponent!\n");
    return 0;
}
printf("Unesite korak diskretizacije: ");
scanf("%lf", &h);
pom=a;
do
{
 clan=a;
 for(i=1;i<n;i++)
 {
     clan*=a;
 }
 
 suma+=clan*h;
if((fabs(a-pom)<epsilon)) suma1=suma/h;
if(fabs(a-pom-h)<epsilon) suma2=suma/h - suma1;
if(fabs(a-pom-2*h)<epsilon) suma3=suma/h - suma1-suma2;
if(fabs(a-pom-3*h)<epsilon) suma4=suma/h - suma1-suma2-suma3;
  a+=h;
}while(a<b);
printf("Korak    x            y = f(x)\n");
for(i=0;i<34;i++)
{
    printf("-");
}

printf("\n    1.%9.6f%16.5f", pom, suma1);
if(suma2>0)printf("\n    2.%9.6f%16.5f", pom+h, suma2);
if(suma3>0)printf("\n    3.%9.6f%16.5f", pom+(2*h), suma3);
if(suma4>0)printf("\n    4.%9.6f%16.5f", pom+(3*h), suma4);
if((fabs(clan-suma4)>epsilon)&& (fabs(clan-suma1)>epsilon) && (fabs(clan-suma2)>epsilon) && (fabs(clan-suma3)>epsilon)){
    printf("\n(...)");
printf("\n %4d.%9.6f%16.5f",(int)((b-pom)/h), b-h,clan);    
}
printf("\n");
for(i=0;i<34;i++)
{
    printf("-");
}
printf("\nP(x^%d)[%d,%d]= %-.6f (dx=%g)",n,(int)pom,(int)b,suma,h);
	return 0;
}
