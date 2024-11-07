#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

struct node * createLinkedList(int size){
    struct node *head = NULL;
    struct node *temp = NULL;
    struct node *p = NULL;

    for(int i=0; i<size; i++){
        temp = (struct node*)malloc(sizeof(struct node));
        printf("Enter the data to be inserted at %d position: ",i+1);
        scanf("%d",&(temp->data));
        temp->link = NULL;
        if(head == NULL){
            head = temp;
        }
        else{
            p = head;
            while(p->link != NULL)
                p = p->link;
            p->link = temp;
        }
    }
    return head;
}

struct node *shorting(struct node *head){
    struct node *NewNode = NULL;
    struct node *temp = NULL;
    struct node *p = NULL;
    struct node *q = head;

    while (q != NULL){
        temp = (struct node*)malloc(sizeof(struct node));
        int key = q->data;
        temp->data = key;
        temp->link = NULL;
        if(NewNode == NULL || key < NewNode->data){
            temp->link = NewNode;
            NewNode = temp;
        }
        else{
            p = NewNode;
            while(p->link != NULL && p->link->data < key)
                p = p->link;
            temp->link = p->link;
            p->link = temp;
        }
        q = q->link;
    }
    return NewNode;
}

void print(struct node *head){
    while(head != NULL){
        printf("%d\t",head->data);
        head = head->link;
    }
    printf("\n");
}

int main(){
    int size;
    struct node *head;
    struct node *NewNode;

    printf("Enter Size of the linked list: ");
    scanf("%d",&size);
    head = createLinkedList(size);
    print(head);

    NewNode = shorting(head);
    print(NewNode);
    return 0;
}