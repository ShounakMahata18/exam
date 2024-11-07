#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *link; // self referential structure
};

struct Node * createLinkedList(int n){   //This will return the starting head address of the linked list
    struct Node *head = NULL;   //This point to the head of the linked list
    struct Node *temp = NULL;   //temp point to the every single linked list to be made i.e every individual node
    struct Node *p; //Help to iterate in the linked list
    for(int i=0; i<n; i++){
        temp = (struct Node*)malloc(sizeof(struct Node)); //mamory allocation for each node
        printf("Enter the value of %d data:",i+1);
        scanf("%d",&(temp->data));  //we give & to get value of the data present in the node of each temp
        temp->link=NULL;    //We create individual linked list so link is pointed toward NULL
        if(head==NULL){     // if the linked list is empty, so tje node point towards null
            head = temp;    // we copy the address of first node from temp to head
        }
        else{
            p = head; // we use p as the raferance of the starting node
            while(p->link != NULL)
                p = p->link;    //Traversing the whole linked list until last node is null
            p->link=temp;   //When we get null we assign the last node as the address of the next node by copy address through temp
        }
    }
    return head;    // in createLinkedList we have to return starting address of head
}

void display(struct Node *head){    //display the linked list
    struct Node *p = head;  //here p pointer help to traverse the linked list 
    while (p != NULL){  //Here the address is checked wheather the value is null
        printf("%d\t",p->data);
        p = p->link;    //Traversing each node of the linked list
    }
}

int main(){
    int size;
    struct Node *HEAD = NULL;
    printf("Enter size of the node:");
    scanf("%d",&size);  //Entering size of the linked list
    HEAD=createLinkedList(size);
    display(HEAD);
    return 0;
}