// Performing dynamic operations
#include <stdio.h>
#include <stdlib.h>

int main(void){
    int *ptr, i, n1, n2;
    printf("Enter the size: ");
    scanf("%d",&n1);
    ptr=(int*)malloc(n1*sizeof(int));
    printf("Addresses of allocated memory: \n");
    for(i=0;i<n1;i++){
        printf("%p ",ptr+i);
    }
    printf("\n");
    printf("Enter the new size: ");
    scanf("%d",&n2);
    ptr = (int*)realloc(ptr, n2);
    printf("Address of many allocated memory: \n");
    for (int i = 0; i < n2; i++){
        printf("%p ",ptr+i);
    }
    printf("\n");
    free(ptr);
    return 0;
}