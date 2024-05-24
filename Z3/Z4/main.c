#include <stdio.h>
#define epsilon 0.0001
#include <math.h>
void sortiraj(double* niz, int velicina)
{
    int i,j,min;
    double tmp;
    for(i=0; i<velicina; i++) {
        min=i;
        for(j=i+1; j<velicina; j++) {
            if(*(niz+j)<*(niz+min)) min=j;
        }
        tmp=*(niz+min);
        *(niz+min)=*(niz+i);
        *(niz+i)=tmp;
    }
}
int matrice_permutacija(double A[100][100], double B[100][100], double C[100][100], int m, int n)
{
    double nizA[10000], nizB[10000], nizC[10000];
    int i,j,a=0;
    for(i=0; i<m; i++) {
        for(j=0; j<n; j++) {
            nizA[a]=A[i][j];
            nizB[a]=B[i][j];
            nizC[a]=C[i][j];
            a++;
        }
    }
    sortiraj(nizA, a);
    sortiraj(nizB, a);
    sortiraj(nizC, a);
    for(i=0; i<m*n; i++) {
        if(fabs(nizA[i]-nizB[i])<epsilon && fabs(nizB[i]-nizC[i])<epsilon)
            continue;
        else return 0;
    }
    return 1;
}
int main()
{
    double A[100][100], B[100][100], C[100][100];
    int m,n,i,j;
    printf("Unesite m i n: \n");
    scanf("%d %d", &m, &n);
    printf("Unesite matricu A: \n");
    for(i=0; i<m; i++) {
        for(j=0; j<n; j++) {
            scanf("%lf", &A[i][j]);
        }
    }
    printf("Unesite matricu B: \n");
    for(i=0; i<m; i++) {
        for(j=0; j<n; j++) {
            scanf("%lf", &B[i][j]);
        }
    }
    printf("Unesite matricu C: \n");
    for(i=0; i<m; i++) {
        for(j=0; j<n; j++) {
            scanf("%lf", &C[i][j]);
        }
    }
    if(matrice_permutacija(A, B, C, m, n)) printf("\n\n1");
    else printf("\n\n0");
    return 0;
}
