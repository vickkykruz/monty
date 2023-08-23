#ifndef PROJECT_GLOBAL_MARCOS
#define PROJECT_GLOBAL_MARCOS


#include <stdio.h>
#define MAX_SIZE 1024

#define OPCODE \
{ \
	{"push", opcode_push}, \
	{"pall", opcode_pall}, \
	{"mul", opcode_mul}, \
	{"pint", opcode_pint}, \
	{"pop", opcode_pop}, \
	{"div", opcode_div}, \
	{NULL, NULL}, \
}

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
 * struct global_s - This is a global structure
 * @str: This argument reprsent the number of arguments passed
 * @file: This argument reprsent the given path file
 * @buffer: This argument reprsent the number of buffer passed
 * @isstack: This is an argument that reprsent if the argument passed is a stack
 * @stack: This is an arguments that reprsent the given stack
 * Description: This struction is to handle and store and arguemt so as to be used
 *
 */
typedef struct global_s
{
	char *buffer;
	char *str;
	FILE *file;
	int isstack;
	stack_t *stack;
} global_str;

extern global_str stru;
#endif
