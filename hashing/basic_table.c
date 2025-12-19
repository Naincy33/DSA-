#include<stdio.h>
#define SIZE 7

int table[SIZE];

int hashFunc(int key){
    return key%SIZE;
}

void insert(int key){
    int index = hashFunc(key);
    table[index]= key;
}


int search(int key){
    int index = hashFunc(key);
    return table[index]== key;
}

void display(){
    for(int i=0;i<SIZE;i++){
        printf("%d ",table[i]);
    }
    printf("\n");
}

void delete(int key){
    int index = hashFunc(key);
    table[index] = -1; // mark as deleted
}

int main() {
    insert(10);
    insert(17);   // collision → overwrite
    insert(24);   // collision → overwrite
    display();    // should show the current state of the table


    printf("%d\n", search(10)); 
    printf("%d\n", search(17)); 
    printf("%d\n", search(24));
    delete(17);
    display();    // should show the current state of the table after deletion
    
    return 0;
}