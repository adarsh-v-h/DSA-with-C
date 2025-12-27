#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int create(int);
void linear_prob(int[],int,int);
void display(int[]);

int main(void){
    int a[MAX],L,key,i;
    int ans=1,count=0;
    printf("Hash Table: Collision handling by linear probing\n");
    for(i=0;i<MAX;i++){
        a[i]=-1;
    }
    do{
        printf("Enter the data: ");
        scanf("%4d",&key);
        count++;
        L=create(key);
        linear_prob(a,L,key);
        if(count==MAX){
            printf("Hash Table is full");
            break;
        }
        printf("1-Add More, 0-exit\n:");
        scanf("%1d",&ans);
    }while(ans);
    display(a);
    return 0;
}

int create(int key){
    return key%100;
}

void linear_prob(int a[],int L, int key){
    int flag=0,i;
    if(a[L]==-1){
        a[L]=key;
    }else{
        printf("Collision Detected..!!");
        for(i=L+1;i<MAX;i++){
            if(a[i]==-1){
                a[i]=key;
                flag=1;
                break;
            }
        }
        i=0;
        while((i<L)&&(flag==0)){
            if(a[i]==-1){
                a[i]=key;
                flag=1;
            }
            i++;
        }
    }
}

void display(int a[]){
    int i,choice,ch;
    do{
        printf("1.Display\n2.Filtered Display");
        scanf("%d",&choice);
        printf("The Hash Table: \n");
        if(choice==1){
            for(i=0;i<MAX;i++){
                printf("[%2d].%4d\n",i,a[i]);
            }
        }else{
            for(i=0;i<MAX;i++){
                if(a[i]!=-1){
                    printf("[%2d].%4d\n",i,a[i]);
                }
            }
        }
        printf("1-To read more,0-exit");
        scanf("%1d",&ch);
    }while(ch);
}
