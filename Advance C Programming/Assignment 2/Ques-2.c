#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node** head, char data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}
void rotateByN(struct Node** head, int N) {
    if (N == 0)
        return;

    struct Node* current = *head;
    int count = 1;
    while (count < N && current != NULL) {
        current = current->next;
        count++;
    }
    if (current == NULL)
        return;

    struct Node* NthNode = current;

    while (current->next != NULL)
        current = current->next;

    current->next = *head;
    (*head)->prev = current;

    *head = NthNode->next;
    (*head)->prev = NULL;

    NthNode->next = NULL;
}
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%c ", node->data);
        node = node->next;
    }
    printf("\n");
}
int main() {
    struct Node* head = NULL;
    insertEnd(&head, 'a');
    insertEnd(&head, 'b');
    insertEnd(&head, 'c');
    insertEnd(&head, 'd');
    insertEnd(&head, 'e');
    int N = 2; 
    printf("Input: ");
    printList(head);
    rotateByN(&head, N);
    printf("Output: ");
    printList(head);
    return 0;
}
