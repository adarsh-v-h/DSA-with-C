// Implementing Queue with circular LinkedList
#include <stdio.h>
#include <stdlib.h>

#define ERROR_CODE -99999

struct node{
    int data;
    struct node *next;
};
struct node *rear, *front;

void EnQueue(struct node);
struct node Dequeue(void);
struct node QueueEmpyt(void);
void display(void);
void Create();

int main(){
    struct node item;
    int  ch;
    printf("\t\tCreation of Linked List\n");
    Create();
    while(1){
        printf("The Operations you can now perform are: ");
        printf("\n1.Enqueue\n2.Dequeue\n3.DISPLAY\n4.EXIT\n");
        printf("Your choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1:{
                printf("Enter the value to add: ");
                if(scanf("%d", &item.data)!=1){printf("Invalid input.."); exit(1);}
                EnQueue(item);
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
        struct node *new;
        new = (struct node*)malloc(sizeof(struct node));
        printf("Enter the value to be insearted: ");
        if(scanf("%d", &data)!=1){printf("Invalid input.."); exit(1);}

        new->data=data;
        if(rear==NULL){
            rear = new;
            front = new;
        }else{
            rear->next = new;
            rear = new;
        }
        printf("Do you want to continue to add? \n");
        printf("1 - Yes\nany digit - No\n:");
        if(scanf("%d", &ch)!=1){printf("Invalid input.."); exit(1);}

    }while(ch==1);
}

void EnQueue(struct node item){
    struct node *new;
    new = (struct node*)malloc(sizeof(struct node));
    new->data = item.data;
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
    struct node item;
    struct node *temp;
    if(front == NULL){
        item.data = ERROR_CODE;
    }else if(front == rear){
        item.data = front->data;
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