#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Datum {
	int dan, mjesec, godina;
};
struct Student {
	char ime[20], prezime[20];
	struct Datum datum_rodjenja;
};
const int dani_u_mjesecu[12]= {31, 28, 31, 30, 31, 30, 31, 31,30, 31,30, 31};
int prestupne_godine(struct Datum d)
{
	int g=d.godina;
	if(d.mjesec<=2)
		g--;
	return g/4 - g/100 +g/400;
}

int valjan_datum(struct Datum d)
{

	int valjan=1, prestupna=0;
	if(d.godina>0) {
		if((d.godina % 4==0 && d.godina % 100 != 0) || d.godina % 400==0) {
			prestupna=1;
		}
		if(d.mjesec>0 && d.mjesec<=12) {
			if(d.mjesec==2) {
				if(prestupna==1 && d.dan<=29) {
					valjan=1;
				} else if(d.dan>28) {
					valjan=0;
				}
			} else if (d.mjesec==4 || d.mjesec==6 || d.mjesec==9 || d.mjesec==11) {
				if(d.dan>30) valjan=0;
			} else if(d.dan>31) valjan=0;
		}
	}
	return valjan;
}

int razlika(struct Datum d1, struct Datum d2)
{
	int i;
	long n1=d1.godina*365 + d1.dan, n2;
	for(i=0; i<d1.mjesec-1; i++) {
		n1+=dani_u_mjesecu[i];
	}
	n1+=prestupne_godine(d1);

	n2=d2.godina*365 + d2.dan;
	for(i=0; i<d2.mjesec-1; i++) {
		n2+=dani_u_mjesecu[i];
	}
	n2+=prestupne_godine(d2);

	return abs(n1-n2);
}
int period(struct Student* s, int broj_clanova_niza, int d)
{
	int i, j;
	for(i=0; i<broj_clanova_niza; i++) {

		for(j=i+1; j<broj_clanova_niza; j++) {
			if(valjan_datum(s[i].datum_rodjenja) && valjan_datum(s[j].datum_rodjenja)) {
				if(razlika(s[i].datum_rodjenja, s[j].datum_rodjenja)==d) {
					printf("%s %s - %s %s\n", s[i].ime, s[i].prezime, s[j].ime, s[j].prezime);
				}
			}
			else return 1;
		}

	}
}
void zapisi(struct Student* s, int velicina)
{
	int i;
	FILE* dat_bin=fopen("studenti.dat", "wb");
	if(dat_bin==NULL) {
		printf("Greska pri otvaranju");
		exit(1);
	}
	for(i=0; i<velicina; i++) {
		fwrite(s[i].ime, sizeof(char), 20, dat_bin);
		fwrite(s[i].prezime, sizeof(char), 20, dat_bin);
		fwrite(&s[i].datum_rodjenja.dan, 1, 1, dat_bin);
		fwrite(&s[i].datum_rodjenja.mjesec, 1, 1, dat_bin);
		fwrite(&s[i].datum_rodjenja.godina, 2, 1, dat_bin);
	}
	fclose(dat_bin);
}
int promijeni(struct Student s, int n)
{
	int pozicija=n*44;
	FILE *izmjena=fopen("studenti.dat", "rb+");
	if(izmjena==NULL) {
		return 1;
	}
	fseek(izmjena, pozicija, SEEK_SET);
	fwrite(s.ime, sizeof(char), 20, izmjena);
	fwrite(s.prezime, sizeof(char), 20, izmjena);
	fwrite(&s.datum_rodjenja.dan, 1, 1, izmjena);
	fwrite(&s.datum_rodjenja.mjesec, 1, 1, izmjena);
	fwrite(&s.datum_rodjenja.godina, 2, 1, izmjena);
	fclose(izmjena);

}
int main()
{
	struct Student niz[5] = {
		{"Naida", "Mujic", {1, 1, 2000}},
		{"Pero", "Peric", {30, 1, 2000}},
		{"Fata", "Fatic", {3, 12, 1999}},
		{"Sara", "Sarac", {1, 2, 2000}},
		{"Dzana", "Dzanic", {1, 3, 2000}}
	};
	period(niz, 5, 29);
	return 0;
}
