#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * left;
    struct node * right;
    int height;
};

int getHeight(struct node *n){
    if(n == NULL)
        return 0;
    return n->height;
}

struct node * createNode(int key){
    struct node * n = (struct node *)malloc(sizeof(struct node));
    n->data = key;
    n->left = NULL;
    n->right = NULL;
    n->height = 1;

    return n;
}

int getBalanceFactor(struct node *n){
    if(n == NULL){
        return 0;
    }
    return getHeight(n->left) - getHeight(n->right);
}

struct node * rightRotate(struct node * y){
    struct node * x = y->left;
    struct node * t2 = x->right;

    x->right = y;
    y->left = t2;

    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;

    return x;
}

struct node * leftRotate(struct node * x){
    struct node * y = x->right;
    struct node * t2 = y->left;

    y->left = x;
    x->right = t2;

    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
    
    return y;
}

struct node * insert(struct node * n, int key){
    if(n == NULL){
        return(createNode(key));
    }
    if(key < n->data){
        n->left = insert(n->left, key);
    }
    else if(key > n->data){
        n->right = insert(n->right, key);
    }
    return n;
}