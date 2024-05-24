#include <stdio.h>
char* rot13(char *s)
{
	char *tmp=s;
	while(*s!='\0') {
		if((*s>='a' && *s<='m')|| (*s>='A' && *s<='M')) {
			*s=*s+13;
		} 
		else if ((*s>='n' && *s<='z')|| (*s>='N' && *s<='Z')) *s=*s-13;
		else {
			s++;
			continue;
		}
		s++;
	}
	return tmp;
}

int main()
{
	char testni_string[] = "Moje ime je medvjedic Lino";
	printf("%s", rot13(testni_string));
	return 0;
}
