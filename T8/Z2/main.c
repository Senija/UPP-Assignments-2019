#include <stdio.h>
float maxtemp(float niz[8]){
	int i;
	float max;
	max=niz[0];
	for(i=0; i<8; i++){
		if(niz[i]>max)
		max=niz[i];
	}
	return max;
}
float prtemp(float niz[8]){
	int i;
	float prosjecna=0;
	for(i=0; i<8; i++)
	{
		prosjecna+=niz[i];
	}
	prosjecna=prosjecna/8;
	return prosjecna;
}
int main() {
	int i;
	float niz[8]={0};
	float max_temp;
	float pr_temp;
	printf("Unesite temperature: ");
	for(i=0; i<8; i++)
	{
		scanf("%f", &niz[i]);
		max_temp=maxtemp(niz);
		pr_temp=prtemp(niz);
		
	}
	printf("Maksimalna temperatura: %.1f\n", max_temp);
	printf("Prosjecna temperatura: %.1f", pr_temp);

	return 0;
}