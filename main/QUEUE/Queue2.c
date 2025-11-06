// Now we are gonna alloct a Queue but dynamically.
#include <stdio.h>
#include <stdlib.h>
#define ERROR_CODE 99999

typedef struct{
    int key;
}element;

element *Queue;
int Rear=-1, Front=-1;
void Enqueue(element);
int capacity = 1;
void QueueFull(void);
element Dequeue(void);
element QueueEmpty(void);
void display();
int main(){
    int ch;
    element item;
    Queue = (element*)malloc(sizeof(Queue));
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
void Enqueue(element item){
    if(Rear >= capacity-1){
        QueueFull();
    }
    if(Front == -1){
        Front++;
    }
    Queue[++Rear] = item;
}
void QueueFull(){
    Queue = (element*)realloc(Queue, 2*capacity*sizeof(Queue));
    capacity *=2;
}
element Dequeue(){
    if((Front==-1) || (Front>Rear)){
        return (QueueEmpty());
    }
    return Queue[Front++];
}
element QueueEmpty(){
    element item;
    item.key = ERROR_CODE;
    return item;
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