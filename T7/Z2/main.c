#include <stdio.h>
long long faktorijel(int x)
{
	long long fakt=1;
	int i;
	for(i=2; i<=x; i++)
	{
		fakt=fakt*i;
	}
	return fakt;
}
int main() {
	int n,i;
	double f;
	double x,suma=0;
	printf("Unesite broj n u intervalu [1, 12]: ");
	scanf("%d", &n);
	printf("Unesite realan broj x: ");
	scanf("%lf", &x);
	for(i=1; i<=n; i++)
	{
		f=faktorijel(i);
		suma+=x/f;
	}

		
	
	printf("Suma od 1 do %d za x = %.3f je %.3f", n, x, suma);
	

	return 0;
}
