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
Node *search(Node*, int);
Node *find_min(Node*);
Node *find_max(Node*);
Node *delete(Node*, int);

int main(void){
    Node *root, *ptr;
    int ch, data;
    root = NULL;
    printf("Creating a tree...\n");
    root = create(root);
    while (1){
        printf("Here are following operation you can perform next: \n");
        printf("1.Insert\n2.Display\n3.Perform Binary search on tree\n4.Find minimum value in the tree\n5.Find Maximum value in the tree\n6.Exit\n:");
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
                printf("Enter the value to be searched: ");
                getInt(&data);
                ptr = search(root, data);
                if(ptr==NULL){
                    printf("The %d is not found \n",data);
                }else{
                    printf("The %d is found at address %p \n", data, &(ptr->data));
                }
                break;
            }
            case 4:{
                ptr = find_min(root);
                printf("The smallest number in the tree is %d \n", ptr->data);
                break;
            }
            case 5:{
                ptr = find_max(root);
                printf("The larget number in the tree is %d\n", ptr->data);
                break;
            }
            case 6:{
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
Node *search(Node *root, int key){
    if(root==NULL){
        return NULL;
    }else if(key<root->data){
        return search(root->left, key);
    }else if(key>root->data){
        return search(root->right, key);
    }else{
        return root;
    }
}

Node *find_min(Node *root){
    if(root==NULL){
        return root;
    }else if(root->left==NULL){
        return root;
    }else{
        return(find_min(root->left));
    }
}

Node*find_max(Node *root){
    if(root==NULL){
        return NULL;
    }else if(root->right==NULL){
        return root;
    }else{
        return find_max(root->right);
    }
}

Node *delete(Node *root, int data){
    if(root==NULL){
        return  root;
    }
    if(data<root->data){
        root->left = delete(root->left, data);
    }else if(data>root->data){
        root->right= delete(root->right, data);
    }else{
        if(root->left==NULL){
            Node *temp = root->right;
            free(root);
            return temp;
        }else if(root->right==NULL){
            Node *temp = root->left;
            free(root);
            return temp;
        }
        Node *temp = find_min(root->right);
        root->data=temp->data;
        root->right=delete(root->right, temp->data);
    }
    return root;
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