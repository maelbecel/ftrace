/*
** EPITECH PROJECT, 2023
** B-PSU-400-REN-4-1-ftrace-mael1.becel
** File description:
** check_syscall
*/

#include "print.h"

/**
 * If the system call number is greater than 328, then single step the process
 * and return 2. Otherwise, return 0
 *
 * @param regs The registers of the child process.
 * @param pid The pid of the process to be traced.
 *
 * @return The return value of the system call.
 */
int is_syscall(struct user_regs_struct regs, pid_t pid)
{
    long opcode;

    if ((opcode = ptrace(PTRACE_PEEKDATA, pid, regs.rip, NULL)) != -1) {
        if ((opcode & 0xffff) == 0x050f)
            return 1;
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
    (void)(print_table);
    (void)(table);
    if (ptrace(PTRACE_SINGLESTEP, pid, NULL, NULL) == -1) {
        printf("\n");
        return 1;
    }
    return 0;
}

int check_syscall(struct user_regs_struct regs, pid_t pid, bool detailed)
{
    syscall_t syscall;

    if (is_syscall(regs, pid)) {
        syscall = get_syscall(regs.rax);
        print_syscall(syscall, regs, pid, detailed);
        ptrace(PTRACE_SINGLESTEP, pid, NULL, NULL);
        wait4(pid, NULL, 0, NULL);
        check_ret(syscall.ret, (long long)regs.rax, pid, detailed);
        if (exit_ftrace(syscall))
            return 1;
    }
    return 0;
}
