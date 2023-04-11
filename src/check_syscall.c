/*
** EPITECH PROJECT, 2023
** B-PSU-400-REN-4-1-ftrace-mael1.becel
** File description:
** check_syscall
*/

#include "ftrace.h"

/**
 * If the system call number is greater than 328, then single step the process
 * and return 2. Otherwise, return 0
 *
 * @param regs The registers of the child process.
 * @param pid The pid of the process to be traced.
 *
 * @return The return value of the system call.
 */
int check_negative_rax(struct user_regs_struct regs, pid_t pid)
{
    if (regs.orig_rax > 328) {
        if (ptrace(PTRACE_SINGLESTEP, pid, NULL, NULL) == -1)
            return 1;
        return 2;
    }
    return 0;
}

/**
 * It checks if the process is in single step mode
 *
 * @param pid The process ID of the child process.
 *
 * @return The return value of the function that was just executed.
 */
int check_single_step(pid_t pid)
{
    if (ptrace(PTRACE_SINGLESTEP, pid, NULL, NULL) == -1) {
        printf("\n");
        return 1;
    }
    return 0;
}
