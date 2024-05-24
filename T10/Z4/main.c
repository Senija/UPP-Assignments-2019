#include <stdio.h>
char* whitespace(char* s)
{
	char* tmp=s, *kraj, *pocetak, *drugi, *prvi, *drugi1, *pom;
	while(*s!='\0') {
		if(*s== ' ' || *s=='\n' || *s=='\t') {
			if(s==tmp) {
				prvi=s;
				s++;
				pom=s;
				while(*pom==' ' || *pom=='\n' || *pom=='\t') {
					pom++;
				}
				drugi1=pom;
				while(*prvi++=*drugi1++);
			} 
			else if(*s==' ' || *s=='\n' || *s=='\t') {
				*s=' ';
				s++;
				pocetak=s;
				drugi=s;
				while(*drugi==' ' || *drugi=='\n' || *drugi=='\t') {
					drugi++;
				}
				kraj=drugi;
				while(*pocetak++=*kraj++);
				if(*s=='\0'){
					*(s-1)='\0';
					break;
				}

			}

		}
		s++;
	}

	return tmp;
}

int main()
{
char tekst[] = "ga\nrecenica\t\n\t\t\t\t\t";
printf("'%s'", whitespace(tekst));
	return 0;
}
