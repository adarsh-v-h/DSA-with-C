#include <stdio.h>
#include <stdlib.h>
#include "c_utils.h"

void getInt(int *data) {
    int check;
    int c; // For character buffer clearing

    do {
        // 1. Try to read the integer
        // Note: We don't print "Enter integer" here so you can 
        // customize the prompt in main() before calling this.
        check = scanf("%d", data); 

        // 2. If it failed (user typed "abc"), print error
        if (check != 1) {
            printf("Invalid input! Please enter a whole number: ");
        }
        
        // 3. CRITICAL STEP: Clear the input buffer 
        // This eats the "Enter" key or the garbage text ("abc")
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