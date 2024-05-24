#include <stdio.h>
//prejsjek skupova
int main()
{
   double a,b,c,d;
   printf("Unesite brojeve a,b,c,d: ");
   scanf("%lf %lf %lf %lf", &a, &b, &c, &d);

   if(c<b && c>a)
   {
       if(d<b)
       {
           printf("Rezultantni interval je [%g,%g].", c,d);
       }
       else
       {
           printf("Rezultantni interval je [%g,%g].", c,b);
       }
   }
   else if(c<b && d>a)
   {
       if(b<d)
       {
           printf("Rezultantni interval je [%g,%g].", a,b);
       }
       else 
       {
           printf("Rezultantni interval je [%g,%g].", a,d);
       }
   }
  else
   {
       printf("Skupovi se ne sijeku.");
   }
	return 0;
}
