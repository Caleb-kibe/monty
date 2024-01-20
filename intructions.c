#include "monty.h"

/**
 * get_opcode - fetches the opcode that corresponds to the instruction
 * @opcode: function that performs an instruction
 * @line_number: line containing the opcode
 * @stack: pointer pointing to the top of the stack
 * @argument: the instruction being passed
 */

void get_opcode(char *opcode, unsigned int line_number, stack_t **stack, int argument)
{
	int i = 0;

	instruction_t instructions[] = {
		{"push", push_opcode},
		{"pall", pall_opcode},
		{NULL, NULL}
	};

	if (strcmp(opcode, "push") == 0)
	{
		push(stack, line_number, argument);
		return;
	}

	while (i != '\0')
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			return;
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
