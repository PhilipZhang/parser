/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : stack.c

* Purpose :

* Creation Date : 17-04-2013

* Last Modified : Wed 17 Apr 2013 04:09:16 PM CST

* Created By : Philip Zhang 

_._._._._._._._._._._._._._._._._._._._._.*/

#include "stack.h"
#include "token.h"
#define MAX_TOKEN_COUNT 100


struct token tokens[MAX_TOKEN_COUNT];
int itop = -1;

void push(struct token t)
{
	tokens[++itop] = t;
}

struct token pop()
{
	return tokens[itop--];
}

int top()
{
	return itop;
}
