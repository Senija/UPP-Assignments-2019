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
int prebroji(char* a, char znak){
	int broj=0;
	char znakMalo = znak;
	if(znakMalo>='A' && znakMalo<='Z') znakMalo+=32;
	while(*a!='\0' && a!=0){
		if(*a==znakMalo || *a==znakMalo-32) broj++;
	    a++;
	}
	return broj;
}
char max_slovo(char* a){
    char* p=a;
    int max=prebroji(p, *p);
    char d=*a;
    while(*p!='\0'){
 
        if(prebroji(p, *p)>max) {
            max=prebroji(a, *a);
            d=*p;}
        p++;
    }
    if(d>='A'&&d<='Z')
        return d;
    else
        return d-32;
    
}
int main() {
    //char a[1000];
    //unesi(a, 1000);
    //printf("%c", max_slovo(a));
    printf("%c\n", max_slovo("Ovo je probni primjer."));
	return 0;
}
