// This a program, where we are gonna implement static Queue
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
#define ERROR_CODE 9999

int Rear = -1, Front =-1; // initally to show how empty queue looks
int Queue[MAX_SIZE]; // an array
void Enqueue(int); // adding an element
void QueueFull(void);
int Dequeue(void); // removing an element
int QueueEmpty(void);
void display(void);

int main(){
    int ch, element;
    while (1){
        printf("1.Enqueue \n2.Dequeue \n3.Display \n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:{
                printf("Enter the element to add: ");
                scanf("%d", &element);
                Enqueue(element);
                break;
            }
            case 2:{
                element = Dequeue();
                if(element==ERROR_CODE){
                    printf("Queue UNDERFLOW!!\n");
                    break;
                }printf("Removed %d\n",element);
                break;
            }
            case 3:{
                display();
                break;
            }case 4:{
                return 0;
            }
        
            default:{
                printf("Invalid input!!!\n");
                break;
            }
        }
    }
}

void Enqueue(int element){
    if(Rear>=MAX_SIZE-1){
        QueueFull();
    }else{
        if(Front==-1){
            Front++;
        }
        Queue[++Rear] = element;
        return;
    }
}
void QueueFull(){
    printf("QUEUE OVERFLOW!!\n");
}

int Dequeue(){
    if((Front==-1) || (Front>Rear)){
        return (QueueEmpty());
    }
    return Queue[Front++];
}
int QueueEmpty(){
    int element = ERROR_CODE;
    return element;
}

void display(){
    if((Front==-1) || (Front>Rear)){
        printf("Queue's Empte \n");
    }else{
        printf("Elements in the Queue are: \n");
        for(int i = Front; i <= Rear; i++){
            printf("%d\n", Queue[i]);
        }
    }
}