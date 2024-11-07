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
        printf("Ener the value of %d element: ",i+1);
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
    p->link->link = head;
    return head;
}

struct node * PointingToTheNextNode(struct node *head){
    int traverse;
    printf("No of index we want to start from current head position: ");
    scanf("%d",&traverse);
    for(int i=0; i<traverse; i++){
        head = head->link;
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

struct node *DeletionAtAnyPosition(struct node *head){
    int index;
    struct node *p = head;
    struct node *q = head->link;
    printf("Enter the index you want to delete:");
    scanf("%d",&index);
    for(int i=0; i<index-1; i++){
        p = p->link;
        q = q->link;
    }
    p->link = q->link;
    free(q);
    return head;
}

void display(struct node *head){
    int size;
    struct node *p = head;
    printf("Enter the size that we want to print: ");
    scanf("%d",&size);
    for(int i=0; i<size; i++){
        printf("%d\t",p->data);
        p = p->link;
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
        printf("5. To print a Linked List\n");
        printf("6. Quit.\n");
        printf("\nEnter the choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter size of first linked list: ");
                scanf("%d",&size);
                head = createLinkedList(size);
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
                display(head);
                break;
            case 6:
                exit(1);
            default:
                printf("Enter a valid value");
                break;
        }
    }
    return 0;
}