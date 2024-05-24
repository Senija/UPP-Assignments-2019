#include <stdio.h>
void sortiraj(double *pok, int velicina){
	int i,j,min;
	double temp;
	for(i=0; i<velicina; i++){
		min=i;
		for(j=i+1; j<velicina; j++){
			if(*(pok+j) < *(pok+min))
			min=j;
		}
		temp=*(pok+min);
		*(pok+min)=*(pok+i);
		*(pok+i)=temp;

	}
}

int main() {
	
	return 0;
}
