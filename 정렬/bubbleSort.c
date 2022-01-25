#include <stdio.h>
#define MAX 100

void swap(int arr[], int dest, int start) 
{
    char temp = arr[start];
    arr[start] = arr[dest];
    arr[dest] = temp;
}

void  bubbleSort(int arr[])
{
    int flag = 0;
    int i, j;
    for(i = 6; i > 0; i --) {
        for(j = 1; j < i; j ++) {
            if(arr[j-1] > arr[j]) {
                swap(arr, j-1, j);
            } else if(arr[j-1] < arr[j]) {
                continue;
            }
        }
        for(int i = 0; i < 6; i ++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

int main() {
    int arr[] = {3,2,1,6,4,5};

    bubbleSort(arr);
}