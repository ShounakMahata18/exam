#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
} *top = NULL;

int isEmpty(){
    if(top == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void push(int data){
    struct node *newNode = NULL;
    newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode == NULL){
        printf("Stack Overflow.");
        exit(1);
    }
    newNode->data = data;
    newNode->link = NULL;
    
    newNode->link = top;
    top = newNode;
}

int pop(){
    struct node *temp = NULL;
    temp = top;
    if(isEmpty()){
        printf("Stack Underflow");
    }
    int value;
    value = temp->data;
    top = top->link;
    free(temp);
    temp = NULL;
    return value;
}

void Palindrome(char *s){
    int i=0;
    while(s[i] != 'x'){
        push(s[i]);
        i++;
    }
    i++;
    while(s[i]){
        if(isEmpty() || s[i] != pop()){
            printf("Not a Palindrome No.");
            exit(1);
        }
        i++;
    }
    if(isEmpty()){
        printf("Palindrome No.");
    }
    else{
        printf("Not a Palindrome No.");
    }
}

int main(){
    char s[100];
    printf("Enter a String: ");
    scanf("%s",s);

    Palindrome(s);
    return 0;
}