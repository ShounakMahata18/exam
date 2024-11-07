#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *link;
}node;

node * CreateLinkedList(int size){
    node *head=NULL;
    node *temp=NULL;
    node *p=NULL;
    for(int i=0; i<size; i++){
        temp=(struct node*)malloc(sizeof(struct node));
        printf("Enter the %d element:",i+1);
        scanf("%d",&(temp->data));
        temp->link = NULL;
        if(head == NULL){
            head=temp;
        }
        else{
            p=head;
            while(p->link != NULL)
                p = p->link;
            p->link=temp;
        }
    }
    return head;
}

node *reverse(node *head){
    node *prev=NULL;
    node *next=NULL;
    while(head != NULL){
        next=head->link;
        head->link=prev;
        prev=head;
        head=next;
    }
    head = prev;
    return head;
}

void display(node *head){
    while(head != NULL){
        printf("%d\t",head->data);
        head = head->link;
    }
    printf("\n");
}

int main(){
    int size;
    node *head;
    printf("Enter size of linked list:");
    scanf("%d",&size);
    head = CreateLinkedList(size);
    display(head);
    head  = reverse(head);
    display(head);
    return 0;
}