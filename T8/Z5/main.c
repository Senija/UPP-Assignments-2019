#include <stdio.h>
#include <math.h>
void zaokruzi(double *pok, int velicina){
	double temp=0;
	double *kopija=pok;
	while(pok<kopija+velicina){
		temp=((int)round((*pok)*10))/10.0;
		*pok=temp;
		pok++;
	}
}
int main(){
	int i,n;
	double niz[10000]={0};
	//double *pok=niz;
	printf("Uneiste niz: \n");
	for(i=0; i<10000; i++){
		scanf("%lf", niz+i);
		if(niz[i]==-1) break;
	}
	n=i;
	for(i=0; i<n; i++){
		zaokruzi(niz,n);
		printf("%g,", *(niz+i));
	}


	return 0;
}
