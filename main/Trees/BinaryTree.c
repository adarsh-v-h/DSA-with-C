#include <stdio.h>
#include <stdlib.h>
#include "c_utils.h"

typedef struct node{
    char data;
    struct node *left, *right;
}Node;

Node *create(void);
void  inorder(Node*);
void postorder(Node*);
void preorder(Node*);
void deleteTree(Node*);

int main(void){
    Node *root;
    root = NULL;
    root = create();
    printf("Preorder Tree traversing: \n");
    preorder(root);
    printf("\n");
    printf("Postorder Tree traversing: \n");
    postorder(root);
    printf("\n");
    printf("Inorder Tree traversing: \n");
    inorder(root);
    printf("\n");
    deleteTree(root);
    return 0;
}

Node *create(void) {
    char data;
    printf("Data('#' for empty node) : ");
    if (scanf(" %c", &data) != 1) { 
        return NULL;
    }
    if (data == '#') {
        return NULL;
    }
    Node *newnode = (Node*)safeAllo(sizeof(Node));
    newnode->data = data;
    printf("Enter the left child of %c:\n", data);
    newnode->left = create();
    printf("Enter the right child of %c: \n", data);
    newnode->right = create();
    return newnode;
}

void inorder(Node *ptr){
    if(ptr){
        if(ptr->left){
            inorder(ptr->left);
        }
        printf("%c ", ptr->data);
        if(ptr->right){
            inorder(ptr->right);
        }
    }
}

void preorder(Node *ptr){
    if(ptr){
        printf("%c ",ptr->data);
        if(ptr->left){
            preorder(ptr->left);
        }
        if(ptr->right){
            preorder(ptr->right);
        }
    }
}

void postorder(Node *ptr){
    if(ptr){
        if(ptr->left){
            postorder(ptr->left);
        }
        if(ptr->right){
            postorder(ptr->right);
        }
        printf("%c ", ptr->data);
    }
}
void deleteTree(Node *ptr) {
    if (ptr){
        deleteTree(ptr->left);
        deleteTree(ptr->right);
        free(ptr);
    }
}

// Test Case:
/*
Data('#' for empty node) : A
Enter the left child of A:
Data('#' for empty node) : B
Enter the left child of B:
Data('#' for empty node) : D
Enter the left child of D:
Data('#' for empty node) : H
Enter the left child of H:
Data('#' for empty node) : #
Enter the right child of H: 
Data('#' for empty node) : #
Enter the right child of D: 
Data('#' for empty node) : I
Enter the left child of I:
Data('#' for empty node) : #
Enter the right child of I: 
Data('#' for empty node) : #
Enter the right child of B: 
Data('#' for empty node) : E
Enter the left child of E:
Data('#' for empty node) : J
Enter the left child of J:
Data('#' for empty node) : #
Enter the right child of J: 
Data('#' for empty node) : #
Enter the right child of E: 
Data('#' for empty node) : K
Enter the left child of K:
Data('#' for empty node) : #
Enter the right child of K: 
Data('#' for empty node) : #
Enter the right child of A: 
Data('#' for empty node) : C
Enter the left child of C:
Data('#' for empty node) : E
Enter the left child of E:
Data('#' for empty node) : L
Enter the left child of L:
Data('#' for empty node) : #
Enter the right child of L: 
Data('#' for empty node) : #
Enter the right child of E: 
Data('#' for empty node) : N
Enter the left child of N:
Data('#' for empty node) : #
Enter the right child of N: 
Data('#' for empty node) : #
Enter the right child of C: 
Data('#' for empty node) : G
Enter the left child of G:
Data('#' for empty node) : N
Enter the left child of N:
Data('#' for empty node) : #
Enter the right child of N: 
Data('#' for empty node) : #
Enter the right child of G: 
Data('#' for empty node) : O
Enter the left child of O:
Data('#' for empty node) : #
Enter the right child of O: 
Data('#' for empty node) : #
Preorder Tree traversing: 
A B D H I E J K C E L N G N O
Postorder Tree traversing:
H I D J K E B L N E N O G C A
Inorder Tree traversing:
H D I B J E K A L E N C N G O
*/