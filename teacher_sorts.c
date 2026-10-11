#include <stdio.h>

#define SWAP(a, b) {int temp = (a); (a) = (b); (b) = temp; }

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%-2d", arr[i]);
    printf("\n");
}

void sortBubble(int arr[], int n) {
    int i, j;
   
    for (i = 0; i < n - 1; i++){
        for (j = 0; j < n - 1-i; j++){
            if(arr[j] > arr[j+1])
                SWAP(arr[j], arr[j+1]);
        }
    }
            
}

void sortSelection(int arr[], int n) {
    int i, j, idx;
   
    for (i = 0; i < n - 1; i++) {
        idx = i;
        for (j = i + 1; j < n; j++)
            if(arr[j] < arr[idx])
                idx = j;
        if(idx != i)
            SWAP(arr[i], arr[idx])
    }
}

void sortInsertion(int arr[], int n) {
    int i, j, tmp;

    for (i = 1; i < n; i++) {
        tmp = arr[i];
        j = i - 1; 

        while(j >= 0 && arr[j] > tmp){
            arr[j+1] = arr[j];
            j--;
        } 

        arr[j+1] = tmp; 
    }
}

void quickSort(int arr[], int left, int right) {
    if (left >= right) return;

    int pivot = arr[right];
    int i = left - 1;
    int j = right;

    while (1) {
            while (arr[++i] < pivot); // 피벗보다 크거나 같은 값을 왼쪽에서 찾음
            while (j > left && arr[--j] > pivot); // 피벗보다 작거나 같은 값을 오른쪽에서 찾음

            if (i < j){
                SWAP(arr[i], arr[j]);
            } else
                break;
        }

    SWAP(arr[i], arr[right]);


    // 재귀적으로 왼쪽 & 오른쪽 부분 집합을 정렬
    quickSort(arr, left, i-1);
    quickSort(arr, i + 1, right);
}

int main() {
    printf("Sort4\n");
    int arr[] = {6, 8, 9, 2, 7, 1, 3, 4, 5};
    int n = sizeof(arr) / sizeof(int);

    printArray(arr, n);

    // sortBubble(arr, n);
    // sortSelection(arr, n);
    // sortInsertion(arr, n);
    quickSort(arr, 0, n-1);
   
    printArray(arr, n);
}