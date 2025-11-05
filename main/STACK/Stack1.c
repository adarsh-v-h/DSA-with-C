// This is a code, where we will implement stack, but static
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
#define ERROR_CODE 99999

typedef struct{
    int key;
} element;
element Stack[MAX_SIZE]; // the stack
void push(element); // adding an element to the stack
element pop(void); // removing an element for stack
void display(void);

// Handling overflow and underflow conditions
void StackFull(void);
element StackEmpty(void);

int top = -1;

int main(){
    int ch;
    element item;
    while (1)
    {
        printf(" 1. push \n 2. pop \n 3. display \n 4. EXIT \n");
        printf("Enter your choice from the above options: ");
        scanf("%d", &ch);
       switch (ch)
        {
        case 1:{ printf("Enter the element to push: ");
            scanf("%d", &item.key);
            push(item);
            break;
        }
        case 2:{ item = pop();
            if(item.key == ERROR_CODE){
                printf("Stack empty ... please push before popping... \n");
                break;
            }printf("Removed %d \n", item.key);
            break;
        }
        case 3:{
            display();
            break;
        }
        case 4:{ printf("Ending \n");
            exit(0);
        }
        default:{
            printf("Invalid choice.. \n");
            break;
        }
    }
    }
    return 0;
}

void push(element item) {
    if (top >= MAX_SIZE - 1) {
        StackFull();
        return;
    }
    Stack[++top] = item;
}
void StackFull(){
    printf("STACK OVERFLOW!!!!");
}

element pop(){
    if(top==-1){
        return (StackEmpty());
    }
    return Stack[top--];
}
element StackEmpty(){
    element item;
    item.key = ERROR_CODE;
    return item;
}

void display(){
    if(top==-1){
        printf("STACK EMPTY! \n");
        return;
    }
    for(int temp = top;temp>=0;temp--){
        printf("%d \n",Stack[temp].key);
    }
}