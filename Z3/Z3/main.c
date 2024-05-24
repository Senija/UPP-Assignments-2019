#include <stdio.h>
#include <math.h>
int provjeri(int matrica[][100], int visina)
{
	int i,j;
	for(i=0; i<visina; i++) {
		for(j=0; j<100; j++) {
			if(matrica[i][j]==-1) break;
			if(matrica[i][j]<-1 || matrica[i][j]==0 || (j==99 && matrica[i][j]!=-1)) {
				return 0;
			}
		}
	}
	return 1;
}
int sav_kvadrat(long long x)
{
	long long z=sqrt(x);
	return(z*z==x);
}
int fibonacci_matrica(int matrica[][100], int visina)
{
	int i,j;
	for(i=0; i<visina; i++) {
		for(j=0; j<100; j++) {
			if(matrica[i][0]==-1) break;
			if(matrica[i][j]==-1) break;
			if(matrica[i][j]!=-1) {
				if(j==0 && (sav_kvadrat(5*pow(matrica[i][j], 2)-4) || sav_kvadrat(5*pow(matrica[i][j], 2)+4))) continue;
				if(j==1 && (sav_kvadrat(5*pow(matrica[i][j]-matrica[i][0], 2)+4) || sav_kvadrat(5*pow(matrica[i][j]-matrica[i][0], 2)-4))) continue;
				if((sav_kvadrat(5*pow(matrica[i][j], 2)+4) || sav_kvadrat(5*pow(matrica[i][j], 2)-4)) && (matrica[i][j]=matrica[i][j-1]+matrica[i][j-2]) && j>1) continue;
				else return 0;//da li je broj fibonacijev
			}
		}
	}
	return 1;

}
int main()
{
	int matrica[100][100]= {{0}}, i,j;
	int visina;
	do {
		printf("Unesite visinu matrice: ");
		scanf("%d", &visina);
	} while(visina<=0 || visina>100);
	printf("Unesite matricu: \n");
	for(i=0; i<visina; i++) {
		for(j=0; j<100; j++) {
			do {
				scanf("%d", &matrica[i][j]);
			} while(matrica[i][j]==0 || matrica[i][j]<-1);

			if(matrica[i][j]==-1)break;

		}
	}

	if(provjeri(matrica, visina)) printf("Matrica je validna.\n");
	else printf("Matrica nije validna\n");
	if(fibonacci_matrica(matrica, visina)) printf("Matrica je Fibonacci matrica.\n");
	else printf("Matrica nije Fibonacci matrica.\n");
	return 0;
}
