/*
* Implementing Polynomial using Linked List.
* Performing Polynomial addition.
* Printing the Resultant Polynomial
* To complie it run: make dan
* To execute run: ./dan for Linux
* or just: dan for windows
* You can customize it in Makefile
*/

#include <stdio.h>
#include "c_utils.h"
#include <stdlib.h>

typedef struct node{
    int exp, data;
    struct node *next;
}Node;
Node *poly1 = NULL, *poly2 = NULL, *poly = NULL;

Node *create(int degree);
void polyAdd(void);
void Result(void);

int main(void){
    int degree;
    printf("\tCreating Polynomials\t\n");
    printf("Enter the highest degree of Polynomial 1: ");
    getInt(&degree);
    printf("Enter the data for polynomial 1: \n");
    poly1 = create(degree);
    printf("Enter the highest degree of Polynomial 2: ");
    getInt(&degree);
    printf("Enter the data for polynomial 2: \n");
    poly2 = create(degree);
    printf("Performing matrix addtion: \n");
    polyAdd();
    printf("Printing the resultant polynomial: \n");
    Result();

    Node *t;
    while (poly1) { t = poly1; poly1 = poly1->next; free(t); }
    while (poly2) { t = poly2; poly2 = poly2->next; free(t); }
    while (poly)  { t = poly;  poly  = poly->next;  free(t); }
    return 0;
}

Node *create(int degree){
    int data;
    Node *head = NULL, *ptr = NULL;
    while(degree >= 0){
        printf("Enter the coefficient of x^%d: ", degree);
        getInt(&data);

        if(data != 0){
            Node *new = (Node *)safeAllo(sizeof(Node));
            new->data = data;
            new->exp = degree;
            new->next = NULL;

            if(head == NULL){
                head = new;
                ptr = new;
            } else {
                ptr->next = new;
                ptr = new;
            }
        }
        degree--;
    }
    return head;
}

void polyAdd(void){
    Node *p1 = poly1;
    Node *p2 = poly2;
    Node *res_head = NULL;
    Node *res_tail = NULL;

    while (p1 != NULL || p2 != NULL) {
        int exp;
        int coef;

        if (p1 != NULL && (p2 == NULL || p1->exp > p2->exp)) {
            exp = p1->exp;
            coef = p1->data;
            p1 = p1->next;
        } else if (p2 != NULL && (p1 == NULL || p2->exp > p1->exp)) {
            exp = p2->exp;
            coef = p2->data;
            p2 = p2->next;
        } else {
            // both non-NULL and exponents equal
            exp = p1->exp;
            coef = p1->data + p2->data;
            p1 = p1->next;
            p2 = p2->next;
        }

        if (coef == 0) continue; // skip zero coefficient

        Node *new = (Node *) safeAllo(sizeof(Node));
        new->exp = exp;
        new->data = coef;
        new->next = NULL;

        if (res_head == NULL) {
            res_head = res_tail = new;
        } else {
            res_tail->next = new;
            res_tail = new;
        }
    }

    poly = res_head;
}

void Result(){
    Node *ptr;
    ptr = poly;
    while(ptr->next!=NULL){
        printf("%dx^%d+ ", ptr->data, ptr->exp);
        ptr = ptr->next;
    }
        printf("%dx^%d", ptr->data, ptr->exp);
}