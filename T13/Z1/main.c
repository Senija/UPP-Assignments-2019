#include <stdio.h>
#include <stdlib.h>
struct Student {
	char prezime[20];
	char ime[15];
	int broj_bodova;
};
int main()
{
	struct Student studenti[300], tmp;
	FILE *ulaz, *izlaz;//=fopen("ispit.txt", "r");
	int i, j, vel, max;
	if((ulaz=fopen("ispit.txt", "r"))==NULL) {
		printf("Greska pri otvaranju datoteke ispit.txt");
		return 1;
	}
	if((izlaz=fopen("ispit_sortiran.txt", "w"))==NULL) {
		fclose(ulaz);
		printf("Greska pri otvaranju datoteke ispit_sortiran.txt");
		return 1;
	}
	i=0;
	while(i<300 &&fscanf(ulaz, "%20s%15s%2d\n", studenti[i].prezime, studenti[i].ime, &studenti[i].broj_bodova)==3)
		i++;
	vel=i;
	for(i=0; i<vel; i++) {
		max=i;
		for(j=i+1; j<vel; j++)
			if(studenti[j].broj_bodova>studenti[max].broj_bodova)
				max=j;
		tmp=studenti[i];
		studenti[i]=studenti[max];
		studenti[max]=tmp;
	}
	
	for(i=0; i<vel; i++){
		fprintf(izlaz, "%-20s%-15s%2d\n", studenti[i].prezime, studenti[i].ime, studenti[i].broj_bodova);
	}
	printf("Izlazna datoteka ispit_sortiran.txt je kreirana\n");
	fclose(ulaz);
	fclose(izlaz);
	return 0;
}
