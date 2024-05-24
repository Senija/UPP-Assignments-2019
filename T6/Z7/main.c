#include <stdio.h>
#define SIRINA 10
int main() {
int mat[SIRINA][SIRINA],imax=0,imin=0,i,j,temp,max,min;
printf("Unesite elemente matrice: ");
for(i=0;i<SIRINA;i++)
    for(j=0;j<SIRINA;j++){
        scanf("%d", &mat[i][j]);
    }
max=mat[0][0];
min=mat[0][0];
for(i=0; i<SIRINA; i++)
    for(j=0; j<SIRINA; j++)
    {
    if(mat[i][j]>max)
    {
        max=mat[i][j];
        imax=i;}
    
    if(mat[i][j]<min)
    {
        min=mat[i][j];
        imin=i;
    }
    }

if(imax==imin)
{
    printf("Najmanji i najveci element se nalaze u istom redu.\n");
    return 0;
}

for(j=0; j<SIRINA; j++)
    {temp=mat[imin][j];
    mat[imin][j]=mat[imax][j];
    mat[imax][j]=temp;}
printf("Nakon zamjene matrica glasi:\n");
for(i=0; i<SIRINA; i++){
    for(j=0; j<SIRINA; j++)
    {
        printf("%d ", mat[i][j]);
    }
    printf("\n");}
	return 0;
}
