/** CODE to create an interpreter for monty bytecode */

#include "monty.h"

FILE *file;
char *line;

/**
 * main - the entry point to the interpreter
 * @ac: the number of arguments passed to main
 * @argv: array of arguments passed to main
 *
 * Return: nothing
 */
int main(int ac, char *argv[])
{

	/*char line[4000];*/
	/*char *line = NULL;*/
	size_t n = 0;
	int line_number = 1;
	stack_t *stack = NULL;

	/* Check the number of arguments passed to main */
	if (ac != 2)
		print_errmsg_argfail();

	/* Open the file for reading */
	file = fopen(argv[1], "r");
	if (file == NULL)
		print_errmsg_openfail(argv);

	/* Get instruction line by line */
	/*while (fgets(line, sizeof(line), file) != NULL)*/
	line = NULL;
	while (getline(&line, &n, file) != -1)
	{
		lineInterpreter(&stack, line, line_number);
		++line_number;
	}
	fclose(file);
	free_stack_t(&stack);
	free(line);
	exit(EXIT_SUCCESS);
}
