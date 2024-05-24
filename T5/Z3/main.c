#include <stdio.h>
#define BROJ_ELEMENATA 5
int main() {
int i;
double nizA[BROJ_ELEMENATA], nizB[BROJ_ELEMENATA], nizC[BROJ_ELEMENATA];
printf("Unesite clanove niza A: ");
for(i=0;i<BROJ_ELEMENATA;i++)
{
	scanf("%lf",&nizA[i]);
}
printf("Unesite clanove niza B: ");
for(i=0;i<BROJ_ELEMENATA;i++)
{
	scanf("%lf",&nizB[i]);
}
for(i=0;i<BROJ_ELEMENATA;i++)
{
	nizC[i]=2*nizA[i]+nizB[i];
}
printf("Niz A glasi: ");
for(i=0;i<BROJ_ELEMENATA;i++)
{
	
	printf("%.2f", nizA[i]);
	if(i<4)
	printf(", ");
	
}
printf("\n");
printf("Niz B glasi: ");
for(i=0;i<BROJ_ELEMENATA;i++)
{
	printf("%.2f", nizB[i]);
	if(i<4)
	printf(", ");
}
printf("\n");
printf("Niz C glasi: ");
for(i=0;i<BROJ_ELEMENATA;i++)
{
	printf("%.2f", nizC[i]);
	if(i<4)
	printf(", ");
};
printf("\n");
	return 0;
}
