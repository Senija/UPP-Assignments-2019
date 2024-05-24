#include <stdio.h>
#include <stdlib.h>
struct Broj {
	char ime[15] ;
	char prezime[20];
	char broj[20];
};
int ucitaj_pascal(struct Broj *b)
{

	int br_ime=0, br_prezime=0, br_telefon=0, i=0, vel=0;
	char *s1, *s2, *s3;
	FILE *ulaz=fopen("imenik.dat", "rb");
	if(ulaz==NULL) {
		printf("Greska");
		return 1;
	}
	while(vel<1000) {
		if(fread(&br_ime, sizeof(char), 1, ulaz)!=1) break;
		fread(b[i].ime, sizeof(char), br_ime, ulaz);
		s1=b[i].ime;
		*(s1+br_ime)='\0';
		fread(&br_prezime, sizeof(char), 1, ulaz);
		fread(b[i].prezime, sizeof(char), br_prezime, ulaz);
		s2=b[i].prezime;
		*(s2+br_prezime)='\0';
		//*b[i].prezime='\0';
		fread(&br_telefon, sizeof(char), 1, ulaz);
		fread(b[i].broj, sizeof(char), br_telefon, ulaz);
		s3=b[i].broj;
		*(s3+br_telefon)='\0';
		i++;
		vel++;
	}
	fclose(ulaz);
	return vel;
}
void zapisi_txt(struct Broj* b, int velicina){
	int i=0;
	FILE *tekstualna=fopen("imenik.txt", "w");
	if(tekstualna==NULL){
		printf("Greska.\n");
		exit(1);
	}
	while(i<velicina && fprintf(tekstualna, "%s %s %s\n", b[i].ime, b[i].prezime, b[i].broj)){
		i++;
	}
	fclose(tekstualna);
	

}
int main()
{
	int vel;
	struct Broj b[1000];
	vel=ucitaj_pascal(b);
	zapisi_txt(b, vel);
	return 0;
}
