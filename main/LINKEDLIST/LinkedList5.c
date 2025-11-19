// This is to perfrom binary search on the linked list, it not recommeneded tho
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insertAtEnd(int value) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

struct node* findMiddle(struct node* start, struct node* end) {
    if (start == NULL)
        return NULL;

    struct node *slow = start;
    struct node *fast = start;

    while (fast != end && fast->next != end) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

struct node* binarySearchLL(struct node* head, int key) {
    struct node *start = head;
    struct node *end = NULL;

    while (start != end) {
        struct node *mid = findMiddle(start, end);

        if (mid == NULL)
            return NULL;

        if (mid->data == key)
            return mid;

        else if (mid->data < key)
            start = mid->next;

        else
            end = mid;
    }
    return NULL;
}

void display() {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n, value, key;

    printf("Enter number of sorted nodes: ");
    scanf("%d", &n);

    printf("Enter elements in sorted order:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insertAtEnd(value);
    }

    printf("List: ");
    display();

    printf("Enter key to search: ");
    scanf("%d", &key);

    struct node* result = binarySearchLL(head, key);

    if (result)
        printf("Found %d in the list.\n", key);
    else
        printf("Not found.\n");

    return 0;
}
