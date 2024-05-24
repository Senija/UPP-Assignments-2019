#include <stdio.h>
#include <math.h>
int sav_kvadrat(long long x)
{
	long long z=sqrt(x);
	return(z*z==x);
}
int izbaci_fib(int* niz, int vel)
{
	int i, j;
	for(i=0; i<vel; i++) {
		if(niz[i]<0) continue;
		if(sav_kvadrat(5*pow(niz[i], 2)+4) || sav_kvadrat(5*pow(niz[i], 2)-4)) {
			for(j=i; j<vel-1; j++)
				niz[j]=niz[j+1];
			i--;
			vel--;
		}

	}


	return vel;
}
int main()
{
	int niz[] = { -1, -2, -3, 102334155, 317810, 196418, 39088169, 102334155, 102334154 };
	int vel = izbaci_fib(niz, 9);
	int i;
	for (i=0; i<vel; i++)
		printf("%d ", niz[i]);

	return 0;
}
