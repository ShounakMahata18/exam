#include<stdio.h>

void printArray(int* element, int size){
    for(int i = 0; i < size; i++){
        printf("%d ",element[i]);
    }
    printf("\n\n");
}

void insertionShort(int * element, int size){
    int key,j;
    for(int i=0; i<size; i++){
        key = element[i];
        j = i-1;
        while (j>=0 && element[j] > key){
            element[j+1] = element[j];
            j--; 
        }
        element[j+1] = key;
    }
}

int main(){
    int elements[] = {12, 54, 65, 7, 23, 9};
    int size = sizeof(elements)/sizeof(int);
    printArray(elements, size);
    insertionShort(elements, size);
    printArray(elements, size);
    return 0;
}