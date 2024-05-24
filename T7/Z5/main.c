#include <stdio.h>
#include <math.h>
long long faktorijel(int n){
	long long fakt=1;
	int i;
	for(i=2; i<=n; i++)
	{
		fakt=fakt*i;
	}
	return fakt;
}
double sinus (double x, int n)
{
	int i;	
	double suma=0;
	for(i=1; i<=n; i++)
	{
		suma+=pow(-1,(i-1))*pow(x,(2*i-1))/(double)faktorijel(2*i-1);
	}
	return suma;
}
int main() {
    int n;
    double x,sinbr,razlika;
    printf("Unesite x: \n");
    scanf("%lf", &x);
    printf("Unesite n: \n");
    scanf("%d", &n);
    sinbr=sinus(x,n);
    printf("sin(x)=%f\n", sin(x));
    printf("sinus(x)=%f\n", sinbr);
    razlika=fabs(sinbr-sin(x));
    printf("Razlika: %f (%.2f%%).", razlika, razlika);
    
	return 0;
}
