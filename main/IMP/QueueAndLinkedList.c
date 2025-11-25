// Implementing Queue with circular LinkedList
#include <stdio.h>
#include <stdlib.h>
#include "c_utils.h"

#define ERROR_CODE -99999

struct node{
    int data;
    struct node *next;
};
struct node *rear, *front;
rear = NULL;
front = NULL;
void EnQueue(int data);
struct node Dequeue(void);
struct node QueueEmpty(void);
void display(void);
void Create(void);

int main(){
    struct node item;
    int ch, data;
    printf("\t\tCreation of Linked List\n");
    Create();
    while(1){
        printf("The Operations you can now perform are: ");
        printf("\n1.Enqueue\n2.Dequeue\n3.DISPLAY\n4.EXIT\n");
        printf("Your choice: ");
        getInt(&ch);
        switch(ch){
            case 1:{
                printf("Enter the value to add: ");
                getInt(&data);
                EnQueue(data);
                break;
            }
            case 2:{
                item = Dequeue();
                if(item.data==ERROR_CODE){
                    printf("QUEUE UNDERFLOW \n");
                    break;
                }
                printf("Removed %d from Front of Queue\n", item.data);
                break;
            }
            case 3:{
                display();
                break;
            }
            case 4:{
                printf("Thanks for using us");
                while (front != NULL) Dequeue();
                return 0;
            }
            default:{
                printf("Invalid Input\n");
                break;
            }
        }
    }
    return 0;
}

void Create(){
    int data, ch;
    do{
        struct node *new = (struct node*)safeAllo(sizeof(struct node));

        printf("Enter the value to be insearted: ");
        getInt(&data);
        new->data=data;
        new->next=NULL;
        if(rear==NULL){
            rear = new;
            front = new;
        }else{
            rear->next = new;
            rear = new;
        }
        printf("Do you want to continue to add? \n");
        printf("1 - Yes\nany digit - No\n:");
        getInt(&ch);
    }while(ch==1);
}

void EnQueue(int data){
    struct node *new;
    new = (struct node*)safeAllo(sizeof(struct node));
    new->data = data;
    new->next=NULL;
    if(rear == NULL){
        rear = new;
        front = new;
    }else{
        rear->next = new;
        rear = new;
    }
}

struct node Dequeue(void){
    if(front == NULL){
       return (QueueEmpty()); 
    }struct node item;
    struct node *temp;
    if(front == rear){
        item.data = front->data;
        free(front);
        front = NULL;
        rear = NULL;
    }else{
        temp = front;
        item.data = front->data;
        front = front->next;
        free(temp);
    }
    return item;
}
struct node QueueEmpty(void){
    struct node item;
    item.data = ERROR_CODE;
    item.next = NULL;
    return item;
}

void display(){
    if(front==NULL){
        printf("Queue Empyt");
        return;
    }
    printf("The elements are: \n");
    struct node *temp = front;
    while(temp!=NULL){
        printf("%d\n", temp->data);
        temp=temp->next;
    }
}