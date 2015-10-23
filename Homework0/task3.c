#include <stdio.h>
#include <stdlib.h>

int my_degree (int a, int n){
    if (n==0) {
        return 1;
    }
    if(n>1) {
        return my_degree(a, n-1)*a;
    }
    else {
        return a;
    }
}

int main(){
    int a, n;
    scanf("%d, %d", &a, &n);
    if(n>0){
        printf("%d", my_degree(a,n));
    }
    else {
        printf("%f", 1/my_degree(a,-n));
    }
    return 0;
}
