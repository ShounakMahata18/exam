#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *link;
};

void Travarse_node(struct Node *ptr){
    while(ptr != NULL){
        printf("%d\n",ptr->data);
        ptr = ptr->link;
    }
}

int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *forth;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    forth = (struct Node*)malloc(sizeof(struct Node));

    head->data = 7;
    head->link = second;

    second->data = 4;
    second->link = third;

    third->data = 72;
    third->link = forth;

    forth->data = 17;
    forth->link = NULL;

    Travarse_node(head);

    return 0;
}