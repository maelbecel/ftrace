/*
** EPITECH PROJECT, 2023
** ftrace
** File description:
** check_funccall
*/

#include "ftrace.h"

int is_func_call(struct user_regs_struct regs, pid_t pid)
{
    long opcode;

    if ((opcode = ptrace(PTRACE_PEEKDATA, pid, regs.rip, NULL)) != -1) {
        if ((opcode & 0xff) == 0xE8 || (opcode & 0xff) == 0x9A) {
            return 1;
        }
        if ((opcode & 0xff) == 0xc3 || (opcode & 0xff) == 0xcb)
            return 2;
    }
    return 0;
}

stack_t *check_funccall(struct user_regs_struct regs, pid_t pid, stack_t *stack)
{
    int ret = 0;

    if ((ret = is_func_call(regs, pid)) == 1) {
        stack = stack_push(stack, "jej");
        fprintf(stderr, "Entering function func_%#llx\n", regs.rip);
    }
    if (ret == 2) {
        stack_t *tmp = stack_pop(stack);
        if (!tmp || !tmp->func)
            fprintf(stderr, "Leaving function unknown\n");
        else {
            fprintf(stderr, "Leaving function %s\n", tmp->func);
            stack = stack->next;
        }
        if (tmp) free(tmp);
    }
    return stack;
}
