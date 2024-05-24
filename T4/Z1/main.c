#include <stdio.h>
#include<math.h>
int main() {
float a, b, c,x1,x2,x1re, x2re, x1im, x2im, t, d;
printf("Unesite koeficijente kvadratne jednadzbe a,b,c: \n");
scanf("%f %f %f", &a, &b, &c);
d=b*b-4*a*c;
if(d>0)
{
	t=sqrt(d);
	x1=(-d+t)/(2*a);
	x2=(-d-t)/(2*a);
	printf("Rjesenja su x1=%f x2=%f\n", x1,  x2);
}
if(d==0)
{
	t=sqrt(d);
	x1=-b/(2*a);
	printf("\n Rjesenja su x1=x2=%f x2=%f", x1);
}
else
{
	t=sqrt(-d);
	x1re=-b/(2*a);
	x2re=x1re;
	x1im=t/2*a;
	x2im=-1*x1im;
	printf("\n Rjesenja su x1=(%f, %f) ", x1re,  x1im);
	printf("\n Rjesenja su x2=(%f, %f) ", x2re,  x2im);
}
	return 0;
}
