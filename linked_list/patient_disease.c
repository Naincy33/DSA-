#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct patient {
    char name[30];
    char disease[30];
    int age;
    struct patient *next;
};

struct patient *start = NULL;

void insertPatient(char name[], char disease[], int age) {
    struct patient *newnode = (struct patient*)malloc(sizeof(struct patient));
    strcpy(newnode->name, name);
    strcpy(newnode->disease, disease);
    newnode->age = age;
    newnode->next = NULL;

    if(start == NULL) {
        start = newnode;
    } else {
        struct patient *temp = start;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }
}

void countDiseases() {
    struct patient *temp1 = start;
    struct patient *temp2;
    int count;
    int visited;

    printf("\nDisease-wise Patient Count:\n");

    while(temp1 != NULL) {
        visited = 0;
        temp2 = start;

        // Check if disease already counted
        while(temp2 != temp1) {
            if(strcmp(temp2->disease, temp1->disease) == 0) {
                visited = 1;
                break;
            }
            temp2 = temp2->next;
        }

        if(!visited) {
            count = 0;
            temp2 = temp1;
            while(temp2 != NULL) {
                if(strcmp(temp2->disease, temp1->disease) == 0)
                    count++;
                temp2 = temp2->next;
            }
            printf("%s : %d\n", temp1->disease, count);
        }

        temp1 = temp1->next;
    }
}

int main() {
    int n, age;
    char name[30], disease[30];

    printf("Enter number of patients: ");
    scanf("%d", &n);

    printf("Enter patient details (Name Disease Age):\n");
    for(int i = 0; i < n; i++) {
        scanf("%s %s %d", name, disease, &age);
        insertPatient(name, disease, age);
    }

    countDiseases();

    return 0;
}
