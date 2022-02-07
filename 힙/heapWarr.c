#include <stdio.h>
#define MAX 100

int heap[MAX];
int front, rear;

void init_queue(void)
{
    front = 0; // 빠져나가야하는 노드의 idx
    rear = 0;
}

int put(int n)
{
    if(rear >= MAX) {
        printf("Queue Overflow\n");
        return -1;
    }
    front = 1;
    heap[++rear] = n;

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
    int n = heap[rear];
    int newIdx = rear;
    while(n < heap[newIdx/2]) {
        if((newIdx/2) == 0) {
            break;
        }
        swap(newIdx, newIdx/2);
        newIdx = newIdx/2;
    }

}
/*
    다운힙
    1. heap[front]과 heap[rear] 교환
    (만약 front*2가 rear보다 크다면 break)
    2. front*2 보다 작은지 비교
    3. front*2+1보다 작은지 비교
    4. 둘 중 큰 것과 교환
*/
void downheap(void)
{
    int tempIdx = front;
    swap(front, rear);
    rear--;
    while(heap[tempIdx] > heap[tempIdx*2] || heap[tempIdx] > heap[tempIdx*2+1]){
        if(tempIdx*2 > rear) {
            break;
        }
        if((tempIdx*2+1) <= rear && heap[tempIdx*2] > heap[tempIdx*2+1]) {
            swap(tempIdx, tempIdx*2+1);
            tempIdx = tempIdx*2+1;
        } else {
            swap(tempIdx, tempIdx*2);
            tempIdx *= 2;         
        }
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

    printf("\n\n");
    downheap();
    downheap();
    print_queue();
}