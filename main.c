#include "monty.h"


glob glb = {NULL, NULL};


/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char **argv)
{
FILE *f;
if (argc != 2)/*if just prog name or more than 2 arg*/
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}

f = fopen(argv[1], "r"); /*pass in: file path, read only*/
glb.f = f;
if (!f)
{/*if wrong with path or file*/
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
exit(EXIT_FAILURE);
}
readFile(f);
fclose(f);
return (0);
}

/**
 * readFile - reads file and parses it
 * @f: file pointer
 */

void readFile(FILE *f)
{
char line[MAX_LINE_LENGTH] = {'\0'};
int isStake = 1;
unsigned int line_number = 0;


/*read every single line from file f*/
while (fgets(line, MAX_LINE_LENGTH, f))
{ /* refine the line*/
line_number++;
opcode_extractor(line, line_number, &isStake);
}


free_list();
}

/**
 * opcode_extractor - extracts opcode from line and sets isStack flag
 * @line: line to extract opcode from
 * @line_number: line number
 * @isStake: pointer to integer indicating whether stack or queue is used
 */

void opcode_extractor(char *line, unsigned int line_number, int *isStake)
{
char *opcode, *push_arg; /* 1st, 2nd word in line*/

/*extracting opcode from the line*/
opcode = strtok(line, "\n ");
if (!opcode) /* for empty line*/
{ /*check message: L<line_number>: unknown instruction <opcode> */
fprintf(stderr, "Error: malloc failed\n");
clean_exit();
}

if (strcmp(opcode, "nop") == 0 || opcode[0] == '#')
return;
if (strcmp(opcode, "stack") == 0)
{
*isStake = 1;
return;
}
if (strcmp(opcode, "queue") == 0)
{
*isStake = 0;
return;
}
/* push argument */
if (strcmp(opcode, "push") == 0)
{/* only push has an argument*/
push_arg = strtok(NULL, "\n ");
handle_push(push_arg, line_number, isStake);
return;
}
else
{
func_executor(opcode, line_number);
return;
}

}

/**
 * handle_push - handles push opcode
 * @push_arg: argument to push
 * @line_number: line number
 * @isStake: pointer to integer indicating whether stack or queue is used
 */


void handle_push(char *push_arg, unsigned int line_number, int *isStake)
{

int n;
stack_t *new_node;

n = push_arg_number(push_arg, line_number);
new_node = pre_push_node(n);


if (*isStake)
{
push_stack(&new_node, line_number);
return;
}
else
{
push_queue(&new_node, line_number);
return;
}
}

/**
 * push_arg_number - converts push argument to number
 * @push_arg: argument to push
 * @line_number: line number
 * Return: number
 */

int push_arg_number(char *push_arg, unsigned int line_number)
{
int i, n, number_sign = 1;

if (!push_arg)
{
fprintf(stderr, "L%d: usage: push integer\n", line_number);
clean_exit();
}

/*transform string to integer:*/
/*handle number sign if exists*/
if (push_arg[0] == '-')
{
push_arg++;
number_sign = -1;
}
/*check all characters are digits*/
for (i = 0; push_arg[i] != '\0'; i++)
{
if (isdigit(push_arg[i]) == 0)
{
fprintf(stderr, "L%d: usage: push integer\n", line_number);
clean_exit();
}
}
n = number_sign *atoi(push_arg);
return (n);
}
