#include<stdio.h>
#include<stdlib.h>
#define MAX 5

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

int pop(){ 
    int value;
    if(top == -1){
        printf("Stack Underflow\n");
        exit(1);
    }
    value = stack_arr[top]; 
    top -= 1;
    return value;
}

void display(){
    printf("\n");
    if(top == -1){
        printf("Stack Underflow\n");
        return;
    }
    for(int i=0; i<=top; i++){
        printf("%d\t",stack_arr[i]);
    }
    printf("\n");
}


int main(){
    int choice, data;
    while(1){
        printf("\n1. Push element in the stack.\n");
        printf("2. Pop element in the Stack.\n");
        printf("3. Print top element.\n");
        printf("4. Print all element in the stack.\n");
        printf("5. Quit. \n");
        scanf("%d",&choice);

        switch (choice){
        case 1:
            printf("Enter element to be pushed: ");
            scanf("%d",&data);
            push(data);
            break;
        case 2:
            data = pop();
            printf("The pop out data is %d",data);
            break;
        case 3:
            printf("Top element is %d",stack_arr[top]);
            break;
        case 4:
            display();
            break;
        case 5:
            exit(1);
        default:
            printf("Enter a valid Choice.");
        }
    }
    return 0;
}