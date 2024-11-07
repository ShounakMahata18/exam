#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Max 100

int top = -1;
char stack[Max];

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

void push(char s){
    if(isFull()){
        printf("Stack Overflow");
        exit(1);
    }
    top++;
    stack[top] = s;
}

char pop(){
    int value;
    if(isEmpty()){
        printf("Stack Underflow.");
    }
    value = stack[top];
    top--;
    return value;
}

int match_char(char a, char b){
    if(a == '(' && b == ')')
        return 1;
    if(a == '{' && b == '}')
        return 1;
    if(a == '[' && b == ']')
        return 1;
    if(a == '<' && b == '>')
        return 1;
    return 0;
}

int check_balance(char *str){
    int i; char temp;
    for(i=0; i <strlen(str); i++){
        if(str[i] == '(' || str[i] == '{' || str[i] == '[' || str[i] =='<'){
            push(str[i]);
        }
        if(str[i] == ')' || str[i] == '}' || str[i] == ']' || str[i] =='>'){
            if(isEmpty()){
                printf("Right Bracket are more than left bracket.\n");
                return 0;
            }
            else{
                temp = pop();
                if(!match_char(temp, str[i])){
                    printf("Mismassed Bracket.\n");
                    return 0;
                }
            }
        }
    }
    if(isEmpty()){
        printf("Bracket are well balanced.\n");
        return 1;
    }
    else{
        printf("Bracket are not well balanced.\n");
        return 0;
    }
}

int main(){
    int balance;
    char expr[Max];
    printf("Enter the Expression: ");
    gets(expr);

    balance =  check_balance(expr);

    if(balance == 1){
        printf("Expression is valid.\n");
    }
    else{
        printf("Expression is not valid.\n");
    }
    return 0;
}