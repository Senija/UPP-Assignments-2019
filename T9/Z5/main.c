#include <stdio.h>
void unesi (char a[], int velicina)
{
	char znak= getchar();
	if (znak == '\n') znak=getchar();
	int i = 0;
	while (i < velicina-1 && znak != '\n') {
		a[i] = znak;
		i++;
		znak = getchar();
	}
	a[i]='\0';
}
int prva_rijec(char* s)
{
	int brojac=0;
	char* p=s;
	char* tmp=s;
	while(*p!='\0') {
		if(p==s && ((*p>='A' && *p<='Z')||(*p>='a' && *p<='z'))) brojac++;
		else if(((*p>='A' && *p<='Z')||(*p>='a' && *p<='z')) && *(p-1)==' ') brojac++;
		p++;
	}
	while(*tmp!='\0') {
		if(tmp==s && *tmp==' ') continue;
		else if(*tmp==' ' && ((*(tmp-1)>='A' && *(tmp-1)<='Z')||(*(tmp-1)>='a' && *(tmp-1)<='z'))){
			*tmp='\0';
			break;
		}
			
		tmp++;
	}
	return brojac;

}
int main()
{
	char s[100];
	unesi(s,100);
	printf("Broj rijeci u stringu je: %d", prva_rijec(s));
	printf("\n%s", s);
	return 0;
}
