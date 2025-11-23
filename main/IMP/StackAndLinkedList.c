// Here we will try to implement stack using Linked list...
#include <stdio.h>
#include <stdlib.h>
// #include <unistd.h>
#include <windows.h>
#define ERROR_CODE 99999

struct node{
    int data;
    struct node *next;
};
struct node *top = NULL;
struct node *temp=NULL;
int n = 0;
// Function prototypes
void Create(void);
void Push(int);
int Pop(void);
void display(void);

int main(){
    int data, ch;
    printf("Lets first start with Creating a Stack \n");
    Sleep(2);
    Create();
    while(1){
        printf("The Operations you can now perform are: ");
        printf("\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n");
        printf("Your choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1:{
                printf("Enter the value to push: ");
                scanf("%d", &data);
                Push(data);
                n++;
                break;
            }
            case 2:{
                Sleep(1);
                data = Pop();
                if(data==ERROR_CODE){
                    printf("Stack UNDERFLOW\n");
                    break;
                }
                printf("Removed %d from top of the stack\n", data);
                n--;
                break;
            }
            case 3:{
                Sleep(1);
                printf("The elements are: \n");
                display();
                break;
            }
            case 4:{
                Sleep(1);
                return 0;
            }
            default:{
                Sleep(1);
                printf("Invalid Input\n");
                break;
            }
        }
    }

}

void Create(){
    int data, ch;
    struct node *new = NULL;
    do{
        printf("Enter data for %d node: ", n);
        scanf("%d", &data);
        new = (struct node*)malloc(sizeof(struct node));
        new->data = data;
        if(top == NULL){
            new->next = NULL;
            top = new;
        }else{
            new->next = top;
            top = new;
        }
        Sleep(1);
        n++;
        printf("To Continue - 1\n To end - any digit\n");
        printf("Your choice: ");
        scanf("%d", &ch);
    }while(ch==1);
}

void Push(int data){
    struct node *new = NULL;
    new = (struct node*)malloc(sizeof(struct node));
    new->next=top;
    new->data = data;
    top = new;
}

int Pop(){
    int data;
    if(top==NULL){
        data = ERROR_CODE;
    }else{
        temp = top;
        top = top->next;
        data = temp->data;
        free(temp);
    }
    return data;
}

void display(){
    temp = top;
    while(temp!=NULL){
        printf("%d->", temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}