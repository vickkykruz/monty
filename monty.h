#ifndef C_STACKS_QUEUES_LIFO_FIFO
#define C_STACKS_QUEUES_LIFO_FIFO

/** Include Stadnard Libraries and Custom Libraries **/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stddef.h>
#include <ctype.h>
#include "global_marcos.h"

/** Prototypes **/

/** OPCODE_FUN.C FILE **/
void analysis_opcode(stack_t **stack, char *s, unsigned int l_cnt);

/** LISTS.C FILE **/
stack_t *add_node(stack_t **stack, const int num);
stack_t *queue_node(stack_t **stack, const int num);
size_t print_stack(const stack_t *stack);

/** FREE.C FILE **/
void f_stack(stack_t *);

/** OP_PUSH_PALL.C FILE **/
void opcode_push(stack_t **, unsigned int);
void opcode_pall(stack_t **, unsigned int);

/** OP_PINT.C FILE **/
void opcode_pint(stack_t **, unsigned int);

/** OP_POP.C FILE **/
void opcode_pop(stack_t **, unsigned int);

/** OP_SWAP.C FILE **/
void opcode_swap(stack_t **, unsigned int);

/** OP_ADD_NOP.C FILE **/
void opcode_nop(stack_t **, unsigned int);
void opcode_add(stack_t **, unsigned int);

/** OP_SUB.C FILE **/
void opcode_sub(stack_t **, unsigned int);

/** OP_MUL_DIV.C FILE **/
void opcode_div(stack_t **, unsigned int);
void opcode_mul(stack_t **, unsigned int);

/** OP_PCHAR_PSTR.C FILE **/
void opcode_pstr(stack_t **, unsigned int);

/** OP_MOD.C FILE **/
void opcode_mod(stack_t **, unsigned int);

/** OP_ROTL_ROTR.C FILE **/
void opcode_rotl(stack_t **, unsigned int);
void opcode_rotr(stack_t **, unsigned int);

/** FUNC.C FILE **/
int is_digit(char *str);
#endif
