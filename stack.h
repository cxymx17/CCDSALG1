#ifndef STACK_H
#define STACK_H

#define MAX_STACK_SIZE 256
typedef char String[51];

typedef struct {
    int top;                    // index of top element
    String items[MAX_STACK_SIZE]; // array of the stack
} Stack;

// Function prototypes
void initStack(Stack *stack);
int isEmpty(Stack *stack);
int isStackFull(Stack *stack);
void push(Stack *stack, const char* value);
char* pop(Stack *stack);
char* topOfStack(Stack *stack);

#endif