#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,j;
    scanf("%d", &n);
    int arr[n] ;
    for (i=1; i<=n; ++i) {
        arr[i] = 1;
    }
    i = 2;
    while(i<n){
            for (j=2*i; j<=n; j+=i){
                arr[j] = 0;
            }
            do{
                i=i+1;
            } while (arr[i]==0);
    }
    for (i=1; i<=n; ++i) {
        if(arr[i]) {
                printf("%d ", i);
        }
    }
    return 0;
}
