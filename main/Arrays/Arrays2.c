// Deletion operation
#include <stdio.h>

int main(void){
    int n,i,pos,a[10];
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    printf("Enter the array elements: \n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter the postion: ");
    scanf("%d",&pos);
    for(i=pos;pos<n-1;i++){
        a[i]=a[i+1];
    }
    n--;
    printf("Array after deletion: \n");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}