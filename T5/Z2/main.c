#include <stdio.h>
#define BROJ_ELEMENATA 10
int main() {
int niz[BROJ_ELEMENATA],i,suma=0,suma_p=0,brojac=0,max,min;
double prosjek, prosjek_p=0;
for(i=0;i<BROJ_ELEMENATA;i++)
{
	printf("Unesite %d. cijeli broj: ", i+1);
	scanf("%d", &niz[i]);
	if(i==0)
	{
		max=niz[0];
		min=niz[0];
	}
	if(niz[i]>max)
	{max=niz[i];}
	if(niz[i]<min)
	{min=niz[i];}
suma+=niz[i];	

	if(niz[i]%2==0)
	{suma_p+=niz[i];
	 brojac++;	
	}
}
/*printf("SUma_p=%d", suma_p);
prosjek_p=(double)suma_p/brojac;
printf("prosjek_p=%.4f", prosjek_p);*/

prosjek=(double)suma/BROJ_ELEMENATA;
printf("Srednja vrijednost unesenih brojeva je %.2f.\n", prosjek);
	
if(brojac==0)
{
prosjek_p=0.00;
printf("Srednja vrijednost parnih brojeva je %.2f.\n", prosjek_p);}
	
else
{
prosjek_p=(double)suma_p/brojac;
printf("Srednja vrijednost parnih brojeva je %.2f.\n", prosjek_p);
	
}
printf("Najveci element je %d a najmanji %d.",max,min );
	return 0;
}
