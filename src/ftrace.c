/*
** EPITECH PROJECT, 2023
** B-PSU-400-REN-4-1-ftrace-mael1.becel
** File description:
** ftrace
*/

#include "print.h"
#include "stack.h"

int exit_ftrace(syscall_t syscall)
{
    if (strcmp(syscall.name, "exit_group") == 0) {
        fprintf(stderr, "+++ exited with 0 +++\n");
        return 1;
    }
    return 0;
}

/**
 * It waits for the child process to make a system call, then prints the system
 * call and its arguments, then waits for the child process to return from the
 * system call, then prints the return value
 *
 * @param pid the pid of the process to trace
 * @param detailed if true, print the arguments of the syscall
 */
int ftrace(pid_t pid, bool detailed)
{
    struct user_regs_struct regs;
    bool is_regs = false;
    my_stack_t *stack = stack_init();

    wait4(pid, NULL, 0, NULL);
    while (1) {
        ptrace(PTRACE_SINGLESTEP, pid, NULL, NULL);
        wait4(pid, NULL, 0, NULL);
        ptrace(PTRACE_GETREGS, pid, NULL, &regs);
        stack = check_funccall(regs, pid, stack);
        if (check_syscall(regs, pid, detailed) == 1)
            break;
    }
    return 0;
}
