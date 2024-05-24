#include <stdio.h>
#define BROJ_EL 10
int main()
{
	int nizA[BROJ_EL], nizB[BROJ_EL], nizC[2*BROJ_EL],i,n,m;
	printf("Unesite elemente niza A: ");
	for(i=0; i<BROJ_EL; i++) {
		scanf("%d", &nizA[i]);
		if(nizA[i]==-1)
			break;
		if(nizA[i]<0) {
			printf("Elementi trebaju biti pozitivni");
			i--;
		}
		nizC[i]=nizA[i];
	}
	n=i;
	printf("Unesite elemente niza B: ");
	for(i=0; i<BROJ_EL; i++) {
		scanf("%d", &nizB[i]);
		if(nizB[i]==-1)
			break;
		if(nizB[i]<0) {
			printf("Elementi trebaju biti pozitivni");
			i--;
		}
		nizC[i+n]=nizB[i];

	}
	m=i;

	printf("Niz C glasi: ");
	for(i=0; i<n+m; i++) {
		printf("%d", nizC[i]);
		if(i<n+m-1)
			printf(",");
	}

	return 0;
}
