#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
	int x,y;
	srand(time(NULL));
	x=rand()%100+1;
	printf("Izabrao sam broj. Probaj ga pogoditi (-1 za izlaz).\n");
	do
	{
		printf("Unesite broj: ");
		scanf("%d", &y);
		if(y==-1)
		{
			printf("Kraj igre.");
			break;
		}
		if(y>x)
		{
			printf("MANJI\n");
			continue;
		}
				if(y<x)
		{
			printf("VECI\n");
			continue;
		}
		
	}while(y!=x);
	if(x==y)printf("JEDNAK");
	return 0;
}
