#include <stdio.h>
#include <stdlib.h>

/*
    단순연결리스트 스택 구현
    # 고려해야하는 부분
    1. 이중연결리스트로 구현
    2. head == stack,  tail == top
    3. 더미노드 존재
*/

struct Node {
    int data;
    struct Node *next;
};

struct LinkedListStack {
    struct Node *top; // tail 대신
    struct Node *stack; // head 대신
    // int count;
};

void createStack(struct LinkedListStack **stack)
{
    (*stack) = malloc(sizeof(struct LinkedListStack));
    // (*stack)->stack = malloc(sizeof(struct LinkedListStack));
    (*stack)->top = malloc(sizeof(struct LinkedListStack));
    // count = 0;
}

void push(struct LinkedListStack *stack, int data)
{
    struct Node *node =  malloc(sizeof(struct Node));
    node->data = data;
    node->next = stack->top->next;
    stack->top->next = node;
}

struct Node *pop(struct LinkedListStack *stack)
{
    struct Node *node = stack->top;
    stack->top = stack->top->next;
    return node;
}

int main()  {
    struct LinkedListStack *stack;
    
    createStack(&stack);
}