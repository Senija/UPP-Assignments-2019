#include <stdio.h>
#include <string.h>
struct Datum {
    int dan, mjesec, godina;
};
struct Predmet {
    int id;
    char naziv[100];
    double ects;
};
struct Ocjena {
    char imeprezime[100];
    int ocjena;
    struct Predmet predmet;
    struct Datum datum;
};


int ucitaj_predmete(struct Predmet* niz)
{
    int i;
    FILE* binarna=fopen("predmeti.bin", "rb");
    if(binarna==NULL) {
        return 0;
    }
    for(i=0; i<1000; i++) {
        if(fread(&niz[i], sizeof(struct Predmet), 1, binarna)!=1) break;
    }
    fclose(binarna);
    return i;
}
int ucitaj_ocjene(struct Predmet* predmeti, int vel, struct Ocjena* ocjena)
{
    
    unsigned short id_studenta[1000]={0};
    int id_studenta_ocjene[1000]={0};
    FILE* tekstualna=fopen("ocjene.txt", "r");
    if(tekstualna==NULL) {
        return 0;
    }
    FILE* studenti=fopen("studenti.bin", "rb");
    if(studenti==NULL) {
        return 0;
    }
    int i;

    for(i=0; i<1000; i++) {
        if(fread(&id_studenta[i], sizeof(unsigned short), 1, studenti)!=1) break;
        if(fread(&ocjena[i].imeprezime, sizeof(char), 100, studenti)!=100) break;
    }
    for(i=0; i<1000; i++){
        if(fscanf(tekstualna, "%d,", &id_studenta_ocjene[i])!=1) break;
        fscanf(tekstualna, "%2d,", &ocjena[i].ocjena);
        fscanf(tekstualna, "%d,", &ocjena[i].predmet.id);
        fscanf(tekstualna, "%2d,%2d,%4d\n", &ocjena[i].datum.dan, &ocjena[i].datum.mjesec, &ocjena[i].datum.godina);
    }
    int vel_o=i;
    int j=0;
    for(j=0; j<vel; j++){
        ocjena[j].predmet.id=predmeti[j].id;
        strcpy(ocjena[j].predmet.naziv, predmeti[j].naziv);
        ocjena[j].predmet.ects=predmeti[j].ects;
    }

    fclose(studenti);
    fclose(tekstualna);
    return vel_o;
}
int main()
{
    return 0;
}
