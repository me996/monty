#include "monty.h"

/**
 * mod - calculates the modulus of the top two nodes
 * @stack: a pointer to the head of the stack
 * @line_number: the line number of the opcode
 * Return: none
 */

void mod(stack_t **stack, unsigned int line_number)
{
stack_t *second, *tmp;

if (!(*stack) || !(*stack)->next)
{
fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
clean_exit();
}
tmp = (*stack); /* save head address*/
second = (*stack)->next; /*get 2nd node address*/
if ((*stack)->n == 0)
{
fprintf(stderr, "L%d: division by zero\n", line_number);
clean_exit();
}
second->n = second->n % (*stack)->n;
(*stack) = second;
free(tmp);
}

/**
 * pchar - prints the ASCII character of the top node on the stack
 * @stack: a pointer to the head of the stack
 * @line_number: the line number of the opcode
 * Return: none
 */

void pchar(stack_t **stack, unsigned int line_number)
{
int n;
if (!(*stack))
{
fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
clean_exit();
}
n = (*stack)->n;
if (n < 0 || n > 127)
{
fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
clean_exit();
}
printf("%c\n", n);
}

/**
 * pstr - prints all the nodes on the stack
 * @stack: a pointer to the head of the stack
 * @line_number: the line number of the opcode
 * Return: none
 */

void pstr(stack_t **stack, unsigned int line_number)
{
stack_t *tmp;
(void) line_number;
tmp = *stack;
if (!*stack)
{
printf("\n");
return;
}


while (tmp)
{
if (tmp->n > 0 && tmp->n <= 127)
{
printf("%c", tmp->n);
tmp = tmp->next;
}
else
{
printf("\n");
return;
}
}
printf("\n");
}

/**
 * rotl - rotates the stack to the left by one position
 * @stack: a pointer to the head of the stack
 * @line_number: the line number of the opcode
 * Return: none
 */

void rotl(stack_t **stack, unsigned int line_number)
{
stack_t *last, *tmp;
(void) line_number;
 /*do nothing in case no node or 1 node*/
if ((!*stack) || !(*stack)->next)
return;

last = (*stack);
tmp = (*stack);
while ((last->next))
{
last = last->next;
}
/*deal with second node to be first node*/
(*stack) = (*stack)->next;
(*stack)->prev = NULL;

/*deal with head to be last node*/
tmp->next = NULL;
tmp->prev = last;
last->next = tmp;
}

/**
 * rotr - rotates the stack to the right by one position
 * @stack: a pointer to the head of the stack
 * @line_number: the line number of the
 * Return: none
 */

void rotr(stack_t **stack, unsigned int line_number)
{
stack_t *last;
(void) line_number;
/*do nothing in case no node or 1 node*/
if ((!*stack) || !(*stack)->next)
return;

last = (*stack);
while ((last->next))
{
last = last->next;
}

/*deal with last node to be first node*/
last->prev->next = NULL; /*node just before last*/
last->prev = NULL;
last->next = (*stack);
(*stack) = last;
}
