#include <stdio.h>
int obrnuto(int x)
{
	int cifra,broj=0;
	do
	{
		cifra=x%10;
		x=x/10;
		broj=broj*10+cifra;
	}while(x!=0);
	return broj;

}
int main() {
	int x,obrnut;
	printf("Uneiste broj: ");
	scanf("%d", &x);
	obrnut=obrnuto(x);
	printf("Obrnut broj je %d", obrnut);
	return 0;
}
