#include <stdio.h>
#define BROJ_ELEMENATA 500
int main() {
int i, niz[BROJ_ELEMENATA], br7=0, br5=0, br11=0;
printf("Unesite brojeve: \n");
for(i=0; i<BROJ_ELEMENATA; i++)
{
	scanf("%d", &niz[i]);
	if(niz[i]==-1)
	{break;}
	if(niz[i]%7==0)
	br7++;
	if(niz[i]%5==0)
	br5++;
	if(niz[i]%11==0)
	br11++;
}
printf("Djeljivih sa 5: %d\n", br5);
printf("Djeljivih sa 7: %d\n", br7);
printf("Djeljivih sa 11: %d\n", br11);
	return 0;
}
