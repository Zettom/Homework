#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxLength 100000
typedef struct node node;
typedef struct hashTable hashTable;
typedef int (*HashFunction)(char*, int);
struct node
{
    char key[maxLength];
    int value;
    struct node *next;
};

struct hashTable
{
    int size;
    node **table;
    HashFunction hashFunc;
};

hashTable *CreateTable(int size, HashFunction HashFunc)
{
    hashTable *newTable;
    newTable = (hashTable*)malloc(sizeof(node));
    if (newTable == NULL)
    {
        printf("Memory is not allocated");
        return NULL;
    }
    newTable->table = (node*)malloc(sizeof(node) * size);
    if (newTable->table == NULL)
    {
        printf("Memory is not allocated");
        return NULL;
    }
    int i;
    for(i = 0; i < size; i++)
    {
        newTable->table[i] = NULL;
    }
    newTable->size = size;
    newTable->hashFunc = HashFunc;
    return newTable;
}

void deleteTable(hashTable *HashTable)
{
    int i = 0;
    for(i; i < HashTable->size; i++)
    {
        deleteCell(&(HashTable->table[i]));
    }
    free(HashTable);
}

void deleteCell(node **head)
{
    node *tmp;
    while ((*head) != NULL)
        {
            tmp = (*head);
            (*head) = (*head)->next;
            free(tmp);
        }
}

node *search(hashTable *HashTable, char *key)
{
    int number = HashTable->hashFunc(key, HashTable->size);
    node *tmp = HashTable->table[number];
    while(tmp != NULL)
    {
        if(strcmp(key, tmp->key) == 0)
        {
            return tmp;
        }
        tmp = tmp->next;
    }
    return tmp;
}


void set (hashTable *HashTable, char *key, int value)
{
    node *tmp = search(HashTable, key);
    if (tmp != NULL)
    {
        tmp->value = value;
    }
    else
    {
        int number = HashTable->hashFunc(key, HashTable->size);
        tmp = (node*)malloc(sizeof(node));
        if (tmp == NULL)
        {
            printf("Memory is not allocated");
            return;
        }
        tmp->value = value;
        strcpy(tmp->key, key);
        tmp->next = HashTable->table[number];
        HashTable->table[number] = tmp;
    }

}

int get(hashTable *HashTable, char *key)
{
    node *tmp = search(HashTable, key);
    if (tmp)
    {
        return tmp->value;
    }
    else
    {
        return NULL;
    }
}

int del(node **head, char *key)
{
    if ((*head) != NULL)
    {
        if (strcmp((*head)->key, key) == 0)
        {

            node *tmp = (*head);
            if ((*head)->next != NULL)
            {
                (*head) = (*head)->next;
            }
            else
            {
                (*head) = NULL;
            }
            free(tmp);
            return 1;
        }
        else
        {

            node *tmp1, *tmp2;
            tmp1 = (*head);
            tmp2 = (*head)->next;
            while (tmp2 != NULL)
            {
                if (strcmp(tmp2->key, key) == 0)
                {
                    tmp1->next = tmp2->next;
                    free(tmp2);
                    return 1;
                }
                tmp1 = tmp1->next;
                tmp2 = tmp1->next;
            }

        }
    }
    return 0;

}

void removeNode(hashTable *Hashtable, char *key)
{
    int number = Hashtable->hashFunc(key, Hashtable->size);
    if (!del(&(Hashtable->table[number]), key))
    {
        printf("This string is not in the table\n");
    }
}

int Hash1(char *key, int sizeOfTable)
{
    return 5;
}

int Hash2(char *key, int sizeOfTable)
{
    int l = strlen(key);
    int i;
    int hash = 0;
    for (i = 0; i < l; i++)
    {
        hash = hash + (int)key[i];
    }
    return hash % sizeOfTable;
}

int Hash3(char *key, int sizeOfTable)
{
    int i = 0;
    int p = 53;
    long long hash = 0;
    while(key[i]!='\0')
    {
        hash = (hash * p + key[i++]) % sizeOfTable;
    }
    return hash;
}

void printTable(hashTable *Table)
{
    int i = 0;
    for(i; i < Table->size; i++)
    {
        node *tmp = Table->table[i];
        p(&tmp, i);
    }
}

void p(node **head, int i)
{
    printf("Elements of cell %d:\n\n", i);
    node *tmp = (*head);
    while (tmp != NULL)
    {
        printf("%s\n", tmp->key);
        tmp = tmp->next;
    }
    printf("\n");
}

void fillTable(hashTable *HashTable, FILE *fp)
{
    if(fp == NULL)
    {
        printf("Cannot open file");
        return;
    }
    int i = 0;
    int data;
    char str[maxLength];
    while(fgets(str, sizeof(str), fp))
    {
        data = strlen(str);
        str[strlen(str)-1] = '\0';
        set(HashTable, str, data);
    }
    fclose(fp);
}

void statistics(hashTable *HashTable)
{
    int filled = 0;
    int sum = 0;
    int min = maxLength + 1;
    int max = -1;
    int num = 0;
    int i = 0;
    for (i; i < HashTable->size; i++)
    {
        if (HashTable->table[i] != NULL)
        {
            filled += 1;
            node *tmp = HashTable->table[i];
            while (tmp != NULL)
            {
                num += 1;
                sum += 1;
                tmp = tmp->next;
            }
            if (num < min)
            {
                min = num;
            }
            if (num > max)
            {
                max = num;
            }
            num = 0;
        }
    }

    double avg = (double)sum / (double)filled;
    printf("The number of non-empty cells: %d\n", filled);
    printf("The number of elements: %d\n", sum);
    printf("The average length of chain: %f\n", avg);
    if(min != maxLength + 1)
    {
        printf("The minimum length of the non-empty chain: %d\n", min);
    }
    if(max != -1)
    {
        printf("The maximum length of the chain: %d\n", max);
    }
}

