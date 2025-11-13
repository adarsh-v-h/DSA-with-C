/* We can represnt a matrix easily, but what if that matrix has most of its values as 0, then it is called as Sparse Matrix.
And using the regualar method of matrix represntattion would be wasting a lot of space, since most elements are 0. So we have a different method.*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_TERMS 101

typedef struct{
    int row, col, value;
}terms;
terms a[MAX_TERMS], b[MAX_TERMS];
void transpose();
void display(terms a[]);
int main(){
    int p,q;
    int i,j;
    int n=0,value;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d",&p, &q);
    a[0].row = p;
    a[0].col = q;
    int k =1;
    for(i=0;i<p;i++){
        for(j=0;j<q;j++){
            printf("Enter the value for row = %d and column = %d :",i,j);
            scanf("%d", &value);
            if(value!=0){
                a[k].row = i;
                a[k].col = j;
                a[k].value = value;
                n++;
                k++;
            }
        }
    }
    a[0].value = n;
    printf("Before transpose : \n");
    display(a);
    transpose();
    printf("-------------------------------------------------------------------------------------------\n");
    printf("After Transpose: \n");
    display(b);
    return 0;
}

void display(terms a[]){
    int n = a[0].value;
    printf("Row\tColumn\tValue\n");
    for(int i = 1; i<=n;i++){
        printf("%d\t%d\t%d\n", a[i].row, a[i].col, a[i].value);
    }
}

void transpose(){
    int i,j,n,Currentb=1;
    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].value = a[0].value;
    n = a[0].value;
    if(n>0){
        for(i=0;i<a[0].col;i++){
            for(j=1;j<=n;j++){
                if(a[j].col == i){
                    b[Currentb].row = a[j].col;
                    b[Currentb].col = a[j].row;
                    b[Currentb].value = a[j].value;
                    Currentb++;
                }
            }
        }
    }
}