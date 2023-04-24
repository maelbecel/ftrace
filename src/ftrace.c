/*
** EPITECH PROJECT, 2023
** B-PSU-400-REN-4-1-ftrace-mael1.becel
** File description:
** ftrace
*/

#include "print.h"

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
    syscall_t syscall;
    struct user_regs_struct regs;
    char opcode;

    wait4(pid, NULL, 0, NULL);
    while (1) {
        ptrace(PTRACE_SINGLESTEP, pid, NULL, NULL);
        wait4(pid, NULL, 0, NULL);
        ptrace(PTRACE_GETREGS, pid, NULL, &regs);
        if (is_syscall(regs, pid)) {
            syscall = get_syscall(regs.rax);
            print_syscall(syscall, regs, pid, detailed);
            ptrace(PTRACE_SINGLESTEP, pid, NULL, NULL);
            wait4(pid, NULL, 0, NULL);
            check_ret(syscall.ret, (long long)regs.rax, pid, detailed);
            if (exit_ftrace(syscall))
                break;
        }
        check_funccall(regs, pid);
    }
    return 0;
}
