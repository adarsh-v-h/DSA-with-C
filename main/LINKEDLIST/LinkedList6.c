// Circular singly Linked List.
#include <stdio.h>
#include <stdlib.h>
// #ifdef _WIN32
#include <Windows.h>
// #else
// #include <unistd.h>
// #endif
#define ERROR_CODE -999999

struct node{
    int data;
    struct node *next;
};
struct node *head, *tail, *temp, *new;

int n =0;
void Create(void);
void display(void);
void InsertAtHead(int);
void InsertAtEnd(int);
void InsertAtPos(int,int);
int DeleteAtHead();
int DeleteAtEnd();
int DeleteAtPos(int);
int main(){
    printf("Creating a LinkedList: \n");
    Create();
    Sleep(1);
    int ch, data, pos, ch1;
    printf("The operations you can perform are: \n");
    Sleep(1);
    while (1){
        noob_move:
        printf("1.Insertion\n2.Deletion\n3.Display\n4.Exit\n");
        printf("Enter your chooice: ");
        scanf("%d",&ch);
        switch (ch){
            case 1:{
                Sleep(1);
                printf("Starting Insertion operation...");
                printf("Here are your choices: \n");
                printf("1.Insertion at the Head\n2.Insertion at the Tail\n3.Insertion at a position\n4.Go back to main menu\n");
                Sleep(1);
                printf("Your choice: ");
                scanf("%d", &ch1);
                switch (ch1){
                    case 1:{
                        Sleep(1);
                        printf("Enter the element: ");
                        scanf("%d", &data);
                        InsertAtHead(data);
                        n++;
                        break;
                    }
                    case 2:{
                        Sleep(1);    
                        printf("Enter the element: ");
                        scanf("%d", &data);
                        InsertAtEnd(data);
                        n++;
                        break;
                    }
                    case 3:{            
                        Sleep(1);    
                        printf("Enter the position to insert at: ");
                        scanf("%d", &pos);
                        printf("Enter the element: ");
                        scanf("%d", &data);
                        InsertAtPos(pos, data);
                        n++;
                        break;
                    }case 4:{
                        goto noob_move;
                    }
                    default:{
                        printf("Invalid Entey\n");
                        break;
                    }
                }
                break;
            }
            case 2:{
                Sleep(1);
                printf("Starting Deletion operation...");
                printf("Here are your choices: \n");
                printf("1.Deletion at the Head\n2. Deletion at the Tail\n3.Deletion at a position\n4.Go back to main menu\n");
                Sleep(1);
                printf("Your choice: ");
                scanf("%d", &ch1);
                switch (ch1){
                    case 1:{
                        Sleep(1);
                        data = DeleteAtHead();
                        if(data==ERROR_CODE){
                            printf("Empty Linked List..\n");
                            break;
                        }
                        printf("The Element removed is %d\n", data);
                        n--;
                        break;
                    }
                    case 2:{
                        Sleep(1);
                        data = DeleteAtEnd();
                        if(data==ERROR_CODE){
                            printf("Empty Linked List...\n");
                            break;
                        }
                        printf("The Element removed is %d\n", data);
                        n--;
                        break;
                    }
                    case 3:{            
                        Sleep(1);    
                        printf("Enter the position to delete at: ");
                        scanf("%d", &pos);
                        data = DeleteAtPos(pos);
                        if(data==ERROR_CODE){
                            printf("Empty Linked List OR invalid positon\n");
                            break;
                        }
                        printf("The Element removed is %d\n", data);
                        n--;
                        break;
                    }case 4:{
                        goto noob_move;
                    }
                    default:{
                        printf("Invalid Entey\n");
                        break;
                    }
                }
                break;
            }
            case 3:{
                Sleep(1);
                if(head==NULL){
                    printf("List is Empty\n");
                    break;
                }
                printf("The elements are: \n");
                display();
                break;
            }
            case 4:{
                printf("Ending");
                return 0;
            }
            default:{
                printf("Invalid Entey\n");
                break;
            }
        }
    }
}

void Create(){
    int data, ch;
    do{
        new = (struct node*)malloc(sizeof(struct node));
        printf("Enter data for %d node: ", n);
        scanf("%d", &data);
        new->next = NULL;
        new->data = data;
        if(head==NULL){
            head = new;
            tail = new;
            new->next = new; // for the first node it will be pointing to itself
        }
        else{
            tail->next = new;
            new->next = head;
            tail = new;
        }
        Sleep(1);
        n++;
        printf("Continue adding - 1 \nor\nExit - any digit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
    }while(ch==1);
}

void InsertAtHead(int data){
    new = (struct node*)malloc(sizeof(struct node));
    new->data = data;
    if(head==NULL){
        head=new;
        tail=new;
        new->next=new;
        return;
    }
    new->next= head;
    tail->next = new;
    head = new;
}

void InsertAtEnd(int data){
    new = (struct node*)malloc(sizeof(struct node));
    new->data=data;
    if(head==NULL){
        head=new;
        tail=new;
        new->next=new;
        return;
    }
    new->next=head;
    tail->next=new;
    tail=new;
}

void InsertAtPos(int pos, int data){
    if(pos==1){
        InsertAtHead(data);
        return;
    }
    if(pos==n+1){
        InsertAtEnd(data);
        return;
    }
    if(pos<0 || pos>n+1){
        printf("Invalid Input \n");
        return;
    }
    new = (struct node*)malloc(sizeof(struct node));
    temp = head;
    new->data = data;
    for(int i = 0; i<pos-2;i++){
        temp = temp->next;
    }
    new->next = temp->next;
    temp->next=new;
}

int DeleteAtHead(){
    if(head==NULL){
        return ERROR_CODE;
    }
    int data;
    if(head == tail) {
    data = head->data;
    free(head);
    head = NULL;
    tail = NULL;
    return data;
    }
    temp=head;
    head = head->next;
    data = temp->data;
    tail->next=head;
    free(temp);
    return data;
}

int DeleteAtEnd(){
    if(head==NULL){
        return ERROR_CODE;
    }
    int data;
    if(head==tail){
        data = head->data;
        free(head);
        head=NULL;
        tail=NULL;
        return data;
    }
    temp=head;
    while(temp->next!=tail){
        temp=temp->next;
    }
    temp->next=head;
    data = tail->data;
    free(tail);
    tail = temp;
    return data;
}

int DeleteAtPos(int pos){
    if(head==NULL){
        return ERROR_CODE;
    }

    int data;
    if(pos==1){
        data = DeleteAtHead();
        return data;
    }

    if(pos==n){
        data = DeleteAtEnd();
        return data;
    }

    if(pos<0 || pos>n){
        return ERROR_CODE;
    }
    struct node *temp2;
    temp=head;
    for(int i = 0; i<pos-2; i++){
        temp=temp->next;
    }

    temp2 = temp->next;
    temp->next=temp2->next;
    data = temp2->data;
    free(temp2);
    return data;
}

void display(){
    temp = head;
    do{
        printf("%d->", temp->data);
        temp = temp->next;
    }while(temp!=head);
    printf(" Back to first node \n");
    printf("Number of elements: %d\n", n);
}
