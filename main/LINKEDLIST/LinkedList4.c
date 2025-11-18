// Lets see how we can create doubly LinkedList and perform insteration and deletion operations on them....
#include <stdio.h>
#include <stdlib.h>

#define ERROR_CODE -999999
struct node{
    struct node *prev, *next;
    int data;
};

struct node *head = NULL, *tail = NULL, *temp, *new;
int n = 0;
void Create();
void InsertAtEnd(int);
void InsertAtHead(int);
void Insertion(int, int);
int DeleteAtEnd(void);
int DeleteAtHead(void);
int Deletion(int);
void Display(void);

int main(){
    int ch, value, pos;
    Create();
    while(1){
        printf("1. Insert at the end\n2. Insert at the head\n3. Insert in between\n4. Delete at the end\n5. Delete at the head\n6. Delete in between\n7. Display\n8. Exit\n");
        printf("Enter you prefered Operation: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:{
            printf("Enter the value to insert: ");
            scanf("%d",&value);
            InsertAtEnd(value);
            break;
        }
        case 2:{
            printf("Enter the value to insert: ");
            scanf("%d",&value);
            InsertAtHead(value);
            break;
        }
        case 3:{
            printf("Enter the value to insert: ");
            scanf("%d",&value);
            printf("Enter the position to insert: ");
            scanf("%d", &pos);
            Insertion(value, pos);
            break;
        }
        case 4:{
            value = DeleteAtEnd();
            if(value == ERROR_CODE){
                printf("There is no LinkedList");
            }else{
                printf("Removed %d", value);
            }
            break;
        }
        case 5:{
            value = DeleteAtHead();
            if(value == ERROR_CODE){
                printf("There is no LinkedList");
            }else{
                printf("Removed %d", value);
            }
            break;
        }
        case 6:{
            printf("Enter the position of the element: ");
            scanf("%d",&pos);
            value = Deletion(pos);
            if(value == ERROR_CODE){
                printf("There is no LinkedList");
            }else{
                printf("Removed %d", value);
            }
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
    return 0;
}

void Create(){
    int value, ch;
    do{
        new = (struct node*)malloc(sizeof(struct node));
        printf("Enter the value: ");
        scanf("%d", &value);
        new->data = value;
        new->next= NULL;
        new->prev = NULL;
        if(head == NULL){
            head = new;
            tail = new;
        }else{
            tail->next = new;
            new->prev = tail;
            tail = new;
           
        }
        n++;
        printf("Continue - 1, Exit - 2\n");
        scanf("%d",&ch);
    }while (ch==1);
}

void InsertAtHead(int value){
    new = (struct node*)malloc(sizeof(struct node));
    new->data=value;
    new->next=head;
    new->prev= NULL;
    if(head == NULL){
        head = new;
        tail = new;
    }else{
    head->prev = new;
    head = new;
    }
    n++;
}

void InsertAtEnd(int value){
    new = (struct node*)malloc(sizeof(struct node));
    new->data=value;
    new->next=NULL;
    new->prev= tail;
    if(tail==NULL){
        head = new;
        tail = new;
    }else{
    tail->next = new;
    tail = new;
    }
    n++;
}

void Insertion(int value, int pos){
    if(pos>n || pos<0){
        printf("Invalid input");
    }else if(pos==0){
        InsertAtHead(value);
        return;
    }else if(pos==n){
        InsertAtEnd(value);
        return;
    }else{
        new = (struct node*)malloc(sizeof(struct  node));
        temp = head;
        for(int i=1;i<pos-1;i++){
            temp = temp->next;
        }
        new->prev = temp;
        new->next = temp->next;
        temp->next->prev=new;
        temp->next=new;
        new->data= value;
        n++;
    }
}

int DeleteAtHead(void){
    if(head==NULL){
        return ERROR_CODE;
    }
    temp= head;
    int value = temp->data;;
    head = head->next;
    if(head == NULL){
        tail=NULL;
    }else{
    head->prev = NULL;
    }
    free(temp);
    n--;
    return value;
}

int DeleteAtEnd(void){
    if(head == NULL){
        return ERROR_CODE;
    }
    temp = tail;
    int value= temp->data;
    tail = tail->prev;
    if(tail == NULL){
        head=NULL;
    }else{
    tail->next=NULL;
    }
    free(temp);
    n--;
    return value;
}

int Deletion(int pos){
    if(pos >=n || pos < 0 || head == NULL){
        return ERROR_CODE;
    }else if(pos==n-1){
        return DeleteAtEnd();
    }else if(pos==0){
        return DeleteAtHead();
    }
        temp=head;
        for(int i =1;i<pos;i++){
            temp = temp->next;
        }
        int value = temp->data;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        n--;
        free(temp);
        return value;
}

void Display(){
    temp=head; 
    int i =0;
    printf("\nList contains: \n");
    while(temp != NULL){
        printf("Element %d: %d\n",i, temp->data);
        temp = temp->next;
        i++;
    }
    printf("Number of elements: %d \n", i);
}
