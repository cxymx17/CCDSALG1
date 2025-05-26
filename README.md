# Expression Evaluator Using Stacks and Queues in C

## Summary: 
The program converts an infix expression to its postfix equivalent using stacks to hold
the operators. It evaluates it using stacks to hold the operands and queues to hold the tokens of
the postfix expression.

### IMPLEMENTATION
#### Infix to Postfix Conversion
The program first asks for an input of the infix expression without spaces. The program
then passes the infix expression as a string to a function named infixToPostfix, which takes in an
infix expression in the form of a string as well as the character pointer that will be used to
contain the resulting postfix expression and is outputted.

#### Postfix Evaluation
The resulting postfix expression from the infixToPostfix function is then passed on to a
function called evaluatePostfix, which takes the postfix expression as a string. The function
passes the string to another function called a tokenizer, which separates the operands and
operators within the expression based on the spaces and tokenizes them. The tokens are then
individually passed on to a queue that will be used to evaluate the expression. The queue is
continuously dequeued until it is empty. The dequeued tokens are classified, depending on
whether they are an operator or an operand. If the dequeued token is an operand, it is pushed
into the stack. On the other hand, if it is an operator, the necessary number of operands are
popped from the stack and evaluated based on the operator that is currently in front of the
queue. The result is continuously pushed back into the stack and repeats dequeuing until the
queue is empty. The final result is obtained by popping the top of the stack.

#### Data Structures
The program used two stacks and one queue. The first stack was used for the infix to
postfix conversion to contain the operators based on precedence. The queue and the second
stack were used for the evaluation of the postfix expression. The queue contained the tokens of
the postfix expression, while the stack served as a buffer stack responsible for containing the
operands based on the precedence of operators.
