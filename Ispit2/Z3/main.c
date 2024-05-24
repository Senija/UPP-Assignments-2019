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
int razlicite_cifre(struct Datum datum)
{
    int brojac=0, i=0, c;

    do {
        c=datum.dan%10;
        

    }while(datum.dan!=0;)


}
int zadatak3(struct Ocjena* niz, int vel)
{
    double ects=0;
    int i=0, j=0, min, c, k;
    for(i=0; i<vel; i++) {
        ects=0
        for(j=0; j<vel; j++) {
            if(strcmp(niz[i].imeprezime, niz[j].imeprezime)==0) {
                if(niz[j].ocjena>5)
                    ects+=niz[j].predmet.ects;
            }
        }
        if(ects>=30) {

        }
    }

    return vel;
}
int main()
{
    printf("Ispit 2, Zadatak 3");
    return 0;
}
