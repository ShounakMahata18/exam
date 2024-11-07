#include<stdio.h>

int partition(int *arr, int low, int high){
    int pivot = arr[low];
    int i = low+1;
    int j = high;
    int temp;
    do{
        while(arr[i] <= pivot){
            i++;
        }
        while(arr[j] > pivot){
            j--;
        }
        if(i<j){
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }while(i<j);    
    
    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}

void quickSort(int *arr, int low, int high){
    int partionIndex;

    if(low<high){
        partionIndex = partition(arr, low, high);
        quickSort(arr, low, partionIndex-1);
        quickSort(arr, partionIndex+1, high);
    }
}

void print(int arr[], int size){
    for(int i = 0; i < size; i++){
        printf("%d\t",arr[i]);
    }
}

int main(){
    int ele[] = {10, 3, 6, 5, 9, 1};
    int size = sizeof(ele)/sizeof(int);
    quickSort(ele, 0, size-1);
    print(ele, size);
    return 0;
}

