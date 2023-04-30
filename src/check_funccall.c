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

    if ((opcode = ptrace(PTRACE_PEEKTEXT, pid, regs.rip)) != -1)
    {
        if ((opcode & 0xff) == 0xE8 || (opcode & 0xff) == 0x9A
        || (opcode & 0xff) == 0xFF)
            return 1;
        if ((opcode & 0xff) == 0xc3 || (opcode & 0xff) == 0xcb
        || (opcode & 0xff) == 0xc2 || (opcode & 0xff) == 0xca)
            return 2;
    }
    return 0;
}

my_stack_t *check_funccall(struct user_regs_struct regs, pid_t pid, my_stack_t *stack)
{
    int ret = 0;
    char *func;

    if ((ret = is_func_call(regs, pid)) == 1) {
        ptrace(PTRACE_SINGLESTEP, pid, NULL, NULL);
        wait4(pid, NULL, 0, NULL);
        ptrace(PTRACE_GETREGS, pid, NULL, &regs);
        func = get_maps(regs.rip, pid);
        stack = stack_push(stack, func);
        if (func)
            fprintf(stderr, "Entering function %s at %#llx\n", func,
            regs.rip);
    }
    if (ret == 2) {
        my_stack_t *tmp = stack_pop(&stack);
        if (tmp && tmp->func)
            fprintf(stderr, "Leaving function %s\n", tmp->func);
        if (tmp)
            free(tmp);
    }
    return stack;
}
