#include <stdio.h>
#include <string.h>
#include <math.h>
struct STUDENT {
    int indexi, predmeti, ocjene;
};
struct PREDMET {
    int broj_predmeta;
    char naziv_predmeta[33];
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
int main()
{
    int i=0, br_studenata=0, br_prolaznosti=0, broj=0, j=0,  postojiPredmet = 0, odslusani_p=0, br_polozenih=0, index, statistika, postojiIndex=0;
    double suma=0, prosjecna_ocjena=0, prolaznost=0, suma1=0;
    struct STUDENT student[1000];
    struct PREDMET predmet[20];
    char predmet_unos[33];// = "Osnove racunarstva";
    char ime[33];
    FILE* ulaz=fopen("ispiti.txt", "r");
    if(ulaz==NULL) {
        printf("Greska pri otvaranju.\n");
        return 1;
    }
    do {
        printf("Unesite 1 za statistiku studenta, 2 za statistiku predmeta, 0 za izlaz: ");
        scanf("%d", &statistika);
        if(statistika==1) {
            printf("Unesite broj indexa: ");
            scanf("%d", &index);
            while(i<1000 && fscanf(ulaz,"%d %d %d\n", &student[i].indexi, &student[i].predmeti, &student[i].ocjene)==3) {
                if(index==student[i].indexi) {
                    postojiIndex=1;
                    odslusani_p++;
                    if(student[i].ocjene>5) {
                        br_polozenih++;
                        suma1+=student[i].ocjene;
                    }
                }
                i++;
            }
            if(!postojiIndex) printf("Zalimo, ali ne postoje podaci o studentu sa brojem indexa %d!", index);
            else printf("Student je slusao %d predmeta, a polozio %d (%g%%).\nProsjecna ocjena polozenih predmeta je %.2g\n", odslusani_p, br_polozenih, ((double)br_polozenih)/odslusani_p*100, round(((double)suma1)/br_polozenih*10)/10);
            fclose(ulaz);

        } 
        else if(statistika==2) {
            do {
                printf("Unesite predmet: ");
                unesi(predmet_unos,33);
                FILE* druga=fopen("predmeti.txt", "r");
                if(druga==NULL) {
                    printf("Greska pri otvaranju.\n");
                    return 1;
                }
                while(i<20 && fscanf(druga, "%d ", &predmet[i].broj_predmeta)==1) {
                    broj=predmet[i].broj_predmeta;
                    j=-1;
                    do {
                        if(j<32) j++;
                        ime[j]=fgetc(druga);
                        if (ime[j] == '\n') {
                            //printf("radi");
                            break;
                        }

                    } while(ime[j]!='\n' && ime[j]!=EOF );
                    ime[j]='\0';
                    if(strcmp(predmet_unos, ime)==0) {
                        //printf("index je %d", broj);
                        postojiPredmet = 1;
                        break;
                    }
                    i++;
                }
                if(!postojiPredmet)
                    printf("Nepostojeci predmet!\n");
                fclose(druga);
            } while(postojiPredmet!=1);


            FILE* ulaz=fopen("ispiti.txt", "r");
            if(ulaz==NULL) {
                printf("Greska pri otvaranju.\n");
                return 1;
            }
            i=0;
            while(i<1000 && fscanf(ulaz, "%d %d %d\n", &student[i].indexi, &student[i].predmeti, &student[i].ocjene)==3) {
                //printf("%d,%d,%d\n",student[i].indexi, student[i].predmeti, student[i].ocjene);
                if(broj==student[i].predmeti) {

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
                prolaznost=((double)(br_prolaznosti))/br_studenata*100;
                printf("Prosjecna ocjena: %.2f\nProlaznost: %g%%\n", prosjecna_ocjena, prolaznost);
            }
            if( br_studenata==0 && postojiPredmet==1) printf("Zalimo, ali ne postoje podaci o predmetu %s!", predmet_unos);

        }
    } while(statistika!=0);
    return 0;
}
