#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
};

struct node * CreateDoubleLinkedList(int size){
    struct node *head = NULL;
    struct node *temp = NULL;
    struct node *p = NULL;
    
    for(int i=0; i<size; i++){
        temp = (struct node*)malloc(sizeof(struct node));
        printf("Enter the data of %d linked list:",i+1);
        scanf("%d",&(temp->data));
        temp->next = NULL;
        temp->prev = NULL;
        if(head == NULL){
            head=temp;
        }
        else{
            p=head;
            while(p->next != NULL){
                p = p->next;
            }
            p->next = temp;
            temp->prev = p;
        }
    }
    return head;
}

void display(struct node *head){
    while(head != NULL){
        printf("%d\t",head->data);
        head = head->next;
    }
}

int main(){
    int size;
    struct node *head=NULL;
    printf("Enter the size of Doubly Linked List:");
    scanf("%d",&size);
    head = CreateDoubleLinkedList(size);
    display(head);
    return 0;
}