#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

void insertSorted(struct Node** head_ref, int data) {
    struct Node* new_node = newNode(data);
    struct Node* current;
    if (*head_ref == NULL || (*head_ref)->data >= new_node->data) {
        new_node->next = *head_ref;
        if (*head_ref != NULL)
            (*head_ref)->prev = new_node;
        *head_ref = new_node;
    } else {
        current = *head_ref;
        while (current->next != NULL && current->next->data < new_node->data) {
            current = current->next;
        }
        new_node->next = current->next;
        if (current->next != NULL)
            current->next->prev = new_node;
        current->next = new_node;
        new_node->prev = current;
    }
}
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
int main() {
    struct Node* head = NULL;
    insertSorted(&head, 3);
    insertSorted(&head, 2);
    insertSorted(&head, 5);
    insertSorted(&head, 8);
    insertSorted(&head, 10);
    insertSorted(&head, 12);

    printf("Sorted Doubly Linked List: ");
    printList(head);

    return 0;
}
