// This code to perform linear search on the elements of the linked list...
#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};

struct node *head=NULL;

void Insertion(int value);
int linearSearch(int key);
void display(void);

int main(){
    int n, value, key;

    printf("How many nodes do you want to insert: ");
    scanf("%d", &n);

    for(int i =0;i<n;i++){
        printf("Enter the valye for node %d: ", i+1);
        scanf("%d", &value);
        Insertion(value);
    }
    printf("\n Linked List: ");
    display();
    printf("Enter the key value to search: ");
    scanf("%d", &key);

    int pos = linearSearch(key);
    if(pos==-1){
        printf("Entered key not found..");
    }else{
        printf("The key value found at %d position", pos);
    }
    return 0;
}

void Insertion(int value){
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next= NULL;
    if(head==NULL){
        head = newNode;
        return;
    }
    struct node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next=newNode;
}

int linearSearch(int key){
    struct node *temp = head;
    int pos = 1;
    while(temp!=NULL){
        if(temp->data== key){
            return pos;
        }
        temp = temp->next;
        pos++;
    }
    return -1;
}

void display(){
    struct node *temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp= temp->next;
    }
    printf("\n");
}