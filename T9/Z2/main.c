#include <stdio.h>
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

int prebroji(char* s, char znak){
	int broj=0;
	while(*s!='\0'){
		if(*s==znak) broj++;
	    s++;
	}
	return broj;
}
int samoglasnici(char*a){
	int broj_s=0;
	while(*a!='\0'){
		if(*a=='A' || *a=='a' || *a=='E' || *a=='e' || *a=='I' || *a=='i' || *a=='O' || *a=='o' || *a=='U' || *a=='u') broj_s++;
		a++;
	}
	return broj_s;
}
int main() {
	char a[80], c;
	printf("\nUnesite jednu rijec do 80 znakova (ENTER za kraj): ");
	unesi(a,80);
	printf("\nKoji znak treba prebrojati: ");
	scanf("%c", &c);
	printf("\nBroj znakova %c je: %d",c,prebroji(a,c));
	printf("\nBroj samoglasnika je: %d\n", samoglasnici(a));
	return 0;
}

