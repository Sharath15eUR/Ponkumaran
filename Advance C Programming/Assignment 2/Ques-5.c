#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Stack {
    int top;
    unsigned capacity;
    char* array;
};

struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, char item) {
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

char pop(struct Stack* stack) {
    if (isEmpty(stack))
        return '\0';
    return stack->array[stack->top--];
}

void reverseString(char* string) {
    int length = strlen(string);
    struct Stack* stack = createStack(length);
    for (int i = 0; i < length; i++)
        push(stack, string[i]);
    for (int i = 0; i < length; i++)
        string[i] = pop(stack);
}

int main() {
    char string[] = "LetsLearn";
    printf("Original string: %s\n", string);
    reverseString(string);
    printf("Reversed string: %s\n", string);
    return 0;
}
