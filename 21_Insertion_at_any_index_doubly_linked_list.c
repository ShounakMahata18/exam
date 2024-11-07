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

struct node * InsertAtTheIndex(struct node *head, int index){
    struct node *new_node = NULL;
    struct node *p = head;
    new_node = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data we want to insert at the beginning:");
    scanf("%d",&(new_node->data));
    for(int i=0; i<index-1; i++){
        p = p->next;
    }
    new_node->next = p->next;
    p->next = new_node;
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
    int size, index;
    struct node *head=NULL;
    printf("Enter the size of Doubly Linked List: ");
    scanf("%d",&size);
    head = CreateDoubleLinkedList(size);
    display(head);
    printf("Enter the index of element i want to enter: ");
    scanf("%d",&index);
    head = InsertAtTheIndex(head,index);
    display(head);
    return 0;
}