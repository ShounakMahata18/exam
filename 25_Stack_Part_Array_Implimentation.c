//stack fifo algorithm

#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int stack_arr[MAX];
int first = -1;

void push(int data){
    first += 1;
    for(int i=first; i>0; i--){
        stack_arr[i] = stack_arr[i-1];
    }
    stack_arr[0] = data;
}

int pop(){
    int value;
    value = stack_arr[0];
    for(int i=0; i<first; i++){
        stack_arr[i] = stack_arr[i+1];
    }
    first-=1;
    return value;
}

void display(){
    if(first == -1){
        printf("Queue Underflow\n");
        exit(1);
    }
    for(int i=0; i<=first; i++){
        printf("%d\t",stack_arr[i]);
    }
}

int main(){
    int data;

    push(20);
    push(10);
    push(70);
    push(40);

    data = pop();

    display();
    return 0;
}