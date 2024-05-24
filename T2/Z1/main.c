#include <stdio.h>
#define NSP1 90.00
#define NSP2 120.00
#define DP1 60.00
#define DP2 80.00
#define P1 55.00
#define P2 100.00
int main() {
	double sp,dp,p;
	printf("Dobro dosli kod Vaseg kucnog ljekara!\n");
	printf("Unesite sistolicki, dijastolicki pritisak i puls\n");
	scanf("%lf %lf %lf", &sp, &dp, &p);
	if(sp>=NSP1 && sp<=NSP2)
	{
		printf("SP: normalan\n");
	}
	else 
	{
		printf("SP: nije normalan\n");
	}
	if(dp>=DP1 && dp<=DP2)
	{
		printf("DP: normalan\n");
	}
	else 
	{
		printf("DP: nije normalan\n");
	}
	if(p>=P1 && p<=P2)
	{
		printf("Puls: normalan\n");
	}
	else 
	{
		printf("Puls: nije normalan\n");
	}
	return 0;
}
