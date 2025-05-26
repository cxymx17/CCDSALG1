#include <math.h>
#include <stdio.h>
#include <string.h>

#include "infix-to-postfix.c"
#include "evaluate-postfix.c"

int main() {
  char infix[256];
  char postfix[256];
  int continueProgram = 1;
  int result;

  while (continueProgram) {
    printf("\n");
    scanf("%s", infix);

    if (strcmp(infix, "QUIT") == 0) {
      continueProgram = 0;
    } else {
      infixToPostfix(infix, postfix);
      printf("%s\n", postfix);
      result = atoi(evaluatePostfix(postfix));
      if(result != -9999999)
        printf("%d\n", result);
    }
  }

  return 0;
}