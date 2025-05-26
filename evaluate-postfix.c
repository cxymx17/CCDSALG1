#include "queue.c"
#include "stack.h"
#include <stdlib.h>
#include <string.h>

/*  tokenizer tokenizes the space separated strings in the postFixExpr then enqueues it to the postFixQueue
  @param postFixQueue - Queue that will hold the tokens of the postfix expression
  @param postFixExpr - Space separated string of the postfix expression
*/
void tokenizer(Queue *postFixQueue, char* postFixExpr){
  char token[MAX_QUEUE_SIZE];
  int index = 0;
  int tokenValIndex=0;

  while(index <= strlen(postFixExpr)){
    if (postFixExpr[index] != ' ' && postFixExpr[index] != '\0'){ // responsible for token
      token[tokenValIndex] = postFixExpr[index];
      tokenValIndex++;
    }
    else if(tokenValIndex > 0){
      token[tokenValIndex] = '\0';
      enqueue(postFixQueue, token);

      tokenValIndex=0; // reset the token index
      strcpy(token, ""); // clears the token
    }
    index++; // goes past the space	
  }
}

/*  isOperator checks if the token being considered is an operator
  @param value - token being considered 

  @returns 1 if value is an operator
  @returns 0 if value is not an operator
*/
int isOperator(const char* value) {
    return (strcmp(value, "+") == 0 || strcmp(value, "-") == 0 || strcmp(value, "*") == 0 || strcmp(value, "/") == 0 ||
            strcmp(value, "%") == 0 || strcmp(value, "^") == 0 || strcmp(value, "<") == 0 || strcmp(value, ">") == 0 ||
            strcmp(value, "<=") == 0 || strcmp(value, ">=") == 0 || strcmp(value, "!") == 0 || strcmp(value, "!=") == 0 || 
      strcmp(value, "==") == 0 || strcmp(value, "&&") == 0 || strcmp(value, "||") == 0);
}

/*  evaluatePostfix evaluates the given postfix expression by pushing the integers into a buffer stack, evaluates 
          based on the operator in front of the queue, then pushes the result back into the buffer stack
          until the queue containing the tokens of the postfix expression are empty
  @param postFixExpr - Queue that will hold the tokens of the postfix expression

  @returns a string containing the evaluated postfix expression
  @returns "-9999999" in the case that there was an error that occured due to division by zero
*/
char* evaluatePostfix(char *postFixExpr){
  char *token;
  int operand1;
  int operand2;
  int result;
  char typeCastedResult[8];
  int errorByZero = 0;
  Queue postFixQueue;
  Stack bufferStack;

  initQueue(&postFixQueue);
  initStack(&bufferStack);

  tokenizer(&postFixQueue, postFixExpr);


  while(!isQueueEmpty(&postFixQueue) && !errorByZero){
    token = dequeue(&postFixQueue);
    if(strcmp(token, "!") == 0){
      operand1 = atoi(pop(&bufferStack));
      result = !operand1;
      sprintf(typeCastedResult, "%d", result);
      push(&bufferStack, typeCastedResult);
    }
    else if(!isOperator(token)){ // if dequeued token is an integer
      push(&bufferStack, token);
    }
    else if(isOperator(token)){
      operand2 = atoi(pop(&bufferStack)); //c
      operand1 = atoi(pop(&bufferStack)); //c

      switch(token[0]){
        case '+':
          result = operand1 + operand2;
          break;
        case '-':
          result = operand1 - operand2;
          break;
        case '*':
          result = operand1 * operand2;
          break;
        case '/':
          if(operand1 > 0 && operand2 == 0){
            printf("Division by zero error!\n");
            errorByZero = 1;
          }
          else 
            result = operand1 / operand2;
          break;
        case '%':
          result = operand1 % operand2;
          break;
        case '^':
          result  = 1;
          while(operand2>0){
            result *= operand1;
            operand2--;
          }
          break;
        case '=':
          if(token[1] == '=') result = operand1 == operand2;
          break;
        case '<':
          if(token[1] == '=') result = operand1 <= operand2;
          else result = operand1 < operand2;
          break;
        case '>':
          if(token[1] == '=') result = operand1 >= operand2;
          else result = operand1 > operand2;
          break;
        case '!':
          if(token[1] == '=') result = operand1 != operand2;
          break;
        case '&':
          result = operand1 && operand2;
          break;
        case '|':
          result = operand1 || operand2;
          break;
      }
      sprintf(typeCastedResult, "%d", result);
      push(&bufferStack, typeCastedResult);
    }

  }

  if(!errorByZero) return pop(&bufferStack);
  else return "-9999999";
}
