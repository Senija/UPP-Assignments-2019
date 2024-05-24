#include <stdio.h>

void unesi (char a[], int velicina){
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

char* kapitaliziraj(char*a){
    char*p=a;
    while(*p!='\0'){
        if(p==a && (*p>='a' && *p<='z')) *p=*p-32;
        else if((*p>='a' && *p<='z') && *(p-1)==' ') *p=*p-32;
        p++;
    }
    return a;
}

int main() {
    char a[1000];
    printf("Unesite neki tekst: ");
    unesi(a,1000);
    kapitaliziraj(a);
    printf("%s", a);
	return 0;
}
