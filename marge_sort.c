#include<stdio.h>

void marge(int *arr, int low, int mid, int high){
    int i = low;
    int j = mid+1;
    int k = low;
    int temp[100];

    while(i <= mid && j <= high){
        if(arr[i] < arr[j]){
            temp[k] = arr[i];
            i++;
            k++;
        }
        else{
            temp[k] = arr[j];
            j++;
            k++;
        }
    }

    while(i <= mid){
        temp[k] = arr[i];
        i++;
        k++;
    }
    while (j <= high){
        temp[k] = arr[j];
        j++;
        k++;
    }

    for(int l = low; l <= high; l++){
        arr[l] = temp[l];
    }
}

void mergeSort(int arr[], int low, int high){
    if(low < high){
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        marge(arr, low, mid, high);
    }
}

void print(int arr[], int size){
    for(int i = 0; i <= size; i++){
        printf("%d\t",arr[i]);
    }
}

int main(){
    int ele[] = {10, 3, 6, 5, 9, 1};
    int size = sizeof(ele)/sizeof(int);
    mergeSort(ele, 0, size - 1);
    print(ele, size-1);
    return 0;
}