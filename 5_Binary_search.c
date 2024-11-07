#include<stdio.h>

void getelement(int *element){
    printf("Enter which element to be searched:");
    scanf("%d",element);
}

void search(int arr[], int *element, int *index, int size, int *steps){
    int low=0, mid, high=size-1;
    while(low<=high){
        mid = (low + high)/2;
        if(arr[mid] == *element){
            *index=mid;
        }
        if(arr[mid]<*element){
            low = mid+1;
        }
        else{
            high = mid -1;
        }
    } 
}

int main(){
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int element, size=10, index;
    getelement(&element);
    search(arr,&element,&index,size);
    printf("%d is found in index %d",element,index);
    return 0;
}