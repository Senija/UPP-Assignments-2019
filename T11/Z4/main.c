#include <stdio.h>
#include <math.h>
#include <stdlib.h>
struct Vrijeme{
	int sati, minute, sekunde;
};
struct Vrijeme unos_vremena(){
	struct Vrijeme v;
	scanf("%d %d %d", &v.sati, &v.minute, &v. sekunde);
	return v;
}
int proteklo(struct Vrijeme v1, struct Vrijeme v2){
	int d=abs(v1.sati*3600+v1.minute*60+v1.sekunde - (v2.sati*3600+v2.minute*60+v2.sekunde));
	return d;
}

int main() {
	struct Vrijeme v1, v2;
	printf("Unesite prvo vrijeme (h m s): \n");
	v1=unos_vremena();
	printf("Unesite drugo vrijeme (h m s): \n");
	v2=unos_vremena();
	printf("Izmedju dva vremena je proteklo %d sekundi.", proteklo(v1, v2));
	
	return 0;
}
