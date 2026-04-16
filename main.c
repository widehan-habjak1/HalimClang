#include <stdio.h>
#include <stdlib.h>
#define SWAP(a, b) {int temp = (a); (a) = (b); (b) = temp; }

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%-2d", arr[i]);
    printf("\n");
}

void sortBubble(int arr[], int n) {
    int i, j;
   
    for (i = 0; i < n - 1; i++)
        for (j = 1; j < n - i; j++)
            if(arr[j+1] > arr[j]) SWAP(arr[j+1], arr[j]);
}

void sortSelection(int arr[], int n) {
    int i, j, idx;
   
    for (i = 0; i < n - 1; i++) {
        idx = i;
        for (j = i + 1; j < n; j++)
            ; // 조건문
        ; // 스와핑
    }
}

void sortInsertion(int arr[], int n) {
    int i, j, tmp;

    for (i = 1; i < n; i++) {
        ; // 변수 초기화

        ; // while 문

        ; // 대입문
    }
}

int main() {
    printf("Sort4\n");
    int arr[] = {6, 8, 9, 2, 7, 1, 3, 4, 5};
    int n = sizeof(arr) / sizeof(int);

    printArray(arr, n);

    sortBubble(arr, n);
    //sortSelection(arr, n);
    //sortInsertion(arr, n);
   
    printArray(arr, n);
}
