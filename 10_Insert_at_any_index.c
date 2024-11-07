#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *link;
}node;

node * createLinkedList(int size){
    node *head= NULL;
    node *temp=NULL;
    node *p=NULL;
    for(int i=0; i<size; i++){
        temp=(struct node*)malloc(sizeof(struct node));
        printf("Enter %d element ",i+1);
        scanf("%d",&(temp->data));
        temp->link=NULL;
        if(head==NULL){
            head=temp;
        }
        else{
            p=head;
            while(p->link != NULL){
                p = p->link;
            }
            p->link=temp;
        }
    }
    return head;
}

node *InsertAtAnyPosition(node *head){
    int position;
    node *p=head;
    node *new_node=NULL;
    new_node=(struct node*)malloc(sizeof(struct node));
    printf("Enter the value you wnt to insert:");
    scanf("%d",&(new_node->data));
    new_node->link=NULL;
    printf("Enter the index of the value:");
    scanf("%d",&position);
    for(int i=0; i<position-1; i++){
        p = p->link;
    }
    new_node->link=p->link;
    p->link=new_node;
    return head;
}

void display(node *head){
    while ( head != NULL){
        printf("%d\t",head->data);
        head = head->link;
    }
    printf("\n");
}

int main(){
    int size;
    node *head;

    printf("Enter size of the linked list:");
    scanf("%d",&size);
    head = createLinkedList(size);
    display(head);
    head = InsertAtAnyPosition(head);
    display(head);
    return 0;
}