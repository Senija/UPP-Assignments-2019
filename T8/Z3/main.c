#include <stdio.h>
float maxtemp(float niz[], int velicina){
	int i;
	float max;
	max=niz[0];
	for(i=0; i<velicina; i++){
		if(niz[i]>max)
		max=niz[i];
	}
	return max;
}
float prtemp(float niz[], int velicina){
	int i;
	float prosjecna=0;
	for(i=0; i<velicina; i++)
	{
		prosjecna+=niz[i];
	}
	prosjecna=prosjecna/velicina;
	return prosjecna;
}
int main() {
	int i,n;
	float niz[10000]={0};
	float max_temp;
	float pr_temp;
	printf("Unesite broj mjerenja: ");
	scanf("%d", &n);
	printf("Unesite temperature: ");
	for(i=0; i<n; i++)
	{
		scanf("%f", &niz[i]);
		max_temp=maxtemp(niz,n);
		pr_temp=prtemp(niz,n);
		
	}
	printf("Maksimalna temperatura: %.1f\n", max_temp);
	printf("Prosjecna temperatura: %.1f", pr_temp);

	return 0;
}
