/* CODE to implement pushing a value up to a stack */

#include "monty.h"

/**
 * push - adds a value to the top of the stack
 * @stack: the stack data structure to push to
 * @line_number: the line number of the instruction in the MBCF
 * Return: nothing
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_block = NULL;
	char *val;
	int n;

	if (stack != NULL)
	{
		/* Attempt to get the value */
		val = strtok(NULL, " ");
		if (val == NULL || (atoi(val) == 0 && (*val != '0' && *val != '-')))
			print_errmsg_pushfail(stack, line_number);

		/* If value was gotten, create a new block of memory */
		new_block = (stack_t *)malloc(sizeof(stack_t));
		if (new_block == NULL)
			print_errmsg_mallocfail();

		/* Assign values to the members of the new block */
		n = atoi(val);
		new_block->n = n;
		new_block->prev = NULL;
		new_block->next = NULL;

		/* For a non-empty stack */
		if (*stack != NULL)
		{
			new_block->next = *stack;
			(*stack)->prev = new_block;
		}
		/* Move stack to the top */
		*stack = new_block;
	}
}
