// Now we are gonna create Static circular queues
#include <stdio.h>
#include <stdlib.h>
#define N 10
#define ERROR_CODE 9999
int Queue[N];
int Rear =-1, Front =-1;
void Enqueue(int);
int Dequeue(void);
void QueueFull(void);
int QueueEmpty(void);
void display(void);
int main(){
    int item, ch;
    while (1){
        printf("1.Enqueue \n2.Dequeue \n3.Display \n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:{
                printf("Enter the element to add: ");
                scanf("%d", &item);
                Enqueue(item);
                break;
            }
            case 2:{
                item = Dequeue();
                if(item==ERROR_CODE){
                    printf("Queue UNDERFLOW!!\n");
                    break;
                }printf("Removed %d\n",item);
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
    return 0;
}

void Enqueue(int item){
    if((Front==-1) || (Rear==-1)){
        Rear=0;
        Front =0;
        Queue[Rear] = item;
    }else if ((Rear+1)%N == Front){
        QueueFull();
    }else{
        Rear = (Rear+1)%N;
        Queue[Rear] = item;
    }
}
void QueueFull(){
    printf("QUEUE OVERFLOW!!! \n");
}

int Dequeue(){
    int item;
    if((Rear==-1)&&(Front==-1)){
        item = QueueEmpty();
    }else{
        if(Front==Rear){
            item = Queue[Front];
            Front = Rear = -1;
        }else{
            item = Queue[Front];
            Front = (Front+1)%N;
        }
    }
    return item;
}
int QueueEmpty(){
    int item = ERROR_CODE;
    return item;
}

void display(){
    if((Front==-1)||(Rear==-1)){
        printf("Stack is empyt... \n");
    }else{
        int i;
        printf("Here are the following elements: \n");
        for(i = Front; i!=Rear; i = (i+1)%N){
            printf("%d \n", Queue[i]);
        }
        i = (i+1)%N;
        printf("%d\n", Queue[i]);
    }
}