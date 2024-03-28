/** CODE to implement swapping the two values at the rop of the stack */

#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: the stack data structure to print
 * @line_number: the line number of the instruction in the MBCF
 *
 * Return: nothing
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *top1, *top2;
	int temp_n;

	if (*stack != NULL)
	{
		top1 = *stack;
		top2 = (*stack)->next;
	}
	if (top2 != NULL)
	{
		temp_n =  top1->n;
		top1->n = top2->n;
		top2->n = temp_n;
	}
	if (top2 == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't swaps, stack too short\n", line_number);
		free_stack_t(stack);
		fclose(file);
		exit(EXIT_FAILURE);
	}
	printf("div fails\n");
}
