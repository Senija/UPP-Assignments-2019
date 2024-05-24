#include <stdio.h>
//od min do max i koliko razlicitih
int main() {
	int a, b, c;
	int min=0, mid=0, max=0;
	printf("Unesite tri broja: ");
	scanf("%d %d %d", &a, &b, &c);//KAKO ZABORAVIS &&&&&&&&&&&&&
	if(a<50 || a>200 || b<50 || b>200 || c<50 || c>200)
	{
		printf("Svi brojevi nisu iz intervala 50 do 200\n");
	}
	else 
	{
		if(a>=b)
		{
			if (b>=c)
			{
				min=c;
				mid=b;
				max=a;
			}
		else
		{
			min=b;
			max=a;
			mid=c;
		}
		}
		else if(c>=a && c>=b)
		{
			if(b>=a)
			{
				max=c;
				mid=b;
				min=a;
			}
			else
			{
				max=c;
				mid=a;
				min=b;
			}
		}
		else if (b>=c && a>=c)
		{
			max=b;
			mid=a;
			min=c;
		}
		else 
		{
			max=b;
			mid=c;
			min=a;
		}
		printf("Brojevi poredani po velicini glase: %d,%d,%d \n", min, mid, max);
	if (a==b && b==c && a==c)
		{
			printf("Unesen je 1 razlicit broj");
		}
	else if(a!=b && a!=c)
{
	if(b==c)
	{
		printf("Unesena su 2 razlicita broja\n");
	}
	else 
	{
		printf("Unesena su 3 razlicita broja\n");
	}
}
else if(c==a)
{
	printf("Unesena su 2 razlicita broja");
}
else  if(a==b)
{
	printf("Unesena su 2 razlicita broja");
}
else 
{
	printf("Unesena su 3 ista broja");
}
	}
//printf("brojevi od min do max su %d %d %d \n", min, mid, max);

	return 0;
}
