#include <stdio.h>
#include <stdlib.h>
#include "c_utils.h"

void getInt(int *data) {
    int check;
    int c; // For character buffer clearing

    do {
        check = scanf("%d", data); 
        if (check != 1) {
            printf("Invalid input! Please enter a whole number: ");
        }
        while ((c = getchar()) != '\n' && c != EOF);

    } while (check != 1); // Loop repeats only if the check failed.
}

void *safeAllo(int size){
    void *ptr = malloc(size);
    if(ptr==NULL){
        fprintf(stderr,"FATAL ERROR: malloc failed to allocate memory\nProbably OS ran out of ram storage");
        exit(EXIT_FAILURE);
    }
    return ptr;
}