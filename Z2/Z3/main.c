#include <stdio.h>
#include<math.h>
int main() {
double EPSILON = 0.0001;
double niz[1000]={0};
double ubaceni;
int i,j,n,decimala;
int brojaci[1000]={0};
do 
{
    printf("Unesite broj clanova niza: ");
    scanf("%d", &n);
}while(n<1||n>100);
printf("Unesite niz: ");
for(i=0; i<n; i++)
{
    scanf("%lf", &niz[i]);
}

for(i=0; i<n-1; i++){
    if(fabs(2*niz[i]-niz[i+1])<EPSILON ){
    ubaceni=(niz[i]+niz[i+1])/2.; 
    for(j=n; j>i; j--)
    {
     niz[j]=niz[j-1];
    }
    n++; 
    niz[i+1]=ubaceni;  
    i++;
    }
    
}
printf("Nakon ubacivanja niz glasi: \n");

for(i=0; i<n; i++)
{
    printf("%g ", niz[i]);
}
printf("\n");
for(i=0; i<n; i++)
{
    decimala=(niz[i]-(int)niz[i])*10;
        brojaci[decimala]++;
}

for(i=0; i<10; i++)
{
    if(brojaci[i]>0)
    printf("Cifra %d se ponavlja %d puta.\n",i, brojaci[i]);
}
	return 0;
}
