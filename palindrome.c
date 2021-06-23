#include<stdio.h>
#include<string.h>
#define MAX 30

/* this is to check whether a given expression is a palindrome or not */

char stk[MAX],arr[MAX];
int top=-1;
char push(char);
void pop(char);

int main()
{
	int i;
	char exp[MAX];
	printf(" Enter the expression : ");
	gets(exp);
	for ( i=0; i<strlen(exp); i++ )
	{
		push(exp[i]);
	}
	for ( i=0; i<strlen(exp); i++ )
	{
		arr[i] = stk[top];
		pop(stk[top]);
	}
	if ( strcmp(exp,arr)==0)
	{
		printf(" Entered expression is a palindrome ");
	}
	else
		printf(" Entered expression is not a palindrome ");
	
	return 0;
}

char push(char c)
{
	if ( top == MAX-1 )
	{
		printf(" Stack OVERFLOW ");
	}
	else
	{
		top++;
		stk[top]=c;
	}
}

void pop(char c)
{
	if ( top == -1 )
	{
		printf(" Stack UNDERFLOW ");
	}
	else
	{
		top--;
	}
}

