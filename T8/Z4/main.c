#include <stdio.h>
int drugi(int niz[], int velicina){
	int i;
	int max1, max2;
	max1=max2=-10000; //niz[0];
	int index1,index2;
	index1=index2=0;
	for(i=0; i<velicina; i++){
		if(velicina==1) return -1;
		if(niz[i]>max1){
		max2=max1;
		index2=index1;
		max1=niz[i];
		index1=i;
		}
		else if(niz[i]>max2 && niz[i]<max1)
		{max2=niz[i];
		index2=i;}
		else if(niz[i]==max1){
			
			if(niz[i]>max2 ) max2=niz[i];
		}
		
	}
	if(max1==max2) return -1;
	return index2;
	
}

int main() {
	int niz[100000], n,index,i;
	printf("Unesite niz brojeva: ");
	for(i=0; i<10000; i++){
		scanf("%d", &niz[i]);
		if(niz[i]==-1) break;
		
	}
 n=i;
 for(i=0; i<n; i++)
 {
 	index=drugi(niz,n);
 }
 printf("Indeks drugog po velicini je: %d", index);
	return 0;
}
