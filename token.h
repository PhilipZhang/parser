/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : token.h

* Purpose :

* Creation Date : 17-04-2013

* Last Modified : Wed 17 Apr 2013 04:10:16 PM CST

* Created By : Philip Zhang 

_._._._._._._._._._._._._._._._._._._._._.*/

#ifndef TOKEN_H_
#define TOKEN_H_

#define MAX_TOKEN_LEN 100

enum token_type
{
	IDENTIFIER,
	QUALIFIER,
	TYPE
};


struct token
{
	char type;
	char str[MAX_TOKEN_LEN];
};

#endif
