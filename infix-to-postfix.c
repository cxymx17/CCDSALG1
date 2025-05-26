#include "stack.c"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

/*    precedence returns the precedence of the operator
      @param op - operator as a string
      @returns the precedence value of the operator
*/
int precedence(const char* op) {
    int result = 9;
  if(strcmp(op, "^")==0){
    result = 1;
  }else if(strcmp(op, "!")==0){
    result = 2;
  }else if(strcmp(op, "*")==0 || strcmp(op, "/")==0 || strcmp(op, "%")==0){
    result = 3;
  }else if(strcmp(op, "+")==0 || strcmp(op, "-")==0){
    result = 4;
  }else if(strcmp(op, ">")==0 || strcmp(op, "<")==0 || strcmp(op, "<=")==0 || strcmp(op, ">=")==0){
    result = 5;
  }else if(strcmp(op, "==")==0 || strcmp(op, "!=")==0){
    result = 6;
  }else if(strcmp(op, "&&")==0){
    result = 7;
  }else if(strcmp(op, "||")==0){
    result = 8;
  }

  return result;
}

/*    infixToPostfix converts the infix expression to postfix expression
      @param infix - infix expression as a string
      @param postfix - postfix expression as a string
*/

void infixToPostfix(char *infix, char *postfix) {
    Stack operatorStack;
    initStack(&operatorStack);

    int i = 0, j = 0, k = 0;
    char ch;
    String Operator = "", temp;

    while (infix[i] != '\0') {

        ch = infix[i];

        if (!isdigit(ch)){ // if operator copy to string
            k = 0;
            if(ch == ')' || ch == '(' || (ch == '!' && infix[i+1] != '=') || (infix[i+1] == '!')){
                Operator[k++] = infix[i++];
            }else{
                while (!isdigit(infix[i]) && infix[i] != '(') {
                    Operator[k++] = infix[i++];
                }
            }

            Operator[k] = '\0';
        }

        if (isdigit(ch)) { // If the current character is a number
            while (isdigit(infix[i])) {
                postfix[j++] = infix[i++];
            }
            postfix[j++] = ' ';
            postfix[j] = '\0';

        } else if (strcmp(Operator,"(") == 0) { // If token is (
            push(&operatorStack, Operator);

        } else if (strcmp(Operator,")") == 0) { // If token is )

            while (!isEmpty(&operatorStack) && strcmp(topOfStack(&operatorStack),"(") != 0) { 
                strcpy(temp, pop(&operatorStack));
                strcat(postfix, temp);
                j += strlen(temp);
                postfix[j++] = ' ';
                postfix[j] = '\0';
            }
            
            
            pop(&operatorStack); // Remove '(' from stack

        } else if (isEmpty(&operatorStack)){ // if stack empty
            push(&operatorStack, Operator);

        } else if ((strcmp(Operator,"^") == 0 && strcmp(topOfStack(&operatorStack),"^") == 0)||
                   (strcmp(Operator,"!") == 0 && strcmp(topOfStack(&operatorStack),"!") == 0)){
            push(&operatorStack, Operator);

        } else {
            while (!isEmpty(&operatorStack) && precedence(topOfStack(&operatorStack)) <= precedence(Operator)) { // pop if based on precedence	
                strcpy(temp, pop(&operatorStack));
                strcat(postfix, temp);
                j += strlen(temp);
                postfix[j++] = ' ';
                postfix[j] = '\0';
            }

                push(&operatorStack, Operator);
        }

    }

    while (!isEmpty(&operatorStack)) { // if finished scanning the infix
        strcpy(temp, pop(&operatorStack));
        strcat(postfix, temp);
        
        j += strlen(temp);
        postfix[j++] = ' ';
        postfix[j] = '\0';
    }

    postfix[j - 1] = '\0'; 
}
