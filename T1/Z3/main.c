#include <stdio.h>
#define PI 3.14
int main() {
     float r,a,b,h,p,v;
     printf("unesi stranicu prizme, visinu prizme , poluprecnik valjka, visinu valjka");
     scanf("%f %f %f %f", &a, &b, &r, &h);
     p=2*a*a+4*a*b+2*PI*r*h;
     v=a*a*b+r*r*PI*h;
     printf("povrsina tijela je %.2f, a zapremina je %.2f", p, v);
     
     return 0;
}