// Linear Search on an array
#include <stdio.h>

int main(void){
    int n,i,ele,a[10];
    printf("Enter the number of element: ");
    scanf("%d",&n);
    printf("Enter the elements: \n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter elements to be search: \n");
    scanf("%d",&ele);
    for(i=0;i<n;i++){
        if(a[i]==ele){
            printf("Elementa found at %d",i);
            return 0;
        }
    }
    printf("Element not found \n");
    return 0;
}