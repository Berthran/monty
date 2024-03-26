/* CODE to handle printing of error messages */

#include "monty.h"

/**
 * print_error_argfail - prints an error message for wrong arguments
 *
 * Return: nothing
 */

void print_errmsg_argfail(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * print_errmsg_openfail - prints an error message for a failed open operation
 * @argv: list of arguments passed to main
 *
 * Return: nothing
 */
void print_errmsg_openfail(char *argv[])
{
	fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
	exit(EXIT_FAILURE);
}

/**
 * print_errmsg_instfail - prints an error message for an invalid instruction
 * @opcode: the invalid opcode 
 * @line_n: line number of the invalid instruction
 *
 * Return: nothing
 */
void print_errmsg_instfail(char *opcode, int line_n)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", line_n, opcode
);
	exit(EXIT_FAILURE);
}

/**
 * print_errmsg_mallocfail - prints an error message for a malloc  fail
 *
 * Return: nothing
 */
void print_errmsg_mallocfail(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}
