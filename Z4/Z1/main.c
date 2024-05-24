#include <stdio.h>
struct Osoba {
    char ime[15];
    char prezime[20];
    int telefon;
};
struct Osoba unos_osobe()
{
    struct Osoba o;
    printf("Unesite ime: ");
    scanf("%s", &o.ime);
    printf("Unesite prezime: ");
    scanf("%s", &o.prezime);
    printf("Unesite broj telefona: ");
    scanf("%d", &o.telefon);
    return o;
}
void ispis_osobe(struct Osoba o)
{
    printf("%s %s, Tel: %d", o.ime, o.prezime, o.telefon);
}

int main()
{
    int k, i, brojac=0;
    struct Osoba imenik[100];
    do {
        printf("Pritisnite 1 za unos, 2 za ispis, 0 za izlaz: ");
        scanf("%d", &k);
        if(k==1){
            imenik[brojac]=unos_osobe();
            brojac++;
        }
        else if(k==2){
            for(i=0; i<brojac; i++){
                printf("\n%d", i+1);
                ispis_osobe(imenik[i]);
            }
        }
    }while(k!=0);
    if(k==0){
        return 1;
    }

    return 0;
}
