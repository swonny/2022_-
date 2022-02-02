#include <stdio.h>

int binary_search(int arr[], int key, int n)
{
    int mid = n/2, left = 0, right = n-1;
    while(arr[mid] != key && right - left >= 0) {
        printf("arr[%d] : %d\n", mid, arr[mid]);
        if(arr[mid] < key) {
            left = mid+1;
        } else if (arr[mid] > key) {
            right = mid-1;
        }
        mid = (left + right) / 2;
    }
    if(arr[mid] == key) {
        return mid;
    }
    return -1;
}

int main() {
    int arr[] = {1,2,3,4,5,6};

    int idx = binary_search(arr, 2, 6);
    printf("arr[%d] : %d\n ", idx, arr[idx]);
}



