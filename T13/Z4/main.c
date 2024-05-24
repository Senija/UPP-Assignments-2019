#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

	
	
	remove("usmeni.dat");
	struct Student studenti[300], tmp;
	struct Usmeni usmeni[300];
	FILE *ulaz, *izlaz;//=fopen("ispit.txt", "r");
	int i, j, vel, max, vel_usmeni=0;
	if((ulaz=fopen("ispit.txt", "r"))==NULL) {
		printf("Greska pri otvaranju datoteke ispit.dat\n");
		return 1;
	}
	if((izlaz=fopen("usmeni.dat", "wb"))==NULL) {
		fclose(ulaz);
		printf("Greska pri otvaranju datoteke usmeni.dat");
		return 1;
	}
	else
		printf("Izlazna datoteka usmeni.dat je kreirana\n");
	i=0;
	while(i<300 &&fscanf(ulaz, "%20s%15s%3d%2d\n", studenti[i].prezime, studenti[i].ime, &studenti[i].broj_bodova1, &studenti[i].broj_bodova2)==4)
		i++;
	vel=i;
	for(i=0; i<vel; i++) {
		max=i;
			for(j=i+1; j<vel; j++) {
					if(studenti[j].broj_bodova1+ studenti[j].broj_bodova2 > studenti[max].broj_bodova1+studenti[max].broj_bodova2)
						max=j;
			}

		tmp=studenti[i];
		studenti[i]=studenti[max];
		studenti[max]=tmp;
	}
	
	
	for(i=0; i<vel; i++) {
		if(studenti[i].broj_bodova1>=10 && studenti[i].broj_bodova2>=10) {
			//fprintf(izlaz, "%-15s%-10s%-2d\n", studenti[i].prezime, studenti[i].ime, studenti[i].broj_bodova1+studenti[i].broj_bodova2);
			strcpy(usmeni[vel_usmeni].prezime , studenti[i].prezime);
			strcpy(usmeni[vel_usmeni].ime ,  studenti[i].ime);
			usmeni[vel_usmeni].ukupno_bodova = studenti[i].broj_bodova1 + studenti[i].broj_bodova2;
			vel_usmeni++;
		}
	}
	fwrite(usmeni, sizeof(struct Usmeni), vel_usmeni, izlaz);


	//fwrite(studenti, sizeof(struct Usmeni), 300, izlaz);
	fclose(ulaz);
	fclose(izlaz);
	return 0;
}
