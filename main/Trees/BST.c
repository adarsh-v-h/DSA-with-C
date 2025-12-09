// This is a code that creates binary search trees and also gives option to insert, and display the nodes in preorder, postorder and inorder
#include <stdio.h>
#include "c_utils.h"
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *left, *right;
}Node;
Node *create(Node*);
void insert(Node*,Node*);
void postorder(Node*);
void preorder(Node*);
void inorder(Node*);
void deleteTree(Node*);

int main(void){
    Node *root;
    int ch;
    root = NULL;
    printf("Creating a tree...\n");
    root = create(root);
    while (1){
        printf("Here are following operation you can perform next: \n");
        printf("1.Insert\n2.Display\n3.Exit\n:");
        getInt(&ch);
        switch (ch){
            case 1:{
                Node *new;
                new = (Node*)safeAllo(sizeof(Node));
                printf("Enter the data for new node: ");
                getInt(&new->data);
                new->left = NULL;
                new->right = NULL;
                insert(root, new);
                printf("Node %d inserted.\n", new->data);
                break;
            }
            case 2:{
                int chh;
                printf("Here are the following ways you can display: \n");
                printf("1.Preorder\n2.Postorder\n3.inorder\n:");
                getInt(&chh);
                switch(chh){
                    case 1:{
                        printf("Preorder Tree traversing: \n");
                        preorder(root);
                        printf("\n");
                        break;
                    }
                    case 2:{
                    printf("Postorder Tree traversing: \n");
                        postorder(root);
                        printf("\n");
                        break;
                    }
                    case 3:{
                        printf("Inorder Tree traversing: \n");
                        inorder(root);
                        printf("\n");
                        break;
                    }
                    default:{
                        printf("Invalid input\n");
                        break;
                    }
                }
                break;
            }
            case 3:{
                printf("Deleting all nodes... \n");
                deleteTree(root);
                printf("Done");
                return 0;
            }
            default:{
                printf("Invalid entry \n");
                break;
            }
        }
    }
    return 0;
}
Node *create(Node *root){
    int ch;
    do{
        Node *new;
        new = (Node*)safeAllo(sizeof(Node));
        new->left = NULL;
        new->right =NULL;
        printf("Enter the data: ");
        getInt(&new->data);
        if(root==NULL){
            root =new; 
        }else{
            insert(root, new);
        }
        printf("1 - For more nodes\nanything else - to exit\n:");
        getInt(&ch);
    }while (ch==1);
    return root;
}

void insert(Node *root, Node *new){
    if(new->data<root->data){
        if(root->left==NULL){
            root->left =new;
        }else{
            insert(root->left, new);
        }
    }else if(new->data>root->data){
        if(root->right==NULL){
            root->right=new;
        }else{
            insert(root->right, new);
        }
    }
    // Note: If new->data == root->data, the node is simply ignored (no duplicates)
}
void inorder(Node *ptr){
    if(ptr){
        if(ptr->left){
            inorder(ptr->left);
        }
        printf("%d ", ptr->data);
        if(ptr->right){
            inorder(ptr->right);
        }
    }
}

void preorder(Node *ptr){
    if(ptr){
        printf("%d ",ptr->data);
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
        printf("%d ", ptr->data);
    }
}

void deleteTree(Node *ptr) {
    if (ptr){
        deleteTree(ptr->left);
        deleteTree(ptr->right);
        free(ptr);
    }
}