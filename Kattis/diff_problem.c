#include<stdio.h>
int main(){
	 long long int a,b;
	while  (scanf("%lli%lli", &a, &b) == 2)
		{printf("%lli\n",b<a?a-b:b-a);}
	return 0;
}
