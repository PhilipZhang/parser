/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : stack.h

* Purpose :

* Creation Date : 17-04-2013

* Last Modified : Wed 17 Apr 2013 03:59:01 PM CST

* Created By : Philip Zhang 

_._._._._._._._._._._._._._._._._._._._._.*/

#ifndef STACK_H_
#define STACK_H_

struct token;

int top();
void push(struct token t);
struct token pop();

#endif
