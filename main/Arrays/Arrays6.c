#include <stdio.h>
#include <stdlib.h>

int **make2dArray(int, int);
int main(void){
    int **myarray;
    int rows, columns;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &columns);
    myarray = make2dArray(rows, columns);
    printf("Enter the elements: \n");
    for(int i =0;i<rows;i++){
        for(int j = 0;j<columns;j++){
            scanf("%d",&myarray[i][j]);
        }
    }
    printf("The 2D array elements are: \n");
    for(int i =0;i<rows;i++){
        for(int j = 0;j<columns;j++){
            printf("%d ",myarray[i][j]);
        }
        printf("\n");
    }
    return 0;
}

int **make2dArray(int rows, int columns){
    int **x, i;
    x = malloc(sizeof(*x)*rows);
    for(i=0;i<rows;i++){
        x[i] = malloc(columns*sizeof(**x));
    }
    return x;
}