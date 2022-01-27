/*
    quickSort 짜기
    축을 하나 정하고 left와 right를 넘겨서 left와 right를 비교하여 arr[left] 중 축보다 큰 값을 arr[right] 중 축보다 작은 값과 교환
    - 10과 0을 비교하는 예외 케이스도 고려하기
    - 비교 범위를 넘겨주고 비교범위로
 */

#include <stdio.h>

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
            swap(arr, left++, right--); // 수정 필요
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

void recursive(int arr[], int left, int right)
{
    printf("called recursive\n");
    if((right - left) > 0 ) {
        int pivot = partition(arr, left, right);
        /* left와 right 갱신 필요 -->  */
        recursive(arr, left, pivot-1);
        recursive(arr, pivot+1, right); // 수정 필요 - right를 어떤 걸로 잡을지
    }
}

int main() {
    // int arr[] = {3,2,4,8,1,5,7};
    int arr[] = {0,3,2,4,5};

    // partition(arr, 0, 4);
    recursive(arr, 0, 4);
    for(int i = 0; i < 5; i ++) {
        printf("%d ", arr[i]);
    }
}