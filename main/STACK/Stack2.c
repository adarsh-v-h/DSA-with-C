// Now we will try to create a stack dynamicallly..
#include <stdio.h>
#include <stdlib.h>
#define ERROR_CODE 9999
typedef struct{
    int key;
}element;

//instead of declaring a whole stack, we will just create pointer
element *stack;
void push(element);
void StackFull();
element pop();
element StackEmpty();
void display();
//intial values
int top =-1;
int capacity = 1;
int main(){
// now use malloc to allocate it its first memory, this should always be in a function
    stack = (element*)malloc(sizeof(stack));
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

void push(element item){
    if(top>=capacity-1){
        StackFull();
    }
    stack[++top] = item;
}
void StackFull(){
    stack = (element*)realloc(stack, 2*capacity*sizeof(stack));
    capacity*=2;
    // here we take the current capacity of the stack, and double it, therefor making space for new elements
}
// everything except except push and StackFull function stays the same, we just had to make sure, we can stretch the stack, 
// that too only when stack is full
element pop(){
    if(top==-1){
        return (StackEmpty());
    }
    return stack[top--];
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
        printf("%d \n",stack[temp].key);
    }
}