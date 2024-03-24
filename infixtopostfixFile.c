#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 30
struct stack
{
char items[MAX_SIZE];
int top;
};
void initialize(struct stack *);
int isFull(struct stack *);
int isEmpty(struct stack *);
void push(struct stack *, char);
char pop(struct stack *);
char peek(struct stack *);
int isOperand(char);
int isOperator(char);
int getPrecedence(char);
void infixToPostfix(char [], char []);
int main()
{
FILE *fptr=fopen("text.txt","w");
fputs("+*ab*cd",fptr);
fclose(fptr);
char infix[30];
char postfix[30];
fptr=fopen("text.txt","r");
fgets(infix, MAX_SIZE, fptr);
fclose(fptr);
infixToPostfix(infix, postfix);
fptr=fopen("text.txt","w");
fputs("The infix Expression is: ",fptr);
fprintf(fptr,"%s",infix);
fputs("\nThe postfix expression is: ",fptr);
fprintf(fptr,"%s",postfix);
fclose(fptr);
return 0;
}
void initialize(struct stack *s)
{
s->top = -1;
}
int isFull(struct stack *s)
{
return s->top == MAX_SIZE - 1;
}
int isEmpty(struct stack *s)
{
return s->top == -1;
}
void push(struct stack *s, char c)
{
if (isFull(s))
{
printf("Stack Overflow\n");
return;
}
s->items[++s->top] = c;
}
char pop(struct stack *s)
{
if (isEmpty(s))
{
printf("Stack Underflow\n");
return '\0';
}
return s->items[s->top--];
}
char peek(struct stack *s)
{
if (isEmpty(s))
{
printf("Stack is empty\n");
return '\0';
}
return s->items[s->top];
}
int isOperand(char c)
{
return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}
int isOperator(char c)
{
return c == '+' || c == '-' || c == '*' || c == '/';
}
int getPrecedence(char c)
{
switch (c) {
case '+':
case '-':
return 1;
case '*':
case '/':
return 2;
}
return -1;
}
void infixToPostfix(char infix[], char postfix[])
{
struct stack s;
initialize(&s);
int i, j = 0;
for (i = 0; infix[i]; i++)
{
char c = infix[i];
if (isOperand(c))
{
postfix[j++] = c;
}
else if (c == '(')
{
push(&s, c);
}
else if (c == ')')
{
while (!isEmpty(&s) && peek(&s) != '(')
{
postfix[j++] = pop(&s);
}
if (!isEmpty(&s) && peek(&s) != '(')
{
printf("Invalid expression\n");
return;
}
else
{
pop(&s);
}
}
else if (isOperator(c))
{
while (!isEmpty(&s) && getPrecedence(c) <= getPrecedence(peek(&s)))
{
postfix[j++] = pop(&s);
}
push(&s, c);
}
}
while (!isEmpty(&s))
{
postfix[j++] = pop(&s);
}
postfix[j] = '\0';
}
