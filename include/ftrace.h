/*
** EPITECH PROJECT, 2022
** ftrace.c
** File description:
** ftrace
*/

#ifndef FTRACE_H_
    #define FTRACE_H_

    #include <sys/stat.h>
    #include <sys/wait.h>
    #include <sys/resource.h>
    #include <sys/types.h>
    #include <sys/ptrace.h>
    #include <sys/time.h>
    #include <sys/user.h>
    #include <stdbool.h>
    #include <string.h>
    #include <stddef.h>
    #include <unistd.h>
    #include <stdio.h>

    #include "my.h"
    #include "printf.h"
    #include "formatstring.h"

    #define HELP "USAGE: ./ftrace [-s] [-p <pid>|<command>]\n"

    typedef struct err_s {
        int code;
        char *name;
    } err_t;

    int is_func_call(struct user_regs_struct regs, pid_t pid);
    int is_syscall(struct user_regs_struct regs, pid_t pid);
    int check_single_step(pid_t pid);
    void get_errno(long long rax);
    void check_ret(int type, long long rax, pid_t pid, bool detailed);
    int ftrace(pid_t pid, bool detailed);
    void show(int type, unsigned long long reg, int pid, bool detailed);

#endif
