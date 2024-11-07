#include<stdio.h>

void printArray(int* element, int size){
    for(int i = 0; i < size; i++){
        printf("%d ",element[i]);
    }
    printf("\n\n");
}

//log(n^2)
void BubbleShort(int * element, int size){ 
    int isShorted = 0;
    for(int i = 0; i < size-1; i++){
        isShorted = 1;
        for(int j = 0; j < size - 1 - i; j++){
            if(element[j] > element[j+1]){
                int temp = element[j];
                element[j] = element[j+1];
                element[j+1] = temp;
                isShorted = 0;
            }
        }
        if(isShorted){
            return;
        }
    }
}

int main(){
    int element[] = {12, 54, 65, 7, 23, 9};
    int size = sizeof(element)/sizeof(int);
    printArray(element, size);
    BubbleShort(element, size);
    printArray(element, size);
    return 0;
}