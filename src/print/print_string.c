/*
** EPITECH PROJECT, 2023
** B-PSU-400-REN-4-1-ftrace-mael1.becel
** File description:
** print_string
*/

#include "print.h"

/**
 * It prints a character to the standard error stream, but if the character is
 * not printable, it prints the octal value of the character instead
 *
 * @param c The character to print.
 */
static void show_char(char c)
{
    if (c < 32 && c > 126)
        fprintf(stderr, "\\%o", c);
    else
        fprintf(stderr, "%c", c);
}

/**
 * It prints a string from the memory of the traced process
 *
 * @param args The address of the first argument of the function.
 * @param pid The process ID of the process we're tracing.
 */
void print_string(unsigned long long args, int pid)
{
    char c;
    int i = 0;
    fprintf(stderr, "\"");
    c = ptrace(PTRACE_PEEKDATA, pid, args + i, NULL);
    while (c != '\0' && i < 32) {
        if (c != -1)
            show_char(c);
        i++;
        c = ptrace(PTRACE_PEEKDATA, pid, args + i, NULL);
    }
    fprintf(stderr, "\"");
    if (i == 32 && c != '\0')
        fprintf(stderr, "...");
}

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
 * It prints the first 32 strings in the array, and if there are more than 32,
 * it prints "..."
 *
 * @param args The address of the first argument.
 * @param pid The process ID of the process being traced.
 */
void print_string_array(unsigned long long args, int pid)
{
    int len = ptrlen(args, pid);
    fprintf(stderr, "[");
    for (int i = 0; i < len && i < 32; i++) {
        print_string(ptrace(PTRACE_PEEKDATA, pid, args, NULL), pid);
        if (i + 1 < len && i + 1 < 32)
            fprintf(stderr, ", ");

        args += sizeof(char *);
    }
    if (len > 32)
        fprintf(stderr, ", ...");
    fprintf(stderr, "]");
}
