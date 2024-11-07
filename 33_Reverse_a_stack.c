#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* link;
};

void push(int data, struct node **ptp_top){
    struct node *new_node;
    new_node = (struct node*)malloc(sizeof(struct node));

    if(new_node == NULL){
        printf("Stack Overflow.");
        exit(1);
    }

    new_node->data = data;
    new_node->link = NULL;

    new_node->link = *ptp_top;
    *ptp_top = new_node;
}

int pop(struct node **ptp_top){
    struct node *temp;
    if(*ptp_top == NULL){
        printf("Stack Underflow:");
        exit(1);
    }
    int value;
    temp = *ptp_top;
    value = temp->data;
    (*ptp_top) = (*ptp_top)->link;
    free(temp);
    temp = NULL;
    return value;
}

void reverse_stack(struct node **ptp_top){
    struct node *top1 = NULL;
    struct node *top2 = NULL;

    while(*ptp_top != NULL){
        push(pop(ptp_top),&top1);
    }
    while(top1 != NULL){
        push(pop(&top1),&top2);
    }
    while(top2 != NULL){
        push(pop(&top2),ptp_top);
    }
}

void print(struct node **ptp_top){
    struct node *temp = *ptp_top;
    printf("The stack element are: ");
    while(temp){ //same temp != NULL 
        printf("%d\t",temp->data);
        temp = temp->link;
    }
    printf("\n");
}

int main(){
    int data;
    struct node *top = NULL;
    // struct node *top1 = NULL;
    // struct node *top2 = NULL;
    struct node *temp;
    push(16,&top);
    push(12,&top);
    push(15,&top);
    print(&top);

    reverse_stack(&top);
    print(&top);

    /*
    //From Original stack to Temporary stack 1
    data = pop(&top);
    push(data,&top1);
    data = pop(&top);
    push(data,&top1);
    data = pop(&top);
    push(data,&top1);

    print(&top);
    print(&top1);
    //From Temporary stack to Temporary stack 2
    data = pop(&top1);
    push(data,&top2);
    data = pop(&top1);
    push(data,&top2);
    data = pop(&top1);
    push(data,&top2);

    print(&top1);
    print(&top2);
    //From Temporary stack 2 to original stack
    data = pop(&top2);
    push(data,&top);
    data = pop(&top2);
    push(data,&top);
    data = pop(&top2);
    push(data,&top);

    print(&top2);
    print(&top);
    */
    return 0;
}