/*
** EPITECH PROJECT, 2023
** B-PSU-400-REN-4-1-ftrace-mael1.becel
** File description:
** syscalls
*/

#include "fff.h"
#include <criterion/criterion.h>
#include "../include/ftrace.h"
#include "../include/syscalls.h"

////////////////////////////////////////////////////////////////////////
///                              check_negative_rax
////////////////////////////////////////////////////////////////////////

int check_negative_rax(struct user_regs_struct regs, pid_t pid);
Test(check_negative_rax, returns_zero_when_rax_is_non_negative)
{
    struct user_regs_struct regs = { .orig_rax = 100 };
    pid_t pid = 1234;
    int result = check_negative_rax(regs, pid);


    cr_assert_eq(result, 0);
}

Test(check_negative_rax, returns_one_when_ptrace_fails)
{
    // Arrange
    struct user_regs_struct regs = { .orig_rax = 500 };
    pid_t pid = 1234;
    int result = check_negative_rax(regs, pid);

    cr_assert_eq(result, 1);

}

////////////////////////////////////////////////////////////////////////
///                              check_single_step
////////////////////////////////////////////////////////////////////////

int check_single_step(pid_t pid);
Test(check_single_step, ptrace_fail)
{
    pid_t pid = 1234;
    int result = check_single_step(pid);

    cr_assert_eq(result, 1);
}

////////////////////////////////////////////////////////////////////////
///                              get_syscall
////////////////////////////////////////////////////////////////////////

syscall_t get_syscall(int num);
Test(get_syscall, finding_sucess)
{
    syscall_t syscall = table[60];
    syscall_t result = get_syscall(60);

    cr_assert_str_eq(result.name, syscall.name);
}

Test(get_syscall, finding_failed)
{
    syscall_t result = get_syscall(1664);

    if (!result.name)
        cr_assert_eq(1, 1);
    else
        cr_assert_eq(1, 2);
}

////////////////////////////////////////////////////////////////////////
///                              check_ret
////////////////////////////////////////////////////////////////////////

void check_ret(int type, long long rax, pid_t pid, bool detailed);
Test(check_ret, error)
{
    check_ret(NUM, -1, 1234, true);
    check_ret(NUM, 1, 1234, true);
    check_ret(NUM, -1, 1234, false);
    check_ret(NUM, -1, 1234, true);
    check_ret(NUM, -125, 1234, true);
}

////////////////////////////////////////////////////////////////////////
///                              print_syscall
////////////////////////////////////////////////////////////////////////

void print_syscall(syscall_t syscall, struct user_regs_struct regs, int pid,
                   bool detailed);
Test(print_syscall, arg1)
{
    syscall_t syscall = {0, "read", 4, NUM, NUM, 0, 0, 0, 0, 0};
    struct user_regs_struct regs = {.rdi = 0, .rsi = 0, .rdx = 0, .rcx = 0, .r8 = 0, .r9 = 0};

    print_syscall(syscall, regs, 1664, true);
}

Test(print_syscall, arg2)
{
    syscall_t syscall = {60, "exit", 2, NUM, 0, NUM, 0, 0, 0, 0};
    struct user_regs_struct regs = {.rdi = 4, .rsi = 3, .rdx = 5, .rcx = 6, .r8 = 0, .r9 = 0};

    print_syscall(syscall, regs, 1664, true);
}

Test(print_syscall, arg3)
{
    syscall_t syscall = {666, "jej", 2, NUM, 0, NUM, 0, 0, 0, 0};
    struct user_regs_struct regs = {.rdi = 4, .rsi = 3, .rdx = 5, .rcx = 6, .r8 = 0, .r9 = 0};

    print_syscall(syscall, regs, 1, true);
}