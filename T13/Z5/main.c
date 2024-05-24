#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define KAPACITET 100
struct Student {
	char ime[15];
	char prezime[20];
	int broj_bodova1;
	int broj_bodova2;
};
struct Usmeni {
	char prezime[20];
	char ime[15];
	int bodovi_ukupno;
};
struct Student unos_student()
{
	struct Student s;
	do {
		printf("Unesite ime: ");
		scanf("%s", &s.ime);
		printf("Unesite prezime: ");
		scanf("%s", &s.prezime);
		printf("Unesite broj bodova na I parcijalnom: ");
		scanf("%d", &s.broj_bodova1);
		printf("Unesite broj bodova na II parcijalnom: ");
		scanf("%d", &s.broj_bodova2);
	} while(s.broj_bodova1<0 || s.broj_bodova1>20 || s.broj_bodova2<0 || s.broj_bodova2>20);
	return s;
}



int main()
{
	remove("ispit.txt");
	//remove("usmeni.dat");
	int broj, brojac=0, i=0, velicina=0, index_u=0, j=0, max;
	struct Student student;

	do {
		printf("Unesite 1 za unos, 2 za ispis, 3 za usmeni, 0 za izlaz: ");
		scanf("%d", &broj);
		if(broj==1) {
			FILE* dat=fopen("ispit.txt", "a+");
			if(dat==NULL) {
				printf("Greska pri otvaranju datoteke ispit.txt");
				return 1;
			}
			student=unos_student();
			fprintf(dat, "%-20s%-15s%2d%3d\n", student.prezime, student.ime, student.broj_bodova1, student.broj_bodova2);
			brojac++;
			fclose(dat);

		} else if(broj==2) {
			//
			i = 0;
			FILE* dat_ispis=fopen("ispit.txt", "r");
			if(dat_ispis==NULL) {
				printf("Greska pri otvaranju datoteke ispit.txt");
				return 1;
			}
			while(i< brojac && fscanf(dat_ispis, "%20s%15s%2d%3d\n", student.prezime, student.ime, &student.broj_bodova1, &student.broj_bodova2)==4) {
				printf("\n%d. %s %s - %d, %d\n", i+1, student.prezime, student.ime, student.broj_bodova1, student.broj_bodova2);
				i++;
			}
			fclose(dat_ispis);

		} 
		else if(broj==3) {
			struct Student s[100], tmp;
			FILE *ulaz=fopen("ispit.txt", "r");
			if(ulaz==NULL) {
				return 1;
			}
			i=0;
			while(i<brojac && fscanf(ulaz, "%20s%15s%2d%3d\n", s[i].prezime, s[i].ime, &s[i].broj_bodova1, &s[i].broj_bodova2)==4) {
				i++;
			}
			i=0;
			for(i=0; i<brojac; i++) {
				max=i;
				for(j=i+1; j<brojac; j++) {
					if(s[j].broj_bodova1+ s[j].broj_bodova2 >= s[max].broj_bodova1+s[max].broj_bodova2)
						max=j;
				}

				tmp=s[i];
				s[i]=s[max];
				s[max]=tmp;
			}

			fclose(ulaz);
			struct Usmeni u[100];
			FILE *binarna=fopen("usmeni.dat", "wb");
			if(binarna==NULL) {
				exit(1);
			}
			for(i=0; i<brojac; i++) {
				if(s[i].broj_bodova1>=10 && s[i].broj_bodova2>=10) {
					strcpy(u[index_u].ime, s[i].ime);
					strcpy(u[index_u].prezime, s[i].prezime);
					u[index_u].bodovi_ukupno=s[i].broj_bodova1 + s[i].broj_bodova2;
					index_u++;
				}
			}
			fwrite(u, sizeof(struct Usmeni), index_u, binarna);
			// for(i=0; i<brojac; i++) {
			// 	fwrite(u[i].ime, sizeof(char), 15, binarna);
			// 	fwrite(u[i].prezime, sizeof(char), 20, binarna);
			// 	fwrite(&u[i].bodovi_ukupno, sizeof(int), 1, binarna);
			// }
			printf("Izlazna datoteka usmeni.dat je kreirana\n");
			fclose(binarna);
		} else {
			continue;
		}

	} while(broj!=0);
	return 0;
}
