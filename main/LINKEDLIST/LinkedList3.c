// Lets perform bubble sort on linked list, and we are swapping data elements and not nodes
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head = NULL;

void Insertion(int);
void BubbleSort(void);
void display();

int main(){
    int n, value;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for(int i=0; i<n;i++){
        printf("Enter value for node %d: ", i+1);
        scanf("%d", &value);
        Insertion(value);
    }
    printf("\n Before sorting: \n");
    display();

    BubbleSort();

    printf("\nAfter sorting: \n");
    display();

    return 0;
}

void Insertion(int value){
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data= value;
    newNode->next = NULL;
    if(head== NULL){
        head = newNode;
        return;
    }
    struct node *temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next = newNode;
}

void BubbleSort(){
    if(head==NULL){
        return;
    }
    struct node *i, *j;
    int temp;
    int swapped;

    for(i=head;i->next != NULL;i = i->next){
        swapped = 0;
        for(j=head;j->next != NULL; j= j->next){
            if(j->data > j->next->data){
                temp = j->data;
                j->data = j->next->data;
                j->next->data = temp;
                swapped =1;
            }
        }
        if(!swapped)
            break;
    }
}

void display(){
    struct node *temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp= temp->next;
    }
    printf("\n");
}