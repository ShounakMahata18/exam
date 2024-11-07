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

//-->1st approach<--  we are  declearing head as the last node of the linked list
/*
struct node * Reverse(struct node *head){
    struct node *p = head;
    while(p->next != NULL){
        p = p->next;
    }
    head = p;
    return head;
}

void display(struct node *head){
    while(head != NULL){
        printf("%d\t",head->data);
        head = head->prev;
    }
    printf("\n");
}

int main(){
    int size;
    struct node *head=NULL;
    printf("Enter the size of Doubly Linked List:");
    scanf("%d",&size);
    head = CreateDoubleLinkedList(size);
    head = Reverse(head);
    display(head);
    return 0;
}
*/

//-->2nd approach<-- By Chenging the direction of linked node where head point last node as the first element 
struct node * Reverse(struct node *head){
    struct node *pre = NULL;
    struct node *nex = NULL;
    while(head != NULL){
        nex = head->next;
        head->next = pre;
        head->prev = nex;
        pre = head;
        head = nex;
    }
    head = pre;
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
    head = Reverse(head);
    display(head);
    return 0;
}
