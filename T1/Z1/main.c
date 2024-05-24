#include <stdio.h>
#define PI 3.14
int main() {
     float r, p, v;
     printf("unesi poluprecnik");
     scanf("%f", &r);
     p=r*r*PI;
     v=(4./3)*r*r*r*PI;
     printf("povrsina kruga sa poluprecnikom %.2fje %.2f \n ",r, p);
     printf(" zapremina kruga sa piluprecnikom %.2fje %.2f\n",r, v);
     /*printf("povrsina lopte sa poluprenickom %.2f je %.2f \n", r, pl);*/ 
     
     return 0;
}