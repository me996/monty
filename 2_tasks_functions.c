#include "monty.h"

/**
 * push_stack - pushes a node to the stack
 * @stack: a pointer to the head of the stack
 * @line_number: the line number of the opcode
 * Return: none
 */

void push_stack(stack_t **stack, unsigned int line_number)
{
stack_t *current;
current = *stack;
(void) line_number;

if (glb.head == NULL) /*no nodes found in the list*/
{
glb.head = current;
}
else  /* there are nodes in the list*/
{
current->next = glb.head;
glb.head->prev = current;
glb.head = current;
}
}

/**
 * push_queue - pushes a node to the queue
 * @stack: a pointer to the head of the queue
 * @line_number: the line number of the opcode
 * Return: none
 */

void push_queue(stack_t **stack, unsigned int line_number)
{
stack_t *current, *tmp;
current = *stack;
tmp = glb.head;
(void) line_number;

if (glb.head == NULL) /*no nodes found in the list*/
glb.head = current;
else  /* there are nodes in the list*/
{
while (tmp->next) /*capture last node at list*/
{
tmp = tmp->next;
}
tmp->next = current;
current->prev = tmp;
}
}


/**
 * pall - prints all of the nodes in the stack
 * @stack: a pointer to the head of the stack
 * @line_number: the line number of the opcode
 * Return: none
 */

void pall(stack_t **stack, unsigned int line_number)
{

stack_t *current;
(void) line_number;
current = *stack;

if (!current)
return;

while (current)
{
printf("%d\n", current->n);
current = current->next;
}
}

/**
 * pint - prints the top node of the stack
 * @stack: a pointer to the head of the stack
 * @line_number: the line number of the opcode
 * Return: none
 */

void pint(stack_t **stack, unsigned int line_number)
{

if (!*stack)
{
fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
clean_exit();
}
printf("%d\n", (*stack)->n);
}
