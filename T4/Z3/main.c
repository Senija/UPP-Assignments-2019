#include <stdio.h>

int main() {
int i,j,p;

for(i=1; i<12; i++)
{
	for(j=0;j<2;j++)
	{
		if(j==0 && i==0)
		printf("    X ");
		else if(j==1)
		printf("|");
		else if(i==1)
		printf("-");
		else if (i==1 && j==1)
		printf("+");
		else if(j==0 && i>=2)
		{
			for(i=1;i<=10;i++)
			printf("%d\n",i);
		}
		else if(i==0 && j>=2)
		{
			for(i=1;i<=10;i++)
			printf("i");
		}
		
		
	}
	printf("\n");
}
			for(i=1; i<=10;i++){
	for(j=1; j<=10; j++)
	{
	    p=i*j;
	    printf("%4d", p);

	}
	printf("\n");
}
	

	return 0;
}
