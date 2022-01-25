#include <stdio.h>

void insertion_sort(int arr[], int n)
{
    int i, j, k;
    for(i = 1; i < n; i ++) { // 비교대상
        int temp = arr[i];
        for(j = 0; j < i; j ++) { // 탐색 범위
            if(arr[j] > arr[i]) {
                for(k = i-1; k >= j; k --) { // 한 칸씩 미루기
                    arr[k] = arr[k+1];
                }
                arr[k+1] = temp;
            }
        }
        for(int i = 0; i < 7; i ++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

int main() {
    int arr[] = {3,2,5,7,6,4,1};

    insertion_sort(arr, 7);
}   