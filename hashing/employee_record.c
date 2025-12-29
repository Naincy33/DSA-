
#include <stdio.h>
#define MAX 100

int main() {
    int HT[MAX], m, n, key, index, i;
    int collisions = 0;

    printf("Enter size of hash table (m): ");
    scanf("%d", &m);
    if (m > MAX) {
        printf("Maximum table size is %d\n", MAX);
        return 1;
    }

    for (i = 0; i < m; i++) {
        HT[i] = -1;
    }

    printf("Enter number of employee records (n): ");
    scanf("%d", &n);

    if (n > m) {
        printf("Error: Hash table overflow!\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("Enter 4-digit employee key: ");
        scanf("%d", &key);

        index = key % m;

        while (HT[index] != -1) {
            collisions++;
            index = (index + 1) % m;
        }

        HT[index] = key;
    }

    printf("\nHash table contents:\n");
    for (i = 0; i < m; i++) {
        if (HT[i] != -1) {
            printf("HT[%d] = %d\n", i, HT[i]);
        } else {
            printf("HT[%d] = EMPTY\n", i);
        }
    }

    printf("\nTotal number of collisions: %d\n", collisions);

    return 0;
}
