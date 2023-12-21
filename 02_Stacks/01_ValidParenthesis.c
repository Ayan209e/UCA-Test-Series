#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 10000

struct Stack {
    int top;
    char items[MAX_SIZE];
};

void initialize(struct Stack *stack) {
    stack->top = -1;
}

void push(struct Stack *stack, char item) {
    if (stack->top == MAX_SIZE - 1) {
        return;
    }
    stack->items[++stack->top] = item;
}

char pop(struct Stack *stack) {
    if (stack->top == -1) {
        return '\0'; 
    }
    return stack->items[stack->top--];
}

bool isMatchingPair(char character1, char character2) {
    return (character1 == '(' && character2 == ')') ||
           (character1 == '{' && character2 == '}') ||
           (character1 == '[' && character2 == ']');
}

bool isValid(char* s) {
    struct Stack stack;
    initialize(&stack);

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            push(&stack, s[i]);
        } 
        else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
            if (stack.top == -1 || !isMatchingPair(pop(&stack), s[i])) {
                return false;
            }
        }
    }

    return stack.top == -1;
}