#include <stdio.h>
# define BROJ_EL 10
int main() {
	int i,j,niz[BROJ_EL],n=0,izbaceni;
printf("Unesite elemente niza: ");
for(i=0;i<BROJ_EL;i++)
{
	scanf("%d", &niz[i]);
	if(niz[i]==-1)
	break;
	if(niz[i]<0)
	{
		printf("Broj treba biti pozitivan.");
		i--;
	}
}
n=i;
printf("Unesite element koji treba izbaciti: ");
scanf("%d", &izbaceni);
for(i=0;i<n;i++)
{
	if(niz[i]==izbaceni)
	{
		for(j=i+1;j<n;j++)
	  niz[j-1]=niz[j];	
	n--;
	i--;	}
}

printf("Novi niz glasi: ");
for(i=0;i<n;i++)
{
printf("%d", niz[i]);
if(i<n-1)
printf(",");
	
}

	return 0;
}
