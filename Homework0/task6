#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main()
{
    int i,n;
    char myString[100];
    fgets(myString, 100, stdin);
    for(i=0; i<strlen(myString); ++i ){
            myString[i] = toupper(myString[i]);
    }
    printf("%s", myString);
    n = strlen(myString)-2;
    for(i=0; n-i>0; i++){
        if (myString[i] == ' '){
            continue;
        }
        if (myString[n] == ' ') {
            n -= 1;
        }
        printf("%c, %c\n", myString[i], myString[n]);
        if (myString[i] != myString[n]) {
            printf("NO");
            return 0;
        }
        n -= 1;
    }
    printf("YES");
}
