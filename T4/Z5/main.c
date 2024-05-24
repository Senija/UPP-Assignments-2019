#include <stdio.h>

int main() {
int x,c=0,broj=0,s=1,m;


do {
	printf("Unesite broj");
	scanf("%d", &x);
}while(x<0);
printf("Unesite cifru: \n");
scanf("%d", &m);
do
{
	c=x%10;
	x=x/10;
	if(c==m) continue;
	broj=broj+c*s;
	s*=10;

}while(x!=0);
printf("Nakon izbacivanja broj glasi %d", broj);
printf("Broj pomnozen sa dva glasi %d", 2*broj);

	return 0;
}
