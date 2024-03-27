/* CODE to implement pushing a value up to a stack */

#include "monty.h"

/**
 * push - adds a value to the top of the stack
 * @stack: the stack data structure to push to
 * @val: tha value to push to the stack
 * @line_number: the line number of the instruction in the MBCF
 *
 * Return: nothing
 */

void push(stack_t **stack, char *val, int line_number)
{
	stack_t *new_block = NULL;

	/* Create a new block of memory */
	if (val == NULL || (atoi(val) == 0 && *val != '0'))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_stack_t(stack);
		fclose(file);
		exit(EXIT_FAILURE);
	}
	if (stack != NULL)
	{
		/* Create a new block of memory */
		new_block = (stack_t *)malloc(sizeof(stack_t));
		if (new_block == NULL)
			print_errmsg_mallocfail();
		/* Assign values to the members of the new block */
		new_block->n = atoi(val);
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
