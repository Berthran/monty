/** CODE to implement adding the two values at the rop of the stack */

#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: the stack data structure to print
 * @line_number: the line number of the instruction in the MBCF
 *
 * Return: nothing
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *top1, *top2 = NULL;
	int n1, n2;

	if (*stack != NULL)
	{
		top1 = *stack;
		top2 = (*stack)->next;
	}
	if (top2 != NULL)
	{
		n1 = top1->n;
		n2 = top2->n;
		push(stack, n1 + n2);
	}
	if (top2 == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_stack_t(stack);
		fclose(file);
		exit(EXIT_FAILURE);
	}
	printf("div fails\n");
}
