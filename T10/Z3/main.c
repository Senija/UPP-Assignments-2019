#include <stdio.h>
char* izbaci_rijec(char* r, int n)
{
	if(n<=0) return r;
	int neslovo=1, broj_rijeci=0;
	char *tmp=r;
	char* pocetak;
	char* kraj;
	while(*r!='\0') {
		if(!((*r>='a' && *r<='z') || (*r>='A' && *r<='Z'))) {
			neslovo=1;
		} else if(neslovo==1) {
			neslovo=0;
			broj_rijeci++;
			if(broj_rijeci==n) {
				pocetak=r;
				while(((*r>='a' && *r<='z') || (*r>='A' && *r<='Z'))) r++;
				kraj=r;
			}
			if(broj_rijeci==n+1) {
				while(*pocetak++=*kraj++);
				return tmp;
			}
		}
		r++;
	}
	if(broj_rijeci==n) *pocetak='\0';
	return tmp;
}



int main()
{
	char testni_string[] = "1abc!@#$%DEF![/]!gHe+`_^*iJK.{|},lmn!   opQ!";
	printf("%s", izbaci_rijec(testni_string, 5));
	return 0;
}
