#include <stdio.h>
#include<math.h>
int main() {
	double visina, obim_struka, masa, kg, bmi, rfm;
	char spol,enter;
	int program, broj_sedmica;
	do 
	{
		printf("Unesite spol (mM/zZ), visinu (u cm), obim struka (u cm), tezinu (u kg): ");
		scanf("%c", &spol);
		scanf(" %lf %lf %lf%c", &visina, &obim_struka, &masa,&enter);
	if(spol!='M' && spol!='m' && spol!='z' && spol!='Z' )
	{
		printf("\nGreska u unosu za spol.\n");
		continue;
	}
	if((visina<100 || visina>220) || (obim_struka<40 || obim_struka>200) || (masa<0 || masa>200))
	{
		printf("\nGreska u unosu atributa.\n");
		continue;
	}
	}while((spol!='M' && spol!='m' && spol!='z' && spol!='Z') || (visina<100 || visina>220) || (obim_struka<40 || obim_struka>200) || (masa<0 || masa>200));
	do
	{
		printf("Odaberite zeljenu opciju za trening:\n[1] Joga\n[2] Joga PLUS\n[3] Cardio\n[4] Super cardio\n[5] Total Body\n[6] Body Builder\n>> ");
		scanf("%d", &program);
		if(program<=0 || program>=7)
		{
			printf("Greska u odabiru opcija.\n");
			continue;
		}
	}while(program<=0 || program>=7);
	do
	{
		printf("Unesite broj kilograma za koliko zelite smanjiti svoju masu (1-10): ");
		scanf("%lf", &kg);
		if(kg<=0 || kg>10)
		{
			printf("Greska u unosu za kilazu. Ocekivane vrijednosti (1-10).\n");
			continue;
		}
	}while(kg<=0 || kg>10);
	
	if((spol=='M' || spol=='m' || spol=='z' ||spol=='Z') && (visina>=100 && visina<=220) && (obim_struka>=40 && obim_struka<=200) &&(masa>0 && masa<=200) && (program>0 && program<7) && (kg>0 && kg<=10))
	{
	  bmi=masa/pow((visina*0.01),2);
	  if(bmi<18.5)
	  {
	  	switch (program) {
			case 1:
			case 2:
			printf("Vas BMI iznosi: %.2f (nizak).\n", bmi);
    		if(spol=='M' || spol== 'm')
			 {
	  		rfm=64-(20*(visina/obim_struka));
			printf("Vas RFM iznosi: %.2f %%.\n", rfm);
			}
			 else if(spol=='z'|| spol=='Z')
			{rfm=76-(20*(visina/obim_struka));
			printf("Vas RFM iznosi: %.2f %%.\n", rfm);
			}
			break;
			default: printf("Odabrani program nije preporucen uz predate podatke.\n");
		}
	  }
	  else if (bmi>=18.5)
		{
			if ((masa-kg)/pow((visina*0.01),2)<18.5)
			{
				printf("Odabrani program nije preporucen uz predate podatke.\n");
			}
			else if ((masa-kg)/pow((visina*0.01),2)>=18.5)
			{
			if (bmi>=18.5 && bmi<25)
	  		{
	  			printf("Vas BMI iznosi: %.2f (normalan).\n", bmi);
	  		}
	    	else if (bmi>=25 && bmi<30)
			{
				printf("Vas BMI iznosi: %.2f (povisen).\n", bmi);
			}
	    	else if (bmi>=30)
			{
				printf("Vas BMI iznosi: %.2f (visok).\n", bmi);
			}
			if(spol=='M' || spol== 'm')
			{
				rfm=64-(20*(visina/obim_struka));
				printf("Vas RFM iznosi: %.2f %%.\n", rfm);
			 }
			else if(spol=='z'|| spol=='Z')
			{
				rfm=76-(20*(visina/obim_struka));
				printf("Vas RFM iznosi: %.2f %%.\n", rfm);
			}
		switch(program)	
	  	{
	  	case 1: 
	  	broj_sedmica=(kg*7000)/(5*200);
	  	printf("Minimalni broj sedmica za treniranje: %d.", broj_sedmica);
	  	break;
	  	case 2:
	  	broj_sedmica=(kg*7000)/(5*300);
	  	printf("Minimalni broj sedmica za treniranje: %d.", broj_sedmica);
	  	break;
	  	case 3:
	  	broj_sedmica=(kg*7000)/(5*400);
	  	printf("Minimalni broj sedmica za treniranje: %d.", broj_sedmica);
	  	break;
	  	case 4:
	  	broj_sedmica=(kg*7000)/(5*500);
	  	printf("Minimalni broj sedmica za treniranje: %d.", broj_sedmica);
	  	break;
	  	case 5:
	  	broj_sedmica=(kg*7000)/(5*600);
	  	printf("Minimalni broj sedmica za treniranje: %d.", broj_sedmica);
	  	break;
	  	case 6:
	  	broj_sedmica=(kg*7000)/(5*600);
	  	printf("Minimalni broj sedmica za treniranje: %d.", broj_sedmica);
	  	break;
	  	//default:printf("Odabrani program nije preporucen uz predate podatke.\n")
	  	}
	
	  }
	}
}
return 0;
}
