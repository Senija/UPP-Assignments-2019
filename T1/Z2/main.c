#include <stdio.h>
#include <math.h>
int main() {
    float x1,x2,y1,y2,z1,z2,d;
    printf("unesi koordinate prve tacke x1, y1,z1");
    scanf("%f %f %f", &x1, &y1, &z1);
    printf("unesi koordinate druge tacke x2, y2,z2");
    scanf("%f %f %f", &x2, &y2, &z2);
    d=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)+(z2-z1)*(z2-z1));
    printf("udaljenost izmedju 2 tacke je %.2f", d);
   
     return 0;
}