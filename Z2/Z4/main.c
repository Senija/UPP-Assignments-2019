// Drugi zadatak sa ispisima iz fajla or-rokovi-ispisi-i-mali-zadaci.pdf

#include<stdio.h>

int main()
{
	// int mat[5][5];
	// int i,j;
	// int m, n, k, l, suma=0;
	// scanf("%d", &m);
	// scanf("%d", &n);
	// for(i=0; i<m;i ++){
	// 	for(j=0; j<n; j++){
	// 		scanf("%d", &mat[i][j]);
	// 	}
	// }
	// for(i=0; i<m; i++){
	// 	suma=0;
	// 	for(j=0; j<n; j++){
	// 		suma+=mat[i][j];
	// 	}
	// 	if(suma==0){
	// 		for(k=m; k>i+1; k--){
	// 			for(l=0; l<n; l++)
	// 			mat[k][l]=mat[k-1][l];
	// 		}
	// 		m++;
	// 		for(j=0; j<n; j++){
	// 			mat[k][j]=mat[k-1][j]+1;
	// 		}
	// 		i++;
				
	// 	} 
	// }
	// for(i=0; i<m; i++){
	// 	for(j=0; j<n; j++){
	// 		printf("%d ", mat[i][j]);
	// 	}
	// 	printf("\n");
	// }
	int x, y=0, znak=1, c, suma=0;
    printf("Unesite broj: ");
    scanf("%d", &x);
    printf("Unesi zifru koju zelis izbacici: ");
    scanf("%d", &y)
    if (x < 0) znak = -1;

    do {
        c = abs( x % 10 );
        if(c==y)
        x = x / 10;
    } while (x != 0);
    y = znak * y;
    printf("%d", y);
	

	return 0;
}

