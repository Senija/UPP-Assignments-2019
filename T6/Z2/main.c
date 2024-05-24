#include <stdio.h>
#define BROJ_El 10
int main() {
double niz[BROJ_El],temp;
int i,j,max;
for(i=0;i<BROJ_El;i++)
{
    printf("Unesite %d. realan broj: ", i+1);
    scanf("%lf", &niz[i]);

}
for(i=0;i<BROJ_El;i++)
{
    max=i;
    for(j=i+1;j<BROJ_El;j++)
    {if(niz[j]>niz[max])
    max=j;}
 temp=niz[i];
 niz[i]=niz[max];
 niz[max]=temp;
}
printf("Sortiran niz:\n");
for(i=0;i<BROJ_El;i++)
{
printf("%g ", niz[i]);
  // printf("\n");
}
	return 0;
}
