#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

struct node * createLinkedList(int n){
    struct node *head=NULL;
    struct node *temp=NULL;
    struct node *p=NULL;
    for(int i=0; i<n; i++){
        temp=(struct node*)malloc(sizeof(struct node));
        printf("Ener the value of %d element:",i+1);
        scanf("%d",&(temp->data));
        temp->link=NULL;
        if(head==NULL){
            head = temp;
        }
        else{
            p = head;
            while(p->link != NULL)
                p=p->link;
            p->link = temp;
        }
    }
    return head;
}

void display(struct node *head){
    struct node *p = head;
    while(p != NULL){
        printf("\t%d",p->data);
        p = p->link;
    }
    printf("\n");
}

struct node * InsertionAtTheBeginning(struct node *head){
    struct node *temp=NULL;

    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter the element which i want to insert at the beginning:");
    scanf("%d",&(temp->data));
    temp->link = head;
    head = temp;
    return head;
}

int main(){
    int size,new_size;
    struct node *head = NULL;
    struct node *new_head = NULL;
    printf("Enter size of first linked list:");  
    scanf("%d",&size);
    head = createLinkedList(size);
    display(head);
    head = InsertionAtTheBeginning(head);
    display(head);
    return 0;
}