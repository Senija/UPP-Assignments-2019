#include <stdio.h>
void zamijeni(int *pok1, int *pok2 ){
	int temp=*pok1;
	*pok1=*pok2;
	*pok2=temp;

}
int main() {
	int a,b;
	printf("Unesite 2 cijela broja: \n");
	scanf("%d %d", &a, &b);
	zamijeni(&a, &b);
	printf("%d, %d",a ,b);
	return 0;
}
