#include<stdio.h>

void getelement(int *element){
    printf("Enter which element to be searched:");
    scanf("%d",element);
}

void search(int arr[], int *element, int *index, int size){
    for(int i=0; i<size; i++){
        if(*element==arr[i]){
            *index=i;
            break;
        }
        else{
            *index=-1;
        }
    }
}

int main(){
    int arr[] = {6,8,3,2,0,1,9,4,7,5};
    int element, size=sizeof(arr)/sizeof(int), index;
    getelement(&element);
    search(arr,&element,&index,size);
    printf("%d is found in index %d",element,index);
    return 0;
}