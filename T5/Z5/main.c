#include <stdio.h>
#define BROJ_ELEMENATA 1000
int main() {
int i,niz[BROJ_ELEMENATA],brojaci[101]={0},n;
printf("Unesite brojeve:\n");
for(i=0; i<BROJ_ELEMENATA; i++)
{
	scanf("%d", &niz[i]);
	if(niz[i]==-1)
	break;
	if(niz[i]<0 || niz[i]>100)
	{
	printf("Brojevi moraju biti izmedju 0 i 100!\n");
	i--;
	}

}
n=i-1;
for(i=0;i<=n;i++)
{
	brojaci[niz[i]]++;
}
if(brojaci[niz[i]]>0)
{
	for(i=0;i<n;i++)
printf("Broj %d se javlja %d puta.\n", niz[i], brojaci[niz[i]]);
	
}


	return 0;
}
