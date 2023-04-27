/*
** EPITECH PROJECT, 2023
** B-PSU-400-REN-4-1-ftrace-mael1.becel
** File description:
** print_syscall
*/

#include "print.h"

/**
 * It prints the value of a register, and if the `detailed` flag is set, it
 * will print the value of the register in a more detailed way
 *
 * @param type The type of the register.
 * @param reg the register value
 * @param pid The process ID of the process to attach to.
 * @param detailed If true, print the register value in a human-readable
 * format.
 *
 * @return The address of the function
 */
void show(int type, unsigned long long reg, int pid, bool detailed)
{
    if (!detailed) {
        fprintf(stderr, "%#llx", reg);
        return;
    }
    for (int i = 0; print_table[i].id != -1; i++) {
        if (print_table[i].id == type) {
            print_table[i].print(reg, pid);
            return;
        }
    }
    fprintf(stderr, "?");
}

/**
 * It prints the value of a
 * system call argument
 *
 * @param arg the argument number (1, 2, 3, 4, 5, 6)
 * @param reg the value of the register
 * @param pid the process ID of the process that made the system call
 * @param detailed whether to show the value of the argument or not
 */
static void check_syscall_arg(int arg, unsigned long long reg, int pid,
    bool detailed)
{
    if (arg) {
        fprintf(stderr, ", ");
        show(arg, reg, pid, detailed);
    }
}

/**
 * It prints the syscall name,
 * and then prints the arguments, if any, using the `show` function
 *
 * @param syscall The syscall structure that contains the name of the syscall
 * and the types of its arguments.
 * @param regs The registers of the process.
 * @param pid the process id of the process we're tracing
 * @param detailed if true, print the contents of the buffer pointed to by the
 * syscall
 */
void print_syscall(syscall_t syscall, struct user_regs_struct regs, int pid,
    bool detailed)
{
    (void)(table);
    fprintf(stderr, "Syscall %s(", syscall.name);
    if (syscall.arg1)
        show(syscall.arg1, regs.rdi, pid, detailed);
    check_syscall_arg(syscall.arg2, regs.rsi, pid, detailed);
    check_syscall_arg(syscall.arg3, regs.rdx, pid, detailed);
    check_syscall_arg(syscall.arg4, regs.rcx, pid, detailed);
    check_syscall_arg(syscall.arg5, regs.r8, pid, detailed);
    check_syscall_arg(syscall.arg6, regs.r9, pid, detailed);
    fprintf(stderr, ")");
}
