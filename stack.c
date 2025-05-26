#include "stack.h"
#include <stdio.h>
#include <string.h>

/*  initStack initializes the stack to be empty
    @param stack - the stack to be initialized
*/
void initStack(Stack *stack) {
  stack->top = -1; // empty
}

/*  isEmpty checks if the stack is empty
    @param stack - The stack to check
*/
int isEmpty(Stack *stack) { 
  return stack->top == -1; 
}

/*  isStackFull checks if the stack is full
    @param stack - The stack to check
*/
int isStackFull(Stack *stack) { 
  return stack->top == MAX_STACK_SIZE - 1; 
}

/*  push adds a value to the top of the stack
    @param stack - the stack to push the value onto
    @param value - the value to push onto the stack
*/
void push(Stack *stack, const char *value) {
  if (!isStackFull(stack)) {
    stack->top += 1;
    strcpy(stack->items[stack->top], value);
  }
  // else {
  //     printf("Stack is full!\n");
  // }
}

/*  pop removes and returns the value from the top of the stack
    @param stack - the stack to pop the value from
*/
char *pop(Stack *stack) {
  if (!isEmpty(stack)) {
    return stack->items[stack->top--];
  } else {
    // printf("Stack is empty!\n");
    return NULL;
  }
}

/*  topOfStack returns the value from the top of the stack without removing it
    @param stack - the stack to get the top value from
*/
char *topOfStack(Stack *stack) {
  if (!isEmpty(stack)) {
    return stack->items[stack->top];
  } else {
    // printf("Stack is empty!\n");
    return NULL;
  }
}
