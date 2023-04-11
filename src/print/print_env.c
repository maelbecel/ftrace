/*
** EPITECH PROJECT, 2023
** B-PSU-400-REN-4-1-ftrace-mael1.becel
** File description:
** print_env.c
*/

#include "print.h"

/**
 * It returns the number of
 * pointers in a string of pointers
 *
 * @param args The address of the first argument.
 * @param pid The process ID of the child process.
 *
 * @return The number of arguments passed to the program.
 */
static int ptrlen(unsigned long long args, int pid)
{
    unsigned long long c = -1;
    int i = 0;

    while ((char *)c != NULL) {
        if ((c = ptrace(PTRACE_PEEKDATA, pid, args, NULL)) ==
        (unsigned long long) -1)
            return (i - 1);
        i++;
        args += sizeof(char *);
    }
    return (i - 1);
}

/**
 * It prints the address of the environment variable array, and the number of
 * variables in the array
 *
 * @param args the address of the environment variables
 * @param pid The process ID of the process to read from.
 */
void print_env(unsigned long long args, int pid)
{
    int len = ptrlen(args, pid);
    fprintf(stderr, "%#llx /* %d vars */", args, len);
}
