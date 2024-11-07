#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define Max 100

int stack[Max];
char infix[Max], postfix[Max];
int top = -1;

int isFull(){
    if(top == Max-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(){
    if(top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(char symbol){
    if(isFull()){
        printf("Stack OverFlow.\n");
        exit(1);
    }
    top++;
    stack[top] = symbol;
}

char pop(){
    if(isEmpty()){
        printf("Stack Underflow");
        exit(1);
    }
    char symbol;
    symbol = stack[top];
    top--;
    return symbol;
}

int precedance(int symbol){
    switch (symbol){
    case '^':
        return 3;
    case '/':
    case '*':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
}

int WhiteSpace(int symbol){
    if(symbol == ' ' || symbol == '\t'){
        return 1;
    }
    else{
        return 0;
    }
}

int post_eval(){
    int i,a,b;
    for(i=0; i<strlen(postfix); i++){
        if(postfix[i] >= '0' && postfix[i] <= '9')
            push(postfix[i] - '0');
        else{
            a = pop();
            b = pop();
            switch(postfix[i]){
                case '+':
                    push(b+a);
                    break;
                case '-': 
                    push(b-a);
                    break;
                case '/':
                    push(b/a);
                    break;
                case '*':
                    push(b*a);
                    break;
                case '^':
                    push(pow(b,a));
                    break;
            }
        }
    }
    return pop();
}

void inToPost(){
    int i, j=0;
    char symbol, next;
    for(i=0; i<strlen(infix); i++){
        symbol = infix[i];
        if(!WhiteSpace(symbol)){
            switch(symbol){
            case '(':
                push(symbol);
                break;
            case ')':
                while((next = pop()) != '(')
                    postfix[j++] = next;
                break;
            case '/':
            case '*':
            case '+':
            case '-':
            case '^':
                while(!isEmpty() && precedance(stack[top]) >= precedance(symbol))
                    postfix[j++] = pop();
                push(symbol);
                break;
            default:
                postfix[j++] = symbol;
            }
        }
    }
    while(!isEmpty())
        postfix[j++] = pop();
    postfix[j] = '\0';
}

void print(){
    int i=0;
    while(postfix[i] != '\0'){
        printf("%c",postfix[i]);
        i++;
    }
}

int main(){
    printf("Enter the infix Expression: ");
    gets(infix);

    inToPost();
    print();

    printf("\nResult of the postfix Expression is %d",post_eval());
    return 0;
}