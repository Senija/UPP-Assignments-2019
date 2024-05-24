#include <stdio.h>
#include <string.h>
struct Ekipa {
	char naziv[100];
	int pobjede, nerijeseno, porazi;
	int dati_golovi, primljeni_golovi;
};
void unesi (char niz[], int velicina)
{
	char znak= getchar();
	if (znak == '\n') znak=getchar();
	int i = 0;
	while (i < velicina-1 && znak != '\n') {
		niz[i] = znak;
		i++;
		znak = getchar();
	}
	niz[i]='\0';
}
int izbaci_sortiraj(struct Ekipa* e, int velicina)
{
	struct Ekipa tmp;
	char s[100];
	int i, j, index, max_i;
	int bodovi=0, max;
	for(i=0; i<velicina; i++) {
		bodovi=0;
		bodovi=e[i].pobjede*3+e[i].nerijeseno;
		if(bodovi<20) {
			e[i]=e[velicina-1];
			velicina--;
			i--;
		}

	}
	if(velicina!=0) {
		max=e[0].dati_golovi - e[0].primljeni_golovi;
		index=0;
		for(i=1; i<velicina; i++) {
			if(e[i].dati_golovi - e[i].primljeni_golovi >= max) {
				max=e[i].dati_golovi - e[i].primljeni_golovi;
				index=i;
			}
		}
		strcpy(s, e[index].naziv);
		printf("Najvecu gol razliku ima: \n%s\n", s);
	} else printf("Najvecu gol razliku ima: \n");
	for(i=0; i<velicina; i++) {
		max_i=i;
		for(j=i+1; j<velicina; j++) {
			if(3*e[j].pobjede + e[j].nerijeseno > 3*e[i].pobjede + e[i].nerijeseno)
				max_i=j;
			tmp=e[max_i];
			e[max_i]=e[i];
			e[i]=tmp;
		}
	}

	return velicina;
}
int main()
{
	struct Ekipa niz[1000];
	int br_timova, i, velicina;
	do {
		printf("Unesite broj timova: ");
		scanf("%d", &br_timova);
	} while(br_timova<0);
	for(i=0; i<br_timova; i++) {
		printf("Unesite naziv %d. tima: ", i+1);
		unesi(niz[i].naziv, 1000);
		printf("Broj pobjeda: ");
		scanf("%d", &niz[i].pobjede);
		printf("Broj nerijesenih: ");
		scanf("%d", &niz[i].nerijeseno);
		printf("Broj poraza: ");
		scanf("%d", &niz[i].porazi);
		printf("Broj datih golova: ");
		scanf("%d", &niz[i].dati_golovi);
		printf("Broj primljenih golova: \n");
		scanf("%d", &niz[i].primljeni_golovi);
	}
	velicina=izbaci_sortiraj(niz, br_timova);
	printf("Tabela nakon izbacivanja: \n");
	for(i=0; i<velicina; i++) {
		printf("%d. %s\n", i+1, niz[i].naziv);
	}
	return 0;
}
