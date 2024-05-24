#include <stdio.h>
#include <math.h>
int main() {
double p1,p2,q1,q2,r1,r2,d,zbir_pp,razlika_pp,xd,yd,xp1,yp1,xp2,yp2,koef,v,f,a,b,c;//x,y dodira; x1,y1,x2,y2 pesjeka
printf("Unesite koordinate centra kruznice A: ");
scanf("%lf %lf", &p1, &q1);
printf("Unesite poluprecnik kruznice A: ");
scanf("%lf", &r1);
printf("Unesite koordinate centra kruznice B: ");
scanf("%lf %lf", &p2, &q2);
printf("Unesite poluprecnik kruznice B: ");
scanf("%lf", &r2);

d=sqrt(pow((p2-p1),2)+pow((q2-q1),2));
zbir_pp=r1+r2;
razlika_pp=fabs(r1-r2);

if(fabs(d)<1e-5 && fabs(r1-r2)<1e-5)
{
    printf("Kruznice su identicne.");
}
else if(d>r1+r2)
{
    printf("Kruznice se ne sijeku.");
}
else if(fabs(d-zbir_pp)<1e-5)
{
    xd=(r1*p2+r2*p1)/(r1+r2);
    yd=(r1*q2+r2*q1)/(r1+r2);
    printf("Kruznice se dodiruju u tacki (%.2f,%.2f).",xd, yd );
}
else if (fabs(d-razlika_pp)<1e-5)//zasto ne radi
{
   xd=(-r1*p2+r2*p1)/(r2-r1);
   yd=(-r1*q2+r2*q1)/(r2-r1);
   printf("Kruznice se dodiruju u tacki (%.2f,%.2f).", xd, yd);
}
else if(d<razlika_pp || (fabs(d)<1e-5 && fabs(r1-r2)>1e-5))
{
   printf("Jedna kruznica je sadrzana u drugoj.");
}
else if(d>razlika_pp && d<zbir_pp)
{
   koef=(r1*r1-r2*r2-p1*p1+p2*p2-q1*q1+q2*q2);///(2*(p2-p1)); 
   v=2*(q2-q1);
   f=2*(p2-p1);
   a=v*v/(f*f)+1;
   b=2*(p1*v/f - (koef*v)/(f*f)-q1);
   c=koef*koef/(f*f)-(2*p1*koef)/f +p1*p1 +q1*q1 - r1*r1;
   yp1=(-b+sqrt(b*b-4*a*c))/(2*a);
   yp2=(-b-sqrt(b*b-4*a*c))/(2*a);;
   xp1=koef/f-(yp1*v)/f;
   xp2=koef/f-(yp2*v)/f;
   printf("Kruznice se sijeku u tackama (%.2f,%.2f) i (%.2f,%.2f).\n",xp1, yp1, xp2, yp2 );

  // printf("%f %f %f ",a,b,c);
   
}

	return 0;
}
