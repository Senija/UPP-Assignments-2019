#include <stdio.h>
int main() {
    float vt, mt,p,r;
    printf("unesite izmos velike i male tarife");
    scanf("%f %f", &vt, &mt);
    r=0.3*vt+0.2*mt;
    p=vt+mt;
    printf("ukupnma potrosnja je %.3f, racun iynosi %.3f KM a udio velike tarife je %.2f %%a udio male je %.2f %%", p,r, (vt/p)*100, (mt/p)*100);
     return 0;
}