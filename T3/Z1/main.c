#include <stdio.h>

int main() {
	int broj,suma=0;
	while(suma<=100)
	{
		printf("Unesite broj: \n");
		scanf("%d", &broj);
		suma+=broj;
	}
	printf("Suma je: %d ", suma);
	return 0;
}
