#include <stdio.h>
#include <math.h>// OBAVEZNO ZAGRADE STAVLJATI KOD IF-OVA
int main() {
int i,n;
printf("Unesite broj: ");
scanf("%d", &n);
if(n<=0)
{
	printf("Broj nije prirodan.");
	return 0;
}
else if(n==1) 
{
    printf("Broj nije ni prost ni slozen.\n");
    
}
else
{  for(i=2; i<=n; i++)
    {   
       if(n%i!=0) 
       {
         continue; 
       //printf("Broj je slozen.");
       }  
       if(n%i==0 && i!=n) 
       {
           printf("Broj je slozen.\n");
           break;
       }
       
       
       if(n%i==0 && (i==n || i== sqrt(n)) )
       {
        printf("Broj je prost.\n");
        break;}
    }

}
return 0;
}
