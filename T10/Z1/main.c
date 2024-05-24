#include <stdio.h>
/*int trazi_rijec(const char* s1, const char* s2) {
    while (*s1 != '\0') {
        while (*s1 == ' ') s1++;
        const char* p = s1;
        const char* q = s2;
        while (*p++ == *q++)
            if (*q == '\0' && (*p == ' ' || 
                *p == '\0')) return 1;
        while (*s1 != ' ' && *s1 != '\0')
            s1++;
    }
    return 0;
}*/
void unesi (char niz[], int velicina){
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
/*void zamijeni1(char* s){
    int duzina=4;
    while(*s!='\0'){
        if(*s==1){
            char*kraj=s;
            while(*kraj!='\0') kraj++;
            while(kraj>s){
                *(kraj+duzina)= *kraj;
                kraj--;
            }
            *s++ ='j'; *s++ = 'e'; *s++ = 'd';
                *s++ = 'a'; *s = 'n';
        }
        s++;
    }
}*/
void zamijeni1(char* s) {
        int duzina = 4;
        while (*s != '\0') {
            if (*s == '1') {
                char* kraj = s;
                while (*kraj != '\0') kraj++;
                while (kraj > s) {
                    *(kraj+duzina) = *kraj;
                    kraj--;
                }
                *s++ = 'j'; *s++ = 'e'; *s++ = 'd';
                *s++ = 'a'; *s = 'n';
            }
            s++;
        }
}

int main() {
char testni_string[100] = "1";
zamijeni1 (testni_string);
printf("'%s'", testni_string);
	return 0;
}
