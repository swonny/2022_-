/* 퀵정렬 비재귀 구현 */

#include <stdio.h>
#include <stdlib.h>

struct node {
    int left;
    int right;
    struct node *next;
};

struct node *head;

void init_stack(void)
{
    head = malloc(sizeof(struct node));
    head->next = NULL;
}

void push(int left, int right) // 노드 key 값 전달받아 삽입
{
    struct node *new = malloc(sizeof(struct node));
    new->left = left;
    new->right = right;
    new->next = head->next;
    head->next = new;
}

struct node *pop(void)
{
    struct node *temp = head->next;
    head->next = head->next->next;
    return temp;
}

void swap(int arr[], int d, int s)
{
    int temp = arr[s];
    arr[s] = arr[d];
    arr[d] = temp;
}

int partition(int arr[], int left, int right)
{
    int pivot = left;
    left++;
    while(left <= right) {
        while(arr[left] < arr[pivot] && left <= right){
            left ++;
        }
        while(arr[right] > arr[pivot] && left <= right) {
            right --;
        }
        if(left < right) {
            swap(arr, left++, right--);
        }
        for(int i = 0; i < 5; i ++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    swap(arr, right, pivot);
    for(int i = 0; i < 5; i ++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return right;
}

void recursive(int arr[], int l, int r)
{
    int left = l, right = r, newLeft, newRight, pivot;
    struct node *temp;
    
    while(1) { // 더이상 비교할 숫자가 없을 때까지
        if(head->next != NULL) {
            temp = pop();
            left = temp->left;
            right = temp->right;
        }
        while(right - left > 0) { // 맨 처음으로 분할한 왼쪽 영역을 모두 정렬할 때까지
            pivot = partition(arr, left, right);
            newLeft = pivot + 1;
            newRight = right;
            push(newLeft, newRight); // 오른쪽 영역을 위한 push

            right = pivot - 1 ;
        }
        if (head->next == NULL) {
            break;
        }
    }
}

int main() {
    int arr[] = {2,3,1,5,4};
    init_stack();

    recursive(arr, 0, 4);
    for(int i = 0; i < 5; i ++) {
        printf("%d ", arr[i]);
    }
}