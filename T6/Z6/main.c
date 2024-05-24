#include <stdio.h>
#define REDOVI 100
#define KOLONE 100
int main() {
int a,b,i,j;
double mat[REDOVI][KOLONE],suma=0;
printf("Unesite dimenzije matrice: ");
do{
scanf("%d %d", &a, &b);
}while((a>100 && a<1) || (b>100 && b<1));
printf("Unesite elemente matrice: ");
for(i=0;i<a;i++){
    for(j=0;j<b;j++){
        scanf("%lf", &mat[i][j]);
        if(i==0 || i==a-1)
        {suma+=mat[i][j];
        }
        if((j==0 && i!=0 && i!=a-1) || (j==b-1 && i!=0 && i!=a-1))
        suma+=mat[i][j];
    }
    }
printf("Suma elemenata na rubu je %.2f", suma);



	return 0;
}
