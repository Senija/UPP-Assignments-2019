#include <stdio.h>
#include <math.h>
struct Tacka{
	double x,y;
};
struct Kruznica{
	struct Tacka centar;
	double poluprecnik;
};
struct Tacka unos_tacke(){
	struct Tacka t;
	printf("Unesite koordinate tacke (x, y): \n");
	scanf("%lf,%lf", &t.x, &t.y);
	return t;
}
struct Kruznica unos_kruznice(){
	struct Kruznica k;
	printf("Unesite centar kruznice: \n");
	k.centar=unos_tacke();
	printf("Unesite poluprecnik kruznice: \n");
	scanf("%lf", &k.poluprecnik);
	return k;
}
double udaljenost(struct Tacka t1, struct Tacka t2){
	return sqrt((t1.x-t2.x)*(t1.x-t2.x)+(t1.y-t2.y)*(t1.y-t2.y));
}
int main() {
	struct Kruznica k;
	struct Tacka t;
	double d;
	printf("Unesite kruznicu: \n");
	k=unos_kruznice();
	printf("Unesite neku tacku: \n");
	t=unos_tacke();
	d=udaljenost(t, k.centar);
	if(d<k.poluprecnik)
		printf("Tacka je unutar kruznice.");
	else if(d==k.poluprecnik)
		printf("Tacka je na kruznici.");
	else
		printf("Tacka je izvan kruznice.");
	return 0;
}
