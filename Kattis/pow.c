#define false 0
#define true 1
#define MAX 2000000
#include <stdio.h>
#include <string.h>
typedef int bool;
int main()
{
    char s[MAX];
    bool trouv;
    int i,j,N;
    while(gets(s)&&s[0]!='.'){
        N = strlen(s);
        trouv = 1;
        for(i=1;i<N-1;i++){
            for(j=i;j<N;j++)
                if(s[j]!=s[j%i]){
                    trouv = 0;
                    break;
                }
	        if(trouv)
	            break;
	        trouv = 1;
	        }
        if(trouv)
			printf("%d\n",N/i);
        else 
			printf("%d\n",N);
    }
    return 0;
}
