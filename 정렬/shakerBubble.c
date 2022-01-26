// 양쪽에서 동시에 탐색 

/*
    왼쪽에서는 가장 큰 값을 가장 우측으로, 오른쪽에서는 가장 작은 값을 왼쪽으로
    1. 첫번째 for문의 i는 0부터 n-2까지 (인덱스는 n-1까지니까)
       1.1 만약 arr[i] > arr[i+1]인 경우 두 개 swap 후 break & i++된 인덱스의 숫자와 나머지 비교
    2. 두번째 for문의 j는 n-2-i부터 0까지
       2.1 만약 arr[j] < arr[j-1]인 경우 두 개 swap 후 break & i--된 인덱스부터 다시 검사
    5 1 2 4 3 6
*/
#include <stdio.h>
#define MAX 100

void swap(int arr[], int d, int s)
{
    int temp = arr[s];
    arr[s] = arr[d];
    arr[d] = temp;
}

void bubble_sort(int arr[], int n)
{
    int i=-1, j=0, k;
    
    for(k = n-1; k > 0; k--) {
        for(i = j; i < k; i ++) {
            if(arr[i] > arr[i+1]) {
                 swap(arr, i, i+1);
            }
        }
        for(j = n-2-i; j > 0; j --) {
            if(arr[j] < arr[j-1]) {
                swap(arr, j, j-1);
            }
        }
        for(int i = 0; i < 6; i ++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

/*
    5 1 4 3 2 6
*/

int main() {
    int arr[] = {5,6,1,4,3,2};

    bubble_sort(arr, 6);
}