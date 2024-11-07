#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

struct node * createLinkedList(int size){
    struct node *head=NULL;
    struct node *temp=NULL;
    struct node *p=NULL;

    for(int i=0; i<size; i++){
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

struct node * InsertAtAnyPosition(struct node *head){
    int index;
    struct node *p=head;
    struct node *new_node=NULL;

    new_node=(struct node*)malloc(sizeof(struct node));
    printf("Enter the value you want to insert:");
    scanf("%d",&(new_node->data));
    new_node->link=NULL;
    printf("Enter the index of the value:");
    scanf("%d",&index);

    if( index == 0){
        new_node->link = head ;
        head = new_node;
    }
    else{
        for(int i=0; i<index-1; i++){
            p = p->link;
        }
        new_node->link=p->link;
        p->link=new_node;
    }
    return head;
}

struct node * DeletionaAtAIndex(struct node *head){
    int index;
    struct node *p=head;
    struct node *q=head->link;

    printf("Enter the Index to delete: ");
    scanf("%d",&index);
    
    if(index == 0){
        head=head->link;
        free(p);
    }
    else{
        for(int i=0; i<index-1; i++){
            p = p->link;
            q = q->link;
        }
        p->link = q->link;
        free(q);
    }    
    return head;
}

struct node * reverse(struct node *head){
    struct node *prev=NULL;
    struct node *next=NULL;
    while(head != NULL){
        next=head->link;
        head->link=prev;
        prev=head;
        head=next;
    }
    head = prev;
    return head;
}

void display(struct node *head){
    printf("\n");
    if (head == NULL){
        printf("NULL");
    }
    while ( head != NULL){
        printf("%d\t",head->data);
        head = head->link;
    }
    printf("\n");
}

int main(){
    int choice, size;
    struct node *head;
    while(1){
        printf("\n1. Create Linked List.\n");
        printf("2. Insertion.\n");
        printf("3. Deletion.\n");
        printf("4. Reverse.\n");
        printf("5. Print Singly Linked List.\n");
        printf("6. Quit.\n");
        printf("==> ");
        scanf("%d",&choice);

        switch (choice){
        case 1:
            printf("Enter size of the linked list:");
            scanf("%d",&size);
            head = createLinkedList(size);
            break;
        case 2:
            head = InsertAtAnyPosition(head);
            break;
        case 3:
            head = DeletionaAtAIndex(head);
            break;
        case 4:
            head = reverse(head);
            break;
        case 5:
            display(head);
            break;
        case 6:
            exit(1);
        default:
            printf("Invalid Data");
        }
    }
    return 0;
}