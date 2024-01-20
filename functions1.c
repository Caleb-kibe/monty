#include "monty.h"

/**
 *push_opcode - pushes an element to the stack
 *@stack: pointer to the top the stack
 *@line_number: where the instruction appears
 */

void push_opcode(stack_t **stack, unsigned int line_number)
{

        stack_t *newnode, *temp;
        stack_t *top = *stack;
        unsigned int data;

	newnode = (stack_t *)malloc(sizeof(stack_t));
        if (newnode == NULL)
	{
		fprintf(stderr,"Error: malloc failed\n");
                exit(EXIT_FAILURE);
	}

        newnode->prev = 0;
        newnode->next = 0;
        newnode->n = data;

        if (top == 0)
        {
                top = newnode;
                temp = newnode;
        }
        else
        {
                temp->next = newnode;
                newnode->prev = temp;
                temp = newnode;
        }
	*stack = top;
        
}
