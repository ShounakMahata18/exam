#include<stdio.h>

void printArray(int* element, int size){
    for(int i = 0; i < size; i++){
        printf("%d ",element[i]);
    }
    printf("\n\n");
}
/*
void selectionShort(int * element, int size){
    int indexOfMin, temp;
    for(int i=0; i<size - 1; i++){
        indexOfMin = i;
        for(int j=i+1; j<size; j++){
            if(element[j] < element[indexOfMin]){
                indexOfMin = j;
            }
        }
        temp = element[i];
        element[i] = element[indexOfMin];
        element[indexOfMin] = temp;
    }
}
*/

void selectionShort(int * element, int size){
    int indexOfMin, temp;
    for(int i=0; i<size - 1; i++){
        indexOfMin = i;
        for(int j=i+1; j<size; j++){
            if(element[j] < element[indexOfMin]){
                indexOfMin = j;
            }
        }
        if(indexOfMin != i){
            temp = element[i];
            element[i] = element[indexOfMin];
            element[indexOfMin] = temp;
        }
    }
}

int main(){
    int elements[] = {12, 54, 65, 7, 23, 9};
    int size = sizeof(elements)/sizeof(int);
    printArray(elements, size);
    selectionShort(elements, size);
    printArray(elements, size);
    return 0;
}