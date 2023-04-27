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
    if (!syscall.name || strcmp(syscall.name, "exit_group") == 0) {
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
    (void)(print_table);
    (void)(table);
    struct user_regs_struct regs;
    my_stack_t *stack = stack_init();

    wait4(pid, NULL, 0, NULL);
    while (1) {
        if (ptrace(PTRACE_SINGLESTEP, pid, NULL, NULL) == -1)
            return 84;
        wait4(pid, NULL, 0, NULL);
        if (ptrace(PTRACE_GETREGS, pid, NULL, &regs) == -1)
            return 84;
        stack = check_funccall(regs, pid, stack);
        if (check_syscall(regs, pid, detailed) == 1)
            break;
    }
    return 0;
}
