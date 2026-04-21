#include <stdio.h>

#define EMPTY -1

int hash(int key, int m) {
    return key % m;
}

void insert(int table[], int m, int key) {
    int h = hash(key, m);

    for (int i = 0; i < m; i++) {
        int index = (h + i * i) % m;

        if (table[index] == EMPTY) {
            table[index] = key;
            return;
        }
    }
}

int search(int table[], int m, int key) {
    int h = hash(key, m);

    for (int i = 0; i < m; i++) {
        int index = (h + i * i) % m;

        if (table[index] == key)
            return 1;

        if (table[index] == EMPTY)
            return 0;
    }

    return 0;
}

int main() {
    int m, q;

    scanf("%d", &m);
    scanf("%d", &q);

    int table[m];

    for (int i = 0; i < m; i++)
        table[i] = EMPTY;

    for (int i = 0; i < q; i++) {
        char op[10];
        int key;

        scanf("%s %d", op, &key);

        if (op[0] == 'I') {
            insert(table, m, key);
        }
        else if (op[0] == 'S') {
            if (search(table, m, key))
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}  