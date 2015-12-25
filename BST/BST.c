#include <stdio.h>
#include <stdlib.h>

typedef struct BT BT;

struct BT
{
    int value;
    struct BT *left, *right;
};

char CheckMembership(BT *root, int Elem)
{
    if (root->value == Elem)
    {
        return 1;
    }
    else
    {
        if (root->value > Elem)
        {
            return CheckMembership(root->left, Elem);
        }
        if (root->value < Elem)
        {
            return CheckMembership(root->right, Elem);
        }
    }
    return 0;
}

BT *newTree(int data)
{
    BT *tmp = (BT*)malloc(sizeof(BT));
    if (tmp == NULL)
    {
        printf("Memory is not allocated");
        return NULL;
    }
    tmp->value = data;
    tmp->left = tmp->right = NULL;
    return tmp;
}

BT *addElem(BT *root, int data)
{
    if (root == NULL)
    {
        return newTree(data);
    }
    else if (data < root->value)
    {
        root->left = addElem(root->left, data);
    }
    else if (data > root->value)
    {
        root->right = addElem(root->right, data);
    }
    return root;
}

BT *leftmost(BT *root)
{
    if (root->left == NULL)
    {
        return root;
    }
    return leftmost(root->left);
}

BT *deleteElem(BT *root, int Elem)
{
    BT *tmp;
    if (root->value == Elem)
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        if (root->left == NULL)
        {
            BT *tmp = root->right;
            free(root);
            return tmp;
        }
        if (root->right == NULL)
        {
            BT *tmp = root->left;
            free(root);
            return tmp;
        }
        BT *tmp = leftmost(root->right);
        root->value = tmp->value;
        root->right = deleteElem(root->right, tmp->value);
    }
    if (root == NULL)
    {
        printf("Element is not in the tree");
        return NULL;
    }
    if (Elem < root->value)
    {
        root->left = deleteElem(root->left, Elem);
    }
    else if(Elem > root->value)
    {
        root->right = deleteElem(root->right, Elem);
    }
    return root;
}

void printDesc(BT *root) // >
{
    if (root == NULL)
    {
        return;
    }
    printDesc(root->right);
    printf("%d ",root->value);
    printDesc(root->left);
}

void printAsc(BT *root) // <
{
   if (root == NULL)
    {
        return;
    }
    printAsc(root->left);
    printf("%d ",root->value);
    printAsc(root->right);
}

void printBT(BT *root)
{
    printf("( %d ", root->value);
    if (root->left == NULL)
    {
        printf("null ");
    }
    else
    {
        printBT(root->left);
    }
    if (root->right == NULL)
    {
        printf("null ");
    }
    else
    {
        printBT(root->right);
    }
    printf(") ");
}

void freeTable(BT *root)
{
    if (root == NULL)
    {

    return;
    }
    freeTable(root->left);
    freeTable(root->right);
    free(root);
    return;
}

int main()
{
    int j = 0;
    BT* root = NULL;
    while(j == 0)
    {
        char enter;
        int val;
        scanf("%c", &enter);
        switch (enter)
        {
            case 'a':
                scanf("%d", &val);
                root = addElem(root, val);
            break;
            case 'r':
                scanf("%d", &val);
                root = deleteElem(root, val);
            break;
             case 'f':
                scanf("%d", &val);
                printf("%d\n", CheckMembership(root, val));
            break;
            case 'p':
                printBT(root);
                printf("\n");
            break;
             case 's':
                printAsc(root);
                printf("\n");
            break;
             case 'd':
                printDesc(root);
                printf("\n");
            break;
            case 'q':
                freeTable(root);
                j = 1;
            break;
        }
    }
    return 0;
}
