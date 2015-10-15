#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i;
    scanf("%d", &n);
    int fib;
    int fib0 = 0;
    int fib1 = 1;
    for(i = 0; i<(n-1); ++i){
        fib = fib1 + fib0;
        fib0 = fib1;
        fib1 = fib;
    }
    if(n != 0) {
            printf("%d", fib1);
    }
    else {
        printf("%d", fib0);
    }
}
