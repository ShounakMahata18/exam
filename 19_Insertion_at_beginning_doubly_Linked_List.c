#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
};

struct node * CreateDoubleLinkedList(int size){
    struct node *head = NULL;
    struct node *p = NULL;
    struct node *q = NULL;
    
    for(int i=0; i<size; i++){
        q = (struct node*)malloc(sizeof(struct node));
        printf("Enter the data of %d linked list:",i+1);
        scanf("%d",&(q->data));
        q->next = NULL;
        q->prev = NULL;
        if(head == NULL){
            head=q;
        }
        else{
            p=head;
            while(p->next != NULL){
                p = p->next;
            }
            p->next = q;
            q->prev = p;
        }
    }
    return head;
}

struct node * InsertAtTheBeginnig(struct node *head){
    struct node *new_node = NULL;
    new_node = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data ew want to insert at the beginning:");
    scanf("%d",&(new_node->data));
    new_node->prev = NULL;
    new_node->next = head;
    head = new_node;
    return head;
}

void display(struct node *head){
    while(head != NULL){
        printf("%d\t",head->data);
        head = head->next;
    }
    printf("\n");
}

int main(){
    int size;
    struct node *head=NULL;
    printf("Enter the size of Doubly Linked List:");
    scanf("%d",&size);
    head = CreateDoubleLinkedList(size);
    display(head);
    head = InsertAtTheBeginnig(head);
    display(head);
    return 0;
}