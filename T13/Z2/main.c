#include <stdio.h>
#include <stdlib.h>
struct Student {
	char prezime[20];
	char ime[15];
	int broj_bodova1;
	int broj_bodova2;
};
struct Usmeni {
	char prezime[20];
	char ime[15];
	int ukupno_bodova;
};
int main()
{
    remove("usmeni.txt");
	struct Student studenti[300], tmp;
	struct Usmeni usmeni[300];
	FILE *ulaz, *izlaz;//=fopen("ispit.txt", "r");
	int i, j, vel, max, vel_usmeni=0;
	if((ulaz=fopen("ispit.txt", "r"))==NULL) {
		printf("Greska pri otvaranju datoteke ispit.txt\n");
		return 1;
	}
	if((izlaz=fopen("usmeni.txt", "w"))==NULL) {
		fclose(ulaz);
		printf("Greska pri otvaranju datoteke usmeni.txt");
		return 1;
	}
	i=0;
	while(i<300 &&fscanf(ulaz, "%20s%15s%3d%2d\n", studenti[i].prezime, studenti[i].ime, &studenti[i].broj_bodova1, &studenti[i].broj_bodova2)==4)
		i++;
	vel=i;
	for(i=0; i<vel; i++) {
		max=i;
		//if(studenti[i].broj_bodova1>=10 && studenti[i].broj_bodova2>=10) {
			for(j=i+1; j<vel; j++) {
				//if(studenti[j].broj_bodova1>=10 && studenti[j].broj_bodova2>=10)
					if(studenti[j].broj_bodova1+ studenti[j].broj_bodova2 > studenti[max].broj_bodova1+studenti[max].broj_bodova2)
						max=j;
			}
		//}

		tmp=studenti[i];
		studenti[i]=studenti[max];
		studenti[max]=tmp;
	}


	for(i=0; i<vel; i++) {
		if(studenti[i].broj_bodova1>=10 && studenti[i].broj_bodova2>=10) {
			fprintf(izlaz, "%-15s%-10s%-2d\n", studenti[i].prezime, studenti[i].ime, studenti[i].broj_bodova1+studenti[i].broj_bodova2);
			vel_usmeni++;
		}
	}

	i=0;
	while(i<vel_usmeni && fscanf(izlaz, "%20s%15s%2d\n", usmeni[i].prezime, usmeni[i].ime, &usmeni[i].ukupno_bodova))
		i++;

	printf("Izlazna datoteka usmeni.txt je kreirana\n");
	fclose(ulaz);
	fclose(izlaz);
	return 0;
}
