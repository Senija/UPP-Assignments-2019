#include <stdio.h>
char *tritacke(char *s){
	char* tmp=s, *kraj, *pom1, *pom2, *pocetak;
	int brojac;
	while(*s!='\0'){
		if((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')){
			brojac=0;
			pom1=s;
			pom2=s;
			while(*pom2!=' '){
				if(*pom2=='\0'){
					break;
				}
				pom2++;
				brojac++;
			}
			if(brojac>=10){
				kraj=pom2;
				*(pom1+3)='.';
				pocetak=pom1+4;
				while(*pocetak++=*kraj++);
			}
		}
		s++;
	}
	return tmp;
}
int main() {
char tekst[] = "Za vrijeme promjena specifikacija moze doci do poremecaja tolerancije izlaznog proizvoda";
printf("%s", tritacke(tekst));
	return 0;
}
