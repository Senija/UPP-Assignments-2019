#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void unesi (char niz[], int velicina){
	char znak= getchar();
	if (znak == '\n') znak=getchar();
    int i = 0;
    while (i < velicina-1 && znak != '\n') {
        niz[i] = znak;
        i++;
        znak = getchar();
    }
    niz[i]='\0';
}
int izracunaj(char *string, int *ok)
{
	char* kopija1=string;
	char* kopija2=string;
	char *kopija3=string;
	char *stepen;
	char *mnozenjeIspred;
	char *mnozenjeIza;
	char *plusIspred;
	char *plusIza;
	int stepeni[100]= {-1}, plus_minus[100]= {-1}, mnozenje_dijeljenje[100]= {-1},  rezultati[200] = {0},  postojiLiRezultat[200] = {0};
	int br_mnozenja_dijeljenja=0, br_plus_minus=0, br_stepena=0, i, cifre=0, vrijednost_eksponenta=0, cifre_eksponenta=0, cifre_mnozenje=0 ;
	int broj=0, predznak=1, postojiPlus = 0;
	char *eksponent;
	int rez=0;
	while(*string!='\0') {
		if((*string>='0' && *string<='9') || *string=='-' || *string=='*' || *string=='/' || *string=='+' || *string=='^') {
			if(string==kopija2) {
				if(!(*string>='0' && *string<='9') && *string!='-') {
					*ok=0;
					break;
				}
				if(*string=='-') {
					if(!(*(string+1)>='0' && *(string+1)<='9')) {
						*ok=0;
						break;
					}
				}
			}
			if(*string>='0' && *string<='9') {
				string++;
				continue;
			}
			if((*string=='*' || *string=='/' || *string=='+' || *string=='^') && string!=kopija2) {
				if(!((*(string+1))>='0' && *(string+1)<='9') && *(string+1)!='-') {
					*ok=0;
					break;
				} else {
					string++;
					continue;

				}
			}
			if(*string=='-' && string!=kopija2) {
				if(*(string+1)>='0' && *(string+1)<='9') {
					string++;
					continue;//string++;
				} else if(!(*(string +1)>='0' && *(string+1)<='9') && *(string+1)!='-') {
					*ok=0;
					break;
				} else if(*(string+1)=='-') {
					if((!(*(string-1)>='0' && *(string-1)<='9')) || (!(*(string+2)>='0' && *(string+2)<='9'))) {
						*ok=0;
						break;
					}
				}
			}
		} else *ok=0;
		string++;
	}
	if(*string=='\0') *ok=1;
	if(*ok==1) {

		while(*kopija1!='\0') {
			if(*kopija1=='^') {
				stepeni[br_stepena]=kopija1-kopija2;
				br_stepena++;
			} else if(*kopija1=='*' || *kopija1=='/') {
				mnozenje_dijeljenje[br_mnozenja_dijeljenja]=kopija1-kopija2;
				br_mnozenja_dijeljenja++;
			} else if(*kopija1=='+') {
				plus_minus[br_plus_minus]=kopija1-kopija2;
				br_plus_minus++;
			} else if(*kopija1=='-') {
				if(*(kopija1+1)=='-') {
					plus_minus[br_plus_minus]=kopija1-kopija2;
					br_plus_minus++;
					kopija1++;
				} else if(kopija1==kopija2) {
					kopija1++;
				} else if(*(kopija1-1)=='^' ||*(kopija1-1)=='*' || *(kopija1-1)=='/' || *(kopija1-1)=='+') {
					kopija1++;
				} else {
					plus_minus[br_plus_minus]=kopija1-kopija2;
					br_plus_minus++;
				}

			}

			kopija1++;
		}
		if(br_plus_minus ==0 && br_mnozenja_dijeljenja == 0 && br_stepena == 0)
			return atoi(kopija3);
		//while(*kopija3!='\0'){
		for(i=0; i< br_stepena; i++) {
			int pozicijaStepeniTemp = -1;
			int pozicijaStepeniKraj = -1;
			//	while(stepeni[i]!=0 || stepeni[i]!=-1) {
			predznak=1;
			stepen=kopija3+stepeni[i]-1;
			cifre=0;
			cifre_eksponenta = 0;
			while(stepen!=kopija3 && (*stepen>='0' && *stepen<='9')) {
				cifre++;
				stepen--;
			}
			if(stepen!=kopija3 || (stepen==kopija3 && *stepen=='-'))
				stepen++;
			if( (*(stepen-1)=='-' && stepen-1 == kopija3) || (*(stepen-1)=='-' && (*(stepen-1)=='-' || *(stepen-1)=='+'))) {
				predznak=-1;
			}
			if(predznak==-1) {
				pozicijaStepeniTemp=stepen-1-kopija3;

			} else pozicijaStepeniTemp=stepen-kopija3;

			broj=atoi(stepen) * predznak;
			eksponent=kopija3+stepeni[i]+1;
			char *prva_cifra_eksponenta=kopija3+stepeni[i]+1;
			predznak=1;
			if(*eksponent=='-') {
				predznak=-1;
				prva_cifra_eksponenta++;
				eksponent++;
			}
			while(*eksponent>='0' && *eksponent<='9') {
				cifre_eksponenta++;
				eksponent++;
			}
			eksponent--; //zadnja cifra eksponenta
			pozicijaStepeniKraj = eksponent - kopija3;
			vrijednost_eksponenta=atoi(prva_cifra_eksponenta)*predznak;
			broj = pow(broj, vrijednost_eksponenta);

			//}
			int j = 0;
			for( j=pozicijaStepeniTemp; j<pozicijaStepeniKraj+1; j++) {
				postojiLiRezultat[j] = 1;
				rezultati[j] = broj;

			}
		}
		for(i = 0; i < br_mnozenja_dijeljenja; i ++) {
			predznak=1;
			cifre=0;
			cifre_mnozenje = 0;
			int brojIspred =0, brojIza =0;
			mnozenjeIspred=kopija3+mnozenje_dijeljenje[i]-1;
			if(postojiLiRezultat[mnozenje_dijeljenje[i] -1]) {
				brojIspred = rezultati[mnozenje_dijeljenje[i] -1];
			} else {
				while(*mnozenjeIspred>='0' && *mnozenjeIspred<='9')  {
					cifre++;
					if(mnozenjeIspred==kopija3)
						break;
					mnozenjeIspred--;
				}
				if((mnozenjeIspred==kopija3 && *(mnozenjeIspred)=='-') || (*mnozenjeIspred=='-' && (*(mnozenjeIspred-1)=='-' || *(mnozenjeIspred-1)=='+'))) {
					predznak=-1;
				}
				if(mnozenjeIspred!=kopija3 || (mnozenjeIspred==kopija3 && *mnozenjeIspred=='-'))
					mnozenjeIspred++;
				brojIspred=atoi(mnozenjeIspred)*predznak;//prva cifra broja ispred *

			}
			mnozenjeIza=kopija3+mnozenje_dijeljenje[i]+1;
			if(postojiLiRezultat[mnozenje_dijeljenje[i] +1]) {
				brojIza = rezultati[mnozenje_dijeljenje[i] +1];
			} else {
				predznak=1;
				char *prva_cifra_mnozenjeIza=kopija3+mnozenje_dijeljenje[i]+1;
				if(*prva_cifra_mnozenjeIza=='-') {
					predznak=-1;
					prva_cifra_mnozenjeIza++;
					mnozenjeIza++;
				}
				while(*mnozenjeIza>='0' && *mnozenjeIza<='9') {
					cifre_mnozenje++;
					mnozenjeIza++;
				}
				mnozenjeIza--;//zadnja cifra mnozenjaIza
				brojIza=atoi(prva_cifra_mnozenjeIza)*predznak;
			}
			//printf("%c\n",*(kopija3 + mnozenje_dijeljenje[i]));
			if(*(kopija3 + mnozenje_dijeljenje[i]) =='*')
				broj = brojIspred*brojIza;
			else
				broj = brojIspred/brojIza;
			int j = mnozenje_dijeljenje[i], k=0;
			if(mnozenje_dijeljenje[i]!=0 && postojiLiRezultat[j-1] ) {
				j--;
				while(j>=0 && postojiLiRezultat[j]) {
					rezultati[j] = broj;
					j--;
				}
			} else {

				for(k=mnozenje_dijeljenje[i] - cifre; k<mnozenje_dijeljenje[i]; k++) {
					postojiLiRezultat[k] = 1;
					rezultati[k] = broj;
				}
			}
			j = mnozenje_dijeljenje[i];
			k=0;
			if ( postojiLiRezultat[j +1]) {
				j++;
				while(postojiLiRezultat[j]) {
					rezultati[j] = broj;
					j++;
				}

			} else {

				for(k=mnozenje_dijeljenje[i]; k<cifre_mnozenje+mnozenje_dijeljenje[i]+1; k++) {
					postojiLiRezultat[k] = 1;
					rezultati[k] = broj;
				}
			}


		}
		for(i=0; i<br_plus_minus; i++) {
			postojiPlus = 1;
			predznak=1;
			int cifre_ispred=0, cifre_iza=0;
			int brojIspred_plus=0, brojIza_plus=0;
			plusIspred=kopija3+ plus_minus[i]-1;
			if(postojiLiRezultat[plus_minus[i] -1]) {
				brojIspred_plus = rezultati[plus_minus[i] -1];
			} else {
				while(*plusIspred>='0' && *plusIspred<='9') {
					cifre_ispred++;
					if(plusIspred==kopija3) break;
					plusIspred--;
				}
				if((plusIspred==kopija3 && *(plusIspred)=='-') || (*plusIspred=='-'&& (*(plusIspred-1)=='-' || *(plusIspred-1)=='+') ) ) {
					predznak=-1;

				}
				if(plusIspred!=kopija3 || (plusIspred==kopija3 && *plusIspred=='-') )
					plusIspred++;
				brojIspred_plus=atoi(plusIspred)*predznak;
			}

			plusIza=kopija3+plus_minus[i]+1;
			predznak=1;
			if(postojiLiRezultat[plus_minus[i] +1]) {
				brojIza_plus = rezultati[plus_minus[i] +1];
			} else {
				char *prva_cifra_plusIza=plusIza;
				if(*(prva_cifra_plusIza-1)=='-' && (*(prva_cifra_plusIza-2)=='-' || *(prva_cifra_plusIza-2)=='+')) {
					predznak=-1;
					prva_cifra_plusIza++;
					plusIza++;
				}
				while(*plusIza>='0' && *plusIza<='9') {
					cifre_iza++;
					plusIza++;
				}
				plusIza--; //zadnja cifra broja kojeg sabiramo
				brojIza_plus=atoi(prva_cifra_plusIza)*predznak;
			}

			if(*(kopija3 + plus_minus[i]) =='+')
				broj = brojIspred_plus+brojIza_plus;
			else
				broj = brojIspred_plus-brojIza_plus;

			int j = plus_minus[i], k=0;
			if(plus_minus[i]!=0 && postojiLiRezultat[j-1] ) {
				j--;
				while(j>= 0 && postojiLiRezultat[j]) {
					rezultati[j] = broj;
					j--;
				}
			} else {

				for(k=plus_minus[i] - cifre_ispred; k<plus_minus[i]; k++) {
					postojiLiRezultat[k] = 1;
					rezultati[k] = broj;
				}
			}
			j = plus_minus[i];
			k=0;
			if ( postojiLiRezultat[j +1]) {
				j++;
				while(postojiLiRezultat[j]) {
					rezultati[j] = broj;
					j++;
				}

			} else {

				for(k=plus_minus[i]; k<cifre_iza+plus_minus[i]+1; k++) {
					postojiLiRezultat[k] = 1;
					rezultati[k] = broj;
				}
			}


		}
		for(i=0; *(kopija3+i)!='\0';i++);
		if(postojiPlus) rez = broj;
		else rez= rezultati[i-1];
	}
	return rez;
}
int main()
{
	int rez, ok;
	char niz[100];
	printf("Unesi matematicki izraz.\n");
	unesi(niz, 100);
	rez = izracunaj(niz, &ok);
	if (ok) printf("rezultat je: %d\n", rez);
	else printf("greska\n");

	return 0;
}
