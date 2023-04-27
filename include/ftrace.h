/*
** EPITECH PROJECT, 2022
** ftrace.c
** File description:
** ftrace
*/

#ifndef FTRACE_H_
    #define FTRACE_H_

    #define _GNU_SOURCE
    #include <sys/stat.h>
    #include <sys/wait.h>
    #include <sys/resource.h>
    #include <sys/types.h>
    #include <sys/ptrace.h>
    #include <sys/time.h>
    #include <sys/user.h>
    #include <stdbool.h>
    #include <string.h>
    #include <fcntl.h>
    #include <stddef.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <err.h>
    #include <gelf.h>
    #include <stdint.h>
    #include <sysexits.h>

    #include "my.h"
    #include "printf.h"
    #include "formatstring.h"
    #include "stack.h"

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
    my_stack_t *check_funccall(struct user_regs_struct regs, pid_t pid,
    my_stack_t *stack);
    char *get_maps(long sym_addr, pid_t pid);
    int check_syscall(struct user_regs_struct regs, pid_t pid, bool detailed);
    char *get_name(long sym_addr, GElf_Shdr *shdr, Elf_Scn *scn, Elf **e);
    Elf_Scn *get_scene(Elf **e, size_t shstrndx, GElf_Shdr *shdr);
    Elf *get_shdrstrndx(int *fd, pid_t pid);
    char *get_exe(long sym_addr, pid_t pid);

#endif
