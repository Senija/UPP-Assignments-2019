#include <stdio.h>
#define SIRINA 2
int main() {
    int mat[SIRINA][SIRINA],min,i,j;
    for(i=0;i<SIRINA;i++){
        for(j=0;j<SIRINA;j++)
        {
            scanf("%d", &mat[i][j]);
        }
    } 
    min=mat[0][0];
    for(i=0;i<SIRINA;i++)
    {
       if(mat[i][i]<min)
       min=mat[i][i];
        
    }
    printf("%d", min);
    
	return 0;
}
