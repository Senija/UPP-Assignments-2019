#include <stdio.h>
#include <math.h>
int prost (int n)
{
	int i;
	if(n==1) return 0;
	for(i=2; i<=sqrt(n); i++)
	{
		if(n%i==0)
		return 0;
	}
	return 1;
}
int main() {
	int i;
 for(i=1; i<100; i++)
 {
   if(prost(i)==1)
   printf("Broj %d je prost\n", i);
 }
	return 0;
}
