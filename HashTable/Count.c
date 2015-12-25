#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"

void fillWords (hashTable *HashTable, FILE *fp)
{
    if(fp == NULL)
    {
        printf("Cannot open file");
        return;
    }
    int i = 0;
    char word[maxLength];
    char c;
    do
    {
        c = fgetc(fp);
        if ((c == EOF || c == '\n' || c == '\t' || c == ' ') && strlen(word) != 0)
        {
            set(HashTable, word, get(HashTable, word) + 1);
            i = 0;
        }
        else
        {
            if ('A' <= c && c <= 'Z' || 'a' <= c && c <= 'z' || '0' <= c && c <= '9' || c == '`')
            {
                word[i] = c;
                word[i+1] = '\0';
                i++;
            }
        }
    }
    while (c != EOF);
    fclose(fp);
}


int main()
{
    FILE *fp = fopen ("input.txt", "r");
    if(fp == NULL)
    {
        printf("Cannot open file");
    }
    hashTable *MyTable = CreateTable(10000, Hash2);
    fillWords(MyTable, fp);
    statistics(MyTable);
    deleteTable(MyTable);
    return 0;
}
