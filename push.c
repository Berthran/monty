/* CODE to implement pushing a value up to a stack */

#include "monty.h"

/**
 * push - adds a value to the top of the stack
 * @stack: the stack data structure to push to
 * @val: tha value to push to the stack
 *
 * Return: nothing
 */

void push(stack_t **stack, int val)
{
	stack_t *new_block = NULL;

	if (stack != NULL)
	{
		/* Create a new block of memory */
		new_block = (stack_t *)malloc(sizeof(stack_t));
		if (new_block == NULL)
			print_errmsg_mallocfail();
		/* Assign values to the members of the new block */
		new_block->n = val;
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
		printf("fail push\n");
	}
}
