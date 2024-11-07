#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int stack_arr[MAX];
int first = -1;

void push(int data){
    first ++;
    for(int i=first; i>0; i--){
        stack_arr[i] = stack_arr[i-1];
    }
    stack_arr[0] = data;
}

int pop(){
    int value;
    value=stack_arr[0];
    for(int i=0; i<first; i++){
        stack_arr[i] = stack_arr[i+1];
    }
    first--;
    return value;
}

void DecimalToBinary(int data){
    int bin;
    while(data != 0){
        bin = data%2;
        push(bin);
        data/=2;
    }
}

void display(){
    if(first == -1){
        printf("Stack Underflow\n");
        exit(1);
    }
    while(first !=- 1){
        printf("%d ",pop());
    }
}

int main(){
    int data;
    printf("Enter a data to convert decimal to binary: ");
    scanf("%d",&data);
    DecimalToBinary(data);
    display();
    return 0;
}