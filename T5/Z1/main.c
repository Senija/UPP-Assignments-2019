#include <stdio.h>
#define BROJ_ELEMENATA 10
int main() {
int niz[BROJ_ELEMENATA],i,suma=0;
double prosjek;
for(i=0;i<BROJ_ELEMENATA;i++)
{
	printf("Unesite %d. cijeli broj: ", i+1);
	scanf("%d", &niz[i]);
}
for(i=0; i<BROJ_ELEMENATA;i++)
{
	suma+=niz[i];
}
prosjek=(double)suma/BROJ_ELEMENATA;
printf("Srednja vrijednost unesenih brojeva je %.2f.\n", prosjek);
	return 0;
}
