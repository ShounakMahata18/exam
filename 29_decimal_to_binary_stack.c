#include<stdio.h>
#include<stdlib.h>
#define Max 50

int stack_arr[Max];
int top = -1;

int isFull(){
    if(top == Max-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(){
    if(top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(int n){
    if(isFull()){
        printf("Stack Overflow.");
        exit(1);
    }
    top++;
    stack_arr[top] = n;
}

int pop(){
    int value;
    if(isEmpty()){
        printf("Stack Underflow.");
        exit(1);
    }
    value = stack_arr[top];
    top--;
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
    while(!isEmpty()){
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