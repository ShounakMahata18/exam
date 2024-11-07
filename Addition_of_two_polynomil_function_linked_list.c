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

struct node *insert(struct node *head, float co, int ex){
    struct node *p;
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->coeff = co;
    temp->exp = ex;
    temp->link = NULL;
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

void polyAdd(struct node *head1, struct node *head2){
    struct node *ptr1 = head1;
    struct node *ptr2 = head2;
    struct node *head3 = NULL;
    while(ptr1 != NULL && ptr2 != NULL){
        if(ptr1->exp == ptr2->exp){
            head3 = insert(head3, ptr1->coeff+ptr2->coeff, ptr1->exp);
            ptr1 = ptr1->link;
            ptr2 = ptr2->link;
        }
        else if(ptr1->exp > ptr2->exp){
            head3 = insert(head3, ptr1->coeff, ptr1->exp);
            ptr1 = ptr1->link;
        }
        else if(ptr1->exp < ptr2->exp){
            head3 = insert(head3, ptr2->coeff , ptr2->exp);
            ptr2 = ptr2->link;
        }
    }
    while(ptr1 != NULL){
        head3 = insert(head3, ptr1->coeff, ptr1->exp);
        ptr1 = ptr1->link;
    }
    while(ptr2 != NULL){
        head3 = insert(head3, ptr2->coeff, ptr2->exp);
        ptr2 = ptr2->link;
    }
    printf("Added polynomial is");
    print(head3);
}

int main(){
    int size1, size2;
    struct node *head1;
    struct node *head2;
    printf("Enter the size of the linked list: ");
    scanf("%d",&size1);
    head1 = createLinkedList(size1);
    printf("Enter the size of the linked list: ");
    scanf("%d",&size2);
    head2 = createLinkedList(size2);

    polyAdd(head1, head2);
    return 0;
}