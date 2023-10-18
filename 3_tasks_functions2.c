#include "monty.h"

/**
 * swap - swaps the top two nodes on the stack
 * @stack: a pointer to the head of the stack
 * @line_number: the line number of the opcode
 * Return: none
 */

void swap(stack_t **stack, unsigned int line_number)
{
stack_t *first,  *second, *tmp;

if (!(*stack) || !(*stack)->next)
{
fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
clean_exit();
}
/*getting the address of first 2 nodes*/
first = (*stack);
second = (*stack)->next;
/*getting 3rd address if there*/
tmp = ((*stack)->next->next) ? (*stack)->next->next : NULL;


/*change innside second content to be first*/
second->prev = NULL;
second->next = first;
/*change inside first content to be second*/
first->prev = second;
first->next = tmp;

(*stack) = second;
}

/**
 * add - adds the top two nodes on the stack and replaces them with the sum
 * @stack: a pointer to the head of the stack
 * @line_number: the line number of the opcode
 * Return: none
 */

void add(stack_t **stack, unsigned int line_number)
{

stack_t *second, *tmp;

if (!(*stack) || !(*stack)->next)
{
fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
clean_exit();
}
tmp = (*stack); /* save head address*/
second = (*stack)->next; /*get 2nd node address*/
second->n =  second->n + (*stack)->n;
(*stack) = second;
free(tmp);
}
