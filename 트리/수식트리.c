#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct Node{
    int key;
    struct Node *left;
    struct Node *right;
};

int top = 0;

struct Node stack[MAX];

void init_stack(void)
{
    struct Node *stack = malloc(sizeof(struct Node)*10);
}

struct Node pop(void)
{

    return stack[--top];
}

void push(struct Node node)
{
    stack[top++] = node;
}

int main() {

}