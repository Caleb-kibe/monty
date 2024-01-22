#include "monty.h"

/**
 * main - main function
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 (success)
 */
int main(int argc, char *argv[])
{
	FILE *file;
	size_t len = 0;
	unsigned int line_number = 0;
	char *line = NULL;
	char *opcode, *argument;
	stack_t *stack;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &len, file))
	{
		line_number++;
		opcode = strtok(line, "\n");
		if (opcode != NULL)
		{
			argument = strtok(NULL, "\n");
			get_opcode(opcode, line_number, &stack, argument);
		}
	}
	free(line);
	fclose(file);
	free_stack(stack);

	return (0);
}
