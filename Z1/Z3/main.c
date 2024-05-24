#include <stdio.h>
#define POBJEDA 301
int main() {
  char slovo,slovof,enter;
  int broj,bodovi_s=0,bodovi_f=0,logicka=1,brojac=0,brojacf=0,brojf;
  printf("Unesite pogotke za Sabita: ");
   do
   {
     do
    {
    scanf("%c", &slovo); 
     if(slovo=='T' || slovo=='S' || slovo=='D')
     {
         scanf("%d", &broj);
         if(broj>0 && broj<10)
         {
             logicka=1;
          switch(slovo)
          {
            case 'S':
                bodovi_s+=broj;
                brojac++;
                logicka=1;
                break;
                
            case 'D':
                bodovi_s+=2*broj;
                brojac++;
                logicka=1;
                break;
            case 'T':
                bodovi_s+=3*broj;
                brojac++;
                logicka=1;
                break;
            }    
         }
         else
         {
             logicka=0;
         }

         
     }
     else if(slovo=='X' || slovo=='I' || slovo=='O')
     {
         switch(slovo)
         {
              case 'X':
                bodovi_s+=0; 
                brojac++;
                logicka=1;
                break;
            case 'I':
                bodovi_s+=50;
                brojac++;
                logicka=1;
                break;
                
            case 'O':
                bodovi_s+=25;
                brojac++;
                logicka=1;
                break;
         }
     }
     else if(slovo=='.')
     {
         getchar();
         break;
     }
     else{
        // printf("Neispravan unos, unesite ponovo.");
         logicka=0;
         brojac=0;
         bodovi_s=0;
         continue;
     }

    }while(slovo!='.'); 
    if(brojac!=9)
    {
        brojac=0;
    }
        if(logicka==0 || brojac!=9)
     {
         printf("Neispravni ulazni podaci.\n");
         printf("Unesite pogotke za Sabita: ");
         continue;
     }
   }while(logicka==0 || brojac!=9);
   printf("Unesite pogotke za Fadilu: ");
   do
   {
     do
    {
     scanf("%c", &slovof); 
     if(slovof=='T' || slovof=='S' || slovof=='D')
     {
         scanf("%d", &brojf);
         if(brojf>0 && brojf<10)
         {
             logicka=1;
          switch(slovof)
          {
            case 'S':
                bodovi_f+=brojf;
                brojacf++;
                logicka=1;
                break;
                
            case 'D':
                bodovi_f+=2*brojf;
                brojacf++;
                logicka=1;
                break;
            case 'T':
                bodovi_f+=3*brojf;
                brojacf++;
                logicka=1;
                break;
            }    
         }
         else
         {
             logicka=0;
         }

         
     }
     else if(slovof=='X' || slovof=='I' || slovof=='O')
     {
         switch(slovof)
         {
              case 'X':
                bodovi_f+=0; 
                brojacf++;
                logicka=1;
                break;
            case 'I':
                bodovi_f+=50;
                brojacf++;
                logicka=1;
                break;
                
            case 'O':
                bodovi_f+=25;
                brojacf++;
                logicka=1;
                break;
         }
     }
     else if(slovof=='.')
     {
         scanf("%c", &enter);
         break;
     }
     else{
        // printf("Neispravan unos, unesite ponovo.");
         logicka=0;
         brojacf=0;
         bodovi_f=0;
         continue;
     }

    }while(slovof!='.'); 
        if(brojacf!=9)
    {
        brojacf=0;
    }
        if(logicka==0 || brojacf!=9)
     {
         printf("Neispravni ulazni podaci.\n");
         printf("Unesite pogotke za Fadilu: ");
         continue;
     }
   }while(logicka==0 || brojacf!=9);
if(bodovi_s>301 && bodovi_f>301)
printf("Oba igraca su premasila potrebni broj poena, rezultat je nerijesen.\n");
if(bodovi_f>301 && bodovi_s<=301)
{
    printf("Fadila je premasila potrebni broj poena, a Sabit je ostvario %d", bodovi_s);
}
else if(bodovi_s<=301 && bodovi_f<=301)
{
    if(bodovi_f>bodovi_s)
printf("Sabit je ostvario %d poena, Fadila je ostvarila %d poena. Pobjednik je Fadila, kojoj je ostalo jos %d poena do pobjede.", bodovi_s, bodovi_f, 301-bodovi_f);
   else if(bodovi_s>bodovi_f) 
printf("Sabit je ostvario %d poena, Fadila je ostvarila %d poena. Pobjednik je Sabit, kojem je ostalo jos %d poena do pobjede.", bodovi_s, bodovi_f, 301-bodovi_s);
   else if(bodovi_s==bodovi_f)
printf("Sabit je ostvario %d poena, Fadila je ostvarila %d poena. Rezultat je nerijesen.", bodovi_s, bodovi_f);
}
else if(bodovi_f>301 && bodovi_s<=301)
{
    printf("Sabit je ostvario %d puena, Fadila je premasila potrebni broj poena. Pobjednik je Sabit, kojem je ostalo jos %d poena do pobjede.", bodovi_s, 301-bodovi_s);
}
else if(bodovi_s>301 && bodovi_f<=301)
{
    printf("Sabit je premasio potrebni broj poena, Fadila je ostvarila %d poena. Pobjednik je Fadila, kojoj je ostalo jos %d poena do pobjede.", bodovi_f, 301-bodovi_f);
}   
   
  	return 0;
}

