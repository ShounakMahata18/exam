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

struct node * InsertionAtTheBeginning(struct node *head, struct node *new_head){
    struct node *p = new_head;
    /*
    if(p==NULL){         // Here we take my_head as the first linked node
        p->link = head;
    }
    else{
        while(p->link != NULL)
            p=p->link;
        p->link = head;
        }
    return new_head;
    */
    while(p->link != NULL)          // Here we are assigning head point to my_head node and last my_node toint to the second node of head
        p = p->link;
    p->link = head;
    head = new_head;
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
    printf("Enter size of second linked list:");
    scanf("%d",&new_size);
    new_head = createLinkedList(new_size);
    display(new_head);
    head = InsertionAtTheBeginning(head,new_head);
    display(head);
    return 0;
}