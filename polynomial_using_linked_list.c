#include<stdio.h>
#include<stdlib.h>

struct node{
    float coeff;
    int exp;
    struct node *link;
};

struct node * createLinkedList(int size){
    struct node * head = NULL;
    struct node * temp = NULL;
    struct node * p = NULL;

    for(int i=0; i<size; i++){
        temp = (struct node*)malloc(sizeof(struct node));
        printf("Enter coefficient to be inserted at %d position: ",i+1);
        scanf("%f",&(temp->coeff));
        printf("Enter exponent to be inserted at %d position: ",i+1);
        scanf("%d",&(temp->exp));
        temp->link = NULL;
        int ex = temp->exp;

        if(head == NULL || ex < head->exp){
            temp->link = head;
            head = temp;
        }
        else{
            p = head;
            while(p->link != NULL && p->link->exp < ex){
                p = p->link;
            }
            temp->link = p->link;
            p->link = temp;
        }
    }
    return head;
}

void print(struct node *head){
    if(head == NULL){
        printf("Not a polynomial Function.");
    }
    else{
        struct node *temp = head;
        while(temp != NULL){
            printf("(%.1fx^%d)",temp->coeff, temp->exp);
            temp = temp->link;
            if(temp != NULL){
                printf(" + ");
            }
            else{
                printf("\n");
            }
        }
    }
}

int main(){
    int size;
    struct node *head;
    printf("Enter the size of the linked list: ");
    scanf("%d",&size);
    head = createLinkedList(size);
    print(head);
    return 0;
}