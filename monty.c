#include "monty.h"

int (int argc, char* argv[])
{
	FILE *file;
	size_t len;
	char *line, *opcode, argument;
	stack_t *stack;

	if (argv != 2)
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
		argument = strtok(NULL, "\n");
	}
	if (opcode && opcode[0] != '#')
	{
		get_opcode(opcode, line_number, &stack, argument);
	}
}
