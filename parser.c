
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "parser.h"
#include "token.h"


// local variables
static char types[][20]={		// list of types
						"void",
						"char",
						"short",
						"int",
						"long",
						"float",
						"double"};
struct token curr;

// external functions
void push(struct token t);
struct token pop();
int top();

void parse()
{
	void read_to_first_identifier();
	void deal_with_declarator();
	read_to_first_identifier(); // the previous tokens are pushed into stack
	deal_with_declarator();     // first look forwards to deal with functions and arrays, then deal with the tokens in the stack.
}

/* This function is used to
 * classify the string into
 * qualifier or type specifier*/
enum token_type classify_token()
{
	int i;
	for(i = 0; i < 7; i++)
	{
		if(!strcmp(curr.str, types[i]))
			return TYPE;
	}
	if(!strcmp(curr.str, "const"))
	{
		strcpy(curr.str, "read-only");
		return QUALIFIER;
	}
	if(!strcmp(curr.str, "volatile"))
		return QUALIFIER;
	return IDENTIFIER;
}


char is_digit_alpha(char c)
{
	if((c >= '0' && c <= '9') || (c >= 'a' && c<= 'z') || (c >= 'A' && c <= 'Z'))
		return 1;
	return 0;
}

void get_next_token()
{
	char *p = curr.str;
	while((*p = getchar()) == ' ');
	ungetc(*p, stdin);
	if(is_digit_alpha(*p = getchar()))
	{
		while(is_digit_alpha(*++p = getchar()));
		ungetc(*p, stdin);
		*p = '\0';
		curr.type = classify_token();
		return;
	}
	if(*p == '*')
	{
		strcpy(curr.str, "pointer to");
		curr.type = *p;
		return;
	}
	curr.type = *p;
	curr.str[1] = '\0';
	return;
}

void read_to_first_identifier()
{
	while(1)
	{
		get_next_token();
		if(curr.type == IDENTIFIER)
		{
			printf("%s is ", curr.str);
			get_next_token();
			break;
		}
		push(curr);
	}
}

void deal_with_declarator()
{
	void deal_with_function();
	void deal_with_array();
	void deal_with_stack_tokens();

	while(curr.type == '[' || curr.type == '(')
	{
		switch(curr.type)
		{
		case '(':
			deal_with_function();
			break;
		case '[':
			deal_with_array();
			break;
		}
	}

	deal_with_stack_tokens();
}

void deal_with_function()
{
	get_next_token();
	while(curr.type != ')')
	{
		get_next_token();
	}
	printf("function returning ");
	get_next_token();
}

void deal_with_array()
{
	printf("array [0...");
	get_next_token();
	if(curr.type != ']')
		printf("%d] of ", atoi(curr.str));
	get_next_token();
	get_next_token();
}

void deal_with_stack_tokens()
{
	while(top() >= 0)
	{
		struct token t;
		t = pop();
		if(t.type == '*')
			printf("pointer to ");
		else if(t.type == '(')
		{
			while(curr.type == ')')
			{
				get_next_token();
			}
			deal_with_declarator();
		}
		else
			printf("%s ", t.str);
	}
}
