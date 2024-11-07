#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* link;
} *top = NULL; 

int isEmpty(){
    if(top == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void push(int data){
    struct node *new_node;
    new_node = (struct node*)malloc(sizeof(struct node));

    if(new_node == NULL){
        printf("Stack Overflow.");
        exit(1);
    }

    new_node->data = data;
    new_node->link = NULL;

    new_node->link = top;
    top = new_node;
}

int pop(){
    struct node *temp;
    temp = top;
    if(isEmpty()){
        printf("Stack Underflow:");
        exit(1);
    }
    int value;
    top = top->link;
    value = temp->data;
    free(temp);
    temp = NULL;
    return value;
}

int peek(){
    if(isEmpty()){
        printf("Stack Underflow:");
        exit(1);
    }
    return top->data;
}

void print(){
    struct node *temp = top;
    if(isEmpty()){
        printf("Stack Underflow:");
        exit(1);
    }
    printf("The stack element are: ");
    while(temp){ //same temp != NULL 
        printf("%d\t",temp->data);
        temp = temp->link;
    }
    printf("\n");
}

int main(){
    int choice, data, value;
    while (1){
        printf("\n1. PUSH\n");
        printf("\n2. Pop\n");
        printf("\n3. Print the top element\n");
        printf("\n4. Print\n");
        printf("\n5.Quite\n");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("\nEnter the data want to push\n: ");
                scanf("%d",&data);
                push(data);
                break;
            case 2:
                printf("\nThe Poped Out Value is: %d\n",pop());
                break;
            case 3:
                printf("\nThe topmost element is %d\n",peek());
                break;
            case 4:
                print();
                break;
            case 5:
                exit(1);
            default:
                printf("Enter a valid choice");
        }
    }
    return 0;
}