#include <stdio.h>
#define MAX 100

int heap[MAX];
int front, rear;

void init_queue(void)
{
    front = 0; // 빠져나가야하는 노드의 idx
    rear = 0;
}

int put(int new)
{
    if(rear >= MAX) {
        printf("Queue Overflow\n");
        return -1;
    }
    front = 1;
    heap[++rear] = new;

    return 0;
}

int get(void)
{
    if(rear <= 0) {
        printf("Queue Underflow\n");
        return -1;
    }
    return heap[rear--];
}

void swap(int d, int s)
{
    int temp = heap[s];
    heap[s] = heap[d];
    heap[d] = temp;
}

void upheap(int key)
{
    int new = heap[rear];
    int newIdx = rear;
    while(new < heap[newIdx/2]) {
        // printf("upheap : %d\n",heap[new/2]);
        if((newIdx/2) == 0) {
            break;
        }
        swap(newIdx, newIdx/2);
        newIdx = newIdx/2;
        printf("newIdx : %d\n", newIdx);
        printf("heap[%d] : %d\n", newIdx, heap[newIdx]);
    }

}

void insert_node(int key)
{
    put(key);
    upheap(key);
}

void print_queue(void)
{
    for(int i = front; i <= rear; i ++) {
        printf("%d\n", heap[i]);
    }
}

int main() {
    init_queue();

    for(int i = 2; i < 9; i ++) {
        insert_node(i);
    }
    insert_node(1);

    print_queue();
}