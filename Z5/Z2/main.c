#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Planina {
	char naziv[50];
	int visina;
};
int ucitaj(struct Planina* p, int velicina)
{
	//struct Planina* zapamti = p;
	int brojacPlanina = 0;
	char c;

	int i=0, broj=0, j=0, velDatoteke = 0;
	FILE* ulaz=fopen("planine.txt", "r");
	if(ulaz==NULL) {
		printf("Greska pri otvaranju datoteke planine.txt");
		return 1;
	}
	char citavaDatoteka[1000] = {0};
	do {
		c = fgetc(ulaz);
		if(c==EOF)
			break;
		citavaDatoteka[i] = c;
		i++;
	} while(c!=EOF);
	citavaDatoteka[i]='\0';

	velDatoteke = i;
	i=0;

	do {
		c=citavaDatoteka[i];

		if((c>='A' && c<='Z') || (c>='a' && c<='z') || c==' ') {
			if(i!=0 && i != velDatoteke && c==' ' && ((citavaDatoteka[i-1]>='a' && citavaDatoteka[i-1]<='z') || (citavaDatoteka[i-1]>='A' && citavaDatoteka[i-1]<='Z')) && ((citavaDatoteka[i+1]>='a' && citavaDatoteka[i+1]<='z') || (citavaDatoteka[i+1]>='A' && citavaDatoteka[i+1]<='Z'))) {
				p->naziv[j]=c;
				j++;

			} else if(c!=' ') {
				p->naziv[j]=c;
				j++;
			}
		} else if((c>='0' && c<='9')) {
			broj=broj*10 + c - '0';
		}

		else if(c=='\n') {
			p->visina=broj;
			p->naziv[j]='\0';
			j=0;
			broj=0;
			p++;
			brojacPlanina++;
		}
		i++;
	} while(i!=velDatoteke);

	p->naziv[j]='\0';
	p->visina=broj;
	brojacPlanina++;
	fclose(ulaz);

	return brojacPlanina;
}
void zapisi(struct Planina* p, int velicina)
{
	FILE* binarna=fopen("planine.dat", "wb");
	if(binarna==NULL) {
		printf("Greska pri otvaranju datoteke.");
		exit(1);
	}

	int zapisano=fwrite(p, sizeof(struct Planina), velicina, binarna);
	if(ferror(binarna)) {
		printf("Greska prilikom pisanja datoteke.\nZapisano je %d clanova", zapisano);

	}
	fclose(binarna);
}
void ispis(struct Planina *p, int velicina)
{
	struct Planina max;
	char *s;
	int i,  ima_a=0, index=-1;
	for(i=0; i<velicina; i++) {
		if(p[i].visina<=2000) {
			s=p[i].naziv;
			while(*s!='\0') {
				if(*s=='a' || *s=='A') {
					ima_a=1;
					break;
				}
				s++;
			}
			if(ima_a==1) {
				index=i;
				max=p[i];
				break;
			}

		}
	}
	for(i=0; i<velicina; i++) {
		if(p[i].visina<=2000 && p[i].visina>max.visina) {
			s=p[i].naziv;
			ima_a=0;
			while(*s!='\0') {
				if(*s=='a' || *s=='A') {
					ima_a=1;
					break;
				}
				s++;
			}
			if(ima_a==1) {
				max=p[i];
				index=i;

			}
		}
	}

		if(index!=-1) printf("%s %d\n", p[index].naziv, p[index].visina);
}
int main()
{
	struct Planina planine[1000] = {
		{ "Bjelsnic", 1},
		{ "Trebevic", 1},
		{ "Jahorina",  3},
		{ "Mount Everest", 4}
	};
	int vel=4;
	ispis(planine, vel);
	//planine[0].visina = 1967;
	//ispis(planine, vel);
	return 0;
}
