/*
** EPITECH PROJECT, 2023
** B-PSU-400-REN-4-1-ftrace-mael1.becel
** File description:
** print_void_ptr
*/

#include "print.h"

/* A table of characters and their names. */
static const charbs_t ascii[12] = {
    {-80, "\\260"},
    {0, "\\0"},
    {1, "\\1"},
    {2, "\\2"},
    {3, "\\3"},
    {7, "\\a"},
    {8, "\\b"},
    {9, "\\t"},
    {10, "\\n"},
    {11, "\\v"},
    {12, "\\f"},
    {13, "\\r"}
};

/**
 * It reads 32 bytes from the address pointed to by the first argument,
 * and if all of them are null bytes, it returns 1, otherwise it returns 0
 *
 * @param args The address of the first argument of the function.
 * @param pid The process ID of the process we want to trace.
 *
 * @return the number of bytes in the string.
 */
int is_empty_string(unsigned long long args, pid_t pid)
{
    char c;
    int count = 0;
    int i = 0;

    c = ptrace(PTRACE_PEEKDATA, pid, args + i, NULL);
    while (i < 32) {
        if (c == 0)
            count++;
        i++;
        c = ptrace(PTRACE_PEEKDATA, pid, args + i, NULL);
    }
    if (count == 32)
        return 1;
    return 0;
}

/**
 * It prints a character, but if the character is a control character,
 * it prints the control character's name instead
 *
 * @param c The character to print.
 *
 * @return the name of the character.
 */
void print_char(char c)
{
    (void)(print_table);
    (void)(table);
    for (int i = 0; i < 11; i++) {
        if (c == ascii[i].id) {
            fprintf(stderr, "%s", ascii[i].name);
            return;
        }
    }
    if (c > 32 && c < 127)
        fprintf(stderr, "%c", c);
    else
        fprintf(stderr, "\\%x", c);
}

/**
 * It prints a string of up to 32 characters, and if the string is longer
 * than 32 characters, it prints "..."
 *
 * @param args the address of the first argument
 * @param pid The process ID of the child process.
 *
 * @return The return value of the function.
 */
void print_void_ptr(unsigned long long args, pid_t pid)
{
    char c;
    int i = 0;

    if (is_empty_string(args, pid)) {
        fprintf(stderr, "\"\"");
        return;
    }
    fprintf(stderr, "\"");
    c = ptrace(PTRACE_PEEKDATA, pid, args + i, NULL);
    while (i < 32) {
        if (c != -1)
            print_char(c);
        i++;
        c = ptrace(PTRACE_PEEKDATA, pid, args + i, NULL);
    }
    fprintf(stderr, "\"");
    if (i == 32 && c == '\0')
        fprintf(stderr, "...");
}
