#include <stdio.h>
#include "c_utils.h"

typedef struct node{
    int data;
    struct node *left, *right;
}Node;

Node *create(void);

int main(void){
    Node *root;
    root = NULL;
    root = create();
    return 0;
}

Node *create(void){
    int x;
    printf("Data(-1 for empyt node) :");
    getInt(&x);
    if(x==-1){
        return NULL;
    }
    Node *newnode = (Node*)safeAllo(sizeof(Node));
    newnode->data = x;
    printf("Enter the left child of %d :\n",x);
    newnode->left = create();
    printf("Enter the right child of %d: \n", x);
    newnode->right = create();
    return newnode;
}

