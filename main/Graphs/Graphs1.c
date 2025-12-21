#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100
int STACK[MAX_SIZE]; // for implementation of DFS
int QUEUE[MAX_SIZE]; // for implementation of BFS
int a[MAX_SIZE][MAX_SIZE]; //for Adjacency Matrix
int visit[MAX_SIZE]; //Track visiting vertices
int top;
int front;
int rear;
int n; //number of vertcies
void BFS(int);
void DFS(int);
void Enqueue(int);
int Dequeue(void);
void push(int);
int pop(void);

int main(void){
    int i,j,ch,startV;
    printf("Enter the number of vertices for a Graph G\n");
    scanf("%d", &n);
    if(n==0){
        printf("Empty Graph\n");
        exit(0);
    }
    printf("Enter the adjaency Matrix of a Graph G\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("Enter the weight for an Edge from vertex %d to %d vertex\n",i,j);
            printf("0 - No Edge, 1-Edge\n");
            scanf("%d", &a[i][j]);
        }
    }
    printf("Adjacency Matrix \n \n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d\t", a[i][j]);
        }
        printf("\n\n");
    }
    do{
        printf("\n \n");
        printf("Enter the choice \n 1-BFS-Travesal \n 2-DFS-Traversal 3-Exit \n \n");
        scanf("%d", &ch);
        if(ch==1){
            front=-1;
            rear = -1;
            // Intialize vertices as unvisited
            for(i=0;i<n;i++){
                visit[i] = 0;
            }
            printf("Enter the starting vertex for BFS-Travesal\n");
            scanf("%d", &startV);
            printf("\n------BFS Travesal------\n");
            BFS(startV);
        }else if(ch==2){
            top = -1;
            // Intialize vertices as unvisited
            for(i=0;i<n;i++){
                visit[i] = 0;
            }
            printf("Enter the starting vertex for DFS-Travesal\n");
            scanf("%d", &startV);
            printf("\n------DFS Travesal------\n");
            DFS(startV);
        }else if(ch==3){
            return 0;
        }
    }while(1);
}

void BFS(int startV){
    int i,j,x;
    front = 0;
    rear = 0;
    QUEUE[rear] = startV;
    do{
        i = QUEUE[front];
        visit[i] = 1;
        for(j=0;j<n;j++)
            if(a[i][j] == 1 && visit[j] != 1){
                Enqueue(j);
                visit[j] =1;
            }
        x = Dequeue();
        printf("%d\t",x);
    }while(front <= rear);
}

void Enqueue(int j){
    rear = rear +1;
    QUEUE[rear] = j;
}

int Dequeue(void){
    int x;
    x = QUEUE[front];
    front = front + 1;
    return(x);
}

void DFS(int startV){
    int flag,i,j,x;
    printf("%d\t",startV);
    visit[startV] = 1;
    push(startV);
    do{
        i = STACK[top];
        flag = 0;
        for(j=0; j<n; j++){
            if(a[i][j] == 1 && visit[j] != 1){
                flag =1;
                visit[j] =1;
                printf("%d\t",j);
                push(j);
                break;
            }
        }
        if(flag !=1)
        pop();
    }while(top != -1);
}

void push(int x){
    STACK[++top] = x;
}
int pop(void){
    int x;
    x = STACK[top];
    top = top - 1;
    return(x);
}