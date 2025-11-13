// This is a code, which takes input of a polynomial, and performs polynomial addition 
#include <stdio.h>
#include <stdlib.h>
#define MAX_TERMS 100

typedef struct {
    float Coef;
    int expo;
}polynomial;
polynomial terms[MAX_TERMS];
int avail=0;
void padd(int,int,int,int,int*,int*);
void attach(float,int);
int compare(int, int);
void display(int, int);

int main(){
    int StartA=0, FinishA, StartB, FinishB, x,y, degree1, degree2, StartD=0, FinishD=0;
    int cf,i;
    printf("Enter the degree of the Polynomial A: ");
    scanf("%d",&degree1);
    printf("---------------------------------------------------------------------\n");
    printf("Enter the degree of the Polynomial B: ");
    scanf("%d",&degree2);
    for(i = degree1;i>=0;i--){
        printf("Enter coefficient for %d of polynomial A:", i);
        scanf("%d", &cf);
        if(cf!=0){
            terms[avail].Coef = cf;
            terms[avail].expo = i;
            avail++;   
        }
    }
    printf("--------------------------------------------------------------------\n");
    FinishA = avail-1;
    StartB = avail;
    for(i = degree2;i>=0;i--){
        printf("Enter coefficient for %d of polynomial B:", i);
        scanf("%d", &cf);
        if(cf!=0){
            terms[avail].Coef = cf;
            terms[avail].expo = i;
            avail++;   
        }
    }
    FinishB = avail -1;
    padd(StartA, FinishA ,StartB, FinishB, &StartD, &FinishD);
    printf("--------------------------------------------------------------------------------\n");
    display(StartD, FinishD);
    return 0;
}

void padd(int StartA, int FinishA ,int StartB, int FinishB, int *StartD,int *FinishD){
    float cf;
    *StartD = avail;
    while((StartA<=FinishA) && (StartB<=FinishB)){
        switch (compare(terms[StartA].expo, terms[StartB].expo)){
            case -1:{ // A Expo < B expo
                attach(terms[StartB].Coef, terms[StartB].expo);
                StartB++;
                break;
            }
            case 1:{ // A expo > B expo
                attach(terms[StartA].Coef, terms[StartA].expo);
                StartA++;
                break;
            }
            case 0:{ // A exp == B exp
                cf= terms[StartA].Coef + terms[StartB].Coef;
                attach(cf, terms[StartA].expo);
                StartB++;
                StartA++;
                break;
            }
            default:
                break;
        }
    }
    // now even after all this there will be some stuff left on either Equation, they are gonna be takenn care by the following statements
    for(; StartA<=FinishA;StartA++){
        attach(terms[StartA].Coef,terms[StartA].expo);
    }
    for(; StartB<=FinishB; StartB++){
        attach(terms[StartB].Coef, terms[StartB].expo);
    }
    *FinishD = avail -1;
}

void attach(float cf, int exp){
    if(avail >= MAX_TERMS){
        printf("Too many terms in the polynomial\n");
        exit(1);
    }
    terms[avail].Coef = cf;
    terms[avail].expo = exp;
    avail++;
}

int compare(int x, int y){
    if(x<y){
        return -1;
    }else if (x>y){
        return 1;
    }
    return 0;
}

void display(int StartD, int FinishD){
    int i;
    printf("\nResult polynomial terms (coef expo):\n");
    if (StartD <= FinishD) {
        for (i = StartD; i < FinishD; ++i) {
            printf("%.1fx^%d + ", terms[i].Coef, terms[i].expo);
        }
        printf("%.1fx^%d", terms[i].Coef, terms[i].expo);
    } else {
        printf("No terms (zero polynomial)\n");
    }
}