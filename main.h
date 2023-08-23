#ifndef C_STACKS_QUEUES_LIFO_FIFO
#define C_STACKS_QUEUES_LIFO_FIFO

/** Include Stadnard Libraries and Custom Libraries **/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stddef.h>
#include "global_marcos.h"

/** Prototypes **/

/** INITIZATED_FILE.C FILE **/
void analysis_file(char *dir);

/** INITIZATED_GLOBAL_STR.C FILE **/
void initizated_global(FILE *, stack_t *, char *, char *, int);

/** OPCODE_FUN.C FILE **/
void (*get_opcode_fun(char *, unsigned int))(stack_t **stack, unsigned int);

/** FREE.C FILE **/
void f_stack(stack_t *);
void free_glob(void);

/** OP_PUSH_PALL.C FILE **/
void opcode_push(stack_t **, unsigned int);
void opcode_pall(stack_t **, unsigned int);

/** OP_PINT.C FILE **/
void opcode_pint(stack_t **, unsigned int);

/** OP_POP.C FILE **/
void opcode_pop(stack_t **, unsigned int);

/** OP_MUL_DIV.C FILE **/
void opcode_div(stack_t **, unsigned int);
void opcode_mul(stack_t **, unsigned int);

/** FUNC.C FILE **/
void is_digit(unsigned int);
char *_itoa(int);
void push_queue(stack_t **, int);
#endif
