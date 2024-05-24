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
int strcmpi (const char *s1, const char *s2, int velikamala)
{
	if(velikamala==1) {
		while(*s1!='\0' && *s2!='\0') {
			if(*s1<*s2) return -1;
			if(*s1>*s2) return 1;
			s1++;
			s2++;
		}
	}
	else{
		while(*s1!='\0' && *s2!='\0') {
			if((*s1 || *(s1+32)) < (*s2 || *(s2+32))) return -1;
			if((*s1 || *(s1+32)) > (*s2 || *(s2+32))) return 1;
			s1++;
			s2++;
		}
	}
	if(*s1== '\0' && *s2=='\0') return 0;
	if(*s1=='\0') return -1;
	if(*s2=='\0') return 1;
}
int main()
{
	char s1[100], s2[100];
	unesi(s1, 100);
	unesi(s2, 100);
	printf("%d", strcmpi(s1, s2, 0));
	return 0;
}
