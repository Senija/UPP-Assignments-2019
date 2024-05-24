#include <stdio.h>
int pascal (int m, int n){
    // if(n>m || m<1 || n<1)
    // return -1;
    if (m==n || n==1)
    return 1;
    if(m>1 && n>1 && m>n)
    return pascal(m-1, n)+ pascal(m-1, n-1);
}
int main() {
    int i, j, n;
    printf("Unesite n: \n");
    scanf("%d", &n);
    for(i=1; i<=n; i++){
        for(j=1; j<=i; j++){
            printf("%4d", pascal(i,j));
        }
        printf("\n");
    }

	return 0;
}
