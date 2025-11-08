// We are gonna create a singlylinked link, which grows like a snake everytime we want to add an element. We are also have operations to perform on them
// We have nodes, which have 2 fields, data field and pointer field.
#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
}*head, *tail;
void Create(void);
void InsertAtEnd(void);
void InsertAtHead(void);
void Insertion(void);
void DeleteAtEnd(void);
void DeleteAtHead(void);
void Deletion(void);
void Display(void);
int main(){
    printf("Lets start with creating a linked list....\n");
    Create();
    int ch;
    while (1){
        printf("1. Insert at the end\n2. Insert at the head\n3. Insert in between\n4. Delete at the end\n5. Delete at the head\n6. Delete in between\n7. Display\n8. Exit\n");
        printf("What operation from the above do you want to perform: ");
        scanf("%d", &ch);
        switch(ch){
            case 1: {
                InsertAtEnd();
                break;
            }
            case 2: {
                InsertAtHead();
                break;
            }
            case 3:{
                Insertion();
                break;
            }
            case 4: {
                DeleteAtEnd();
                break;
            }
            case 5: {
                DeleteAtHead();
                break;
            }
            case 6: {
                Deletion();
                break;
            }
            case 7: {
                Display();
                break;
            }
            case 8: {
                printf("All the Links you have will be gone...");
                return 0;
            }
            default:{
                printf("INVALID INPUT!! \nEnter only among the follow\n");
            }
        }
    }
}

void Create(){
    int value, ch, i=0;
    do{
        struct node *newNode = malloc(sizeof(struct node));
        newNode = (struct node*)malloc(sizeof(struct node));
        newNode->next = NULL;
        printf("Enter the value you want to add at the %d newNode: ", i);
        scanf("%d", &value);
        newNode->data = value;
        if(head==NULL){
            head= newNode;
            tail = newNode;
        }else{
            tail->next=newNode;
            tail= newNode;
        }
        // free(newNode);
        i++;
        printf("1-Continue, anything else-Exit: ");
        scanf("%d", &ch);
    }while (ch==1);
}
void InsertAtHead(){
    int value;
    struct node *newNode = malloc(sizeof(struct node));
    newNode->next = NULL;
    printf("Enter the value: ");
    scanf("%d", &value);
    newNode->next = head;
    newNode->data = value;
    head = newNode;
    if(tail==NULL){
        tail=newNode;
    }
}

void InsertAtEnd(){
    int value;
    struct node *newNode = malloc(sizeof(struct node));
    newNode->next = NULL;
    printf("Enter the value: ");
    scanf("%d", &value);
    newNode->data=value;
    if(tail==NULL){
        head=tail=newNode;
    }else{
        tail->next=newNode;
        tail=newNode;
    }
}
void Insertion(){
    int value, pos;
    printf("Enter the position: ");
    scanf("%d", &pos);
    if(pos<0){
        printf("INVALID INPUT!!");
        return; 
    }else if(pos==1){
        InsertAtHead();
        return;
    }
    struct node *newNode = malloc(sizeof(struct node));
    newNode->next=NULL;
    printf("Enter the value: ");
    scanf("%d", &value);
    newNode->data = value;
    struct node *temp= head;
    for(int i=0;i<pos-1;i++){
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    if (newNode->next == NULL){
        tail = newNode;
    }
}

void DeleteAtHead(){
    if(head==NULL){
        printf("Empty linkedList...");
        return;
    }
    struct node *temp = head;
    head = head->next;
    if(head==NULL){
        tail= NULL;
    }
    free(temp);
}

void DeleteAtEnd(){
    if(head==NULL){
        printf("Empty linkedList...");
        return;
    }
    if (head == tail) {
        free(head);
        head = tail = NULL;
        return;
    }
    struct node *temp= head;
    while(temp->next != tail){
        temp=temp->next;  
    }
    free(tail);
    tail = temp;
    tail->next=NULL;
}

void Deletion(){
    int pos;
    printf("Enter the position of the list, which you want to delete: ");
    scanf("%d", &pos);
    if (head == NULL) { 
        printf("List empty. Nothing to delete.\n"); 
        return; 
    }if (pos <= 0) { 
        printf("Position must be >= 1\n"); 
        return; 
    }
    struct node *temp, *temp2;
    temp = head;
    for(int i = 0; i<pos-1;i++){
        temp = temp->next;
    }
    temp2= temp->next;
    // temp->next = temp->next->next; or
    temp->next = temp2->next;
    if(temp2->next==NULL){
        tail= temp;
    }
    free(temp2);
}

void Display(){
    if(head==NULL){
        printf("Empty linkedList...\n");
        return;
    }
    int count=0;
    struct node *temp= head;
    while(temp!=NULL){
        count++;
        printf("%d\n", temp->data);
        temp=temp->next;
    }
    printf("No. of nodes are: %d\n", count);
}