#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE

#include <stdio.h> /*FILE*/
#include <stdlib.h> /*exit(Macros)*/
#include <stddef.h> /*size_t*/
#include <string.h> /*strtok()*/
#include <ctype.h> /*isdigit()*/
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
int n;
struct stack_s *prev;
struct stack_s *next;
} stack_t;

/*extern stack_t *head;*/

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct glob - carries global variables
 * @f: pointer to file
 * @line: input line of monty file
 * @head: linked list head
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */

typedef struct glob
{
FILE *f;
char *line;
stack_t *head;
} glob;

extern glob glb;






/* functions declaraction: */

/* processing the raw file content file:   main.c*/
void readFile(FILE *f);
void opcode_extractor(char *line, unsigned int line_number, int *isStake);
void handle_push(char *push_arg, unsigned int line_number, int *isStake);
int push_arg_number(char *push_arg, unsigned int line_number);

/* processing the raw file content file: 1_processisng.c*/
stack_t *pre_push_node(int n);
void func_executor(char *opcode, unsigned int line_number);
void free_list(void);
void clean_exit(void);




/*tasks functions file:    2_taks_fucntions*/
void push_stack(stack_t **stack, unsigned int line_number);
void push_queue(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);

/*tasks functions file:    3_taks_fucntions*/
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);

/*tasks functions file:    4_taks_fucntions*/
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);




#endif
