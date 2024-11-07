#include<stdio.h>
#include<stdlib.h>
#define Max 400 

int arr[Max];
int f = -1;
int r = -1;

int isFull(){
    if(r == Max-1){
        return 1;
    }
    return 0;
}

int isEmpty(){
    if(r == f){
        return 1;
    }
    return 0;
}

void enqueue(int data){
    if(isFull()){
        printf("Stack Overflow");
    }
    r++;
    arr[r] = data;
}

int dequeue(){
    if(isEmpty()){
        printf("Stack Underflow");
    }
    f++;
    int value = arr[f];
    return value;
}

int main(){
    int node;
    int i=0;
    int visited[7] = {0,0,0,0,0,0,0};
    int a[7][7] = {
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0}
    };
    printf("%d",i);
    visited[i] = 1;
    enqueue(i);
    while(!isEmpty()){
        int node = dequeue();
        for(int j=0; j < 7; j++){
            if(a[node][j] == 1 && visited[j] == 0){
                printf("%d",j);
                visited[j] = 1;
                enqueue(j);
            }
        }
    }
    return 0;
}