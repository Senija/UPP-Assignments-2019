#include <stdio.h>



void strcopy(char *s, char *p)
{
    while(*p++=*s++);
    *p='\0';
}

char *prebaci_u_male(char* stringNeki)
{
    char* vrati=stringNeki;
    while(*stringNeki!='\0') {
        if(*stringNeki>='A' && *stringNeki<='Z') *stringNeki=*stringNeki+32;
        stringNeki++;
    }
    return vrati;
}

char *sortiraj(char *znakVeliko, int velicina)
{
    int i=0,j=0,min=0;
    char tmp=0;
    for(i=0; i<velicina; i++) {
        min=i;
        for(j=i+1; j<velicina; j++) {
            if(*(znakVeliko+min)>='A' && *(znakVeliko+min)<='Z' && *(znakVeliko+j)>='a' && *(znakVeliko+j)<='z') {
                if(*(znakVeliko+j) < *(znakVeliko+min)+32)
                    min=j;
            } else if(*(znakVeliko+min)>='a' && *(znakVeliko+min)<='z' && *(znakVeliko+j)>='A' && *(znakVeliko+j)<='Z') {
                if(*(znakVeliko+j)+32 < *(znakVeliko+min))
                    min=j;
            } else {
                if(*(znakVeliko+j)<*(znakVeliko+min))
                    min=j;
            }
        }
        tmp=*(znakVeliko+min);
        *(znakVeliko+min)=*(znakVeliko+i);
        *(znakVeliko+i)= tmp;
    }
    return znakVeliko-velicina;

}
char *izbaci_anagrame(char *recenica, char *anagrami)
{
    char niz_s1[1000] = "wat";
    char niz_s2[1000] = "sat";
    //char niz_s2[] ="fdsdfdfs";
    int brojac_p_anagrami=0;
    int brojac_p_recenica=0;
    char *p_recenica=&niz_s1[0];
    char *p_anagrami=&niz_s2[0];
    char *pomocni = 0;
    char *pomocni2 = 0;
    strcopy(recenica, p_recenica);
    strcopy(anagrami, p_anagrami);
    prebaci_u_male(p_recenica);
    prebaci_u_male(p_anagrami);
    char *p_anagrami_0 = p_anagrami;
    char *p_recenica_0 = p_recenica;
    char *recenica_0 = recenica;
    
    
    while(*p_anagrami!='\0') {
        while(*p_anagrami>='a' && *p_anagrami<='z') {
            brojac_p_anagrami++;
            p_anagrami++;
        }
        p_anagrami-=brojac_p_anagrami;
        p_recenica = p_recenica_0;
        recenica =recenica_0;
        brojac_p_recenica = 0;
        while(*p_recenica!='\0') {
            while(*p_recenica>='a' && *p_recenica<='z') {
                brojac_p_recenica++;
                p_recenica++;
            }
            p_recenica-=brojac_p_recenica;
            pomocni = p_recenica;
            pomocni2 = recenica;
            if(brojac_p_anagrami==brojac_p_recenica){
                sortiraj(p_anagrami, brojac_p_anagrami);
                sortiraj(p_recenica, brojac_p_recenica);
                int i = 0, tacno = 0;
                for(i=0; i<brojac_p_anagrami; i++){
                    if(*(p_anagrami+i) == *(p_recenica+i)){
                        tacno++;
                    }
                }
                char *p_anagrami_kraj=p_anagrami+i;
                char *p_recenica_kraj=p_recenica+i;
                char *recenica_kraj = recenica+i;
                if(tacno==brojac_p_anagrami){
                    while(*p_recenica++ = *p_recenica_kraj++);
                    while(*recenica++ = *recenica_kraj++);
                    p_recenica = pomocni;
                    recenica = pomocni2;
                    
                }
                else
                {
                p_recenica+=brojac_p_recenica;
                recenica +=brojac_p_recenica;
                    
                }
            }
            else {
                p_recenica+=brojac_p_recenica;
                recenica +=brojac_p_recenica;
            }
            
            while(*p_recenica==' ' &&*p_recenica!='\0') {
                p_recenica++;
                brojac_p_recenica=0;
            }
            while(*recenica==' ' ) {
                recenica++;
                //brojac_p_recenica=0;
            }
        }


        p_anagrami+=brojac_p_anagrami;

        while(*p_anagrami==' '&&*p_anagrami!='\0') {
            p_anagrami++;
            brojac_p_anagrami=0;
        }
    }
    
    return recenica_0;
}
int main()
{

    
     char tekst[] = "Senija";
    char anagrami[] = "ANAAAAAAAA gram oloma vo oov jejeje";
    printf("'%s'", sortiraj(tekst, 9));

    return 0;
}
