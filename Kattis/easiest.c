#include<stdio.h>
unsigned long int sum_digit(unsigned long int nb)
{  int sum = 0;
  while (nb) {
    sum += nb % 10;
    nb /= 10;
  }
  return sum;
}
int main(){
    unsigned long int N,p;
        while (scanf("%lu", &N) && N != 0 ){
        		p=11;
        		while (sum_digit(++p*N) != sum_digit(N));
				printf("%lu",p);
				}
   		}
