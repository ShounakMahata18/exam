#include<stdio.h>
#include<stdlib.h>
#define Max 50

int stack_arr[Max];
int top = -1;

void push(int data){
    if(top == Max-1){
        printf("Stack Overflow.\n");
        exit(1);
    }
    top+=1;
    stack_arr[top] = data;
}

int pop(){
    int value;
    if( top == -1){
        printf("Stack Underflow\n");
        exit(1);
    }
    value = stack_arr[top];
    top --;
    return value;
}

void prime_factor(int data){
    int fact = 2;
    while(data != 1){
        while(data%fact == 0){
            push(fact);
            data = data/fact;
        }
        fact++;
    }
}

void display(){
    printf("Prime factor in desending order.\n");
    while(top != -1){
        printf("%d\t",pop());
    }
}

int main(){
    int data;
    printf("Enter a no to find its prime factorial: ");
    scanf("%d",&data);
    
    prime_factor(data);
    display();
    return 0;
}