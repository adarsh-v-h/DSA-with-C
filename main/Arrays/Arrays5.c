// Calulating the sum of n numbers, dynmaically allocated
#include <stdio.h>
#include <stdlib.h>

int main(void){
    int *ptr, n, i, sum =0;
    printf("Enter number of elements to be added: ");
    scanf("%d",&n);
    ptr = (int*)malloc(n*sizeof(int));

    if(ptr==NULL){
        printf("Memory not allocated \n");
        exit(EXIT_FAILURE);
    }

    printf("Enter the elements: \n");
    for(i=0;i<n;i++){
        scanf("%d", ptr+i);
        sum += *(ptr+i);
    }
    printf("Sum: %d", sum);
    return 0;
}