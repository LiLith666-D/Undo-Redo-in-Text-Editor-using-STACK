#include <stdio.h>
#include "stack.h"

void initStack(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

void push(Stack *s, Operation op) {
    if (isFull(s)) {
        printf("Stack Overflow!\n");
        return;
    }
    s->data[++(s->top)] = op;
}

Operation pop(Stack *s) {
    Operation empty = {"", "", 0};
    if (isEmpty(s)) {
        printf("Stack Underflow!\n");
        return empty;
    }
    return s->data[(s->top)--];
}

Operation peek(Stack *s) {
    Operation empty = {"", "", 0};
    if (isEmpty(s)) return empty;
    return s->data[s->top];
}
