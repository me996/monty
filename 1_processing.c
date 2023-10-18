#include "monty.h"

/**
 * pre_push_node - creates a new node for the stack or queue
 * @n: the value to be stored in the node
 * Return: a pointer to the new node
 */

stack_t *pre_push_node(int n)
{
stack_t *new = malloc(sizeof(stack_t));
if (!new)
{
fprintf(stderr, "Error: malloc failed\n");
clean_exit();
}
new->n = n;
new->prev = NULL;
new->next = NULL;

return (new);
}

/**
 * func_executor - executes the given opcode
 * @opcode: the opcode to be executed
 * @line_number: the line number of the opcode
 */

void func_executor(char *opcode, unsigned int line_number)
{
int i;
instruction_t opcode_func[] = {
{"pall", pall},
{"pint", pint},
{"pop", pop},
{"swap", swap},
{"add", add},
{"sub", sub},
{"div", _div},
{"mul", mul},
{"mod", mod},
{"pchar", pchar},
{"pstr", pstr},
{"rotl", rotl},
{"rotr", rotr},
{NULL, NULL}
};

for (i = 0; opcode_func[i].opcode != NULL; i++)
{
if (strcmp(opcode_func[i].opcode, opcode) == 0)
{/*execute the correct function*/
opcode_func[i].f(&glb.head, line_number);
return;
}
}
/*if opcode not in above list, exit*/
fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
clean_exit();
}


/**
* free_list - frees all of the nodes in the stack or queue
*/

void free_list(void)
{
stack_t *tmp, *current = glb.head;

if (glb.head == NULL)
return;

while (current)
{
tmp = current->next;
free(current);
current = tmp;
}
}

/**
 * clean_exit - frees dynamic allocated memory
 */

void clean_exit(void)
{
free_list();
fclose(glb.f);
exit(EXIT_FAILURE);
}
