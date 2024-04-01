#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE

/* Include header files */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>

/* Data structures for stack and queue implementation */

/* 1. */
/* DOUBLY-LINKED LIST FOR STACK OR QUEUE*/

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/* 2. */
/* INSTRUCTION DATA TYPE FOR OPERATIONS ON THE STACK OR QUEUE */

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode; /* push pop dequeue enqueue */
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Global declaration of file pointer */
extern FILE *file;
/* Global declaration of data structure type */
extern int FIFO;

/* Interprete the instruction line */
int lineInterpreter(stack_t **stack, char *line, int line_number);
void (*get_func(char *opcode))(stack_t **, unsigned int);

/* Handle instruction line with no arguments */
int is_newline(char *inst_line);
int is_spaces(char *inst_line);
int is_empty(char *inst_line);

/* Handle nop opcode and comment */
int is_nop(char *inst_line);
int is_comment(char *inst_line);
int is_nocommand(char *inst_line);

/* Functions to handle printing error messages */
void print_errmsg_argfail(void);
void print_errmsg_openfail(char *argv[]);
void print_errmsg_instfail(char *opcode, int line_n);
void print_errmsg_mallocfail(void);

void print_errmsg_pushfail(stack_t **stack, int line_number);
void print_errmsg_opcodefail(stack_t **stack, int line_number, char *opcode);


/* Handle instruction line with arguments */
char *get_opcode(char *inst_line);

/* Fuction prototype for adding elements to the DLL structure */
void push(stack_t **stack, unsigned int line_number);
/* Custom str to int converter */
int stoi(char *str);
/* Sub-function to handle push operations */ 
void push_to_stack(stack_t **new_block, stack_t **stack);
/* Sub-fucntion to handle enqueue operations */
void enqueue(stack_t **new_block, stack_t **stack);

/* Print the Stack */
void pall(stack_t **stack, unsigned int line_number);
void pall_back(stack_t **stack, unsigned int line_number);

/* Print the top of the stack */
void pint(stack_t **stack, unsigned int line_number);

/* Remove the top of the stack */
void pop(stack_t **stack, unsigned int line_number);

/* Swap the top two elements of a stack */
void swap(stack_t **stack, unsigned int line_number);

/* Add the top two elements of a stack */
void add(stack_t **stack, unsigned int line_number);

/* Subtract the top two elements of a stack */
void sub(stack_t **stack, unsigned int line_number);

/* Divide the top two elements of a stack */
void _div(stack_t **stack, unsigned int line_number);

/* Multiply the top two elements of a stack */
void mul(stack_t **stack, unsigned int line_number);

/* Find the modulus of the two top elements of the stack */
void mod(stack_t **stack, unsigned int line_number);

/* Print the ASCII value of top of the stack */
void pchar(stack_t **stack, unsigned int line_number);

/* Print the ASCII value of each value of the stack until 0 or end of stack */
void pstr(stack_t **stack, unsigned int line_number);

/* Rotate the top element of the stack to the bottom */
void rotl(stack_t **stack, unsigned int line_number);

/* Rotate the bottom element of the stack to the top */
void rotr(stack_t **stack, unsigned int line_number);


/* For stack data structure */
void set_stack(stack_t **stack, unsigned int line_number);
void set_queue(stack_t **stack, unsigned int line_number);

/* Clean up stack */
void free_stack_t(stack_t **stack);
#endif
