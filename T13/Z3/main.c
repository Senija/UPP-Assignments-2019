#include <stdio.h>
#define KAPACITET 100
struct Student {
	char ime[15];
	char prezime[20];
	int broj_bodova1;
	int broj_bodova2;
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
	int broj, brojac=0, i=0;
	char s[100];
	struct Student student;
	FILE* dat=fopen("ispit.txt", "a+");
	if(dat==NULL) {
		printf("Greska pri otvaranju datoteke ispit.txt");
		return 1;
	}
	do {
		printf("Unesite 1 za unos, 2 za ispis, 0 za izlaz: ");
		scanf("%d", &broj);
		if(broj==1) {
			student=unos_student();
			fprintf(dat, "%-20s%-15s%2d%3d\n", student.prezime, student.ime, student.broj_bodova1, student.broj_bodova2);
			brojac++;
			fclose(dat);
		} else if(broj==2) {
			FILE* dat_ispis=fopen("ispit.txt", "r");
			if(dat==NULL) {
				printf("Greska pri otvaranju datoteke ispit.txt");
				return 1;
			}
			while(i< brojac && fscanf(dat_ispis, "%20s%15s%2d%3d\n", student.prezime, student.ime, &student.broj_bodova1, &student.broj_bodova2)==4){
				printf("\n%d. %s %s - %d, %d\n", i+1, student.prezime, student.ime, student.broj_bodova1, student.broj_bodova2);
				i++;
			}

		} 
		else {
			continue;
		}

	} while(broj!=0);
	return 0;
}
/*
	struct Student student[KAPACITET];
	int k, brojac=0, i;
	char c;
	FILE* ulaz=fopen("ispit.txt", "a+");
	if(ulaz==NULL){
	    printf("Greska pri otvaranju datoteke ispit.txt");
	    return 1;
	}
	do{
	    printf("Unesite 1 za unos, 2 za ispis, 0 za izlaz: ");
	    scanf("%d", &k);
	    if(k==1){
	        student[brojac]=unos_student();
	        fprintf(ulaz,"%15s%10s%3d%2d\n", student[brojac].ime, student[brojac].prezime, student[brojac].broj_bodova1, student[brojac].broj_bodova2);
	    	brojac++;

	    }
	    if(k==2){
	    	fclose(ulaz);
	    	FILE* izlaz=fopen("ispiti.txt", "r");
	    	//while(i< brojac && fscanf(izlaz,"%-10s%-15s%-2d %-2d\n",student[i].ime, student[i].prezime, &student[i].broj_bodova1, &student[i].broj_bodova2 ));
	    	for(i=0; i<brojac; i++){
	    		printf("%-10s%-15s%-2d %-2d\n", student[i].ime, student[i].prezime, student[i].broj_bodova1, student[i].broj_bodova2);
	    	}
	    	do{
	    		c=fgetc(izlaz);
	    		printf("%c", c);
	    	}while(c!=EOF);
	    }

	}while(k!=0);
	if(k==0){
		return 0;
	 }*/
