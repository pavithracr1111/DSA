#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
//macro declaration
#define SUCCESS 0
#define FAILURE -1

//structure variable
typedef struct stack
{
	unsigned int capacity;
	int top;
	int *stack;
}Stack_t;

//function prototypes for push(), pop(), create_stack(), peek(), peep() functions
int create_stack(Stack_t *, int );
int Push(Stack_t *, int);
int Pop(Stack_t *);
int Peek(Stack_t *);
void Peep(Stack_t);

#endif