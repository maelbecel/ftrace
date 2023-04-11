/*
** EPITECH PROJECT, 2023
** B-PSU-400-REN-4-1-ftrace-mael1.becel
** File description:
** ftrace
*/

#include "print.h"

/**
 * It waits for the child process to make a system call, then prints the system
 * call and its arguments, then waits for the child process to return from the
 * system call, then prints the return value
 *
 * @param pid the pid of the process to trace
 * @param detailed if true, print the arguments of the syscall
 */
void ftrace(pid_t pid, bool detailed)
{
    syscall_t syscall;
    struct user_regs_struct regs;
    int res = 0;

    while (1) {
        wait4(pid, NULL, 0, NULL);
        ptrace(PTRACE_GETREGS, pid, NULL, &regs);
        if ((res = check_negative_rax(regs, pid)) == 1)
            break;
        if (res == 2)
            continue;
        syscall = get_syscall(regs.orig_rax);
        print_syscall(syscall, regs, pid, detailed);
        if (check_single_step(pid))
            break;
        wait4(pid, NULL, 0, NULL);
        ptrace(PTRACE_SINGLESTEP, pid, NULL, NULL);
        check_ret(syscall.ret, (long long)regs.rax, pid, detailed);
    }
}
