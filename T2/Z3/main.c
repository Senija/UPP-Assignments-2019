#include <stdio.h>

int main() {
	int dan, mjesec;
    printf("Dan: ");
    scanf("%d", &dan);
    printf("Mjesec: ");
    scanf("%d", &mjesec);
   /* if(dan<1 && dan>31 || mjesec<1 && mjesex>12)
    {
    	printf()
    }*/
    if(mjesec==1 && dan>=20 || mjesec==2 && dan<=18)
    {
    	printf("Vas znak je Vodolija!");
    }
     if(mjesec==2 && dan>18 || mjesec==3 && dan<=20 )
    {
    	printf("Vas znak je Ribe!");
    }
     if(mjesec==3 && dan>20 || mjesec==4 && dan<=19 )
    {
    	printf("Vas znak je Ovan!");
    }
     if(mjesec==4 && dan>19 || mjesec==5 && dan<=20 )
    {
    	printf("Vas znak je Bik!");
    }
     if(mjesec==5 && dan>20 || mjesec==6 && dan<=20 )
    {
    	printf("Vas znak je Blizanci!");
    }
     if(mjesec==6 && dan>20 || mjesec==7 && dan<=22 )
    {
    	printf("Vas znak je Rak!");
    }
     if(mjesec==7 && dan>22 || mjesec==8 && dan<=22 )
    {
    	printf("Vas znak je Lav!");
    }
     if(mjesec==8 && dan>22 || mjesec==9 && dan<=22 )
    {
    	printf("Vas znak je Djevica!");
    }
     if(mjesec==9 && dan>22 || mjesec==10 && dan<=22 )
    {
    	printf("Vas znak je Vaga!");
    }
     if(mjesec==10 && dan>22 || mjesec==11 && dan<=21 )
    {
    	printf("Vas znak je Skorpija!");
    }
     if(mjesec==11 && dan>21 || mjesec==12 && dan<=21 )
    {
    	printf("Vas znak je Strijelac!");
    }
     if(mjesec==12 && dan>21 || mjesec==1 && dan<=19 )
    {
    	printf("Vas znak je Jarac!");
    }
	return 0;
}
