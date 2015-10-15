#include <stdio.h>
#include <stdlib.h>

int main()
{
    const n = 5;
    srand( time( 0 ) );
    int array[n];
    int i;
    int zeros = 0;
    for(i = 0; i<n; ++i){
        array[i] = rand() % 3;
        printf("%d\n", array[i]);
    }
    for (i=0; i< n/2; ++i){
        if(array[i] != array[n-i-1]) {
            printf("No");
            return 0;
        }
    }
    printf("Yes");
    return 0;
}
