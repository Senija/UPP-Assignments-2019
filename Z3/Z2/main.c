#include <stdio.h>
#include <math.h>
#define epsilon 0.0001
double stepen(double x)
{
	static int brojac;
	static double kopija;
	if(fabs(kopija-x)>epsilon) {
		brojac=1;
		kopija=x;
		return x;
	}
	if(fabs(kopija-x)<epsilon) {
		brojac++;
		return pow(x,brojac);
	}
}
void stepenuj_niz(double A[], int s[], int duzina)
{
	int i,j;
	double temp;
	for(i=0; i<duzina; i++) {
		temp=A[i];
		for(j=0; j<s[i]; j++) {
			A[i]=stepen(temp);
		}
		stepen(0);
	}
}
int main()
{
	double A[5]= {4, 55, 3, 6, 16};
	int s[5]= {2, 2, 2, 2, 2};
	int i;
	stepenuj_niz(A,s,5);
	for(i=0; i<5; i++) {
		printf("%.2f, ", A[i]);
	}

	return 0;
}
