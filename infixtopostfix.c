#include<stdio.h>

int isOperater(char ch);
int precedence(char operater);
int main()
{
	int top =-1, i, j;
	char infix[100], postfix[100], stack[100];
	
	printf("Enter the Expression: ");
	scanf("%s", infix);
	
	for(i=0, j=0; infix[i] != '\0'; i++)
	{
		if(isOperater(infix[i]))
		{	
			if(top == -1)
				stack[++top] = infix[i];
			else if(infix[i] == ')')
			{
				while(top > -1 && stack[top] != '(')
					postfix[j++] = stack[top--];
				
				top--;
			}
			else if(precedence(infix[i]) <= precedence(stack[top]))
			{
				while(top > -1 && precedence(infix[i]) <= precedence(stack[top]))
					postfix[j++] = stack[top--];
				
				stack[++top] = infix[i];
			}
			else 
				stack[++top] = infix[i];
		}
		else
			postfix[j++] = infix[i];
	}
	
	while(top > -1)
		postfix[j++] = stack[top--];
	
	postfix[j] = '\0';	
	printf("%s\n", postfix);
	return 0;
}

int isOperater(char ch)
{
	return ch == '+' || ch == '-' || ch == '/' || ch == '*' || ch == '^' || ch == '(' || ch == ')';
}

int precedence(char operater)
{
	switch(operater)
	{
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
		case '^':
			return 3;
		default:
			return -1;
	}
}
