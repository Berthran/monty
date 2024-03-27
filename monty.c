/** CODE to create an interpreter for monty bytecode */

#include "monty.h"

/**
 * main - the entry point to the interpreter
 * @ac: the number of arguments passed to main
 * @argv: array of arguments passed to main
 *
 * Return: nothing
 */
int main(int ac, char *argv[])
{
	char line[2048];
	FILE *file;
	int line_number = 1;
	stack_t *stack = NULL;
	/*char *opcode;*/

	/* Check the number of arguments passed to main */
	if (ac != 2)
		print_errmsg_argfail();

	/* Open the file for reading */
	file = fopen(argv[1], "r");
	if (file == NULL)
		print_errmsg_openfail(argv);

	/* Get instruction line by line */
	while (fgets(line, sizeof(line), file) != NULL)
	{
		if (lineInterpreter(&stack, line, line_number) != 0)
		{
			fclose(file);
			exit(EXIT_FAILURE);
		}
		++line_number;
	}
	fclose(file);
	exit(EXIT_SUCCESS);
}
