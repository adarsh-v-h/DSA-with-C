// Now we will try to implement circular queues dynamically, we will be useing malloc and realloc

#include <stdio.h>
#include <stdlib.h>
#define ERROR_CODE 99999
typedef struct {
    int key;
}element;
element *Queue;
int Rear = -1, Front = -1, Capacity = 1;
void Enqueue(element);
element Dequeue(void);
void QueueFull(void);
element QueueEmpty(void);
void display();
void copy(element*, element*, element*);
int main(){
    element item;
    int ch;
    Queue = (element*)malloc(sizeof(element));
    while (1){
        printf("1.Enqueue \n2.Dequeue \n3.Display \n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:{
                printf("Enter the element to add: ");
                scanf("%d", &item.key);
                Enqueue(item);
                break;
            }
            case 2:{
                item = Dequeue();
                if(item.key==ERROR_CODE){
                    printf("Queue UNDERFLOW!!\n");
                    break;
                }printf("Removed %d\n",item.key);
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

void Enqueue(element item){
    if((Front==-1)&&(Rear==-1)){
        Rear=Front=0;
        Queue[Rear] = item;
        return;
    }else{ 
        if((Rear+1)%Capacity == Front)
            QueueFull();
        Rear = (Rear+1)%Capacity;
        Queue[Rear]=item;
    }
}
void QueueFull(){
    element *new;
    new = (element*)malloc(2*Capacity*sizeof(element));
    int Start= Front;
    if(Start<=Rear){
        copy(Queue+Start, Queue+Start+Capacity-1, new);
    }else{
        // we are dividing the queue, first from front to end
        copy(Queue+Start, Queue+ Capacity-1, new);
        // the second from 0 to rear
        copy(Queue, Queue+Rear, new+Capacity-Start);
    }
    free(Queue);
    Queue = new;
    Front = 0;
    Rear = Capacity-1;
    Capacity *=2;
}
void copy(element *Start, element *End, element *new){
    int i =0;
    while((Start+i)!=End){
        new[i] = Start[i];
        i++;
    }
    new[i] = Start[i];
}

// The dequeue operations remain the same
element Dequeue(){
    element item;
    if((Rear==-1)&&(Front==-1)){
        item = QueueEmpty();
    }else{
        item = Queue[Front];
        if(Front==Rear){ 
            Front = Rear = -1;
        }else{
            Front = (Front+1)%Capacity;
        }
    }
    return item;
}
element QueueEmpty(){
    element item;
    item.key = ERROR_CODE;
    return item;
}

// A slight change in display function, instead of a fixed value like N, we are gonna use Capacity
void display(){
    if((Front==-1)||(Rear==-1)){
        printf("Stack is empyt... \n");
    }else{
        int i;
        printf("Here are the following elements: \n");
        for(i = Front; i!=Rear; i = (i+1)%Capacity){
            printf("%d \n", Queue[i].key);
        }
        // i = (i+1)%Capacity;
        printf("%d\n", Queue[i].key);
    }
}