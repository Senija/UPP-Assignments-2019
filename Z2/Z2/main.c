#include <stdio.h>
#include<math.h>
int main() {
char cifreSegmenti[20][20][20]={{{'*', '*', '*', '*', '*'}, {'*', ' ', ' ',' ', '*'},{'*', ' ', ' ',' ','*'},{'*', ' ', ' ',' ','*'}, {'*', '*', '*', '*','*'/*cigra 0*/}} ,{{' ', ' ', ' ',' ','*'},{' ', ' ', ' ',' ', '*'},{' ', ' ', ' ',' ', '*'},{' ', ' ', ' ',' ','*'},{' ', ' ', ' ',' ','*'} /*cifra 1*/},{{'*', '*', '*', '*', '*'},{' ', ' ', ' ',' ','*'},{'*', '*', '*', '*', '*'}, {'*', ' ', ' ', ' ',' '}, {'*', '*', '*', '*','*'} /*cigra 2*/},{{'*', '*', '*', '*', '*'},{' ', ' ', ' ', ' ','*'},{'*', '*', '*', '*','*'},{' ', ' ', ' ', ' ','*'},{'*', '*', '*', '*','*'}/*cifra 3*/},{{'*', ' ', ' ', ' ', '*'},{'*', ' ', ' ', ' ','*'},{'*', '*', '*', '*','*'},{' ', ' ', ' ', ' ','*'},{' ', ' ', ' ', ' ','*'}/*cifra 4*/},{{'*', '*', '*', '*', '*'},{'*', ' ', ' ', ' ',' '},{'*', '*', '*', '*','*'},{' ', ' ', ' ', ' ','*'},{'*', '*', '*', '*','*'}/*cifra 5*/},{{'*', '*', '*', '*', '*'},{'*', ' ', ' ', ' ',' '},{'*', '*', '*', '*','*'},{'*', ' ', ' ', ' ','*'},{'*', '*', '*', '*','*'}/*cifra 6*/},{{'*', '*', '*','*','*'},{' ', ' ', ' ',' ', '*'},{' ', ' ', ' ',' ', '*'},{' ', ' ', ' ',' ','*'},{' ', ' ', ' ',' ','*'}/*cifra 7*/},{{'*', '*', '*', '*', '*'},{'*', ' ', ' ', ' ','*'},{'*', '*', '*', '*','*'},{'*', ' ', ' ', ' ','*'},{'*', '*', '*', '*','*'}/*cifra 8*/},{{'*', '*', '*', '*', '*'},{'*', ' ', ' ', ' ','*'},{'*', '*', '*', '*','*'},{' ', ' ', ' ', ' ','*'},{'*', '*', '*', '*','*'}/*cifra 9*/},{{'*', '*', '*', '*', '*'},{'*', ' ', ' ', ' ',' '},{'*', '*', '*', '*','*'},{'*', ' ', ' ', ' ',' '},{'*', '*', '*', '*','*'}/*E*/},{{' ', ' ', ' ', ' ', ' '},{' ', ' ', ' ', ' ',' '},{'*', '*', '*', '*','*'},{'*', ' ', ' ', ' ',' '},{'*', ' ', ' ', ' ',' '}}/*r*/};
//char cifra2[20][20][20]={{'*', '*', '*', '*', '*'},{' ', ' ', ' ',' ','*'},{'*', '*', '*', '*', '*'}, {'*', ' ', ' ', ' ',' '}, {'*', '*', '*', '*','*'} };
//char cifra6{{' ', ' ', ' ', ' ', ' '},{' ', ' ', ' ', ' ',' '},{'*', '*', '*', '*','*'},{'*', ' ', ' ', ' ',' '},{'*', ' ', ' ', ' ',' '}};
int desetica, jedinica, m,n,operand, rez,i,j,brojac=1;
do{
printf("\nOdaberite cjelobrojnu operaciju: \n[1] Sabiranje\n[2] Oduzimanje\n[3] Mnozenje\n[4] Dijeljenje\n[5] Izlaz iz programa\n>>");
scanf("%d", &operand);
//printf("Unesite operande: ");
//scanf("%d %d", &n, &m);
switch (operand)
{
    case 1: printf("\n[1] Sabiranje\n");
            printf("Unesite operande: ");
            scanf("%d %d", &n, &m);
            rez=n+m;
            break;
    case 2: printf("\n[2] Oduzimanje\n");
            printf("Unesite operande: ");
            scanf("%d %d", &n, &m);
            rez= n-m;
            break;
    case 3: printf("\n[3] Mnozenje\n");
            printf("Unesite operande: ");
            scanf("%d %d", &n, &m);
            rez=m*n;
            break;
    case 4: printf("\n[4] Dijeljenje\n");
            printf("Unesite operande: ");
            scanf("%d %d", &n, &m);
            if(m==0) rez=-1;
            else rez=n/m;
            break;
    case 5: return 0;
            brojac=0;
            break;
}
desetica=rez/10;
jedinica=rez%10;
if((operand==1 && rez<100 && rez>=0)||(operand==2 && n>m && rez>=0 &&rez<100) || (operand==3 && rez>=0 && rez<100) || (operand==4 && m!=0 && rez<100 && rez>=0)){
for(i=0; i<5; i++)
{
    for(j=0; j<17; j++)
    {
        if(j<5)
        printf("%c", cifreSegmenti[desetica][i][j]);
        //printf("       ");
        if(j>=5 && j<=11)
        printf(" ");
        if(j>11)
        printf("%c", cifreSegmenti[jedinica][i][j-12]);
    }
    printf("\n");
}}
else if(rez>100 || rez<0 )
{
    for(i=0; i<5; i++)
{
    for(j=0; j<17; j++)
    {
        if(j<5)
        printf("%c", cifreSegmenti[10][i][j]);
        //printf("       ");
        if(j>=5 && j<=11)
        printf(" ");
        if(j>11)
        printf("%c", cifreSegmenti[11][i][j-12]);
    }
    printf("\n");
}}
}while(brojac==1 || operand<1 ||  operand>5);
 	return 0;
}
