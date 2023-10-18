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
free_list();
/*free(line);*/
exit(EXIT_FAILURE);
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
free_list();
/*free(line);*/
exit(EXIT_FAILURE);
}
tmp = (*stack); /* save head address*/
second = (*stack)->next; /*get 2nd node address*/
second->n =  second->n + (*stack)->n;
(*stack) = second;
free(tmp);
}

/**
 * sub - subtracts the top two nodes
 * @stack: a pointer to the head of the stack
 * @line_number: the line number of the opcode
 * Return: none
 */

void sub(stack_t **stack, unsigned int line_number)
{

stack_t *second, *tmp;

if (!(*stack) || !(*stack)->next)
{
fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
free_list();
/*free(line);*/
exit(EXIT_FAILURE);
}
tmp = (*stack); /* save head address*/
second = (*stack)->next; /*get 2nd node address*/
second->n = second->n - (*stack)->n;
(*stack) = second;
free(tmp);
}

/**
 * _div - divides the top two nodes
 * @stack: a pointer to the head of the stack
 * @line_number: the line number of the opcode
 * Return: none
 */

void _div(stack_t **stack, unsigned int line_number)
{
stack_t *second, *tmp;

if (!(*stack) || !(*stack)->next)
{
fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
free_list();
/*free(line);*/
exit(EXIT_FAILURE);
}
tmp = (*stack); /* save head address*/
second = (*stack)->next; /*get 2nd node address*/
if ((*stack)->n == 0)
{
fprintf(stderr, "L%d: division by zero\n", line_number);
free_list();
/*free(line);*/
exit(EXIT_FAILURE);
}
second->n = second->n / (*stack)->n;
(*stack) = second;
free(tmp);
}


/**
 * mul - multiplies the top two nodes
 * @stack: a pointer to the head of the stack
 * @line_number: the line number of the opcode
 * Return: none
 */

void mul(stack_t **stack, unsigned int line_number)
{

stack_t *second, *tmp;

if (!(*stack) || !(*stack)->next)
{
fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
free_list();
/*free(line);*/
exit(EXIT_FAILURE);
}
tmp = (*stack); /* save head address*/
second = (*stack)->next; /*get 2nd node address*/
second->n = second->n * (*stack)->n;
(*stack) = second;
free(tmp);
}
