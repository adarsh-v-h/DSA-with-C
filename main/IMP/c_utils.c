#include <stdio.h>
#include <stdlib.h>
#include "c_utils.h"
#include <stddef.h>
#define ERROR_CODE NULL

struct node{
    int data;
    struct node *next;
};

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

void *parent_node(void *head, void *target){
    if(head == NULL || target == NULL){
        fprintf(stderr,"Either head or target is NULL");
        return NULL;
    }
    if(head == target){
        fprintf(stderr, "both target and head at same location\n Cannot find parent for the first node");
        return ERROR_CODE;
    }
    struct node *current = head;

    while(current !=NULL && current->next !=head){
        if(current->next==target){
            return current;
        }
        current = current->next;
    }

    fprintf(stderr, "Target Node not found");
    return ERROR_CODE;
}

void *parent_pos(void *head, int pos){
    if(pos<=1 || head==NULL){
        fprintf(stderr,"Invalid values");
        return ERROR_CODE;
    }
    struct node *current = head;
    int count = 1;

    while(current !=NULL && count<pos-1){
        current = current->next;
        if(current==head){
            return ERROR_CODE;
        }
        count ++;
    }

    if(current ==NULL){
        return ERROR_CODE;
    }

    return current;
    
}