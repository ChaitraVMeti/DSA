#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 100
struct stack
{
char items[MAX_SIZE];
int top;
};
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
exit(EXIT_FAILURE);
}
s->items[++s->top] = c;
}

char pop(struct stack *s)
{
if (isEmpty(s))
{
printf("Stack Underflow\n");
exit(EXIT_FAILURE);
}
return s->items[s->top--];
}
char peek(struct stack *s)
{
if (isEmpty(s))
{
printf("Stack is empty\n");
exit(EXIT_FAILURE);
}
return s->items[s->top];
}
int isBalanced(char equation[])
{
struct stack s;
initialize(&s);
for (int i = 0; equation[i] != '\0'; i++)
{
if (equation[i] == '(' || equation[i] == '[' || equation[i] == '{')
{
push(&s, equation[i]);
}
else if (equation[i] == ')' || equation[i] == ']' || equation[i] == '}')
{
if (isEmpty(&s))
{
return false;
}
char top = pop(&s);
if ((equation[i] == ')' && top != '(') || (equation[i] == ']' && top != '[') || (equation[i] == '}' && top != '{'))
{
return false;
}
}
}
return isEmpty(&s);
}
int main()
{
FILE *fptr;
fptr = fopen("text.txt", "w");
if (fptr == NULL)
{
printf("File not available.");
exit(EXIT_FAILURE);
}
fputs("Check for Paranthesis\nThe Equation is :", fptr);
fputs("((x+y)z)", fptr);
fclose(fptr);
char equation[MAX_SIZE];
fptr = fopen("text.txt", "r");
if (fptr == NULL)
{
printf("File not available.");
exit(EXIT_FAILURE);
}
fgets(equation, MAX_SIZE, fptr);
fclose(fptr);
fptr=fopen("text.txt","a");
if (isBalanced(equation))
{
fputs("\nThe equation has balanced parentheses.\n",fptr);
}
else
{
fputs("\nThe equation does not have balanced parentheses.\n",fptr);
}
fclose(fptr);
return 0;
}
