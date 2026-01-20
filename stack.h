#ifndef STACK_H
#define STACK_H

#define MAX 100

typedef struct {
    char action[10];  
    char text[100];   
    int position;    
} Operation;

typedef struct {
    Operation data[MAX];
    int top;
} Stack;

void initStack(Stack *s);
int isEmpty(Stack *s);
int isFull(Stack *s);
void push(Stack *s, Operation op);
Operation pop(Stack *s);
Operation peek(Stack *s);

#endif
