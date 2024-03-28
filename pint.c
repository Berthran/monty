/** CODE to implement printing the value at top of the stack */

#include "monty.h"

/**
 * pint - prints the element at the top of the stack
 * @stack: the stack data structure to print
 * @line_number: the line number of the instruction in the MBCF
 *
 * Return: nothing
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_stack_t(stack);
		fclose(file);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
	printf("fail pint\n");
}
