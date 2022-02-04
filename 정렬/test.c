#include <stdio.h>
#include <stdlib.h>
struct Node {
    int key;
    struct Node *next;
};

struct Node stack[100];

int main() {
    // struct Node *new = malloc(sizeof(struct Node));
    struct Node new;
    new.key = 3;
    stack[0].next = &new;

    printf("%d", stack[0].next->key);
}