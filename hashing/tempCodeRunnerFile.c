#include <stdio.h>
#include <stdlib.h>

#define SIZE 7

struct Node
{
    int data;
    struct Node *next;
};

struct Node *chainTable[SIZE];

int hashFunc(int key)
{
    return key % SIZE;
}

void chainInsert(int key)
{
    int index = hashFunc(key);
    struct Node *node = malloc(sizeof(struct Node));
    node->data = key;
    node->next = chainTable[index];
    chainTable[index] = node;
}

void chainDelete(int key)
{
    int index = hashFunc(key);
    struct Node *curr = chainTable[index], *prev = NULL;

    while (curr)
    {
        if (curr->data == key)
        {
            if (prev == NULL)
                chainTable[index] = curr->next;
            else
                prev->next = curr->next;
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

int chainSearch(int key)
{
    int index = hashFunc(key);
    struct Node *t = chainTable[index];
    while (t)
    {
        if (t->data == key)
            return 1;
        t = t->next;
    }
    return 0;
}

void chainDisplay()
{
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d: ", i);
        struct Node *t = chainTable[i];
        while (t)
        {
            printf("%d -> ", t->data);
            t = t->next;
        }
        printf("NULL\n");
    }
}

#define DELETED -1
int linearTable[SIZE];

void linearInsert(int key)
{
    int index = hashFunc(key);
    while (linearTable[index] != 0 && linearTable[index] != DELETED)
        index = (index + 1) % SIZE;
    linearTable[index] = key;
}

void linearDelete(int key)
{
    int index = hashFunc(key);
    int start = index;

    while (linearTable[index] != 0)
    {
        if (linearTable[index] == key)
        {
            linearTable[index] = DELETED;
            return;
        }
        index = (index + 1) % SIZE;
        if (index == start)
            break;
    }
}

int linearSearch(int key)
{
    int index = hashFunc(key);
    int start = index;

    while (linearTable[index] != 0)
    {
        if (linearTable[index] == key)
            return 1;
        index = (index + 1) % SIZE;
        if (index == start)
            break;
    }
    return 0;
}

int quadTable[SIZE];

void quadInsert(int key)
{
    int index = hashFunc(key);
    int i = 1;

    while (quadTable[index] != 0 && quadTable[index] != DELETED)
    {
        index = (key + i * i) % SIZE;
        i++;
    }
    quadTable[index] = key;
}

int quadSearch(int key)
{
    int index = hashFunc(key);
    int i = 1;

    while (quadTable[index] != 0)
    {
        if (quadTable[index] == key)
            return 1;
        index = (key + i * i) % SIZE;
        i++;
    }
    return 0;
}

void quadDelete(int key)
{
    int index = hashFunc(key);
    int i = 1;

    while (quadTable[index] != 0)
    {
        if (quadTable[index] == key)
        {
            quadTable[index] = DELETED;
            return;
        }
        index = (key + i * i) % SIZE;
        i++;
    }
}

int doubleTable[SIZE];

int h2(int key)
{
    return 1 + (key % (SIZE - 1));
}

void doubleInsert(int key)
{
    int index = hashFunc(key);
    int step = h2(key);

    while (doubleTable[index] != 0 && doubleTable[index] != DELETED)
        index = (index + step) % SIZE;

    doubleTable[index] = key;
}

int doubleSearch(int key)
{
    int index = hashFunc(key);
    int step = h2(key);

    while (doubleTable[index] != 0)
    {
        if (doubleTable[index] == key)
            return 1;
        index = (index + step) % SIZE;
    }
    return 0;
}

void doubleDelete(int key)
{
    int index = hashFunc(key);
    int step = h2(key);

    while (doubleTable[index] != 0)
    {
        if (doubleTable[index] == key)
        {
            doubleTable[index] = DELETED;
            return;
        }
        index = (index + step) % SIZE;
    }
}

void linearDisplay()
{
    for (int i = 0; i < SIZE; i++)
        printf("%d ", linearTable[i]);
    printf("\n");
}

void quadDisplay()
{
    for (int i = 0; i < SIZE; i++)
        printf("%d ", quadTable[i]);
    printf("\n");
}

void doubleDisplay()
{
    for (int i = 0; i < SIZE; i++)
        printf("%d ", doubleTable[i]);
    printf("\n");
}

int main()
{

    /* ========= CHAINING ========= */
    printf("\n===== CHAINING =====\n");
    chainInsert(10);
    chainInsert(17);
    chainInsert(24);

    printf("Before delete:\n");
    chainDisplay();

    chainDelete(17);

    printf("After delete:\n");
    chainDisplay();

    printf("Search 24: %d\n", chainSearch(24));

    /* ========= LINEAR PROBING ========= */
    printf("\n===== LINEAR PROBING =====\n");
    linearInsert(10);
    linearInsert(17);
    linearInsert(24);

    printf("Before delete:\n");
    linearDisplay();

    linearDelete(17);

    printf("After delete:\n");
    linearDisplay();

    printf("Search 24: %d\n", linearSearch(24));

    /* ========= QUADRATIC PROBING ========= */
    printf("\n===== QUADRATIC PROBING =====\n");
    quadInsert(10);
    quadInsert(17);
    quadInsert(24);

    printf("Before delete:\n");
    quadDisplay();

    quadDelete(17);

    printf("After delete:\n");
    quadDisplay();

    printf("Search 24: %d\n", quadSearch(24));

    /* ========= DOUBLE HASHING ========= */
    printf("\n===== DOUBLE HASHING =====\n");
    doubleInsert(10);
    doubleInsert(17);
    doubleInsert(24);

    printf("Before delete:\n");
    doubleDisplay();

    doubleDelete(17);

    printf("After delete:\n");
    doubleDisplay();

    printf("Search 24: %d\n", doubleSearch(24));

    return 0;
}
