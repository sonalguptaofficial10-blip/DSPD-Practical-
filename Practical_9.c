#include <stdio.h>

#define SIZE 7

int hashFunction(int key) {
    return key % SIZE;
}

void insert(int hashTable[], int key) {
    int index = hashFunction(key);
    int startIndex = index;

    // Linear probing
    while (hashTable[index] != -1) {
        index = (index + 1) % SIZE;
        if (index == startIndex) {
            printf("Hash table is full, cannot insert %d\n", key);
            return;
        }
    }
    hashTable[index] = key;
}

void display(int hashTable[]) {
    printf("\nFinal Hash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] != -1)
            printf("Slot %d --> %d\n", i, hashTable[i]);
        else
            printf("Slot %d --> [empty]\n", i);
    }
}

int main() {
    int hashTable[SIZE];
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;

    int n, key;
    printf("Enter number of keys to insert: ");
    scanf("%d", &n);

    printf("Enter %d keys:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &key);
        insert(hashTable, key);
    }

    display(hashTable);
    return 0;
}
