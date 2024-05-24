#include <stdio.h>
char *ukloni_komentare(char *s)
{
	char* tmp=s,  *pocetak, *pom, *kraj;
	while(*s!='\0') {
		if(*(s+1)!='\0'){
			if(*s=='/' && *(s+1)=='*') {
				pocetak=s;
				pom=s+2;
				while(1){
					if(*pom=='*'){
						pom++;
						if(*pom=='/'){
							pom++;						
							break;
						}
					}
						if(*pom=='\0'){
							pom=pocetak;
							break;
						}
					pom++;
				}
				kraj=pom;
				while(*pocetak++=*kraj++);
				//if(*s=='/') s--;
			}
			else if(*s=='/' && *(s+1)=='/'){
				pocetak=s;
				pom=s+2;
				while(*pom!='\n'){
					if(*pom=='\0'){
						kraj=pom;
						break;
					}
					pom++;
				}
				kraj=pom;
				while(*pocetak++=*kraj++);
			}
		}
		s++;
	}
	return tmp;
}
int main()
{
	char kod[] = "/*Cijeli string je komentar*///u C ili C++ stilu";
	printf("%s", ukloni_komentare(kod));
	return 0;
}
