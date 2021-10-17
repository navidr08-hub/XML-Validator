#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

static int top = 0;
static char * stack[100];

char * pop()
{
	if(top == 0){
		fprintf(stderr, "Stack is empty. (Underflow error)");
		return ((char *) 0);  
	}
	else{
		fprintf(stdout, "top = %d\tpop = %s\n", top-1, stack[top-1]);
		int i;
		for (i = 0; i < 2; i++){
			fprintf(stdout, "%s\n", stack[i]);
		}
		char * x = stack[--top];
		return x;	
	}
}

void push(char * thing2push)
{
	if(top >= 100){
		fprintf(stderr, "Stack is full. (Overflow error)");
	}
	else{
		stack[top] = thing2push;
		fprintf(stdout, "top = %d\tpush = %s\n", top, stack[top]);
		top++;	
	}
}

int isEmpty()
{
	if(top == 0){
		return 1;
	}
	return 0;
}
