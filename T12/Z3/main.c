#include <stdio.h>
/*void build_up()
{
	FILE* izlaz;

	int indexi[] = {12345, 12345, 12233, 13579, 13579, 13337, 13337, 13337, 13337, 13337, 12345, 13579, 17773, 17773};
	int predmeti[] = {3, 4, 4, 2, 3, 1, 2, 3, 4, 5, 5, 2, 1, 2};
	int ocjene[] = {10, 9, 10, 8, 8, 5, 6, 7, 7, 9, 10, 6, 8, 5};
	int n = sizeof(indexi) / sizeof(int), i;

	izlaz = fopen("ispiti.txt", "w");

	for (i = 0; i < n; i++) {
		fprintf(izlaz, "%d %d %d\n", indexi[i], predmeti[i], ocjene[i]);
	}

	fclose(izlaz);
}*/
struct STUDENT {
	int indexi, predmeti, ocjene;
};
int main()
{
	struct STUDENT student[10000];
	int i=0, br_studenata=0, br_predmeta, br_prolaznosti=0;
	double suma=0, prosjecna_ocjena, prolaznost;
	FILE* ulaz=fopen("ispiti.txt", "r");
	if(ulaz==NULL) {
		printf("Greska pri otvaranju.\n");
		return 1;
	}
	printf("Unesite predmet: ");
	scanf("%d", &br_predmeta);
	if(br_predmeta<1 || br_predmeta>5) {
		printf("Zalimo, ali ne postoje podaci o predmetu sa brojem %d!", br_predmeta);
		return 0;
	}
	while(i<10000 && fscanf(ulaz, "%d %d %d\n", &student[i].indexi, &student[i].predmeti, &student[i].ocjene)==3) {
		if(student[i].predmeti==br_predmeta) {
			//br_studenata++;
			if(student[i].ocjene>5) {
				br_prolaznosti++;
			}
			br_studenata++;
			suma+=student[i].ocjene;

		}
		i++;
	}


	if(br_studenata!=0) {
		prosjecna_ocjena=suma/br_studenata;
		prolaznost=(double)(br_prolaznosti)/br_studenata*100;
		printf("Prosjecna ocjena: %.2f\nProlaznost: %g%%", prosjecna_ocjena, prolaznost);
	}

	return 0;
}
