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
    p->next->next = head;
    head->prev = p->next;
    return head;
}

struct node * PointingToTheNextNode(struct node *head){
    int traverse;
    printf("No of index we want to start from current head position:: ");
    scanf("%d",&traverse);
    for(int i=0; i<traverse; i++){
        head = head->next;
    }
    return head;
}

struct node *InsertAtAnyPosition(struct node *head){
    int position;
    struct node *p=head;
    struct node *new_node=NULL;
    new_node=(struct node*)malloc(sizeof(struct node));
    printf("Enter the value you want to insert:");
    scanf("%d",&(new_node->data));
    new_node->prev=NULL;
    new_node->next=NULL;
    printf("Enter the index of the value:");
    scanf("%d",&position);
    for(int i=0; i<position-1; i++){
        p = p->next;
    }
    new_node->next=p->next;
    new_node->prev = p;
    return head;
}

struct node *DeletionAtAnyPosition(struct node *head){
    int index;
    struct node *p = head;
    struct node *q = head->next;
    printf("Enter the index you want to delete:");
    scanf("%d",&index);
    for(int i=0; i<index-1; i++){
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    if( p->next != NULL){
        q->next->prev = p;
    }
    free(q);
    return head;
}

struct node * Reverse(struct node *head){
    struct node *pre = NULL;
    struct node *nex = NULL;
    if(head == NULL){

    }
    while(head != NULL){
        nex = head->next;
        head->next = pre;
        head->prev = nex;
        pre = head;
        head = nex;
    }
    head = pre->next;
    return head;
}

void display(struct node *head){
    int size;
    printf("Enter the size we want to traverse: ");
    scanf("%d",&size);
    for(int i=0; i<size; i++){
        printf("%d\t",head->data);
        head = head->next;
    }
    printf("\n");
}

int main(){
    int size,choice;
    struct node *head = NULL;
    struct node *new_head = NULL;
    while(1){
        printf("\n1. To create A Linked List.\n");
        printf("2. To make a circular Linked List\n");
        printf("3. To insert a node in the Linked List\n");
        printf("4. To delete a node in the Linked List\n");
        printf("5. To Reverse a Linked List\n");
        printf("6. To print a Linked List\n");
        printf("7. Quit.\n");
        printf("\nEnter the choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter size of first linked list: ");
                scanf("%d",&size);
                head = CreateDoubleLinkedList(size);
                break;
            case 2:
                head = PointingToTheNextNode(head);
                break;
            case 3:
                head = InsertAtAnyPosition(head);
                break;
            case 4:
                head = DeletionAtAnyPosition(head);
                break;
            case 5:
                head = Reverse(head);
                break;
            case 6:
                display(head);
                break;
            case 7:
                exit(1);
            default:
                printf("Enter a valid value");
                break;
        }
    }
    return 0;
}