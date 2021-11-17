#include<stdio.h>


float alanlar_toplami(int n, float yaricap, int kacinci_daire)
{
  if (kacinci_daire < n)
  {
    return (3.14 * yaricap * yaricap) + alanlar_toplami(n, yaricap / 2.0, ++kacinci_daire);
  }
  else{
  	return 0.0;
  }
}
int main() 
{
  int n;
  float yaricap;
  printf("Daire sayisini giriniz : ");
  scanf("%d", &n);
  printf("Yaricap degerini giriniz : ");
  scanf("%f", &yaricap);
  int kacinci_daire = 0;
  float alan = alanlar_toplami(n, yaricap, kacinci_daire);
  printf("%f", alan);
  return 0;
}
