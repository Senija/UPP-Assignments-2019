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
struct Vrijeme proteklo(struct Vrijeme v1, struct Vrijeme v2){
    struct Vrijeme v;
	int d=abs(v1.sati*3600+v1.minute*60+v1.sekunde - (v2.sati*3600+v2.minute*60+v2.sekunde));
	v.sati=d/3600;
	v.minute=(d%3600)/60;
	v.sekunde=(d%3600)%60;
	return v;
}

int main() {
	struct Vrijeme v1, v2,v3;
	printf("Unesite prvo vrijeme (h m s): \n");
	v1=unos_vremena();
	printf("Unesite drugo vrijeme (h m s): \n");
	v2=unos_vremena();
	v3=proteklo(v1, v2);
	printf("Izmedju dva vremena je proteklo %d sati, %d minuta i %d sekundi.", v3.sati, v3. minute, v3.sekunde);
	
	return 0;
}
