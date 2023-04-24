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
            // fprintf(stderr, "OPCODE: %#llx\n", opcode);
            return 1;
        }
        if ((opcode & 0xff) == 0xc3 || (opcode & 0xff) == 0xcb)
            return 2;
    }
    return 0;
}

void check_funccall(struct user_regs_struct regs, pid_t pid)
{
    int ret = 0;

    if ((ret = is_func_call(regs, pid)) == 1)
        fprintf(stderr, "Entering function func_%#llx\n", regs.rip);
    else if (ret == 2)
        fprintf(stderr, "Leaving function func\n", regs.rip);
}