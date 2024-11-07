#include<stdio.h>
#define MAX 4

int stack_arr[MAX];
int top = -1;

void push(int data){
    if(top == MAX-1){
        printf("Stack Overflow.\n");
        return;
    }
    top+=1;
    stack_arr[top] = data;
}

void display(){
    for(int i=0; i<=top; i++){
        printf("%d\t",stack_arr[i]);
    }
}

int main(){
    /*
    push(1);
    push(2);
    push(3);
    push(4);
    */
    int size, data;
    printf("Enter size of element i want to push but less or equal to %d: ",MAX);
    scanf("%d",&size);
    for(int i=0; i<size; i++){
        printf("\nEnter The data of %d stack: ",i);
        scanf("%d",&data);
        push(data);
    }
    display();
    return 0;
}