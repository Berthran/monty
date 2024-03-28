/* CODE to handle printing of error messages for opcodes*/

#include "monty.h"

/**
 * print_errmsg_pushfail - prints an error message for failed push
 * @stack: the stack data structure
 * @line_number: the line number of the instruction
 *
 * Return: nothing
 */

void print_errmsg_pushfail(stack_t **stack, int line_number)
{
	fprintf(stderr, "L%d: usage: push integer\n", line_number);
	free_stack_t(stack);
	fclose(file);
	exit(EXIT_FAILURE);
}

/**
 * print_errmsg_opcodefail - prints an error message for failed push
 * @stack: the stack data structure
 * @line_number: the line number of the instruction
 * @opcode: the invalid instruction code
 *
 * Return: nothing
 */

void print_errmsg_opcodefail(stack_t **stack, int line_number, char *opcode)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	printf("force fail\n");
	free_stack_t(stack);
	fclose(file);
	exit(EXIT_FAILURE);
}
