#include <stdio.h>
#include <stdlib.h>

struct node { // 배열
    int data;
};

struct ArrayStack { // 스택 정보
    int capacity;
    int top;
    struct node *nodes;
};

void createStack(struct ArrayStack **stack, int capacity) // 메모리 할당
{
    *stack = malloc(sizeof(struct node)*capacity);

    (*stack)->nodes = malloc(sizeof(struct node)*capacity); // capacity 크기 만큼의 배열 생성 
    
    (*stack)->capacity = capacity; // capacity 저장
 
    (*stack)->top = 0; // top idx 0으로 초기화

}

// ArrayStack -> nodes에 배열이 선언되었기 때문에 삭제할 때는 nodes 삭제 -> ArrayStack 삭제 순서로 삭제해야한다.
void destroyStack(struct ArrayStack *stack) // 
{
    free(stack->nodes);
    free(stack);
}

int getSize(struct ArrayStack *stack)
{
    return stack->top;
}

int pop(struct ArrayStack *stack) 
{
    if(getSize(stack) <= 0) {
        printf("Stack Underflow\n");
        return 0;
    }
    return stack->nodes[--(stack->top)].data;
}

int push(struct ArrayStack *stack, int data)
{
    if(getSize(stack) >= stack->capacity) {
        printf("Stack Overflow\n");
        return 0;
    }
    stack->nodes[stack->top++].data = data;
    printf("!!! %d\n", stack->top);

    return 1;
}

int top(struct ArrayStack *stack)
{
    return stack->nodes[--(stack->top)].data;
}

int isEmpty(struct ArrayStack *stack)
{
    if(stack->top == 0) {
        return 0; // 비어있는 경우
    }
    return 1; // 비어있지 않은 경우
}

int main() {
    struct ArrayStack *AS_stack;
    createStack(&AS_stack, 100);
    push(AS_stack, 3);
    push(AS_stack, 6);


    // while(isEmpty(AS_stack)) {
    //     printf("data : %d\n", pop(AS_stack));
    // }
    destroyStack(AS_stack);

    // printf("%d", isEmpty(AS_stack));
    printf("after free : %d\n", pop(AS_stack));
}