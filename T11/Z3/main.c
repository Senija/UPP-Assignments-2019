#include <stdio.h>
#include <math.h>
#define PI 3.14159
struct Tacka{
	double x,y;
};

struct Pravougaonik{
	struct Tacka dole_lijevo, gore_desno;
};
struct Tacka unos_tacke(){
	struct Tacka t;
	printf("Unesite koordinate tacke (x, y): \n");
	scanf("%lf,%lf", &t.x, &t.y);
	return t;
}
struct Pravougaonik unos_pravougaonika(){
	struct Pravougaonik p;
	printf("Unesite donju lijevu koordinatu pravougaonika.\n");
	p.dole_lijevo=unos_tacke();
	printf("Unesite gornju desnu koordinatu pravougaonika.\n");
	p.gore_desno=unos_tacke();
	return p;
}
double udaljenost(struct Tacka t1, struct Tacka t2){
	return sqrt((t1.x-t2.x)*(t1.x-t2.x)+(t1.y-t2.y)*(t1.y-t2.y));
}
double povrsina_pravougaonika(struct Pravougaonik p){
	double a=udaljenost(p.dole_lijevo, p.gore_desno);
	double k=p.gore_desno.y - p.dole_lijevo.y/(p.gore_desno.x - p.dole_lijevo.x);
	double ugao=atan(k);
	return a*sin(ugao)*a*cos(ugao);
}
double obim_pravougaonika(struct Pravougaonik p){
	double a=udaljenost(p.dole_lijevo, p.gore_desno);
	double k=p.gore_desno.y - p.dole_lijevo.y/(p.gore_desno.x - p.dole_lijevo.x);
	double ugao=atan(k);
	return 2*a*sin(ugao)+2*a*cos(ugao);
}
int tacka_u_pravougaoniku(struct Tacka t, struct Pravougaonik p){
	if(t.x<=p.gore_desno.x && t.x>=p.dole_lijevo.x && t.y>=p.dole_lijevo.y && t.y<=p.gore_desno.y) 
		return 1;
	else
		return 0;
}
int main() {
	struct Tacka t;
	printf("Unesite neku tacku: \n");
	t=unos_tacke();
	struct Pravougaonik p;
	printf("Unesite pravougaonik: \n");
	p=unos_pravougaonika();
	printf("Povrsina pravougaonika je %f", povrsina_pravougaonika(p));
	printf("Obim pravougaonika je %f", obim_pravougaonika(p));
	return 0;
}
