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

struct node * DeletionAtAnyIndex(struct node *head, int index){
    struct node *p = head;
    struct node *q = head->next;
    for(int i=0; i<index-1; i++){
        p = p->next;
        q= q->next;
    }
    p->next = q->next;
    if( p->next != NULL){
        q->next->prev = p;
    }
    free(q);
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
    head = DeletionAtAnyIndex(head,index);
    display(head);
    return 0;
}