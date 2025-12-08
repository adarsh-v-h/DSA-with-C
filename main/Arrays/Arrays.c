// inserting at a position
#include <stdio.h>
int main(void){
    int n, i, pos, a[10], ele;
    printf("Enter the number of elements in an array: ");
    scanf("%d",&n);
    printf("Enter array elements: \n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter the element to be inserted: ");
    scanf("%d",&ele);
    printf("Enter the position: ");
    scanf("%d",&pos);
    for(i=n-1;i>=pos;i--){
        a[i+1] = a[i];
    }
    a[pos] = ele;
    n++;
    printf("New array is: ");
    for(i=0;i<n;i++){
        printf("%d ", a[i]);
    }
    return 0;
}
