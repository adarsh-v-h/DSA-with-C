#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
    bool leftThread;   
    bool rightThread;  
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->leftThread = true;
    newNode->rightThread = true;
    return newNode;
}

Node* leftmost(Node* node) {
    if (node == NULL)
        return NULL;
    while (node->left != NULL && !node->leftThread)
        node = node->left;
    return node;
}

Node* insert(Node* root, int data) {
    Node* ptr = root;
    Node* parent = NULL;
    while (ptr != NULL) {
        if (data == ptr->data) {
            printf("Duplicate key!\n");
            return root;
        }
        parent = ptr;
        if(data < ptr->data){
            if (!ptr->leftThread)
                ptr = ptr->left;
            else
                break;
        }else{
            if(!ptr->rightThread){
                ptr = ptr->right;
            }
            else{
                break;
            }
        }
    }
    Node* newNode = createNode(data);
    if(parent == NULL){
        root = newNode;
        newNode->left = NULL;
        newNode->right = NULL;
    }else if(data < parent->data){
        newNode->left = parent->left;
        newNode->right = parent;
        parent->leftThread = false;
        parent->left = newNode;
    }else{
        newNode->right = parent->right;
        newNode->left = parent;
        parent->rightThread = false;
        parent->right = newNode;
    }
    return root;
}

void inorderTraversal(Node* root) {
    if (root == NULL) {
        printf("Tree is empty!\n");
        return;
    }
    Node* current = leftmost(root);
    while (current != NULL) {
        printf("%d ", current->data);
        if (current->rightThread)
            current = current->right;
        else
            current = leftmost(current->right);
    }
    printf("\n");
}

void displayTree(Node* root, int space) {
    if (root == NULL)
        return;
    space += 5;
    if (!root->rightThread)
        displayTree(root->right, space);
    printf("\n");
    for (int i = 5; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);
    
    if (!root->leftThread)
        displayTree(root->left, space);
}

int main() {
    Node* root = NULL;
    int choice, value;
    
    printf("=== Threaded Binary Tree Implementation ===\n\n");
    
    while (1) {
        printf("\n1. Insert Node\n");
        printf("2. Inorder Traversal\n");
        printf("3. Display Tree Structure\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Node inserted successfully!\n");
                break;
                
            case 2:
                printf("Inorder Traversal: ");
                inorderTraversal(root);
                break;
                
            case 3:
                printf("\nTree Structure:\n");
                displayTree(root, 0);
                break;
                
            case 4:
                printf("Exiting program...\n");
                exit(0);
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}
