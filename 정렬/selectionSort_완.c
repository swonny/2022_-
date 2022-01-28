/* 선택정렬 구현 완성 */

#include <stdio.h>

void swap(int arr[], int d, int s)
{
    int temp = arr[s];
    arr[s] = arr[d];
    arr[d] = temp;
}

void selection_sort(int arr[], int n)
{
    int sIdx = -1;
    for(int i = 0; i < n-1; i ++) {
        sIdx = i; // 정렬되지 않은 영역의 가장 첫번째 idx
        for(int j = i+1; j < n; j ++) {
            if(arr[j] < arr[sIdx]) {
                sIdx = j;
            }
        }
        swap(arr, sIdx, i);
        for(int i = 0; i < 7;  i ++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

int main() {
    int arr[] = {0,4,8,3,1,9,7};

    selection_sort(arr, 7);

    for(int i = 0; i < 7;  i ++) {
        printf("%d ", arr[i]);
    }
}